#ifndef __NEBULA_APP_H__
#define __NEBULA_APP_H__

#include <fstream>

#include <boost/archive/polymorphic_xml_iarchive.hpp>

//#include <ft2build.h>
//#include FT_FREETYPE_H

#include <gal/itf/shared.hpp>
#include <gal/stl/wrapper.hpp>

#include <neb/core/app/Base.hpp>
#include <neb/core/core/scene/util/parent.hpp>
#include <neb/core/core/shape/util/decl.hpp>
#include <neb/core/util/wrapper.hpp>
#include <neb/core/util/decl.hpp>

#include <neb/gfx/app/base.hpp>
#include <neb/gfx/util/decl.hpp>
#include <neb/gfx/window/Base.hpp>
#include <neb/gfx/window/util/Parent.hpp>
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
		virtual public neb::fnd::app::Base,
		virtual public neb::gfx::app::Base,
		virtual public neb::gfx::gui::layout::util::parent,
		virtual public neb::fin::app::glfw,
		virtual public neb::phx::app::base
	{
		public:
			typedef std::weak_ptr<neb::fnd::core::scene::base>	scene_w;
			static std::shared_ptr<neb::fin::app::base>		global();
			static std::shared_ptr<neb::fin::app::base>		s_init(int ac, char ** av);
			base();
			virtual ~base();
		protected:
			//virtual void						init();
			void							__init();
			void							initRegistry();
			void							read_config();
		public:
			neb::fnd::math::pose					getPose();
			neb::fnd::math::pose					getPoseGlobal();
			template<typename T> void				loadXml(std::string filename, gal::stl::wrapper<T>& w)
			{
			}
			void							release();
			virtual void						step(gal::etc::timestep const & ts);
			virtual void						render();
			void							preloop();
			void							loop();
			void							set_should_release();
			virtual std::weak_ptr<neb::fnd::core::scene::base>	createScene();
			virtual std::weak_ptr<neb::fnd::core::scene::base>	createSceneDLL(std::string);
			virtual std::weak_ptr<neb::fnd::gui::layout::Base>	createLayout(
					std::shared_ptr<neb::fnd::window::Base> window,
					std::shared_ptr<neb::fnd::context::Base> context);
	};
}}}

#endif

