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
#include <neb/app/base.hpp>

#include <neb/core/scene/base.hpp>

#include <neb/fin/gfx_phx/app/base.hpp>


/** @todo since std smart pointers dont have ref counted unique pointers, owned objects must be stored as shared pointers.
 * to avoid unwanted shared_ptrs to owned objects, care must be taken when passing these objects around.
 * better documentation inside function bodies should be used to let me know what a shared_ptr is being used (how it 
 * should be treated.
 */


void				neb::fin::gfx_phx::app::base::init() {

	// command set
	
	command_set_ = sp::make_shared<gal::std::command_set>();

	command_set_->init();	
	
	// exit command
	
	auto cmd_exit = sp::make_shared<gal::std::command>();

	cmd_exit->func_ = [&] (sp::shared_ptr<gal::std::terminal> term, bpo::variables_map vm) {
		sp::shared_ptr<neb::app::base> app = neb::app::base::global();
		app->flag_.set(neb::app::util::flag::SHOULD_RELEASE);
	};

	command_set_->map_["exit"] = cmd_exit;
	
}
void				neb::fin::gfx_phx::neb::app::base::loop() {

	auto self(sp::dynamic_pointer_cast<neb::app::base>(shared_from_this()));
	assert(self);
	
	//::std::thread t(::std::bind(&neb::app::base::loop2, self));
	
	
	while(!flag_.any(neb::app::util::flag::E::SHOULD_RELEASE)) {

		::std::cout << "loop1" << ::std::endl;

		ts_.step(glfwGetTime());

		step(ts_);
		
		//::std::this_thread::yield();
	}
	
	//t.join();
	
//	if(server_) server_->close();
//	if(client_) client_->close();

}
void				neb::fin::gfx_phx::app::base::step(gal::std::timestep const & ts) {

	neb::core::scene::util::parent::step(ts);

	neb::gfx::window::util::parent::step(ts);

	glfwPollEvents();
}



