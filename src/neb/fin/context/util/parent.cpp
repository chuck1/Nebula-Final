
#include <neb/core/context/util/Parent.hpp>

#include <neb/core/context/Window.hpp>
#include <neb/core/context/FBO.hpp>
#include <neb/core/context/FBOM.hpp>

typedef neb::fnd::context::util::Parent THIS;

std::weak_ptr<neb::fnd::context::Window>	THIS::createContextWindow()
{
	//auto self = isWindowBase();
	//assert(self);
	
	return create<neb::fnd::context::Window>();
	/*
	std::shared_ptr<C_W> context(new C_W());
	
	insert(context);
	
	context->init();
	
	return context;*/
}
std::weak_ptr<neb::fnd::context::FBO>		THIS::createContextFBO()
{

	return create<neb::fnd::context::FBO>();
/*
	auto self = isWindowBase();
	assert(self);

	std::shared_ptr<C_FBO> context(new C_FBO(self));
	
	insert(context);

	context->init();

	return context;*/
}
std::weak_ptr<neb::fnd::context::FBOM>		THIS::createContextFBOMulti()
{
	return create<neb::fnd::context::FBOM>();
}
std::weak_ptr<neb::fnd::context::Window>	THIS::createContextVisDepth()
{
	return create<neb::fnd::context::Window>();
}

