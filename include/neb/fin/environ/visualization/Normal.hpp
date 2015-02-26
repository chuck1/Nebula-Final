#ifndef NEBULA_FIN_ENVIRON_NORMAL_MAP_HPP
#define NEBULA_FIN_ENVIRON_NORMAL_MAP_HPP

#include <neb/fnd/environ/visualization/Normal.hpp>

namespace neb { namespace fin { namespace environ { namespace visualization {
	/** @brief Normal
	 */
	class Normal:
		virtual public neb::fnd::environ::visualization::Normal
	{
		public:
			typedef std::shared_ptr<neb::fnd::glsl::program::Base>		program_shared;
			typedef std::shared_ptr<neb::fnd::camera::view::Base>		view_shared;
			typedef std::shared_ptr<neb::fnd::camera::proj::Base>		proj_shared;
		public:
			virtual void		init(parent_t * const & p);
			virtual void		release();
			//virtual void		step(gal::etc::timestep const & ts);
	};
}}}}

#endif
