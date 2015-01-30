#ifndef NEBULA_FIN_ENVIRON_SHADOW_POINT_HPP
#define NEBULA_FIN_ENVIRON_SHADOW_POINT_HPP

#include <neb/fin/environ/base.hpp>

#include <neb/gfx/environ/shadow/point.hpp>

namespace neb { namespace fin { namespace environ { namespace shadow {
	/** @brief base
	 */
	class Point:
		virtual public neb::gfx::environ::shadow::point,
		virtual public neb::fin::environ::base
	{
	};
}}}}


#endif
