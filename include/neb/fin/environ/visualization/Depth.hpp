#ifndef NEBULA_FIN_ENVIRON_VIS_DEPTH_HPP
#define NEBULA_FIN_ENVIRON_VIS_DEPTH_HPP

#include <neb/fnd/environ/visualization/Depth.hpp>


namespace neb { namespace fin { namespace environ { namespace visualization {
	/** @brief base
	 */
	class Depth:
		virtual public neb::fnd::environ::visualization::Depth
	{
		public:
			virtual void		init(parent_t * const & p);
			virtual void		release();
	};
}}}}

#endif
