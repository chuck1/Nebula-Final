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
#include <gal/log/log.hpp>
#include <gal/stl/deleter.hpp>
#include <argparse.hpp>

#include <neb/core/free.hpp>
#include <neb/core/util/config.hpp>
#include <neb/core/util/log.hpp>
#include <neb/core/app/Base.hpp>
#include <neb/core/core/scene/base.hpp>

#include <neb/gfx/util/log.hpp>
#include <neb/gfx/context/Base.hpp>
#include <neb/gfx/window/Base.hpp>
#include <neb/gfx/core/light/spot.hpp>
#include <neb/gfx/core/light/point.hpp>
#include <neb/gfx/gui/layout/util/parent.hpp>
#include <neb/gfx/gui/object/terminal.hh>
#include <neb/gfx/app/base.hpp>

#include <neb/phx/util/log.hpp>

#include <neb/py/util/config.hpp> // neb/py/util/config.hpp.in
#include <neb/py/core/scene/base.hpp>
#include <neb/py/app/base.hpp>

#include <neb/fin/app/base.hpp>
#include <neb/fin/core/scene/base.hpp>
#include <neb/fin/core/actor/rigiddynamic/base.hpp>
#include <neb/fin/core/actor/rigidstatic/base.hpp>
#include <neb/fin/core/shape/box.hpp>
#include <neb/fin/core/shape/HeightField.hpp>
#include <neb/fin/util/log.hpp>

#define STRINGIZE2(x) #x
#define STRINGIZE(x) STRINGIZE2(x)

typedef neb::fin::app::base THIS;

std::shared_ptr<neb::fin::app::base>		THIS::global()
{
	LOG(lg, neb::fin::sl, debug) << __PRETTY_FUNCTION__;

	auto app(dynamic_pointer_cast<neb::fin::app::base>(g_app_));
	assert(app);
	return app;
}
std::shared_ptr<neb::fin::app::base>	THIS::s_init(int ac, char ** av)
{
	LOG(lg, neb::fin::sl, debug) << __PRETTY_FUNCTION__;

	typedef neb::fin::app::base T;

	std::shared_ptr<T> app(new T(), gal::stl::deleter<T>());

	// parse args	
	auto args = Parse(ac, av, "");
	
	if(args.has_long("python")) {
		auto filename = args.get_value_from_long("python");

		app->_M_preloop_scripts_python.push_back(filename);

		printf("%s\n", filename.c_str());
	}
	
	// continue init
	app->neb::fnd::app::Base::__init();

	app->neb::gfx::app::Base::__init();
	app->neb::gfx::app::glsl::__init();
	app->neb::gfx::app::glfw::__init();
	app->neb::gfx::app::draw::__init();

	app->neb::phx::app::base::__init();

	app->neb::fin::app::base::__init();


	LOG(lg, neb::fin::sl, debug) << "&g_app_ = " << &g_app_;
	g_app_ = app;
	return app;
}
neb::fin::app::base::base()
{
}
neb::fin::app::base::~base()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
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
	
	// log levels

	struct Pair
	{
		char const *		c;
		severity_level * const	sl;
	};

	static const Pair pairs[13] = {
		{"neb core",		&neb::fnd::sl},
		{"neb core scene",	&neb::fnd::core::scene::sl},
		{"neb core actor",	&neb::fnd::core::actor::sl},
		{"neb core shape",	&neb::fnd::core::shape::sl},
		{"neb core light",	&neb::fnd::core::light::sl},
		{"neb gfx",		&neb::gfx::sl},
		{"neb gfx actor",	&neb::gfx::core::actor::sl},
		{"neb gfx shape",	&neb::gfx::core::shape::sl},
		{"neb gfx light",	&neb::gfx::core::light::sl},
		{"neb phx",		&neb::phx::sl},
		{"neb phx scene",	&neb::phx::core::scene::sl},
		{"neb phx actor",	&neb::phx::core::actor::sl},
		{"neb phx shape",	&neb::phx::core::shape::sl}
	};

