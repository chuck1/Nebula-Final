#include <gal/stl/deleter.hpp>

#include <neb/core/context/Window.hpp>
#include <neb/core/context/util/Parent.hpp>
#include <neb/core/window/Base.hpp>

#include <neb/gfx/core/light/directional.hpp>
#include <neb/gfx/core/light/point.hpp>

#include <neb/fin/environ/two.hpp>
#include <neb/fin/environ/SceneDefault.hpp>
#include <neb/fin/environ/util/Parent.hpp>
#include <neb/fin/environ/visualization/Depth.hpp>
#include <neb/fin/environ/visualization/Normal.hpp>
#include <neb/fin/environ/shadow/Directional.hpp>
#include <neb/fin/environ/shadow/Point.hpp>

typedef neb::fin::environ::util::Parent THIS;

std::weak_ptr<neb::core::environ::SceneDefault>			THIS::createEnvironSceneDefault()
{
	typedef neb::fin::environ::SceneDefault E;
	
	std::shared_ptr<E> environ(new E(), gal::stl::deleter<E>());
	
	auto c = is_fnd_context_Base();

	auto w = c->getParent()->is_fnd_window_base();
	if(w) {
		w->makeCurrent();
	}
	
	environ->init();

	c->setEnviron(environ);

	return environ;
}
std::weak_ptr<neb::core::environ::visualization::Normal>	THIS::createEnvironVisualizationNormal()
{
	typedef neb::fin::environ::visualization::Normal E;
	
	std::shared_ptr<E> environ(new E(), gal::stl::deleter<E>());

	auto c = is_fnd_context_Base();
	
	auto w = c->getParent()->is_fnd_window_base();
	if(w) {
		w->makeCurrent();
	}

	environ->init();

	c->setEnviron(environ);

	return environ;
}
std::weak_ptr<neb::core::environ::shadow::Directional>		THIS::createEnvironShadowDirectional()
{
	typedef neb::fin::environ::shadow::Directional E;

	std::shared_ptr<E> environ (new E(), gal::stl::deleter<E>());

	auto c = is_fnd_context_Base();

	auto w = c->getParent()->is_fnd_window_base();
	if(w) {
		w->makeCurrent();
	}

	environ->init();
	
	c->setEnviron(environ);
	
	return environ;
}
std::weak_ptr<neb::core::environ::Two>			THIS::createEnvironTwo()
{
	typedef neb::fin::environ::Two E;
	
	std::shared_ptr<E> environ (new E(), gal::stl::deleter<E>());

	auto c = is_fnd_context_Base();
	
	auto w = c->getParent()->is_fnd_window_base();
	if(w) {
		w->makeCurrent();
	}

	environ->init();

	c->setEnviron(environ);
	
	return environ;
}
std::weak_ptr<neb::core::environ::visualization::Depth>		THIS::createEnvironVisualizationDepth()
{
	typedef neb::fin::environ::visualization::Depth E;
	
	std::shared_ptr<E> environ (new E(), gal::stl::deleter<E>());

	auto c = is_fnd_context_Base();

	auto w = c->getParent()->is_fnd_window_base();
	if(w)
	{
		w->makeCurrent();
	}

	environ->init();
	
	c->setEnviron(environ);
	
	return environ;
}
std::weak_ptr<neb::core::environ::shadow::Point>		THIS::createEnvironShadowPoint()
{
	typedef neb::fin::environ::shadow::Point E;
	
	std::shared_ptr<E> environ (new E(), gal::stl::deleter<E>());

	auto c = is_fnd_context_Base();

	auto w = c->getParent()->is_fnd_window_base();
	if(w) w->makeCurrent();

	environ->init();
	
	c->setEnviron(environ);
	
	return environ;
}

