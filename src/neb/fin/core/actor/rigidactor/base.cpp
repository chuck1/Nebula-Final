
#include <neb/fnd/app/Base.hpp>
#include <neb/fnd/plug/gfx/core/shape/Base.hpp>

#include <neb/fin/core/shape/box.hpp>
#include <neb/fin/core/actor/rigidactor/base.hpp>

/*neb::fin::core::actor::rigidactor::base::base(std::shared_ptr<neb::fin::gfx_phx::core::actor::util::parent> parent):
	neb::fnd::core::actor::base(parent),
	neb::phx::core::actor::base(parent),
	neb::phx::core::actor::actor::base(parent),
	neb::phx::core::actor::rigidactor::base(parent),
	neb::gfx::core::actor::base(parent),
	neb::fin::core::actor::base(parent)
{}*/
std::weak_ptr<neb::fnd::core::shape::base>		neb::fin::core::actor::rigidactor::base::createShapeBoxUninitialized(
		glm::vec3 size)
{
	printv_func(DEBUG);
	
	//auto self(::std::dynamic_pointer_cast<neb::fin::core::actor::rigidactor::base>(shared_from_this()));

	typedef neb::fin::core::shape::box T;

	std::shared_ptr<T> shape(new T(), gal::stl::deleter<T>());

	neb::fnd::core::shape::util::parent::insert(shape);
	
	shape->scale_ = size;
	
	return shape;
}
std::weak_ptr<neb::fnd::core::shape::base>		neb::fin::core::actor::rigidactor::base::createShapeBox(
		gal::math::pose pose,
		glm::vec3 size)
{
	printv_func(DEBUG);

	auto shape = createShapeBoxUninitialized(size).lock();
	
	shape->init(this);

	// P::get_object->
	setupFiltering();

	return shape;
}    

