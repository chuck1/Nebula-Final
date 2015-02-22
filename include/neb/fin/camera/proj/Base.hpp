#ifndef NEB_FIN_CAMERA_PROJ_BASE_HPP
#define NEB_FIN_CAMERA_PROJ_BASE_HPP

#include <PxPhysicsAPI.h>

#include <neb/core/camera/proj/Base.hpp>
#include <neb/core/environ/util/decl.hpp>

#include <neb/fin/tmp/Child.hpp>

namespace neb { namespace fin { namespace camera { namespace proj {
	class Base:
		virtual public neb::fnd::camera::proj::Base,
		virtual public neb::fin::tmp::Child<neb::fnd::environ::Base>
	{
		public:
			virtual void		calculate_geometry();

			physx::PxGeometry*	_M_px_geometry;
	};
}}}}

#endif
