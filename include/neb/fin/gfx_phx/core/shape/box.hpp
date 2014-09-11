#ifndef NEB_FIN_GFX_PHX_CORE_SHAPE_BOX_HPP
#define NEB_FIN_GFX_PHX_CORE_SHAPE_BOX_HPP

#include <neb/phx/core/shape/box.hpp>

#include <neb/gfx/core/shape/box.hpp>

#include <neb/fin/gfx_phx/core/shape/base.hpp>

namespace neb { namespace fin { namespace gfx_phx { namespace core { namespace shape {
	
	class box:
		virtual public neb::gfx::core::shape::box,
		virtual public phx::core::shape::box,
		virtual public neb::fin::gfx_phx::core::shape::base
	{
		public:
			box();
			virtual ~box();
			virtual void						init(neb::core::core::shape::util::parent * const &);
			virtual void						release();
			virtual void						step(gal::etc::timestep const & ts);


	};
}}}}}

#endif



