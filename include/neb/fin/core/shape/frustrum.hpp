#ifndef NEB_FIN_CORE_SHAPE_FRUSTRUM_HPP
#define NEB_FIN_CORE_SHAPE_FRUSTRUM_HPP

//#include <neb/gfx/camera/util/decl.hpp>

#include <neb/fnd/camera/util/decl.hpp>

#include <neb/fin/core/shape/base.hpp>

namespace neb { namespace fin { namespace core { namespace shape {
	/** @ brief */
	class frustrum:
		virtual public neb::fin::core::shape::base
	{
		public:
			frustrum();

			//virtual void				init() = 0;
			//virtual void				release() = 0;
			//virtual void				step(gal::etc::timestep  const & ts) = 0;
			
			std::weak_ptr<neb::fnd::camera::proj::Base>	camera_;
			
			virtual physx::PxGeometry*			to_geo();
	};
}}}}

#endif

