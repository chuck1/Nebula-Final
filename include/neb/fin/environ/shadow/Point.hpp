#ifndef NEBULA_FIN_ENVIRON_SHADOW_POINT_HPP
#define NEBULA_FIN_ENVIRON_SHADOW_POINT_HPP

#include <neb/fin/environ/base.hpp>

#include <neb/core/environ/shadow/Point.hpp>

namespace neb { namespace fin { namespace environ { namespace shadow {
	/** @brief base
	 */
	class Point:
		virtual public neb::fnd::environ::shadow::Point,
		virtual public neb::fin::environ::base
	{
		public:
			virtual void		init(parent_t * const & p);
			virtual void		release();
	};
}}}}


#endif
