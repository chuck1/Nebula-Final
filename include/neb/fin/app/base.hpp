#ifndef __NEBULA_APP_H__
#define __NEBULA_APP_H__

#include <fstream>

#include <boost/archive/polymorphic_xml_iarchive.hpp>

//#include <ft2build.h>
//#include FT_FREETYPE_H

#include <gal/itf/shared.hpp>
#include <gal/stl/wrapper.hpp>

#include <neb/fnd/app/Base.hpp>
#include <neb/fnd/core/scene/util/parent.hpp>
#include <neb/fnd/core/shape/util/decl.hpp>
#include <neb/fnd/util/wrapper.hpp>
#include <neb/fnd/util/decl.hpp>
#include <neb/fnd/environ/util/decl.hpp>


namespace neb { namespace fin { namespace app {
	/** @brief Base
	 *
	 * final implementation
	 */
	class base:
		virtual public neb::fnd::app::Base
		/*virtual public neb::gfx::app::Base,*/
		//virtual public neb::phx::app::base
	{

	};
}}}

#endif

