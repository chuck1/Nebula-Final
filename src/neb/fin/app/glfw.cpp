#include <neb/fin/app/glfw.hpp>
#include <neb/fin/window/Base.hpp>

typedef neb::fin::app::glfw THIS;

std::weak_ptr<neb::core::window::Base>	THIS::createWindow()
{
	auto window = neb::gfx::window::util::parent::create<neb::fin::window::base>();
	
	onFirstContext();
	
	return window;
}

