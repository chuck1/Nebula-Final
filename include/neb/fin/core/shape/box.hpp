#ifndef NEB_FIN_GFX_PHX_CORE_SHAPE_BOX_HPP
#define NEB_FIN_GFX_PHX_CORE_SHAPE_BOX_HPP

//#include <neb/phx/core/shape/box.hpp>

//#include <neb/gfx/core/shape/box.hpp>

#include <neb/fin/core/shape/base.hpp>

namespace neb { namespace fin { namespace core { namespace shape {
	
	class box:
		/*virtual public neb::gfx::core::shape::box,*/
		//virtual public neb::phx::core::shape::box,
		virtual public neb::fin::core::shape::base
	{
		public:
			//neb::fnd::core::shape::util::parent
			box();
			virtual ~box();
			virtual void		init(parent_t * const &);
			virtual void		release();
			virtual void		step(gal::etc::timestep const & ts);

			virtual void		load(ba::polymorphic_iarchive & ar, unsigned int const &);
			virtual void		save(ba::polymorphic_oarchive & ar, unsigned int const &) const;
			BOOST_SERIALIZATION_SPLIT_MEMBER();
	};
}}}}

#endif



