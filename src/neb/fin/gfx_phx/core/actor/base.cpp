#include <neb/fin/gfx_phx/core/actor/base.hpp>
#include <neb/fin/gfx_phx/core/shape/box.hpp>

neb::fin::gfx_phx::core::actor::base::base(std::shared_ptr<neb::fin::gfx_phx::core::actor::util::parent> parent):
	neb::core::core::actor::base(parent),
	neb::phx::core::actor::base(parent),
	neb::gfx::core::actor::base(parent)
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

	auto actor(make_shared<neb::fin::gfx_phx::core::shape::base>(self));

	neb::fin::gfx_phx::core::shape::util::parent::insert(actor);
	actor->init();
	return actor;
}
weak_ptr<neb::core::core::shape::base>		neb::fin::gfx_phx::core::actor::base::createShapeCuboid(
		neb::core::core::shape::cuboid::desc desc)
{

	auto self(std::dynamic_pointer_cast<neb::fin::gfx_phx::core::actor::base>(shared_from_this()));

	auto shape(std::make_shared<neb::fin::gfx_phx::core::shape::box>(self));

	shape->pose_ = desc.pose_;
	shape->scale_ = desc.scale_;

	neb::fin::gfx_phx::core::shape::util::parent::insert(shape);
	
	shape->init();

	return shape;

}

