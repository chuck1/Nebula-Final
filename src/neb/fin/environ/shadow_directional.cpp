
#include <neb/core/environ/shadow/Directional.hpp>
//#include <neb/core/environ/SceneDefault.hpp>

typedef neb::fnd::environ::shadow::Directional THIS;

void			THIS::init(parent_t * const & p)
{
	setParent(p);

	//neb::fnd::environ::shadow::Directional::init(p);
}

