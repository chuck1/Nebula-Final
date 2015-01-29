

typedef neb::fin::context::base THIS;

std::weak_ptr<neb::core::environ::SceneDefault>		THIS::createEnvironSceneDefault()
{
	typedef neb::fin::environ::SceneDefault E;
	
	std::shared_ptr<E> environ(new E(), gal::stl::deleter<E>());

	auto w = getParent()->is_fnd_window_base();
	if(w)
	{
		w->makeCurrent();
	}

	environ->init();

	environ_ = environ;

	return environ;
}
std::weak_ptr<neb::core::environ::visualization::Normal>	THIS::createEnvironNormalMap()
{
	typedef neb::fin::environ::NormalMap E;
	
	std::shared_ptr<E> environ(new E(), gal::stl::deleter<E>());

	auto w = getParent()->isWindowBase();
	if(w)
	{
		w->makeCurrent();
	}

	environ->init();

	environ_ = environ;

	return environ;
}
std::weak_ptr<neb::gfx::environ::shadow::directional>	THIS::createEnvironShadowDirectional()
{
	typedef neb::fin::environ::shadow::directional E;

	std::shared_ptr<E> environ (new E(), gal::stl::deleter<E>());

	auto p = getParent();
	auto w = p->isWindowBase();
	if(w)
	{
		w->makeCurrent();
	}

	environ->init();
	
	environ_ = environ;
	
	return environ;
}
std::weak_ptr<neb::gfx::environ::two>			THIS::createEnvironTwo()
{
	typedef neb::fin::environ::two E;
	
	std::shared_ptr<E> environ (new E(), gal::stl::deleter<E>());

	auto w = getParent()->isWindowBase();
	if(w)
	{
		w->makeCurrent();
	}

	environ->init();

	environ_ = environ;
	
	return environ;
}
std::weak_ptr<neb::gfx::environ::vis_depth>		THIS::createEnvironVisDepth()
{
	typedef neb::fin::environ::VisDepth E;
	
	std::shared_ptr<E> environ (new E(), gal::stl::deleter<E>());

	auto p = getParent();
	auto w = p->isWindowBase();
	if(w)
	{
		w->makeCurrent();
	}

	environ->init();
	
	environ_ = environ;
	
	return environ;
}
std::weak_ptr<neb::gfx::environ::shadow::point>		THIS::createEnvironShadowPoint()
{
	typedef neb::fin::environ::shadow::point E;
	
	std::shared_ptr<E> environ (new E(), gal::stl::deleter<E>());

	auto p = getParent();
	auto w = p->isWindowBase();
	if(w)
	{
		w->makeCurrent();
	}

	environ->init();
	
	environ_ = environ;
	
	return environ;
}
