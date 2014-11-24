
#include <gal/stl/deleter.hpp>

#include <neb/gfx/context/util/Parent.hh>
#include <neb/gfx/window/Base.hh>

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
std::weak_ptr<neb::gfx::environ::NormalMap>		neb::gfx::context::base::createEnvironNormalMap() {

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
std::weak_ptr<neb::gfx::environ::shadow::directional>	neb::gfx::context::base::createEnvironShadowDirectional() {

	typedef neb::fin::environ::shadow::directional E;

	std::shared_ptr<E> environ (new E());

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
std::weak_ptr<neb::gfx::environ::two>			neb::gfx::context::base::createEnvironTwo()
{
	auto environ = std::make_shared<neb::gfx::environ::two>();
	
	auto w = getParent()->isWindowBase();
	if(w)
	{
		w->makeCurrent();
	}

	environ->init();

	environ_ = environ;
	
	return environ;
}
std::weak_ptr<neb::gfx::environ::vis_depth>		neb::gfx::context::base::createEnvironVisDepth()
{
	auto environ = std::make_shared<neb::gfx::environ::vis_depth>();

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
std::weak_ptr<neb::gfx::environ::shadow::point>		neb::gfx::context::base::createEnvironShadowPoint()
{
	auto environ = sp::make_shared<neb::gfx::environ::shadow::point>();

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


