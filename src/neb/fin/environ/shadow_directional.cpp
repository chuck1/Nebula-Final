
#include <neb/fnd/environ/shadow/Directional.hpp>
//#include <neb/fnd/environ/SceneDefault.hpp>

typedef neb::fnd::environ::shadow::Directional THIS;

void			THIS::init(parent_t * const & p)
{
	setParent(p);

	//neb::fnd::environ::shadow::Directional::init(p);
}

