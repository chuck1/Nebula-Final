#ifndef NEBULA_FIN_CONTEXT_WINDOW_HH
#define NEBULA_FIN_CONTEXT_WINDOW_HH

#include <neb/gfx/context/Window.hpp>

#include <neb/fin/context/base.hpp>

namespace neb { namespace fin { namespace context {
	/** @brief %window
	 */
	class Window:
		virtual public neb::gfx::context::Window,
		virtual public neb::fin::context::Base
	{
		public:
			virtual void		init(parent_t * const parent);
			virtual void		step(gal::etc::timestep const & ts);
			virtual void		render();
//			virtual void		setDrawable(std::shared_ptr<neb::fnd::drawable::Base>);
//			virtual void		setEnviron(std::shared_ptr<neb::fnd::environ::Base>)  0;

	};
}}}

#endif

