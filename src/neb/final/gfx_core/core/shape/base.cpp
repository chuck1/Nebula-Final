#include <neb/fin/gfx_phx/core/shape/base.hpp>
#include <neb/fin/gfx_phx/core/shape/util/parent.hpp>

neb::fin::gfx_phx::core::shape::base::base(shared_ptr<neb::fin::gfx_phx::core::shape::util::parent> parent):
	neb::core::shape::base(parent),
	neb::gfx::core::shape::base(parent),
	neb::phx::core::shape::base(parent)
{
}
void		neb::fin::gfx_phx::core::shape::base::init() {
}
void		neb::fin::gfx_phx::core::shape::base::release() {
}
void		neb::fin::gfx_phx::core::shape::base::step(gal::std::timestep const & ts) {
}


