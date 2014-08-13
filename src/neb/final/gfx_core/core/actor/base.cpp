#include <neb/fin/gfx_phx/core/actor/base.hpp>
#include <neb/fin/gfx_phx/core/shape/base.hpp>

weak_ptr<neb::core::shape::base>			neb::fin::gfx_phx::core::actor::base::createShapeBase(neb::core::pose pose) {
	
	auto self(dynamic_pointer_cast<neb::fin::gfx_phx::core::actor::base>(shared_from_this()));
	
	auto actor(make_shared<neb::fin::gfx_phx::core::shape::base>(self));
	
	return actor;
}

