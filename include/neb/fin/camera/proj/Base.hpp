#ifndef NEB_FIN_CAMERA_PROJ_BASE_HPP
#define NEB_FIN_CAMERA_PROJ_BASE_HPP

#include <PxPhysicsAPI.h>

#include <neb/gfx/camera/proj/base.hpp>

namespace neb { namespace fin { namespace camera { namespace proj {
	class Base:
		virtual public neb::gfx::camera::proj::Base
	{
		public:
			virtual void		calculate_geometry();

			physx::PxGeometry*	_M_px_geometry;
	};
}}}}

#endif
