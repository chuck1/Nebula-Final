#ifndef NEBULA_FIN_ENVIRON_NORMAL_MAP_HPP
#define NEBULA_FIN_ENVIRON_NORMAL_MAP_HPP

#include <neb/fin/environ/base.hpp>
#include <neb/gfx/environ/NormalMap.hpp>

namespace neb { namespace fin { namespace environ {
	/** @brief base
	 */
	class NormalMap:
		virtual public neb::gfx::environ::NormalMap,
		virtual public neb::fin::environ::base
	{
		public:
			typedef std::shared_ptr<neb::gfx::glsl::program::base>		program_shared;
			typedef std::shared_ptr<neb::gfx::camera::view::base>		view_shared;
			typedef std::shared_ptr<neb::gfx::camera::proj::base>		proj_shared;
		public:
			//virtual void		init();
			//virtual void		step(gal::etc::timestep const & ts);
	};


}}}


#endif
