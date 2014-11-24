
#include <neb/fin/context/util/parent.hpp>

#include <neb/fin/context/window.hpp>
#include <neb/fin/context/fbo.hpp>
#include <neb/fin/context/fbo_multi.hpp>

typedef neb::fin::context::util::parent THIS;

std::weak_ptr<neb::gfx::context::window>	THIS::createContextWindow()
{
	//auto self = isWindowBase();
	//assert(self);
	
	return create<neb::fin::context::window>();
	/*
	std::shared_ptr<C_W> context(new C_W());
	
	insert(context);
	
	context->init();
	
	return context;*/
}
std::weak_ptr<neb::fin::context::fbo>		THIS::createContextFBO()
{

	return create<neb::fin::context::fbo>();
/*
	auto self = isWindowBase();
	assert(self);

	std::shared_ptr<C_FBO> context(new C_FBO(self));
	
	insert(context);

	context->init();

	return context;*/
}
std::weak_ptr<neb::gfx::context::fbo_multi>	THIS::createContextFBOMulti()
{
	return create<neb::fin::context::fbo_multi>();
}
std::weak_ptr<neb::gfx::context::window>	THIS::createContextVisDepth()
{
	return create<neb::gfx::context::window>();
}

