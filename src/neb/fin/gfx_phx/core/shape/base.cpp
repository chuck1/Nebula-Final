#include <neb/fin/gfx_phx/core/shape/base.hpp>
#include <neb/fin/gfx_phx/core/shape/util/parent.hpp>

neb::fin::gfx_phx::core::shape::base::base()
{
}
neb::fin::gfx_phx::core::shape::base::base(std::shared_ptr<neb::fin::gfx_phx::core::shape::util::parent> parent):
	gal::stl::child<neb::core::core::shape::util::parent>(parent.get())
{
}
void		neb::fin::gfx_phx::core::shape::base::init() {
	neb::core::core::shape::base::init();
	neb::gfx::core::shape::base::init();
	neb::phx::core::shape::base::init();
}
void		neb::fin::gfx_phx::core::shape::base::release()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}
void		neb::fin::gfx_phx::core::shape::base::step(gal::etc::timestep const & ts) {
}


