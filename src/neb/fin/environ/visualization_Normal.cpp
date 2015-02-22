#include <neb/fin/environ/visualization/Normal.hpp>

typedef neb::fin::environ::visualization::Normal THIS;

void			THIS::init(parent_t * const & p)
{
	setParent(p);

	//neb::gfx::environ::NormalMap::init(p);
	neb::fin::environ::base::init(p);

}