/*	std::map<std::string, int> map_var({
			{"neb core",		0},
			{"neb core scene",	1},
			{"neb core actor",	2},
			{"neb core shape",	3},
			{"neb core light",	4},
			{"neb gfx",		5},
			{"neb gfx actor",	6},
			{"neb gfx shape",	7},
			{"neb gfx light",	8},
			{"neb phx",		9},
			{"neb phx scene",	10},
			{"neb phx actor",	11},
			{"neb phx shape",	12}});
			*/
	std::map<std::string, int> map_val({
			{"debug",	debug},
			{"info",	info},
			{"warning",	warning},
			{"error",	error},
			{"critical",	critical}});


	std::ifstream ifs(NEB_SHARE_DIR"/config.txt");
	if(ifs.is_open()) {
		for(std::string line; std::getline(ifs, line);) {
			auto loc = line.find("=");
			if(loc != std::string::npos) {
				auto var = line.substr(0,loc);
				auto val = line.substr(loc+1);
	
				auto it_val = map_val.find(val);
				if(it_val == map_val.end()) {
					std::cout << "invalid value" << std::endl;
					abort();
				}
				
				unsigned int i = 0;
				for(i = 0; i < (sizeof(pairs) / sizeof(Pair)); i++)
				{
					if(strcmp(var.c_str(), pairs[i].c) == 0)
					{
						*pairs[i].sl = (severity_level)it_val->second;
						break;
					}
				}
				if(i == (sizeof(pairs) / sizeof(Pair)))
				{
					 std::cout << "log group not found: '" << var << "'" << std::endl;
					 abort();
				}

				/*
				auto it_var = map_var.find(var);

				if(it_var == map_var.end()) {
					std::cout << "invalid variable" << std::endl;
					abort();
				}

				switch(it_var->second) {
					case 0: neb::fnd::sl			= (severity_level)it_val->second; break;
					case 1: neb::fnd::core::scene::sl	= (severity_level)it_val->second; break;
					case 2: neb::fnd::core::actor::sl	= (severity_level)it_val->second; break;
					case 3: neb::fnd::core::shape::sl	= (severity_level)it_val->second; break;
					case 4: neb::fnd::core::light::sl	= (severity_level)it_val->second; break;
					case 5: neb::gfx::sl			= (severity_level)it_val->second; break;
					case 6: neb::gfx::core::actor::sl	= (severity_level)it_val->second; break;
					case 7: neb::gfx::core::shape::sl	= (severity_level)it_val->second; break;
					case 8: neb::gfx::core::light::sl	= (severity_level)it_val->second; break;
					case 9: neb::phx::sl			= (severity_level)it_val->second; break;
					case 10: neb::phx::core::scene::sl	= (severity_level)it_val->second; break;
					case 11: neb::phx::core::actor::sl	= (severity_level)it_val->second; break;
					case 12: neb::phx::core::shape::sl	= (severity_level)it_val->second; break;
					default:
						 std::cout << "default" << std::endl;
						 abort();
				}
				*/
			}
		}
	}

	initRegistry();
}
void				THIS::initRegistry()
{
	makeDLLFunc<neb::fnd::core::scene::base, neb::fin::core::scene::base>();

	makeDefaultFunc<neb::fnd::core::actor::base, neb::fin::core::actor::rigiddynamic::base>();
	makeDefaultFunc<neb::fnd::core::actor::__base, neb::fin::core::actor::rigiddynamic::base>();
	makeDefaultFunc<neb::fnd::core::actor::__base, neb::fin::core::actor::base>();
	makeDefaultFunc<neb::fnd::core::actor::__base, neb::fin::core::actor::rigidstatic::base>();

	makeDefaultFunc<neb::fnd::core::shape::base, neb::fin::core::shape::base>();
	makeDefaultFunc<neb::fnd::core::shape::base, neb::fin::core::shape::box>();
	makeDefaultFunc<neb::fnd::core::shape::base, neb::fin::core::shape::HeightField::Base>();

	makeDefaultFunc<neb::fnd::core::light::__base, neb::gfx::core::light::spot>();
	makeDefaultFunc<neb::fnd::core::light::__base, neb::gfx::core::light::point>();
}
void				neb::fin::app::base::release()
{
	//neb::fnd::app::__base::__release();
	neb::fnd::app::Base::__release();

	neb::gfx::app::Base::__release();
	//neb::gfx::app::__gfx_glsl::__release();

	neb::phx::app::base::__release();

}
void				neb::fin::app::base::preloop()
{
	neb::gfx::gui::layout::util::parent::preloop();
}
void				neb::fin::app::base::loop()
{
	//auto self(std::dynamic_pointer_cast<neb::fnd::app::Base>(shared_from_this()));
	//assert(self);

	preloop();

	while(!flag_.any(neb::fnd::app::util::flag::E::SHOULD_RELEASE)) {
		
		// check for exit condition

		if(!neb::gfx::window::util::parent::map_.front()) break;
		
		// update
		
		glfwPollEvents();
		
		neb::gfx::app::glfw::update_joysticks();
		
		// integrate
		
		ts_.step(glfwGetTime());
		
		step(ts_);
		
		// render

		render();
	}
}
void							THIS::step(gal::etc::timestep const & ts)
{
	neb::fnd::core::scene::util::parent::step(ts);

	neb::gfx::gui::layout::util::parent::step(ts);

	neb::fnd::game::game::util::parent::step(ts);

	neb::gfx::window::util::parent::step(ts);

}
void				neb::fin::app::base::render()
{
	//neb::fnd::core::scene::util::parent::render();
	//neb::gfx::gui::layout::util::parent::render();
	//neb::fnd::game::game::util::parent::render();

	neb::gfx::app::glfw::render();
}
neb::fnd::math::pose					THIS::getPose()
{
	return neb::fnd::math::pose();
}
neb::fnd::math::pose					THIS::getPoseGlobal()
{
	return neb::fnd::math::pose();
}
void							THIS::set_should_release()
{
}
std::weak_ptr<neb::fnd::core::scene::base>		THIS::createScene()
{
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
			cout << "unhandled execption\n";
			PyErr_Print();
		}
	}

	return scene;
}
std::weak_ptr<neb::fnd::core::scene::base>		neb::fin::app::base::createSceneDLL(std::string dll_name)
{
	auto self(dynamic_pointer_cast<neb::fin::app::base>(shared_from_this()));

	typedef neb::fin::core::scene::base		T;
	typedef gal::dll::helper<T>				H;

	std::shared_ptr<H> h(new H(dll_name, "scene"));
	h->open();

	std::shared_ptr<T> scene = h->make_shared();

	neb::fnd::core::scene::util::parent::insert(scene);

	scene->init(this);

	// python object
	if(console_) {
		neb::py::core::scene::base py_scene(scene);

		try {
			console_->main_namespace_["scene"] = py_scene;
		} catch(bp::error_already_set const &) {
			cout << "unhandled execption\n";
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
		std::shared_ptr<neb::fnd::context::Base> context)
{
	typedef neb::gfx::gui::layout::base T;

	auto layout = neb::gfx::gui::layout::util::parent::create<T>().lock();

	layout->connect(window);

	layout->createObjectTerminal();

	context->setDrawable(layout);

	return layout;
}


