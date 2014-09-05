#include <gal/stl/deleter.hpp>

#include <neb/fin/gfx_phx/core/actor/base.hpp>
#include <neb/fin/gfx_phx/core/shape/box.hpp>

neb::fin::gfx_phx::core::actor::base::base()
{
}
neb::fin::gfx_phx::core::actor::base::base(std::shared_ptr<neb::fin::gfx_phx::core::actor::util::parent> parent):
	gal::stl::child<neb::core::core::actor::util::parent>(parent.get())
{
}
void						neb::fin::gfx_phx::core::actor::base::init() {
}
void						neb::fin::gfx_phx::core::actor::base::release() {
}
void						neb::fin::gfx_phx::core::actor::base::step(gal::etc::timestep const & ts) {
}
weak_ptr<neb::core::core::shape::base>		neb::fin::gfx_phx::core::actor::base::createShapeBase(neb::core::pose pose) {

	auto self(dynamic_pointer_cast<neb::fin::gfx_phx::core::actor::base>(shared_from_this()));

	typedef neb::fin::gfx_phx::core::shape::base T;

	std::shared_ptr<T> shape(new T(self), gal::stl::deleter<T>());

	neb::fin::gfx_phx::core::shape::util::parent::insert(shape);
	shape->init();
	return shape;
}
weak_ptr<neb::core::core::shape::base>		neb::fin::gfx_phx::core::actor::base::createShapeCuboid(
		neb::core::core::shape::cuboid::desc desc)
{

	auto self(std::dynamic_pointer_cast<neb::fin::gfx_phx::core::actor::base>(shared_from_this()));

	typedef neb::fin::gfx_phx::core::shape::box T;

	std::shared_ptr<T> shape(new T(self), T::deleter());

	shape->pose_ = desc.pose_;
	shape->scale_ = desc.scale_;

	neb::fin::gfx_phx::core::shape::util::parent::insert(shape);
	
	shape->init();

	return shape;

}

