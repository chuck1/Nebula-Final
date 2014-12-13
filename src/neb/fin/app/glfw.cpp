#include <neb/fin/app/glfw.hpp>
#include <neb/fin/window/Base.hpp>

typedef neb::fin::app::glfw THIS;

THIS::window_w THIS::createWindow()
{
	auto window = neb::gfx::window::util::parent::create<neb::fin::window::base>();
	
	onFirstContext();
	
	return window;
}

