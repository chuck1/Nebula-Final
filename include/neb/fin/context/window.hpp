#ifndef NEBULA_FIN_CONTEXT_WINDOW_HH
#define NEBULA_FIN_CONTEXT_WINDOW_HH

#include <neb/gfx/context/Window.hpp>

#include <neb/fin/context/base.hpp>

namespace neb { namespace fin { namespace context {
	/** @brief %window
	 */
	class window:
		virtual public neb::gfx::context::window,
		virtual public neb::fin::context::base
	{
	};
}}}

#endif

