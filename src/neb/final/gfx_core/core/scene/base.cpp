
#include <neb/fin/gfx_phx/core/actor/rigidstatic/base.hpp>
#include <neb/fin/gfx_phx/core/actor/rigiddynamic/base.hpp>
#include <neb/fin/gfx_phx/core/scene/base.hpp>

typedef weak_ptr<neb::core::actor::base>			wbase;
typedef weak_ptr<neb::phx::core::actor::rigidstatic::base>	wstatic;
typedef weak_ptr<neb::phx::core::actor::rigiddynamic::base>	wdynamic;

neb::fin::gfx_phx::core::scene::base::base(shared_ptr<neb::fin::gfx_phx::core::scene::util::parent> parent):
	neb::core::core::scene::base(parent),
	neb::gfx::core::scene::base(parent),
	neb::phx::core::scene::base(parent)
{
}
void		neb::fin::gfx_phx::core::scene::base::init() {
	neb::core::core::scene::base::init();
	neb::gfx::core::scene::base::init();
	neb::phx::core::scene::base::init();
}
void		neb::fin::gfx_phx::core::scene::base::release() {
}
void		neb::fin::gfx_phx::core::scene::base::step(gal::std::timestep const & ts) {
	neb::core::core::scene::base::step(ts);
	neb::gfx::core::scene::base::step(ts);
	neb::phx::core::scene::base::step(ts);
}
wbase		neb::fin::gfx_phx::core::scene::base::createActorBase(neb::core::pose pose) {
	
	auto self(dynamic_pointer_cast<neb::fin::gfx_phx::core::scene::base>(shared_from_this()));

	auto actor(make_shared<neb::fin::gfx_phx::core::actor::base>(self));

	insert(actor);

	actor->init();

	return actor;
}
wstatic		neb::fin::gfx_phx::core::scene::base::createActorRigidStaticUninitialized() {

	auto self(dynamic_pointer_cast<neb::fin::gfx_phx::core::scene::base>(shared_from_this()));

	auto actor(make_shared<neb::fin::gfx_phx::core::actor::rigidstatic::base>(self));

	neb::core::actor::util::parent::insert(actor);

	actor->simulation_.word0 = phx::filter::filter::type::STATIC;
	actor->simulation_.word1 = phx::filter::filter::RIGID_AGAINST;
	actor->simulation_.word2 = phx::filter::filter::type::STATIC;
	actor->simulation_.word3 = phx::filter::filter::type::PROJECTILE;

	return actor;
}
wdynamic	neb::fin::gfx_phx::core::scene::base::createActorRigidDynamicUninitialized() {

	auto self(dynamic_pointer_cast<neb::fin::gfx_phx::core::scene::base>(shared_from_this()));

	auto actor = make_shared<neb::fin::gfx_phx::core::actor::rigiddynamic::base>(self);

	neb::core::actor::util::parent::insert(actor);

	actor->simulation_.word0 = phx::filter::filter::type::DYNAMIC;
	actor->simulation_.word1 = phx::filter::filter::RIGID_AGAINST;
	actor->simulation_.word2 = phx::filter::filter::type::DYNAMIC;
	actor->simulation_.word3 = phx::filter::filter::type::PROJECTILE;

	return actor;

}

