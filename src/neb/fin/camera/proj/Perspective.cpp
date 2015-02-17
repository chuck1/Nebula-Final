#include <neb/gfx/environ/base.hpp>

#include <neb/fin/camera/proj/Perspective.hpp>

typedef neb::fin::camera::proj::Perspective THIS;

THIS::Perspective()
{
}
void	THIS::init(parent_t * const & p)
{
	setParent(p);

	calculate();
}
void	THIS::release()
{
}

