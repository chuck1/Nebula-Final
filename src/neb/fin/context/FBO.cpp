#include <neb/gfx/texture/Base.hpp>

#include <neb/fin/context/fbo.hpp>

typedef neb::fin::context::fbo THIS;
typedef neb::fnd::environ::shadow::Directional ESD;

void			THIS::init(parent_t * const parent)
{
	setParent(parent);

	neb::gfx::context::fbo::init(parent);
}
void			THIS::render()
{
	neb::gfx::context::fbo::render();
}
std::weak_ptr<ESD>	THIS::createEnvironShadowDirectional()
{
	return neb::fin::environ::util::Parent::createEnvironShadowDirectional();
}
void			THIS::setTexture(
		std::shared_ptr<neb::fnd::itf::shared> tex)
{
	auto t = std::dynamic_pointer_cast<neb::gfx::texture::Base>(tex);
	texture_ = t;
}

