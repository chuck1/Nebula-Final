#ifndef NEB_FIN_CORE_SHAPE_FRUSTRUM_HPP
#define NEB_FIN_CORE_SHAPE_FRUSTRUM_HPP

#include <neb/phx/core/shape/base.hpp>

#include <neb/gfx/camera/util/decl.hpp>

namespace neb { namespace fin { namespace core { namespace shape {
	/** @ brief */
	class frustrum:
		virtual public neb::phx::core::shape::base
	{
		public:
			frustrum();

			//virtual void				init() = 0;
			//virtual void				release() = 0;
			//virtual void				step(gal::etc::timestep  const & ts) = 0;
			
			std::weak_ptr<neb::gfx::camera::proj::base>	camera_;
			
			virtual physx::PxGeometry*			to_geo();
	};
}}}}

#endif

