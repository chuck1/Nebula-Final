#include <gal/stl/deleter.hpp>
#include <gal/stl/verbosity.hpp>

#include <neb/fnd/app/Base.hpp>
#include <neb/fnd/plug/gfx/core/shape/Base.hpp>
#include <neb/fnd/plug/gfx/core/actor/Base.hpp>
#include <neb/fnd/plug/gfx/core/actor/util/decl.hpp>


#include <neb/fin/core/actor/base.hpp>
#include <neb/fin/core/shape/box.hpp>
#include <neb/fin/core/shape/HeightField.hpp>

typedef neb::fin::core::actor::base THIS;

THIS::base()
{
}
void						THIS::init(
		neb::fnd::core::actor::util::parent* const & p)
{
	printv_func(DEBUG);

	setParent(p);

	auto app = get_fnd_app();

	if(!G::has_object())
		G::make_object<THIS, int>(
				app->_M_graphics_plugin,
				neb::fnd::plug::gfx::core::actor::type::BASE
				);

	neb::fnd::core::actor::util::parent::initChildren(this);
	neb::fnd::core::shape::util::parent::initChildren(this);

	// base classes

	neb::fnd::core::actor::base::init(p);

	neb::phx::core::actor::base::init(p);

	//neb::gfx::core::actor::base::init(p);
}
void						THIS::release()
{
	neb::fnd::core::actor::base::release();
}
void						THIS::step(gal::etc::timestep const & ts)
{
}
std::weak_ptr<neb::fnd::core::shape::base>	THIS::createShapeBase(gal::math::pose const & pose)
{
	auto self(dynamic_pointer_cast<neb::fin::core::actor::base>(shared_from_this()));

	typedef neb::fin::core::shape::base T;

	std::shared_ptr<T> shape(new T(), gal::stl::deleter<T>());

	neb::fnd::core::shape::util::parent::insert(shape);

	shape->init(this);

	return shape;
}
std::weak_ptr<neb::fnd::core::shape::base>		neb::fin::core::actor::base::createShapeCuboid(
		neb::fnd::core::shape::cuboid::Desc const & desc)
{
	auto self(std::dynamic_pointer_cast<neb::fin::core::actor::base>(shared_from_this()));
	typedef neb::fin::core::shape::box T;

	std::shared_ptr<T> shape(new T(), gal::stl::deleter<T>());

	shape->pose_ = desc.pose_;
	shape->scale_ = desc.scale_;

	neb::fnd::core::shape::util::parent::insert(shape);

	shape->init(this);

	return shape;

}
std::weak_ptr<neb::fnd::core::shape::base>		THIS::createShapeHeightField(
		neb::fnd::core::shape::HeightField::desc const & desc)
{
	auto self(std::dynamic_pointer_cast<neb::fin::core::actor::base>(shared_from_this()));

	typedef neb::fin::core::shape::HeightField::Base T;

	std::shared_ptr<T> shape(new T(), gal::stl::deleter<T>());

	//shape->pose_ = desc.pose_;
	//shape->scale_ = desc.scale_;
	
	shape->desc_ = desc;

	neb::fnd::core::shape::util::parent::insert(shape);



	shape->init(this);

	return shape;
}
void			THIS::load(ba::polymorphic_iarchive & ar, unsigned int const & v)
{
	BOOST_SERIALIZATION_BASE_OBJECT_NVP(gal::itf::shared);
	BOOST_SERIALIZATION_BASE_OBJECT_NVP(neb::fnd::core::actor::base);

	//gal::itf::shared::load(ar, v);
	gal::itf::shared::serialize(ar, v);
	neb::fnd::core::actor::base::load(ar, v);
}
void			THIS::save(ba::polymorphic_oarchive & ar, unsigned int const & v) const
{
	BOOST_SERIALIZATION_BASE_OBJECT_NVP(gal::itf::shared);
	BOOST_SERIALIZATION_BASE_OBJECT_NVP(neb::fnd::core::actor::base);

	//gal::itf::shared::save(ar, v);
	const_cast<THIS*>(this)->gal::itf::shared::serialize(ar, v);
	neb::fnd::core::actor::base::save(ar, v);
}


