#ifndef NEBULA_FIN_CONTEXT_FBO_MULTI_HPP
#define NEBULA_FIN_CONTEXT_FBO_MULTI_HPP

#include <neb/gfx/context/fbo_multi.hpp>

#include <neb/fin/context/base.hpp>

namespace neb { namespace fin { namespace context {
	/** @brief
	*/
	class FBOMulti:
		virtual public neb::gfx::context::fbo_multi,
		virtual public neb::fin::context::Base
	{
		public:
			virtual void		init(parent_t * const parent);
			//virtual void		setTexture(std::shared_ptr<neb::core::itf::shared>);
			virtual std::weak_ptr<neb::core::environ::shadow::Directional>		createEnvironShadowDirectional();
			virtual std::weak_ptr<neb::core::environ::shadow::Point>		createEnvironShadowPoint();
	};
}}}

#endif
