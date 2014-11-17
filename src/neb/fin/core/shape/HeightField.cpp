
#include <neb/fin/core/shape/HeightField.hpp>

void				neb::phx::core::shape::HeightField::init(THIS::parent_t * const & p)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	setParent(p);

	neb::core::core::shape::base::init(p);
	neb::gfx::core::shape::base::init(p);
	neb::phx::core::shape::base::__init(p);
}


