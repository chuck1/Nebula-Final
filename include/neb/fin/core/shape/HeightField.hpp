#ifndef NEB_FIN_CORE_SHAPE_HEIGHT_FIELD_HPP
#define NEB_FIN_CORE_SHAPE_HEIGHT_FIELD_HPP

//#include <neb/gfx/core/shape/HeightField/Base.hpp>

#include <neb/fnd/core/shape/HeightField.hpp>

#include <neb/fin/core/shape/base.hpp>

namespace neb { namespace fin { namespace core { namespace shape { namespace HeightField {
	class Base:
		virtual public neb::fin::core::shape::base,
		virtual public neb::fnd::core::shape::HeightField::Base
		//virtual public neb::phx::core::shape::HeightField::Base
	{
		public:
			typedef neb::fnd::core::shape::util::parent	parent_t;

			virtual void		init(parent_t * const & p);
			virtual void		release();
			virtual void		step(gal::etc::timestep  const & ts);
			virtual void		v_set_pose_data(gal::math::pose const & pose_global);
			virtual void		load(ba::polymorphic_iarchive & ar, unsigned int const &);
			virtual void		save(ba::polymorphic_oarchive & ar, unsigned int const &) const;
			BOOST_SERIALIZATION_SPLIT_MEMBER();
	};

}}}}}

#endif

