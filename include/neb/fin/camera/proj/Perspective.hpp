#ifndef NEB_FIN_CAMERA_PROJ_PERSPECTIVE_HPP
#define NEB_FIN_CAMERA_PROJ_PERSPECTIVE_HPP

#include <PxPhysicsAPI.h>

//#include <neb/fnd/camera/proj/perspective.hpp>

#include <neb/fin/camera/proj/Base.hpp>

namespace neb { namespace fin { namespace camera { namespace proj {
	class Perspective:
		//virtual public neb::fnd::camera::proj::Perspective
		virtual public neb::fin::camera::proj::Base
	{
		public:
			Perspective();
			virtual void		init(parent_t * const & p);
			virtual void		step(gal::etc::timestep const & p);
			virtual void		release();
	};
}}}}

#endif
