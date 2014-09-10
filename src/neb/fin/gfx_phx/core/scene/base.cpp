//#include <neb/fin/gfx_phx/util/log.hpp>

#include <gal/stl/deleter.hpp>

#include <neb/fin/gfx_phx/core/actor/rigidstatic/base.hpp>
#include <neb/fin/gfx_phx/core/actor/rigiddynamic/base.hpp>
#include <neb/fin/gfx_phx/core/scene/base.hpp>

typedef weak_ptr<neb::core::core::actor::base>			wbase;

neb::fin::gfx_phx::core::scene::base::base(std::shared_ptr<neb::fin::gfx_phx::core::scene::util::parent> parent):
	neb::core::core::scene::base(parent),
	neb::phx::core::scene::base(parent)
{
}
void		neb::fin::gfx_phx::core::scene::base::init() {
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	neb::core::core::scene::base::init();
	neb::phx::core::scene::base::init();
}
void		neb::fin::gfx_phx::core::scene::base::release() {
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	neb::core::core::scene::base::release();

	neb::phx::core::scene::base::release();
}
void		neb::fin::gfx_phx::core::scene::base::step(gal::etc::timestep const & ts) {
	//std::cout << __PRETTY_FUNCTION__ << std::endl;
	neb::core::core::scene::base::step(ts);
	neb::phx::core::scene::base::step(ts);
}
wbase		neb::fin::gfx_phx::core::scene::base::createActorBase(neb::core::pose pose) {
	
	auto self(dynamic_pointer_cast<neb::fin::gfx_phx::core::scene::base>(shared_from_this()));

	typedef neb::fin::gfx_phx::core::actor::base T;

	std::shared_ptr<T> actor(new T(self), gal::stl::deleter<T>());

	actor->pose_ = pose;

	insert(actor);

	actor->init();

	return actor;
}
wbase		neb::fin::gfx_phx::core::scene::base::createActorRigidStaticUninitialized() {

	auto self(dynamic_pointer_cast<neb::fin::gfx_phx::core::scene::base>(shared_from_this()));

	typedef neb::fin::gfx_phx::core::actor::rigidstatic::base T;

	std::shared_ptr<T> actor(new T(self), gal::stl::deleter<T>());

	neb::core::core::actor::util::parent::insert(actor);

	actor->simulation_.word0 = phx::filter::filter::type::STATIC;
	actor->simulation_.word1 = phx::filter::filter::RIGID_AGAINST;
	actor->simulation_.word2 = phx::filter::filter::type::STATIC;
	actor->simulation_.word3 = phx::filter::filter::type::PROJECTILE;

	return actor;
}
wbase		neb::fin::gfx_phx::core::scene::base::createActorRigidDynamicUninitialized() {

	auto self(dynamic_pointer_cast<neb::fin::gfx_phx::core::scene::base>(shared_from_this()));

	typedef neb::fin::gfx_phx::core::actor::rigiddynamic::base T;

	std::shared_ptr<T> actor(new T(self), T::deleter());

	neb::core::core::actor::util::parent::insert(actor);

	actor->simulation_.word0 = phx::filter::filter::type::DYNAMIC;
	actor->simulation_.word1 = phx::filter::filter::RIGID_AGAINST;
	actor->simulation_.word2 = phx::filter::filter::type::DYNAMIC;
	actor->simulation_.word3 = phx::filter::filter::type::PROJECTILE;

	return actor;

}
wbase			neb::fin::gfx_phx::core::scene::base::createActorRigidDynamic(
		neb::core::core::actor::rigiddynamic::desc const * const & desc
		)
{

	auto self(dynamic_pointer_cast<neb::fin::gfx_phx::core::scene::base>(shared_from_this()));

	typedef neb::fin::gfx_phx::core::actor::rigiddynamic::base T;

	std::shared_ptr<T> actor(new T(self), T::deleter());

	neb::core::core::actor::util::parent::insert(actor);

	actor->simulation_.word0 = phx::filter::filter::type::DYNAMIC;
	actor->simulation_.word1 = phx::filter::filter::RIGID_AGAINST;
	actor->simulation_.word2 = phx::filter::filter::type::DYNAMIC;
	actor->simulation_.word3 = phx::filter::filter::type::PROJECTILE;

	actor->init();

	return actor;

}

