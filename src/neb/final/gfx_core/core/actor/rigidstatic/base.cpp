
#include <neb/fin/gfx_phx/core/actor/rigidstatic/base.hpp>

neb::fin::gfx_phx::core::actor::rigidstatic::base::base(shared_ptr<neb::fin::gfx_phx::core::actor::util::parent> parent):
	neb::core::actor::base(parent),
	neb::phx::core::actor::base(parent),
	neb::phx::core::actor::actor::base(parent),
	neb::phx::core::actor::rigidactor::base(parent),
	neb::phx::core::actor::rigidstatic::base(parent),
	neb::gfx::core::actor::base(parent),
	neb::fin::gfx_phx::core::actor::base(parent),
	neb::fin::gfx_phx::core::actor::rigidactor::base(parent)
{}
void						neb::fin::gfx_phx::core::actor::rigidstatic::base::init() {
	neb::core::actor::base::init();

	neb::gfx::core::actor::base::init();

	neb::phx::core::actor::base::init();
	//neb::phx::core::actor::actor::base::init();
	//neb::phx::core::actor::rigidactor::base::init();
	//neb::phx::core::actor::rigidstatic::base::init();

	neb::fin::gfx_phx::core::actor::base::init();
	//neb::fin::gfx_phx::core::actor::rigidactor::base::init();
}
void						neb::fin::gfx_phx::core::actor::rigidstatic::base::release() {
}
void						neb::fin::gfx_phx::core::actor::rigidstatic::base::step(gal::std::timestep const & ts) {
}

