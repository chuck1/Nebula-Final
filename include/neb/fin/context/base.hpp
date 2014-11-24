#ifndef NEBULA_FIN_CONTEXT_BASE_HH
#define NEBULA_fin_CONTEXT_BASE_HH

#include <neb/gfx/context/Base.hh>

namespace neb { namespace fin { namespace context {
	/** @brief Context
	*/
	class base:
		virtual public neb::gfx::context::base
	{
		public:
			typedef neb::gfx::context::util::parent parent_t;

			virtual std::weak_ptr<neb::gfx::environ::two>			createEnvironTwo();
			virtual std::weak_ptr<neb::gfx::environ::SceneDefault>		createEnvironSceneDefault();
			virtual std::weak_ptr<neb::gfx::environ::NormalMap>		createEnvironNormalMap();
			virtual std::weak_ptr<neb::gfx::environ::shadow::point>		createEnvironShadowPoint();
			virtual std::weak_ptr<neb::gfx::environ::shadow::directional>	createEnvironShadowDirectional();
			virtual std::weak_ptr<neb::gfx::environ::vis_depth>		createEnvironVisDepth();
	};

}}}

#endif


