#ifndef NEB_FINAL_GFX_PHX_CORE_ACTOR_RIGIDACTOR_BASE_HPP
#define NEB_FINAL_GFX_PHX_CORE_ACTOR_RIGIDACTOR_BASE_HPP

#include <neb/phx/core/actor/rigidactor/base.hpp>

#include <neb/fin/core/actor/base.hpp>

namespace neb { namespace fin { namespace core { namespace actor { namespace rigidactor {

	class base:
		virtual public neb::phx::core::actor::rigidactor::base,
		virtual public neb::fin::core::actor::base
	{
		public:
			/** @brief
			 *
			 */
			virtual void							init(neb::core::core::actor::util::parent * const & p) = 0;
			/** @brief
			 *
			 */
			virtual void							release() = 0;
			/** @brief
			 *
			 */
			virtual void							step(gal::etc::timestep const & ts) = 0;
			/** @brief
			 *
			 */
			std::weak_ptr<neb::core::core::shape::base>			createShapeBoxUninitialized(glm::vec3 size);
			/** @brief
			 *
			 */
			std::weak_ptr<neb::core::core::shape::base>			createShapeBox(neb::core::math::pose, glm::vec3 size);
	};

}}}}}


#endif



