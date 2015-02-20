#include <neb/phx/util/log.hpp>
#include <neb/fin/core/shape/base.hpp>
#include <neb/fin/core/shape/util/parent.hpp>

typedef neb::fin::core::shape::base THIS;

neb::fin::core::shape::base::base()
{
}
void		neb::fin::core::shape::base::init(neb::fnd::core::shape::util::parent * const & p)
{
	setParent(p);

	neb::fnd::core::shape::base::init(p);
	neb::gfx::core::shape::base::init(p);
	neb::phx::core::shape::base::init(p);
}
void		neb::fin::core::shape::base::release()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	neb::gfx::core::shape::base::release();
	neb::phx::core::shape::base::release();
}
void		neb::fin::core::shape::base::step(gal::etc::timestep const & ts) {
}
void		THIS::load(ba::polymorphic_iarchive & ar, unsigned int const & v)
{
	LOG(lg, neb::phx::core::shape::sl, debug) << __PRETTY_FUNCTION__;

	typedef neb::fnd::core::shape::base core_shape_base;
	typedef neb::gfx::core::shape::base gfx_shape_base;

	BOOST_SERIALIZATION_BASE_OBJECT_NVP(core_shape_base);
	BOOST_SERIALIZATION_BASE_OBJECT_NVP(gfx_shape_base);
	
/*	ar >> boost::serialization::make_nvp(
			"core_shape_base",
			boost::serialization::base_object<neb::fnd::core::shape::base>(*this)
			);*/

	neb::fnd::core::shape::base::__serialize(ar,v);

}
void		THIS::save(ba::polymorphic_oarchive & ar, unsigned int const & v) const
{
	LOG(lg, neb::phx::core::shape::sl, debug) << __PRETTY_FUNCTION__;

	typedef neb::fnd::core::shape::base core_shape_base;
	typedef neb::gfx::core::shape::base gfx_shape_base;

	BOOST_SERIALIZATION_BASE_OBJECT_NVP(core_shape_base);
	BOOST_SERIALIZATION_BASE_OBJECT_NVP(gfx_shape_base);

/*	ar << boost::serialization::make_nvp(
			"core_shape_base",
			boost::serialization::base_object<neb::fnd::core::shape::base>(*this)
			);*/

	const_cast<THIS*>(this)->neb::fnd::core::shape::base::__serialize(ar,v);

}
void				THIS::v_set_pose_data(
		neb::fnd::math::pose const & pose_global)
{
	neb::fnd::core::shape::base::__set_pose_data(pose_global);
}


