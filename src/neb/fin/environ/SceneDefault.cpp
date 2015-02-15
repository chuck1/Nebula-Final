#include <neb/fin/environ/SceneDefault.hpp>

typedef neb::fin::environ::SceneDefault THIS;

void			THIS::init(parent_t * const & p)
{
	setParent(p);

	neb::gfx::environ::SceneDefault::init(p);
	neb::fin::environ::base::init(p);
}

