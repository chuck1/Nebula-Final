#ifndef NEBULA_FIN_ENVIRON_SCENE_DEF_HPP
#define NEBULA_FIN_ENVIRON_SCENE_DEF_HPP

#include <neb/fnd/environ/SceneDefault.hpp>

#include <neb/fin/environ/base.hpp>

namespace neb { namespace fin { namespace environ {
	/** @brief */
	class SceneDefault:
		virtual public neb::fnd::environ::SceneDefault,
		virtual public neb::fin::environ::base
	{
		public:
/*			typedef std::shared_ptr<neb::gfx::glsl::program::Base>		program_shared;
			typedef std::shared_ptr<neb::gfx::camera::view::Base>		view_shared;
			typedef std::shared_ptr<neb::gfx::camera::proj::Base>		proj_shared;*/
	};
}}}

#endif

