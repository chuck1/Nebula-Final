#include <neb/fin/context/FBOMulti.hpp>

typedef neb::fin::context::FBOMulti THIS;

void		THIS::init(parent_t * const parent)
{
	setParent(parent);

	neb::gfx::context::fbo_multi::init(parent);
}
/*void		THIS::setTexture(std::shared_ptr<neb::core::itf::shared>)
{

}*/
std::weak_ptr<neb::core::environ::shadow::Directional>		THIS::createEnvironShadowDirectional()
{
	return neb::fin::environ::util::Parent::createEnvironShadowDirectional();
}
std::weak_ptr<neb::core::environ::shadow::Point>		THIS::createEnvironShadowPoint()
{
	return neb::fin::environ::util::Parent::createEnvironShadowPoint();
}

