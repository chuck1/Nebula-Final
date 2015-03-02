#include <neb/fnd/app/Base.hpp>
#include <neb/fnd/core/light/Point.hpp>
#include <neb/fnd/core/light/Directional.hpp>
#include <neb/fnd/core/light/Spot.hpp>

#include <neb/fnd/plug/gfx/core/light/Point.hpp>
#include <neb/fnd/plug/gfx/core/light/Directional.hpp>
#include <neb/fnd/plug/gfx/core/light/Spot.hpp>

#include <neb/fin/core/shape/base.hpp>

typedef neb::fin::core::shape::base THIS;

void		THIS::load(ba::polymorphic_iarchive & ar, unsigned int const & v)
{
	printv_func(DEBUG);

	typedef neb::fnd::core::shape::base core_shape_base;
	//typedef neb::gfx::core::shape::base gfx_shape_base;

	BOOST_SERIALIZATION_BASE_OBJECT_NVP(core_shape_base);
	//BOOST_SERIALIZATION_BASE_OBJECT_NVP(gfx_shape_base);
	
/*	ar >> boost::serialization::make_nvp(
			"core_shape_base",
			boost::serialization::base_object<neb::fnd::core::shape::base>(*this)
			);*/

	neb::fnd::core::shape::base::__serialize(ar,v);

}
void		THIS::save(ba::polymorphic_oarchive & ar, unsigned int const & v) const
{
	printv_func(DEBUG);

	typedef neb::fnd::core::shape::base core_shape_base;
	//typedef neb::gfx::core::shape::base gfx_shape_base;

	BOOST_SERIALIZATION_BASE_OBJECT_NVP(core_shape_base);
	//BOOST_SERIALIZATION_BASE_OBJECT_NVP(gfx_shape_base);

/*	ar << boost::serialization::make_nvp(
			"core_shape_base",
			boost::serialization::base_object<neb::fnd::core::shape::base>(*this)
			);*/

	const_cast<THIS*>(this)->neb::fnd::core::shape::base::__serialize(ar,v);

}
void				THIS::v_set_pose_data(
		gal::math::pose const & pose_global)
{
	printv_func(DEBUG);
	neb::fnd::core::shape::base::__set_pose_data(pose_global);
}
std::weak_ptr<neb::fnd::core::light::base>		THIS::createLightSpot(glm::vec3 d)
{
	printv_func(DEBUG);

	auto self(std::dynamic_pointer_cast<neb::fnd::core::shape::base>(shared_from_this()));

	//auto app = get_fnd_app();

	typedef neb::fnd::core::light::Spot L;
	typedef neb::fnd::plug::gfx::core::light::Spot G;

	auto l = new L();
	auto light = std::shared_ptr<L>(l, gal::stl::deleter<L>());

	light->set_spot_direction(d);

	neb::fnd::core::light::util::parent::insert(light);

	light->init(this);

	return light;
}
std::weak_ptr<neb::fnd::core::light::base>		THIS::createLightDirectional(glm::vec3 d)
{
	printv_func(DEBUG);

	auto self(std::dynamic_pointer_cast<neb::fnd::core::shape::base>(shared_from_this()));

	typedef neb::fnd::core::light::Directional L;
	typedef neb::fnd::plug::gfx::core::light::Directional G;
	
	auto light = std::shared_ptr<L>(new L(), gal::stl::deleter<L>());

	light->pose_.pos_ = d;

	neb::fnd::core::light::util::parent::insert(light);

	light->init(this);

	return light;
}


