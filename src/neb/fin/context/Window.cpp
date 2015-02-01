#include <neb/fin/context/Window.hpp>

typedef neb::fin::context::Window THIS;

void		THIS::init(parent_t * const parent)
{
	setParent(parent);

	//neb::fin::context::Base::init(parent);
	neb::gfx::context::Window::init(parent);
}
void		THIS::step(gal::etc::timestep const & ts)
{
}
void		THIS::render()
{
}

