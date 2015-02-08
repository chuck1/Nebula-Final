
#include <neb/fin/context/util/parent.hpp>

#include <neb/fin/context/Window.hpp>
#include <neb/fin/context/fbo.hpp>
#include <neb/fin/context/FBOMulti.hpp>

typedef neb::fin::context::util::parent THIS;

std::weak_ptr<neb::fnd::context::Window>	THIS::createContextWindow()
{
	//auto self = isWindowBase();
	//assert(self);
	
	return create<neb::fin::context::Window>();
	/*
	std::shared_ptr<C_W> context(new C_W());
	
	insert(context);
	
	context->init();
	
	return context;*/
}
std::weak_ptr<neb::fnd::context::FBO>		THIS::createContextFBO()
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
std::weak_ptr<neb::fnd::context::FBOM>		THIS::createContextFBOMulti()
{
	return create<neb::fin::context::FBOMulti>();
}
std::weak_ptr<neb::fnd::context::Window>	THIS::createContextVisDepth()
{
	return create<neb::fin::context::Window>();
}

