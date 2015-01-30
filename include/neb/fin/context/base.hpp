#ifndef NEBULA_FIN_CONTEXT_BASE_HH
#define NEBULA_FIN_CONTEXT_BASE_HH

#include <neb/core/environ/util/decl.hpp>

#include <neb/gfx/context/Base.hh>

#include <neb/fin/environ/util/Parent.hpp>

namespace neb { namespace fin { namespace context {
	/** @brief Context
	*/
	class base:
		virtual public neb::gfx::context::base,
		virtual public neb::fin::environ::util::Parent
	{
		public:
			//typedef neb::gfx::context::util::parent parent_t;

			/*
			virtual std::weak_ptr<neb::core::environ::Two>				createEnvironTwo();
			virtual std::weak_ptr<neb::core::environ::SceneDefault>			createEnvironSceneDefault();
			virtual std::weak_ptr<neb::core::environ::shadow::Point>		createEnvironShadowPoint();
			virtual std::weak_ptr<neb::core::environ::shadow::Directional>		createEnvironShadowDirectional();
			virtual std::weak_ptr<neb::core::environ::visualization::Normal>	createEnvironVisualNormal();
			virtual std::weak_ptr<neb::core::environ::visualization::Depth>		createEnvironVisualDepth();
			*/
	};

}}}

#endif


