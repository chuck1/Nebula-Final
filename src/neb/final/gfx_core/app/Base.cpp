#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <map>

#include <ft2build.h>
#include FT_FREETYPE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
//#include <glfw3.h>

#include <gal/console/backend/command.hpp>
#include <gal/console/backend/command_set.hpp>


#include <gal/log/log.hpp>

#include <neb/util/config.hh>
//#include <neb/actor/event.hh>
#include <neb/gfx/Context/Base.hh>
#include <neb/gfx/window/Base.hh>
#include <neb/gfx/GUI/Object/terminal.hh>

//#include <neb/core/actor/RigidBody/Base.hh>
#include <neb/app/Base.hh>

#include <neb/core/scene/base.hpp>


void					neb::app::base::loop1() {

	auto self(sp::dynamic_pointer_cast<neb::app::base>(shared_from_this()));
	assert(self);
	
	//::std::thread t(::std::bind(&neb::app::base::loop2, self));
	
	
	while(!flag_.any(neb::app::util::flag::E::SHOULD_RELEASE)) {

		::std::cout << "loop1" << ::std::endl;

		ts_.step(glfwGetTime());

		step1(ts_);
		step2(ts_);
		
		//::std::this_thread::yield();
	}
	
	//t.join();
	
//	if(server_) server_->close();
//	if(client_) client_->close();

}
void					neb::app::base::loop2() {

	gal::std::timestep ts;

	while(!flag_.any(neb::app::util::flag::E::SHOULD_RELEASE)) {

		::std::cout << "loop2" << ::std::endl;

		ts.step(glfwGetTime());

		step2(ts);

		//::std::this_thread::yield();
	}


}
void					neb::app::base::step1(gal::std::timestep const & ts) {

	neb::core::scene::util::parent::step(ts);

}
void					neb::app::base::step2(gal::std::timestep const & ts) {

	neb::gfx::window::util::parent::step(ts);

	glfwPollEvents();
}
/*void		neb::app::base::transmit_scenes(sp::shared_ptr<neb::Network::Communicating> c) {
	//NEBULA_DEBUG_0_FUNCTION;

	assert(c);

	typedef neb::core::scene::util::parent S;

	S::map_.for_each<0>([&] (S::map_type::iterator<0> it) {
			auto scene = sp::dynamic_pointer_cast<neb::core::scene::base>(it->ptr_);
			assert(scene);

			auto msg = sp::make_shared<gal::net::omessage>();

			neb::message::scene::Create scene_create;

			scene_create.load(scene);

			** @todo why?!?!?!? *
			//msg->ar_ << scene_create;

			c->write(msg);
			});
}*/
sp::shared_ptr<neb::gfx::window::base>		neb::app::base::get_window(GLFWwindow* window) {
	auto it = windows_glfw_.find(window);

	assert(it != windows_glfw_.end());

	return it->second;
}
void		neb::app::base::loadXml(::std::string filename, neb::std::wrapper& w) {
	::std::ifstream ifs;

	ifs.open(filename, ::std::ifstream::in);

	boost::archive::polymorphic_xml_iarchive ar(ifs);

	ar >> boost::serialization::make_nvp("wrapper",w);
}






