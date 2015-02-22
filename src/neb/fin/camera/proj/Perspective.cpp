//#include <neb/gfx/environ/base.hpp>

#include <neb/fnd/camera/proj/Perspective.hpp>

#include <neb/fnd/plug/gfx/camera/proj/Base.hpp>


typedef neb::fnd::camera::proj::Perspective THIS;

THIS::Perspective()
{
}
void	THIS::init(parent_t * const & p)
{
	setParent(p);
	
	if(_M_graphics_object)
		_M_graphics_object->calculate();
}
void	THIS::release()
{
}

