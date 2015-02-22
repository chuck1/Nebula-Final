#include <gal/log/log.hpp>

#include <neb/fnd/util/log.hpp>

#include <neb/fin/core/actor/rigidstatic/base.hpp>

neb::fin::core::actor::rigidstatic::base::base()
{
}
neb::fin::core::actor::rigidstatic::base::~base()
{
	LOG(lg, neb::fnd::sl, debug) << __PRETTY_FUNCTION__;
}
void						neb::fin::core::actor::rigidstatic::base::init(parent_t * const & p)
{
	LOG(lg, neb::fnd::sl, debug) << __PRETTY_FUNCTION__;

	setParent(p);

	neb::fnd::core::actor::base::init(p);

	//neb::gfx::core::actor::base::init(p);

	neb::phx::core::actor::base::init(p);
	//neb::phx::core::actor::actor::base::init();
	//neb::phx::core::actor::rigidactor::base::init();
	//neb::phx::core::actor::rigidstatic::base::init();

	neb::fin::core::actor::base::init(p);
	//neb::fin::core::actor::rigidactor::base::init();
}
void						neb::fin::core::actor::rigidstatic::base::release()
{
	LOG(lg, neb::fnd::sl, debug) << __PRETTY_FUNCTION__;

	neb::fnd::core::actor::base::release();
	
	//neb::gfx::core::actor::base::release();
	
	//neb::phx::core::actor::base::release();
	neb::phx::core::actor::actor::base::release();
	//neb::phx::core::actor::rigidactor::base::release();
	//neb::phx::core::actor::rigidstatic::base::release();

	neb::fin::core::actor::base::release();
	//neb::fin::core::actor::rigidactor::base::release();
}
void						neb::fin::core::actor::rigidstatic::base::step(gal::etc::timestep const & ts) {
}

