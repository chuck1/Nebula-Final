#include <neb/gfx/core/light/directional.hpp>

#include <neb/fin/environ/shadow/Directional.hpp>
#include <neb/fin/environ/SceneDefault.hpp>

typedef neb::fin::environ::shadow::Directional THIS;

void			THIS::init(parent_t * const & p)
{
	setParent(p);

	neb::gfx::environ::shadow::directional::init(p);
}

