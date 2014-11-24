#ifndef NEB_FIN_APP_GLFW_HPP
#define NEB_FIN_APP_GLFW_HPP

#include <neb/gfx/app/glfw.hpp>

namespace neb { namespace fin { namespace app {
	/** @brief gfx
	 * 
	 * graphics and window handling
	 */
	class glfw:
		virtual public neb::gfx::app::glfw
	{
		public:
			typedef std::weak_ptr<neb::gfx::window::base>		window_w;
			window_w						createWindow();
	};
}}}

#endif




