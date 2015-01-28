
#include <gal/stl/deleter.hpp>

#include <neb/gfx/context/util/Parent.hh>
#include <neb/gfx/core/light/directional.hpp>
#include <neb/gfx/core/light/point.hpp>
#include <neb/gfx/window/Base.hh>

#include <neb/fin/environ/two.hpp>
#include <neb/fin/environ/VisDepth.hpp>
#include <neb/fin/environ/NormalMap.hpp>
#include <neb/fin/environ/SceneDefault.hpp>
#include <neb/fin/environ/shadow/point.hpp>
#include <neb/fin/environ/shadow/spot.hpp>
#include <neb/fin/environ/shadow/directional.hpp>

#include <neb/fin/context/base.hpp>

typedef neb::fin::context::base THIS;

std::weak_ptr<neb::gfx::environ::SceneDefault>		THIS::createEnvironSceneDefault()
{
	typedef neb::fin::environ::SceneDefault E;
	
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
std::weak_ptr<neb::gfx::environ::NormalMap>		THIS::createEnvironNormalMap() {

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
std::weak_ptr<neb::gfx::environ::shadow::directional>	THIS::createEnvironShadowDirectional() {

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


