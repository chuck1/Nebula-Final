
#include <neb/fin/environ/base.hpp>
#include <neb/fin/camera/proj/Perspective.hpp>
#include <neb/fin/camera/proj/Ortho.hpp>

typedef neb::fin::environ::base THIS;

void			THIS::init(parent_t * const & p)
{
	setParent(p);

	//neb::fnd::environ::Base::init(p);
}
THIS::proj_shared	THIS::createCameraPerspective()
{
	proj_ = THIS::proj_shared(new neb::fin::camera::proj::Perspective);
	
	proj_->init(this);

	return proj_;
}
THIS::proj_shared	THIS::createCameraOrtho()
{
	proj_ = THIS::proj_shared(new neb::fin::camera::proj::Ortho);
	
	proj_->init(this);

	return proj_;
}


