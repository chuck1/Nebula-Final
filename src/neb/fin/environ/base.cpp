#include <neb/fnd/app/Base.hpp>
#include <neb/fnd/environ/Base.hpp>
#include <neb/fnd/camera/proj/Perspective.hpp>
#include <neb/fnd/camera/proj/Ortho.hpp>

#include <neb/fnd/plug/gfx/camera/proj/Perspective.hpp>

typedef neb::fnd::environ::Base THIS;

void			THIS::init(parent_t * const & p)
{
	setParent(p);

	//neb::fnd::environ::Base::init(p);
}
THIS::proj_shared	THIS::createCameraPerspective()
{
	auto app = get_fnd_app();

	typedef neb::fnd::camera::proj::Perspective C;
	typedef neb::fnd::plug::gfx::camera::proj::Perspective G;
	
	auto c = new C();
	proj_ = THIS::proj_shared(c);

	if(app->_M_graphics_plugin) {
		auto g = app->_M_graphics_plugin->template make_shared<G>();
		proj_->_M_graphics_object = g;
	}
	
	proj_->init(this);

	return proj_;
}
THIS::proj_shared	THIS::createCameraOrtho()
{
	typedef neb::fnd::camera::proj::Ortho C;

	auto c = new C;
	proj_.reset(c);


	proj_->init(this);

	return proj_;
}


