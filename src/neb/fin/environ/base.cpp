
#include <neb/fin/environ/base.hpp>
#include <neb/fin/camera/proj/Perspective.hpp>
#include <neb/fin/camera/proj/Ortho.hpp>

typedef neb::fin::environ::base THIS;

THIS::proj_shared	THIS::createCameraPerspective()
{
	return THIS::proj_shared(new neb::fin::camera::proj::Perspective);
}
THIS::proj_shared	THIS::createCameraOrtho()
{
	return THIS::proj_shared(new neb::fin::camera::proj::Ortho);
}


