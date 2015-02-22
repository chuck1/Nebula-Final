
#ifndef NEBULA_FIN_ENVIRON_BASE_HPP
#define NEBULA_FIN_ENVIRON_BASE_HPP

#include <neb/fnd/glsl/program/util/decl.hpp>
#include <neb/fnd/environ/Base.hpp>
#include <neb/fnd/camera/util/decl.hpp>

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
