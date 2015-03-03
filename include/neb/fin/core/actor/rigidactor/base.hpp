#ifndef NEB_FINAL_GFX_PHX_CORE_ACTOR_RIGIDACTOR_BASE_HPP
#define NEB_FINAL_GFX_PHX_CORE_ACTOR_RIGIDACTOR_BASE_HPP

#include <neb/fnd/core/actor/rigidactor/Base.hpp>

namespace neb { namespace fin { namespace core { namespace actor { namespace rigidactor {

	class base:
		virtual public neb::fnd::core::actor::rigidactor::base
	{
		public:
			virtual void							init(neb::fnd::core::actor::util::parent * const & p) = 0;
			virtual void							release() = 0;
			virtual void							step(gal::etc::timestep const & ts) = 0;
			std::weak_ptr<neb::fnd::core::shape::base>			createShapeBoxUninitialized(glm::vec3 size);
			std::weak_ptr<neb::fnd::core::shape::base>			createShapeBox(gal::math::pose, glm::vec3 size);
	};

}}}}}


#endif



