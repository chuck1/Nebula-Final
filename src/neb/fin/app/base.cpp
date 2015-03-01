#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <map>

#include <ft2build.h>
#include FT_FREETYPE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <gal/console/base.hpp>
#include <gal/etc/stopwatch.hpp>
#include <gal/dll/helper.hpp>
#include <gal/stl/deleter.hpp>
#include <gal/argparse/Parser.hpp>

#include <neb/fnd/free.hpp>
#include <neb/fnd/util/config.hpp>
#include <neb/fnd/environ/Base.hpp>
#include <neb/fnd/game/weapon/util/decl.hpp>
#include <neb/fnd/plug/gfx/app/Base.hpp>
#include <neb/fnd/context/Base.hpp>
#include <neb/fnd/window/Base.hpp>

#include <neb/fnd/gui/layout/util/Parent.hpp>
#include <neb/fnd/gui/object/Terminal.hpp>

#include <neb/fnd/core/scene/Base.hpp>
#include <neb/fnd/core/light/Point.hpp>

//#include <neb/gfx/util/log.hpp>
//
//#include <neb/gfx/core/light/spot.hpp>
//#include <neb/gfx/core/light/point.hpp>
//#include <neb/gfx/app/base.hpp>

#include <neb/py/util/config.hpp> // neb/py/util/config.hpp.in
#include <neb/py/core/scene/base.hpp>
#include <neb/py/app/base.hpp>

#include <neb/fin/app/base.hpp>
#include <neb/fin/core/scene/base.hpp>
#include <neb/fin/core/actor/rigiddynamic/base.hpp>
#include <neb/fin/core/actor/rigidstatic/base.hpp>
#include <neb/fin/core/shape/box.hpp>
#include <neb/fin/core/shape/HeightField.hpp>

#define STRINGIZE2(x) #x
#define STRINGIZE(x) STRINGIZE2(x)

typedef neb::fin::app::base THIS;

