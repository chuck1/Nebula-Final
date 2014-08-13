#include <neb/fin/gfx_phx/core/actor/rigiddynamic/base.hpp>

neb::fin::gfx_phx::core::actor::rigiddynamic::base::base(shared_ptr<neb::fin::gfx_phx::core::actor::util::parent> parent):
	neb::core::actor::base(parent),
	neb::phx::core::actor::base(parent),
	neb::phx::core::actor::actor::base(parent),
	neb::phx::core::actor::rigidactor::base(parent),
	neb::phx::core::actor::rigidbody::base(parent),
	neb::phx::core::actor::rigiddynamic::base(parent),
	neb::gfx::core::actor::base(parent),
	neb::fin::gfx_phx::core::actor::base(parent),
	neb::fin::gfx_phx::core::actor::rigidactor::base(parent)
{
}
void					neb::fin::gfx_phx::core::actor::rigiddynamic::base::init() {
}
void					neb::fin::gfx_phx::core::actor::rigiddynamic::base::release() {
}
void					neb::fin::gfx_phx::core::actor::rigiddynamic::base::step(
		gal::std::timestep const & ts) {
}


