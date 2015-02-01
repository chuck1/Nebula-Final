#ifndef NEBULA_FIN_CONTEXT_FBO_HH
#define NEBULA_FIN_CONTEXT_FBO_HH

#include <neb/gfx/context/fbo.hpp>

#include <neb/fin/context/Window.hpp>

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
		public:
			typedef neb::core::environ::shadow::Directional ESD;

			virtual void			init(parent_t * const parent);
			virtual void			render();
			virtual std::weak_ptr<ESD>	createEnvironShadowDirectional();
			virtual void			setTexture(std::shared_ptr<neb::core::itf::shared>);
	};
}}}

#endif
