#ifndef NEBULA_FIN_ENVIRON_SHADOW_DIRECTIONAL_HPP
#define NEBULA_FIN_ENVIRON_SHADOW_DIRECTIONAL_HPP

#include <neb/fin/environ/base.hpp>

#include <neb/core/environ/shadow/Directional.hpp>

namespace neb { namespace fin { namespace environ { namespace shadow {
	/** @brief base
	 */
	class Directional:
		virtual public neb::fnd::environ::shadow::Directional,
       		virtual public neb::fin::environ::base
	{
		public:
			virtual void		init(parent_t * const & p);
			virtual void		release();
	};
}}}}


#endif
