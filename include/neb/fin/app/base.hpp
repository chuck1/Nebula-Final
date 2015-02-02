#ifndef __NEBULA_APP_H__
#define __NEBULA_APP_H__

#include <fstream>

#include <boost/archive/polymorphic_xml_iarchive.hpp>

#include <ft2build.h>
#include FT_FREETYPE_H

#include <gal/itf/shared.hpp>
#include <gal/stl/wrapper.hpp>

#include <neb/core/app/__base.hpp>
#include <neb/core/core/scene/util/parent.hpp>
#include <neb/core/core/shape/util/decl.hpp>
#include <neb/core/util/wrapper.hpp>
#include <neb/core/util/decl.hpp>

#include <neb/gfx/app/__gfx.hpp>
#include <neb/gfx/app/__gfx_glsl.hpp>
#include <neb/gfx/app/glfw.hpp>
#include <neb/gfx/util/decl.hpp>
#include <neb/gfx/window/Base.hh>
#include <neb/gfx/window/util/Parent.hh>
#include <neb/gfx/gui/layout/util/parent.hpp>

#include <neb/phx/app/base.hpp>

#include <neb/fin/app/glfw.hpp>

#include <neb/fin/core/scene/util/decl.hpp>

namespace neb { namespace fin { namespace app {
	/** @brief Base
	 *
	 * final implementation
	 */
	class base:
		virtual public neb::core::app::base,
		virtual public neb::gfx::app::__gfx,
		virtual public neb::gfx::app::__gfx_glsl,
		virtual public neb::fin::app::glfw,
		virtual public neb::phx::app::base,
		virtual public neb::gfx::gui::layout::util::parent
	{
		public:
			typedef std::weak_ptr<neb::core::core::scene::base>	scene_w;
			static std::shared_ptr<neb::fin::app::base>		global();
			static std::shared_ptr<neb::fin::app::base>		s_init(int ac, char ** av);
			base();
			virtual ~base();
		protected:
			//virtual void						init();
			void							__init();
			void							initRegistry();
		public:
			neb::core::math::pose					getPose();
			neb::core::math::pose					getPoseGlobal();
			template<typename T> void				loadXml(std::string filename, gal::stl::wrapper<T>& w)
			{
			}
			void							release();
			virtual void						step(gal::etc::timestep const & ts);
			void							preloop();
			void							loop();
			void							set_should_release();
			virtual std::weak_ptr<neb::core::core::scene::base>	createScene();
			virtual std::weak_ptr<neb::core::core::scene::base>	createSceneDLL(std::string);
			virtual std::weak_ptr<neb::core::gui::layout::Base>	createLayout(
					std::shared_ptr<neb::core::window::Base> window,
					std::shared_ptr<neb::core::context::Base> context);
	};
}}}

#endif

