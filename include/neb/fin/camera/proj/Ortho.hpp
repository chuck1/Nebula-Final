#ifndef NEB_FIN_CAMERA_PROJ_ORTHO_HPP
#define NEB_FIN_CAMERA_PROJ_ORTHO_HPP

#include <PxPhysicsAPI.h>

#include <neb/gfx/camera/proj/ortho.hpp>

#include <neb/fin/camera/proj/Base.hpp>

namespace neb { namespace fin { namespace camera { namespace proj {
	class Ortho:
		virtual public neb::gfx::camera::proj::Ortho,
		virtual public neb::fin::camera::proj::Base
	{
		public:
			Ortho();
			virtual void		init(parent_t * const & p);
			virtual void		release();
	};
}}}}

#endif
