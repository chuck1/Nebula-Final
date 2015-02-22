
#ifndef NEBULA_FIN_ENVIRON_BASE_HPP
#define NEBULA_FIN_ENVIRON_BASE_HPP

#include <neb/core/glsl/program/util/decl.hpp>
#include <neb/core/environ/Base.hpp>
#include <neb/core/camera/util/decl.hpp>

namespace neb { namespace fin { namespace environ {
	/** @brief base
	 *
	 * Abstract class that contains functions and data needed to render a specific kind of drawable.
	 */
	class base:
		virtual public neb::fnd::environ::Base
	{
		public:
	};
}}}


#endif
