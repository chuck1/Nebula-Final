#include <neb/fin/gfx_phx/core/shape/box.hpp>
#include <neb/fin/gfx_phx/core/shape/util/parent.hpp>

neb::fin::gfx_phx::core::shape::box::deleter::deleter()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}
neb::fin::gfx_phx::core::shape::box::deleter::~deleter()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}
void	neb::fin::gfx_phx::core::shape::box::deleter::operator()(box* p) const
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	p->release();

	delete p;
}

neb::fin::gfx_phx::core::shape::box::box()
{
}
neb::fin::gfx_phx::core::shape::box::~box()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}
void		neb::fin::gfx_phx::core::shape::box::init(neb::core::core::shape::util::parent * const & p)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	setParent(p);

	neb::core::core::shape::base::init(p);

	neb::gfx::core::shape::base::init(p);
	neb::gfx::core::shape::box::init(p);

	neb::phx::core::shape::base::init(p);
	neb::phx::core::shape::box::init(p);

	neb::fin::gfx_phx::core::shape::base::init(p);
}
void		neb::fin::gfx_phx::core::shape::box::release() {
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	neb::core::core::shape::base::release();

	neb::gfx::core::shape::base::release();
	neb::gfx::core::shape::box::release();

	neb::phx::core::shape::base::release();
	//neb::phx::core::shape::box::release();

	neb::fin::gfx_phx::core::shape::base::release();
	
}
void		neb::fin::gfx_phx::core::shape::box::step(gal::etc::timestep const & ts) {
}


