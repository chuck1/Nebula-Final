#include <gal/log/log.hpp>

#include <neb/fnd/app/Base.hpp>
#include <neb/fnd/plug/gfx/core/actor/util/decl.hpp>
#include <neb/fnd/plug/gfx/core/actor/Base.hpp>

#include <neb/fnd/plug/phx/core/actor/util/decl.hpp>
#include <neb/fnd/plug/phx/core/actor/Base.hpp>

#include <neb/fin/core/actor/rigidstatic/base.hpp>

typedef neb::fin::core::actor::rigidstatic::base THIS;

neb::fin::core::actor::rigidstatic::base::base()
{
}
neb::fin::core::actor::rigidstatic::base::~base()
{
	printv_func(DEBUG);
}
void						neb::fin::core::actor::rigidstatic::base::init(parent_t * const & p)
{
	printv_func(DEBUG);

	setParent(p);

	auto app = get_fnd_app();

	if(!G::has_object())
		G::make_object<THIS, int>(
				app->_M_graphics_plugin,
				neb::fnd::plug::gfx::core::actor::type::RIGIDSTATIC);

	if(!P::has_object())
		P::make_object<THIS, int>(
				app->_M_physics_plugin,
				neb::fnd::plug::phx::core::actor::type::RIGIDSTATIC);

	neb::fnd::core::actor::base::init(p);

	//neb::gfx::core::actor::base::init(p);

	//neb::phx::core::actor::base::init(p);
	//neb::phx::core::actor::actor::base::init();
	//neb::phx::core::actor::rigidactor::base::init();
	//neb::phx::core::actor::rigidstatic::base::init();

	neb::fin::core::actor::base::init(p);
	//neb::fin::core::actor::rigidactor::base::init();
}
void						neb::fin::core::actor::rigidstatic::base::release()
{
	printv_func(DEBUG);

	neb::fnd::core::actor::base::release();
	
	//neb::gfx::core::actor::base::release();
	
	//neb::phx::core::actor::base::release();
	//neb::phx::core::actor::actor::base::release();
	//neb::phx::core::actor::rigidactor::base::release();
	//neb::phx::core::actor::rigidstatic::base::release();

	neb::fin::core::actor::base::release();
	//neb::fin::core::actor::rigidactor::base::release();
	
}
void						neb::fin::core::actor::rigidstatic::base::step(gal::etc::timestep const & ts)
{
}

