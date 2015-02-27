#include <neb/fin/core/shape/box.hpp>
#include <neb/fin/core/shape/util/parent.hpp>

typedef neb::fin::core::shape::box THIS;

THIS::box()
{
}
THIS::~box()
{
	printv_func(DEBUG);
}
void		THIS::init(neb::fnd::core::shape::util::parent * const & p)
{
	printv_func(DEBUG);

	setParent(p);

	neb::fnd::core::shape::base::init(p);

	//neb::gfx::core::shape::base::init(p);
	//neb::gfx::core::shape::box::init(p);

	neb::phx::core::shape::base::init(p);
	neb::phx::core::shape::box::init(p);

	neb::fin::core::shape::base::init(p);
}
void		THIS::release()
{
	printv_func(DEBUG);

	neb::fnd::core::shape::base::release();

	//neb::gfx::core::shape::base::release();
	//neb::gfx::core::shape::box::release();

	neb::phx::core::shape::base::release();
	//neb::phx::core::shape::box::release();

	neb::fin::core::shape::base::release();
	
}
void		THIS::step(gal::etc::timestep const & ts)
{
	printv_func(DEBUG);
}
void		THIS::load(ba::polymorphic_iarchive & ar, unsigned int const & v)
{
	printv_func(DEBUG);

	gal::itf::shared::serialize(ar, v);//load(ar, v);
	neb::fnd::core::shape::base::load(ar, v);
}
void		THIS::save(ba::polymorphic_oarchive & ar, unsigned int const & v) const
{
	printv_func(DEBUG);

	const_cast<THIS*>(this)->gal::itf::shared::serialize(ar, v);//save(ar, v);
	neb::fnd::core::shape::base::save(ar, v);
}


