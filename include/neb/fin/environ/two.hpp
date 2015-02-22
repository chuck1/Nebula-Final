#ifndef NEBULA_FIN_ENVIRON_TWO_HPP
#define NEBULA_FIN_ENVIRON_TWO_HPP

#include <neb/fnd/environ/Two.hpp>

#include <neb/fin/environ/base.hpp>

namespace neb { namespace fin { namespace environ {
	/** @brief base
	 */
	class Two:
		virtual public neb::fnd::environ::Two,
		virtual public neb::fin::environ::base
	{
		public:
			virtual void		init(parent_t * const & p);
			virtual void		release();
	};
}}}

#endif



