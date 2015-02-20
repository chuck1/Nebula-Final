#ifndef NEB_FIN_GFX_PHX_CORE_SHAPE_BASE_HPP
#define NEB_FIN_GFX_PHX_CORE_SHAPE_BASE_HPP

#include <neb/phx/core/shape/base.hpp>

#include <neb/gfx/core/shape/base.hpp>

#include <neb/fin/core/shape/util/decl.hpp>
#include <neb/fin/tmp/Child.hpp>

namespace neb { namespace fin { namespace core { namespace shape {
	class base:
		/*virtual public neb::gfx::core::shape::base,*/
		virtual public neb::phx::core::shape::base,
		virtual public neb::fin::tmp::Child<neb::fnd::core::shape::util::parent>
	{
		public:
			base();
			virtual void				init(neb::fnd::core::shape::util::parent * const & p);
			virtual void				release();
			virtual void				step(
					gal::etc::timestep const & ts);
			virtual void	load(ba::polymorphic_iarchive & ar, unsigned int const &);
			virtual void	save(ba::polymorphic_oarchive & ar, unsigned int const &) const;
			virtual void				v_set_pose_data(
					neb::fnd::math::pose const & pose_global);
	};
}}}}

#endif

