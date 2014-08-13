

#include <neb/gfx/GUI/Object/terminal.hh>

#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <map>

#include <ft2build.h>
#include FT_FREETYPE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <gal/console/base.hpp>

#include <gal/log/log.hpp>

#include <neb/core/util/config.hpp>
#include <neb/core/app/__base.hpp>
#include <neb/core/scene/base.hpp>

#include <neb/gfx/Context/Base.hh>
#include <neb/gfx/window/Base.hh>

#include <neb/fin/gfx_phx/app/base.hpp>


shared_ptr<neb::fin::gfx_phx::app::base>		neb::fin::gfx_phx::app::base::global() {
	auto app(dynamic_pointer_cast<neb::fin::gfx_phx::app::base>(g_app_));
	assert(app);
	return app;
}
shared_ptr<neb::fin::gfx_phx::app::base>		neb::fin::gfx_phx::app::base::init() {
	neb::init_log();
	auto app(make_shared<neb::fin::gfx_phx::app::base>());
	app->neb::core::app::__base::__init();
	g_app_ = app;
	return app;
}
void				neb::fin::gfx_phx::app::base::__init() {
	
}
void				neb::fin::gfx_phx::app::base::loop() {

	auto self(sp::dynamic_pointer_cast<neb::core::app::__base>(shared_from_this()));
	assert(self);
	
	//::std::thread t(::std::bind(&neb::app::base::loop2, self));
	
	
	while(!flag_.any(neb::core::app::util::flag::E::SHOULD_RELEASE)) {

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

	neb::core::core::scene::util::parent::step(ts);

	neb::gfx::window::util::parent::step(ts);

	glfwPollEvents();
}



