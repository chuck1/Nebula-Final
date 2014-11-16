#include <neb/fin/core/shape/box.hpp>
#include <neb/fin/core/shape/util/parent.hpp>

typedef neb::fin::core::shape::box THIS;

THIS::box()
{
}
THIS::~box()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}
void		THIS::init(neb::core::core::shape::util::parent * const & p)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	setParent(p);

	neb::core::core::shape::base::init(p);

	neb::gfx::core::shape::base::init(p);
	neb::gfx::core::shape::box::init(p);

	neb::phx::core::shape::base::init(p);
	neb::phx::core::shape::box::init(p);

	neb::fin::core::shape::base::init(p);
}
void		THIS::release() {
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	neb::core::core::shape::base::release();

	neb::gfx::core::shape::base::release();
	neb::gfx::core::shape::box::release();

	neb::phx::core::shape::base::release();
	//neb::phx::core::shape::box::release();

	neb::fin::core::shape::base::release();
	
}
void		THIS::step(gal::etc::timestep const & ts) {
}
void		THIS::load(ba::polymorphic_iarchive & ar, unsigned int const & v)
{
	LOG(lg, neb::core::core::shape::sl, debug) << __FUNCSIG__;

	gal::itf::shared::serialize(ar, v);//load(ar, v);
	neb::core::core::shape::base::load(ar, v);
}
void		THIS::save(ba::polymorphic_oarchive & ar, unsigned int const & v) const
{
	LOG(lg, neb::core::core::shape::sl, debug) << __FUNCSIG__;

	const_cast<THIS*>(this)->gal::itf::shared::serialize(ar, v);//save(ar, v);
	neb::core::core::shape::base::save(ar, v);
}


