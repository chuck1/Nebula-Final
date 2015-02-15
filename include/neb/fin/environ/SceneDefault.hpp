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
			typedef std::shared_ptr<neb::gfx::glsl::program::Base>		program_shared;
			typedef std::shared_ptr<neb::gfx::camera::view::Base>		view_shared;
			typedef std::shared_ptr<neb::gfx::camera::proj::Base>		proj_shared;
			virtual void					init(parent_t * const & p);
	};
}}}

#endif

