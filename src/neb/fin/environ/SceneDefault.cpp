#include <neb/core/environ/SceneDefault.hpp>

typedef neb::fnd::environ::SceneDefault THIS;

void			THIS::init(parent_t * const & p)
{
	setParent(p);

	//neb::fnd::environ::SceneDefault::init(p);
	neb::fnd::environ::Base::init(p);
}

