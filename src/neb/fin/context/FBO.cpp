#include <neb/gfx/texture.hpp>

#include <neb/fin/context/fbo.hpp>

typedef neb::fin::context::fbo THIS;

void		THIS::setTexture(
		std::shared_ptr<neb::core::itf::shared> tex)
{
	auto t = std::dynamic_pointer_cast<neb::gfx::texture>(tex);
	texture_ = t;
}

