#ifndef NEBULA_FIN_CONTEXT_FBO_MULTI_HPP
#define NEBULA_FIN_CONTEXT_FBO_MULTI_HPP

#include <neb/gfx/context/fbo_multi.hpp>

#include <neb/fin/context/base.hpp>

namespace neb { namespace fin { namespace context {
	/** @brief
	*/
	class FBOMulti:
		virtual public neb::gfx::context::fbo_multi,
		virtual public neb::fin::context::base
	{
	};
}}}

#endif

