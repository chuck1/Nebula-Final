#ifndef NEBULA_FIN_ENVIRON_SCENE_DEF_HPP
#define NEBULA_FIN_ENVIRON_SCENE_DEF_HPP

#include <neb/core/environ/SceneDefault.hpp>

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
			virtual void					init(parent_t * const & p);
			virtual void					release();
			virtual view_ridealong_weak			create_view_ridealong(
					std::weak_ptr<neb::fnd::core::actor::base> actor);
	};
}}}

#endif

