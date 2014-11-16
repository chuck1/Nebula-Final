#ifndef NEB_FINAL_GFX_PHX_CORE_ACTOR_BASE_HPP
#define NEB_FINAL_GFX_PHX_CORE_ACTOR_BASE_HPP

#include <neb/gfx/core/actor/base.hpp>

#include <neb/phx/core/actor/base.hpp>

#include <neb/fin/core/actor/util/parent.hpp>
#include <neb/fin/core/shape/util/parent.hpp>

namespace neb { namespace fin { namespace core { namespace actor {

	class base:
		virtual public neb::phx::core::actor::base,
		virtual public neb::gfx::core::actor::base
	{
		public:
			typedef neb::core::core::actor::util::parent parent_t;
			base();
			virtual void						init(parent_t * const &);
			virtual void						release();
			virtual void						step(gal::etc::timestep const & ts);

			/** @brief
			 *
			 */
			virtual void	load(ba::polymorphic_iarchive & ar, unsigned int const &);
			/** @brief
			 *
			 */
			virtual void	save(ba::polymorphic_oarchive & ar, unsigned int const &) const;
			/** @brief
			 *
			 */
			virtual std::weak_ptr<neb::core::core::shape::base>		createShapeBase(
					neb::core::math::pose pose);
			/** @brief
			 *
			 */
			virtual std::weak_ptr<neb::core::core::shape::base>		createShapeCuboid(
					neb::core::core::shape::cuboid::desc);
			/** @brief
			 *
			 */
			virtual std::weak_ptr<neb::core::core::shape::base>		createShapeHeightField(
					neb::core::core::shape::HeightField::desc const &);

	};
}}}}


#endif



