#ifndef NEB_FIN_ENVIRON_UTIL_PARENT_HPP
#define NEB_FIN_ENVIRON_UTIL_PARENT_HPP

#include <memory>

//#include <neb/core/environ/util/decl.hpp>

#include <neb/core/environ/util/Parent.hpp>

namespace neb { namespace fin { namespace environ { namespace util {
	class Parent:
		virtual public neb::fnd::environ::util::Parent
	{
		public:
			virtual std::weak_ptr<neb::fnd::environ::Two>				createEnvironTwo();
			virtual std::weak_ptr<neb::fnd::environ::SceneDefault>			createEnvironSceneDefault();
			virtual std::weak_ptr<neb::fnd::environ::shadow::Point>		createEnvironShadowPoint();
			virtual std::weak_ptr<neb::fnd::environ::shadow::Directional>		createEnvironShadowDirectional();
			virtual std::weak_ptr<neb::fnd::environ::visualization::Depth>		createEnvironVisualizationDepth();
			virtual std::weak_ptr<neb::fnd::environ::visualization::Normal>	createEnvironVisualizationNormal();
	};
}}}}

#endif
