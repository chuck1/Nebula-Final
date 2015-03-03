#ifndef NEB_FIN_CORE_ACTOR_RIGIDDYNAMIC_BASE_HPP
#define NEB_FIN_CORE_ACTOR_RIGIDDYNAMIC_BASE_HPP

#include <neb/fnd/core/actor/rigiddynamic/Base.hpp>

//#include <neb/cfin/core/actor/util/decl.hpp>
#include <neb/fin/core/actor/rigidactor/base.hpp>

namespace neb { namespace fin { namespace core { namespace actor { namespace rigiddynamic {
		class base:
			virtual public neb::fnd::core::actor::rigiddynamic::base,
			virtual public neb::fin::core::actor::rigidactor::base
		{
			public:
				base();
				~base();
				virtual void		init(neb::fnd::core::actor::util::parent * const &);
				virtual void		release();
				virtual void		step(gal::etc::timestep const & ts);
				virtual void		createControlManual(std::shared_ptr<neb::fnd::input::source> window);
				void			createControlPD();
		};
}}}}}

#endif

