

#ifndef NEBULA_FIN_ENVIRON_BASE_HPP
#define NEBULA_FIN_ENVIRON_BASE_HPP

#include <neb/gfx/environ/base.hpp>

namespace neb { namespace fin { namespace environ {
	/** @brief base
	 *
	 * Abstract class that contains functions and data needed to render a specific kind of drawable.
	 */
	class base:
		virtual public neb::gfx::environ::base
	{
		public:
			typedef std::shared_ptr<neb::gfx::glsl::program::Base>		program_shared;
			typedef std::shared_ptr<neb::gfx::camera::view::Base>		view_shared;
			typedef std::shared_ptr<neb::gfx::camera::proj::Base>		proj_shared;
			//typedef neb::gfx::core::light::directional			light_type;
			//typedef std::shared_ptr<light_type>				light_shared;
			//typedef std::weak_ptr<light_type>				light_weak;
		public:
			virtual proj_shared	createCameraPerspective();
			virtual proj_shared	createCameraOrtho();
	};
}}}


#endif
