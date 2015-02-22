
#include <neb/phx/test.hpp>

//#include <neb/gfx/environ/base.hpp>

#include <neb/fin/camera/proj/Base.hpp>
#include <neb/fin/app/base.hpp>

void		neb::fin::camera::proj::Base::calculate_geometry()
{
	auto app = get_fin_app();

	_M_px_geometry = app->frustrum_geometry(_M_matrix);
}



