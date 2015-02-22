#include <neb/fin/environ/two.hpp>

typedef neb::fin::environ::Two THIS;

void			THIS::init(parent_t * const & p)
{
	setParent(p);

	//neb::fnd::environ::Two::init(p);
	neb::fin::environ::base::init(p);

}
