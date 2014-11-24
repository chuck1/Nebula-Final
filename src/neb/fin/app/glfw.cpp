#include <neb/fin/app/glfw.hpp>
#include <neb/fin/window/Base.hpp>

typedef neb::fin::app::glfw THIS;

THIS::window_w	THIS::createWindow()
{
	return create<neb::fin::window::base>();
}

