#ifndef NEB_FIN_ENVIRON_UTIL_PARENT_HPP
#define NEB_FIN_ENVIRON_UTIL_PARENT_HPP

#include <neb/core/environ/util/decl.hpp>
//#include <neb/core/util/parent.hpp>

namespace neb { namespace fin { namespace environ { namespace util {
	class Parent
		//virtual public neb::core::util::parent<neb::core::context::Base, Parent>
	{
		public:
			virtual std::weak_ptr<neb::core::environ::two>				createEnvironTwo();
			virtual std::weak_ptr<neb::core::environ::SceneDefault>			createEnvironSceneDefault();
			virtual std::weak_ptr<neb::core::environ::shadow::point>		createEnvironShadowPoint();
			virtual std::weak_ptr<neb::core::environ::shadow::directional>		createEnvironShadowDirectional();
			virtual std::weak_ptr<neb::core::environ::visualization::Depth>		createEnvironVisualizationDepth();
			virtual std::weak_ptr<neb::core::environ::visualization::Normal>	createEnvironVisualizationNormal();
	};
}}}}

#endif
