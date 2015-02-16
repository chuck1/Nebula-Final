#include <gal/log/log.hpp>

#include <neb/core/util/log.hpp>

#include <neb/fin/core/actor/rigiddynamic/base.hpp>

typedef neb::fin::core::actor::rigiddynamic::base THIS;

THIS::base()
{
}
neb::fin::core::actor::rigiddynamic::base::~base() {
	LOG(lg, neb::fnd::core::actor::sl, debug) << __PRETTY_FUNCTION__;
}
void					neb::fin::core::actor::rigiddynamic::base::init(
		neb::fnd::core::actor::util::parent * const & p
		)
{
	LOG(lg, neb::fnd::core::actor::sl, debug) << __FUNCSIG__;

	setParent(p);

	neb::fnd::core::actor::base::init(p);

	neb::phx::core::actor::base::init(p);
	//neb::phx::core::actor::actor::base::init();
	//neb::phx::core::actor::rigidactor::base::init();
	//neb::phx::core::actor::rigidbody::base::init();
	//neb::phx::core::actor::rigiddynamic::base::init();

	neb::gfx::core::actor::base::init(p);

	neb::fin::core::actor::base::init(p);
	//neb::fin::core::actor::rigidactor::base::init();
}
void					neb::fin::core::actor::rigiddynamic::base::release() {
	LOG(lg, neb::fnd::core::actor::sl, debug) << __PRETTY_FUNCTION__;

	neb::fnd::core::actor::base::release();

	//neb::phx::core::actor::base::release();
	neb::phx::core::actor::actor::base::release();
	//neb::phx::core::actor::rigidactor::base::release();
	//neb::phx::core::actor::rigidbody::base::release();
	//neb::phx::core::actor::rigiddynamic::base::release();

	neb::gfx::core::actor::base::release();

	neb::fin::core::actor::base::release();
}
void					neb::fin::core::actor::rigiddynamic::base::step(
		gal::etc::timestep const & ts) {
	neb::fnd::core::actor::base::step(ts);

	neb::phx::core::actor::base::step(ts);
	//neb::phx::core::actor::actor::base::step(ts);
	//neb::phx::core::actor::rigidactor::base::step(ts);
	neb::phx::core::actor::rigidbody::base::step(ts);
	//neb::phx::core::actor::rigiddynamic::base::step(ts);

	neb::gfx::core::actor::base::step(ts);

	neb::fin::core::actor::base::step(ts);

}
void				THIS::createControlManual(
		std::shared_ptr<neb::fnd::input::source> window)
{
	neb::phx::core::actor::rigidbody::base::createControlManual(window);
}


