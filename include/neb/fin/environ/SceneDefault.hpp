#ifndef NEBULA_FIN_ENVIRON_SCENE_DEF_HPP
#define NEBULA_FIN_ENVIRON_SCENE_DEF_HPP

#include <neb/gfx/environ/SceneDefault.hpp>
#include <neb/fin/environ/base.hpp>

namespace neb { namespace fin { namespace environ {
	/** @brief */
	class SceneDefault:
		virtual public neb::gfx::environ::SceneDefault,
		virtual public neb::fin::environ::base
	{
		public:
			typedef std::shared_ptr<neb::gfx::glsl::program::base>		program_shared;
			typedef std::shared_ptr<neb::gfx::camera::view::base>		view_shared;
			typedef std::shared_ptr<neb::gfx::camera::proj::base>		proj_shared;
		public:
			//virtual void							init();
	};
}}}

#endif

