#ifndef __NEBULA_APP_H__
#define __NEBULA_APP_H__

#include <fstream>

#include <boost/archive/polymorphic_xml_iarchive.hpp>

#include <ft2build.h>
#include FT_FREETYPE_H

#include <gal/std/shared.hpp>

#include <neb/core/free.hpp>
#include <neb/core/app/__core.hpp>
#include <neb/core/scene/util/Parent.hh>
#include <neb/core/shape/util/Types.hh>
#include <neb/core/util/wrapper.hpp>
#include <neb/core/util/decl.hpp>

#include <neb/gfx/app/__gfx.hpp>
#include <neb/gfx/app/__gfx_glsl.hpp>
#include <neb/gfx/util/decl.hpp>
#include <neb/gfx/window/Base.hh>
#include <neb/gfx/window/util/Parent.hh>

#include <neb/phx/game/game/util/parent.hpp>

#include <neb/fin/gfx_phx/core/scene/util/parent.hpp>

namespace neb {
	namespace fin {
		namespace gfx_phx {
			namespace app {
				/** @brief Base
				 *
				 * final implementation
				 */
				class base:
					virtual public neb::app::__gfx,
					virtual public neb::app::__gfx_glsl,
					virtual public neb::app::__core,
					virtual public neb::fin::gfx_phx::core::scene::util::parent,
					virtual public neb::phx::game::game::util::parent
				{
					public:
						static shared_ptr<neb::fin::gfx_phx::app::base>		global();
						static shared_ptr<neb::fin::gfx_phx::app::base>		init();
					public:
						base();
						virtual ~base();
					protected:
						void							__init();
					public:
						neb::core::pose						getPose();
						neb::core::pose						getPoseGlobal();
						void							loadXml(::std::string filename, neb::std::wrapper& w);
					public:
						void							release() {}
						virtual void						step(gal::std::timestep const & ts);
						void							loop();
						void							set_should_release();
				};
			}
		}
	}
}

#endif

