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
	neb::core::actor::base::init();

	neb::phx::core::actor::base::init();
	//neb::phx::core::actor::actor::base::init();
	//neb::phx::core::actor::rigidactor::base::init();
	//neb::phx::core::actor::rigidbody::base::init();
	//neb::phx::core::actor::rigiddynamic::base::init();

	neb::gfx::core::actor::base::init();

	neb::fin::gfx_phx::core::actor::base::init();
	//neb::fin::gfx_phx::core::actor::rigidactor::base::init();
}
void					neb::fin::gfx_phx::core::actor::rigiddynamic::base::release() {
	neb::core::actor::base::release();

	//neb::phx::core::actor::base::release();
	neb::phx::core::actor::actor::base::release();
	//neb::phx::core::actor::rigidactor::base::release();
	//neb::phx::core::actor::rigidbody::base::release();
	//neb::phx::core::actor::rigiddynamic::base::release();

	neb::gfx::core::actor::base::release();

	neb::fin::gfx_phx::core::actor::base::release();
}
void					neb::fin::gfx_phx::core::actor::rigiddynamic::base::step(
		gal::std::timestep const & ts) {
	neb::core::actor::base::step(ts);

	neb::phx::core::actor::base::step(ts);
	//neb::phx::core::actor::actor::base::step(ts);
	//neb::phx::core::actor::rigidactor::base::step(ts);
	neb::phx::core::actor::rigidbody::base::step(ts);
	//neb::phx::core::actor::rigiddynamic::base::step(ts);

	neb::gfx::core::actor::base::step(ts);

	neb::fin::gfx_phx::core::actor::base::step(ts);

}


