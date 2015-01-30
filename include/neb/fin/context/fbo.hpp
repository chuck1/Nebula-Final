#ifndef NEBULA_FIN_CONTEXT_FBO_HH
#define NEBULA_FIN_CONTEXT_FBO_HH

#include <neb/gfx/context/fbo.hpp>

#include <neb/fin/context/window.hpp>

namespace neb { namespace fin { namespace context {
	/** @brief Context
	 *
	 * A context with an OpenGL FBO as target.
	 *
	 * @todo allow for manual ordering of context objects in parent's context map
	 * such that things like layouts are render ON TOP of existing scene.'
	 */
	class fbo:
		virtual public neb::gfx::context::fbo,
		virtual public neb::fin::context::Window
	{
		virtual void								render();
		virtual std::weak_ptr<neb::core::environ::shadow::Directional>		createEnvironShadowDirectional();
	};
}}}

#endif

