
//#include <neb/gfx/core/light/point.hpp>
//#include <neb/gfx/environ/SceneDefault.hpp>

#include <neb/fin/environ/shadow/Point.hpp>

typedef neb::fin::environ::shadow::Point THIS;

void			THIS::init(parent_t * const & p)
{
	setParent(p);

//	neb::gfx::environ::shadow::point::init(p);
	neb::fin::environ::base::init(p);
}

