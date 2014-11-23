#ifndef NEB_FINAL_GFX_PHX_CORE_SCENE_BASE_HPP
#define NEB_FINAL_GFX_PHX_CORE_SCENE_BASE_HPP

#include <neb/core/core/actor/util/decl.hpp>

#include <neb/gfx/RenderDesc.hpp>

#include <neb/phx/core/scene/base.hpp>

#include <neb/fin/core/actor/util/decl.hpp>

typedef std::weak_ptr<neb::core::core::actor::base> wbase;

namespace neb { namespace fin { namespace core { namespace scene {
	/***/
	class base:
		virtual public phx::core::scene::base
	{
		public:
			base();
			virtual void			init(parent_t * const & p);
			virtual void			release();
			virtual void			step(gal::etc::timestep const & ts);
			/***/
			virtual void			load(boost::archive::polymorphic_iarchive & ar, unsigned int const & version);
			virtual void			save(boost::archive::polymorphic_oarchive & ar, unsigned int const & version) const;
			BOOST_SERIALIZATION_SPLIT_MEMBER();
			/***/
			void				drawPhysxVisualization(
					neb::gfx::RenderDesc const & desc);
			/***/
			virtual wbase			createActorBase(neb::core::math::pose);
			virtual wbase			createActorRigidStaticUninitialized();
			/***/
			virtual wbase			createActorRigidDynamic(neb::core::core::actor::rigiddynamic::desc const * const &);
			/***/
			virtual wbase			createActorRigidDynamicUninitialized();
	};
}}}}

#endif

