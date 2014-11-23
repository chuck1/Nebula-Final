#ifndef NEB_FIN_CORE_SHAPE_HEIGHT_FIELD_HPP
#define NEB_FIN_CORE_SHAPE_HEIGHT_FIELD_HPP

#include <neb/gfx/core/shape/HeightField/Base.hpp>
#include <neb/phx/core/shape/HeightField/Base.hpp>

namespace neb { namespace fin { namespace core { namespace shape { namespace HeightField {
	class Base:
		public neb::gfx::core::shape::HeightField::Base,
		public neb::phx::core::shape::HeightField::Base
	{
		public:
			typedef nc::core::shape::util::parent	parent_t;

			virtual void		init(parent_t * const & p);
			virtual void		release();
			virtual void		step(gal::etc::timestep  const & ts);

			virtual void		load(ba::polymorphic_iarchive & ar, unsigned int const &);
			virtual void		save(ba::polymorphic_oarchive & ar, unsigned int const &) const;
			BOOST_SERIALIZATION_SPLIT_MEMBER();
	};

}}}}}

#endif

