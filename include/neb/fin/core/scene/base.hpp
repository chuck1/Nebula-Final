#ifndef NEB_FINAL_GFX_PHX_CORE_SCENE_BASE_HPP
#define NEB_FINAL_GFX_PHX_CORE_SCENE_BASE_HPP

#include <neb/core/core/actor/util/decl.hpp>

#include <neb/gfx/RenderDesc.hpp>
#include <neb/gfx/core/scene/base.hpp>

#include <neb/phx/core/scene/base.hpp>

#include <neb/fin/core/actor/util/decl.hpp>
#include <neb/fin/tmp/Child.hpp>

typedef std::weak_ptr<neb::fnd::core::actor::base> wbase;

namespace neb { namespace fin { namespace core { namespace scene {
	/***/
	class base:
		virtual public neb::phx::core::scene::base,
		virtual public neb::gfx::core::scene::base,
		virtual public neb::fin::tmp::Child<neb::fnd::core::scene::util::parent>
	{
		public:
			base();
			virtual void			init(parent_t * const & p);
			virtual void			release();
			virtual void			step(gal::etc::timestep const & ts);
		protected:
			void				__init(parent_t * const & p);
			void				__release();
			void				__step(gal::etc::timestep const & ts);
		public:
			/***/
			virtual void			load(boost::archive::polymorphic_iarchive & ar, unsigned int const & version);
			virtual void			save(boost::archive::polymorphic_oarchive & ar, unsigned int const & version) const;
			BOOST_SERIALIZATION_SPLIT_MEMBER();
			/***/
			void				drawPhysxVisualization(
					neb::gfx::RenderDesc const & desc);
			/***/
			virtual wbase			createActorBase(neb::fnd::math::pose);
			virtual wbase			createActorRigidStaticUninitialized();
			/***/
			virtual wbase			createActorRigidDynamic();
			virtual wbase			createActorRigidDynamic(neb::fnd::core::actor::rigiddynamic::Desc const * const &);
			/***/
			virtual wbase			createActorRigidDynamicUninitialized();
	};
}}}}

#endif