std::shared_ptr<neb::fin::app::base>		THIS::global()
{
	printv_func(DEBUG);

	auto app(dynamic_pointer_cast<neb::fin::app::base>(g_app_));
	assert(app);
	return app;
}
std::shared_ptr<neb::fin::app::base>	THIS::s_init(int ac, char ** av)
{
	printv_func(DEBUG);

	typedef neb::fin::app::base T;

	std::shared_ptr<T> app(new T(), gal::stl::deleter<T>());

	// parse args	
	gal::argparse::Parser parser;
	auto args = parser.parse(ac, av, "");
	
	if(args.has_long("python")) {
		auto filename = args.get_value_from_long("python");

		app->_M_preloop_scripts_python.push_back(filename);

		printf("%s\n", filename.c_str());
	}
	
	// continue init
	app->neb::fnd::app::Base::__init();
	app->neb::fin::app::base::__init();

	//app->neb::gfx::app::Base::__init();
	//app->neb::gfx::app::glsl::__init();
	//app->neb::gfx::app::glfw::__init();
	//app->neb::gfx::app::draw::__init();

	app->neb::phx::app::base::__init();



	printv(DEBUG, "&g_app_ = %p\n", &g_app_);

	g_app_ = app;

	return app;
}
neb::fin::app::base::base()
{
}
neb::fin::app::base::~base()
{
	printv_func(DEBUG);
}
void			THIS::__init()
{
	char buffer[256];
	strcpy(buffer, "import sys\nsys.path.append(\"");
	strcat(buffer, STRINGIZE(PY_LIB_DIR));
	strcat(buffer, "\")");

	printf("%s\n", buffer);

	//auto app = global();
	
	auto me = std::dynamic_pointer_cast<THIS>(shared_from_this());

	neb::py::app::Base py_app(me);

	try {
		console_->eval(buffer);
		console_->main_namespace_["neb"] = boost::python::import(STRINGIZE(PY_LIB_NAME));
		console_->main_namespace_["app"] = py_app;
	} catch(bp::error_already_set const &) {
		printf("unhandled python execption\n");
		printf("%s\n", STRINGIZE(PY_LIB_NAME));
		// print all other errors to stderr
		PyErr_Print();

		printf("lines: %lu\n", console_->lines_.size());

		abort();
	}

	read_config();	

	initRegistry();
}
void				THIS::read_config()
{
	printv_func(DEBUG);

	assert(console_);

	boost::python::object o;

	// python
	try {
		console_->eval("execfile(\"../share/config.py\")");
		o = console_->main_namespace_["log"];
	} catch(bp::error_already_set const &) {
		printf("unhandled python execption\n");
		printf("%s\n", STRINGIZE(PY_LIB_NAME));
		// print all other errors to stderr
		PyErr_Print();
		printf("lines: %lu\n", console_->lines_.size());
		console_->print();
		abort();
	}

	// log levels

	struct Pair
	{
		char const *		c;
		int * const		sl;
	};

	// fnd
	gal::tmp::VerbosityRegister::reg<neb::fnd::game::weapon::SimpleProjectile>(	"neb core game weapon simple projectile");

	gal::tmp::VerbosityRegister::reg<neb::fnd::core::scene::base>(			"neb fnd core scene base");
	gal::tmp::VerbosityRegister::reg<neb::fnd::core::actor::base>(			"neb fnd core actor base");
	gal::tmp::VerbosityRegister::reg<neb::fnd::core::shape::base>(			"neb fnd core shape base");
	gal::tmp::VerbosityRegister::reg<neb::fnd::core::light::base>(			"neb fnd core light base");

	gal::tmp::VerbosityRegister::reg<neb::fnd::window::Base>(			"neb fnd window base");
	gal::tmp::VerbosityRegister::reg<neb::fnd::context::Base>(			"neb fnd context base");
	gal::tmp::VerbosityRegister::reg<neb::fnd::environ::Base>(			"neb fnd environ base");
	
	gal::tmp::VerbosityRegister::reg<neb::fnd::gui::layout::Base>(			"neb fnd gui layout base");
	gal::tmp::VerbosityRegister::reg<neb::fnd::gui::object::Base>(			"neb fnd gui object base");
	gal::tmp::VerbosityRegister::reg<neb::fnd::gui::object::Terminal>(		"neb fnd gui object terminal");

	// phx
/*
	gal::tmp::VerbosityRegister::reg<neb::phx::core::scene::base>(			"neb phx core scene base");
	gal::tmp::VerbosityRegister::reg<neb::phx::core::actor::base>(			"neb phx core actor base");
	gal::tmp::VerbosityRegister::reg<neb::phx::core::actor::rigiddynamic::base>(	"neb phx core actor rigiddynamic base");
	gal::tmp::VerbosityRegister::reg<neb::phx::core::actor::rigidstatic::base>(	"neb phx core actor rigidstatic base");
	gal::tmp::VerbosityRegister::reg<neb::phx::core::shape::base>(			"neb phx core shape base");
*/	


/*		{"neb gfx",					(int*)&neb::gfx::sl},
		{"neb gfx actor",				(int*)&neb::gfx::core::actor::sl},
		{"neb gfx shape",				(int*)&neb::gfx::core::shape::sl},
		{"neb gfx light",				(int*)&neb::gfx::core::light::sl},
		{"neb gfx core light base",			&gal::tmp::Verbosity<neb::gfx::core::light::base>::_M_severity_level},
		{"neb phx",					(int*)&neb::phx::sl},
		{"neb phx scene",				(int*)&neb::phx::core::scene::sl},
		{"neb phx actor",				(int*)&neb::phx::core::actor::sl},
		{"neb phx actor control rigidbody base",	&gal::tmp::Verbosity<neb::phx::core::actor::control::rigidbody::base>::_M_severity_level},
		{"neb phx shape",				(int*)&neb::phx::core::shape::sl}
	};
	*/

	std::map<std::string, int> map_val({
			{"debug",	DEBUG},
			{"info",	INFO},
			{"warning",	WARNING},
			{"error",	ERROR},
			{"critical",	CRITICAL}});


	boost::python::extract<boost::python::dict> e(o);
	assert(e.check());
	boost::python::dict py_dict = e;

	boost::python::list keys = py_dict.keys();

	std::map<std::string, std::string> m;

	console_->print();

	printf("log %lu\n", len(keys));
	for (int i = 0; i < len(keys); ++i) {
		boost::python::extract<std::string> extracted_key(keys[i]);  
		if(!extracted_key.check()){  
			printv(WARNING, "Key invalid, map might be incomplete\n");
			abort();
			continue;
		}
		std::string key = extracted_key;  
		
		printf("%s\n", key.c_str());

		boost::python::extract<std::string> extracted_val(py_dict[key]);  
		if(!extracted_val.check()){  
			printv(WARNING, "Value invalid, map might be incomplete\n");  
			abort();
			continue;                 
		}
		std::string value = extracted_val;  
		m[key] = value;  
	}

	for(auto p : m) {
		auto var = p.first;
		auto val = p.second;

		auto it_val = map_val.find(val);
		if(it_val == map_val.end()) {
			printv(CRITICAL, "Value invalid, map might be incomplete\n");  
			abort();
		}

		int level = it_val->second;

		gal::tmp::VerbosityRegister::set(var, level);
	}
}
void				THIS::initRegistry()
{
	makeDLLFunc<neb::fnd::core::scene::base, neb::fnd::core::scene::base, neb::fin::core::scene::base>("scene");

	makeDefaultFunc<neb::fnd::core::actor::base, neb::fin::core::actor::rigiddynamic::base>();
	makeDefaultFunc<neb::fnd::core::actor::__base, neb::fin::core::actor::rigiddynamic::base>();
	makeDefaultFunc<neb::fnd::core::actor::__base, neb::fin::core::actor::base>();
	makeDefaultFunc<neb::fnd::core::actor::__base, neb::fin::core::actor::rigidstatic::base>();

	makeDefaultFunc<neb::fnd::core::shape::base, neb::fin::core::shape::base>();
	makeDefaultFunc<neb::fnd::core::shape::base, neb::fin::core::shape::box>();
	makeDefaultFunc<neb::fnd::core::shape::base, neb::fin::core::shape::HeightField::Base>();

	/*	makeDefaultFunc<neb::fnd::core::light::__base, neb::gfx::core::light::spot>();
		makeDefaultFunc<neb::fnd::core::light::__base, neb::gfx::core::light::point>();
		*/
}
void				neb::fin::app::base::release()
{
	//neb::fnd::app::__base::__release();
	neb::fnd::app::Base::__release();

	//neb::gfx::app::Base::__release();
	//neb::gfx::app::__gfx_glsl::__release();

	neb::phx::app::base::__release();

}
void				neb::fin::app::base::preloop()
{
	neb::fnd::gui::layout::util::Parent::preloop();
}
void				neb::fin::app::base::loop()
{
	//auto self(std::dynamic_pointer_cast<neb::fnd::app::Base>(shared_from_this()));
	//assert(self);

	auto g = G::get_object();

	preloop();

	while(!flag_.any(neb::fnd::app::util::flag::E::SHOULD_RELEASE)) {

		// check for exit condition

		if(!neb::fnd::window::util::Parent::map_.front()) break;

		// update

		if(G::has_object())
			G::get_object()->update();
		

		// integrate

		//ts_.step(glfwGetTime());
		ts_.step(g->get_time());

		step(ts_);

		// render

		render();
	}
}
void							THIS::step(gal::etc::timestep const & ts)
{
	neb::fnd::core::scene::util::parent::step(ts);

	neb::fnd::game::game::util::parent::step(ts);

	neb::fnd::window::util::Parent::step(ts);

	neb::fnd::gui::layout::util::Parent::step(ts);
}
gal::math::pose					THIS::getPose()
{
	return gal::math::pose();
}
gal::math::pose					THIS::getPoseGlobal()
{
	return gal::math::pose();
}
void							THIS::set_should_release()
{
}
std::weak_ptr<neb::fnd::core::scene::base>		THIS::createScene()
{
	printv_func(DEBUG);

	auto self(dynamic_pointer_cast<neb::fin::app::base>(shared_from_this()));

	typedef neb::fin::core::scene::base T;

	std::shared_ptr<T> scene (new T, gal::stl::deleter<T>());

	neb::fnd::core::scene::util::parent::insert(scene);

	scene->init(this);

	// python object
	if(console_)
	{
		neb::py::core::scene::base py_scene(scene);

		try {
			console_->main_namespace_["scene"] = py_scene;
		} catch(bp::error_already_set const &) {
			printv(DEBUG, "unhandled execption\n");
			PyErr_Print();
		}
	}

	return scene;
}
std::weak_ptr<neb::fnd::core::scene::base>		neb::fin::app::base::createSceneDLL(
		std::string dll_name)
{
	printv_func(DEBUG);

	auto self(dynamic_pointer_cast<neb::fin::app::base>(shared_from_this()));

	typedef neb::fin::core::scene::base		T;
	typedef gal::dll::helper<T>				H;

	std::shared_ptr<H> h(new H(dll_name));
	h->open();
	h->template add<T>("scene");
	std::shared_ptr<T> scene = h->template make_shared<T>();

	neb::fnd::core::scene::util::parent::insert(scene);

	scene->init(this);

	// python object
	if(console_) {
		neb::py::core::scene::base py_scene(scene);

		try {
			console_->main_namespace_["scene"] = py_scene;
		} catch(bp::error_already_set const &) {
			printv(DEBUG, "unhandled execption\n");
			PyErr_Print();
		}

		console_->eval(
				"import os, sys\n"
				"def set_exit_handler(func):\n"
				"    if os.name == \"nt\":\n"
				"        try:\n"
				"            import win32api\n"
				"            win32api.SetConsoleCtrlHandler(func, True)\n"
				"        except ImportError:\n"
				"            version = \".\".join(map(str, sys.version_info[:2]))\n"
				"            raise Exception(\"pywin32 not installed for Python \" + version)\n"
				"    else:\n"
				"        import signal\n"
				"        signal.signal(signal.SIGTERM, func)"
			      );

		console_->eval(
				"def on_exit(sig, func=None):\n"
				"    print \"exit handler\"\n"
				"    import time\n"
				"    time.sleep(10)"
			      );
		console_->eval(
				"set_exit_handler(on_exit)"
			      );
		console_->eval(
				"print on_exit"
			      );
	}

	return scene;
}
std::weak_ptr<neb::fnd::gui::layout::Base>	THIS::createLayout(
		std::shared_ptr<neb::fnd::window::Base> window,
		std::shared_ptr<neb::fnd::environ::Base> environ)
{
	printv_func(DEBUG);

	typedef neb::fnd::gui::layout::Base T;
	
	auto layout = neb::fnd::gui::layout::util::Parent::create<T>().lock();
	
	layout->connect(window);
	
	layout->createObjectTerminal();
	
	environ->set_drawable(layout);
	
	return layout;
}
std::weak_ptr<neb::fnd::window::Base>	THIS::createWindow()
{
	printv_func(DEBUG);

	auto window = neb::fnd::window::util::Parent::create<neb::fnd::window::Base>();

	if(G::has_object())
		G::get_object()->onFirstContext();

	return window;
}


