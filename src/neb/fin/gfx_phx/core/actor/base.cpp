#include <gal/stl/deleter.hpp>

#include <neb/fin/gfx_phx/core/actor/base.hpp>
#include <neb/fin/gfx_phx/core/shape/box.hpp>
#include <neb/phx/core/shape/HeightField.hpp>

typedef neb::fin::gfx_phx::core::actor::base THIS;

neb::fin::gfx_phx::core::actor::base::base()
{
}
void						THIS::init(neb::core::core::actor::util::parent* const & p)
{
	LOG(lg, neb::core::core::actor::sl, debug) << __FUNCSIG__;

	setParent(p);

	neb::util::parent<neb::actor::__base>::init(this);
	neb::core::core::shape::util::parent::init(this);

	// base classes
	
	neb::core::core::actor::base::init(p);

	neb::phx::core::actor::base::init(p);

	//neb::gfx::core::actor::base::init(p);
}
void						neb::fin::gfx_phx::core::actor::base::release()
{
	neb::core::core::actor::base::release();
}
void						neb::fin::gfx_phx::core::actor::base::step(gal::etc::timestep const & ts) {
}
weak_ptr<neb::core::core::shape::base>		neb::fin::gfx_phx::core::actor::base::createShapeBase(neb::core::pose pose) {

	auto self(dynamic_pointer_cast<neb::fin::gfx_phx::core::actor::base>(shared_from_this()));

	typedef neb::fin::gfx_phx::core::shape::base T;

	std::shared_ptr<T> shape(new T(), gal::stl::deleter<T>());

	neb::core::core::shape::util::parent::insert(shape);
	
	shape->init(this);

	return shape;
}
weak_ptr<neb::core::core::shape::base>		neb::fin::gfx_phx::core::actor::base::createShapeCuboid(
		neb::core::core::shape::cuboid::desc desc)
{

	auto self(std::dynamic_pointer_cast<neb::fin::gfx_phx::core::actor::base>(shared_from_this()));

	typedef neb::fin::gfx_phx::core::shape::box T;

	std::shared_ptr<T> shape(new T(), gal::stl::deleter<T>());

	shape->pose_ = desc.pose_;
	shape->scale_ = desc.scale_;

	neb::core::core::shape::util::parent::insert(shape);
	
	shape->init(this);

	return shape;

}
std::weak_ptr<neb::core::core::shape::base>		neb::fin::gfx_phx::core::actor::base::createShapeHeightField(
					neb::core::core::shape::HeightField::desc const &)
{
	auto self(std::dynamic_pointer_cast<neb::fin::gfx_phx::core::actor::base>(shared_from_this()));

	typedef neb::phx::core::shape::HeightField T;

	std::shared_ptr<T> shape(new T(), gal::stl::deleter<T>());

	//shape->pose_ = desc.pose_;
	//shape->scale_ = desc.scale_;

	neb::core::core::shape::util::parent::insert(shape);

	shape->init(this);

	return shape;
}
void	neb::fin::gfx_phx::core::actor::base::load(ba::polymorphic_iarchive & ar, unsigned int const &)
{
	BOOST_SERIALIZATION_BASE_OBJECT_NVP(neb::core::core::actor::base);
}
void	neb::fin::gfx_phx::core::actor::base::save(ba::polymorphic_oarchive & ar, unsigned int const &) const
{
	BOOST_SERIALIZATION_BASE_OBJECT_NVP(neb::core::core::actor::base);
}


