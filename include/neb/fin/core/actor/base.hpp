#ifndef NEB_FINAL_GFX_PHX_CORE_ACTOR_BASE_HPP
#define NEB_FINAL_GFX_PHX_CORE_ACTOR_BASE_HPP

//#include <neb/gfx/core/actor/base.hpp>

#include <neb/phx/core/actor/base.hpp>

#include <neb/fin/core/actor/util/parent.hpp>
#include <neb/fin/core/shape/util/parent.hpp>

namespace neb { namespace fin { namespace core { namespace actor {

	class base:
		virtual public neb::phx::core::actor::base
		//virtual public neb::gfx::core::actor::base
	{
		public:
			typedef neb::fnd::core::actor::util::parent parent_t;
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
			virtual std::weak_ptr<neb::fnd::core::shape::base>		createShapeBase(
					neb::fnd::math::pose const & pose);
			/** @brief
			 *
			 */
			virtual std::weak_ptr<neb::fnd::core::shape::base>		createShapeCuboid(
					neb::fnd::core::shape::cuboid::Desc const &);
			/** @brief
			 *
			 */
			virtual std::weak_ptr<neb::fnd::core::shape::base>		createShapeHeightField(
					neb::fnd::core::shape::HeightField::desc const &);

	};
}}}}


#endif



