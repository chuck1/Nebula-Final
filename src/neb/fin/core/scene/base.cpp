//#include <neb/fin/gfx_phx/util/log.hpp>

#include <gal/stl/deleter.hpp>

#include <neb/fnd/util/log.hpp>
#include <neb/fnd/plug/gfx/core/scene/Base.hpp>

/*
#include <neb/gfx/RenderDesc.hpp>
#include <neb/gfx/camera/proj/base.hpp>
#include <neb/gfx/camera/view/Base.hpp>
#include <neb/gfx/free.hpp>
*/

#include <neb/phx/util/log.hpp>

#include <neb/fin/app/base.hpp>
#include <neb/fin/core/actor/rigidstatic/base.hpp>
#include <neb/fin/core/actor/rigiddynamic/base.hpp>
#include <neb/fin/core/scene/base.hpp>

typedef neb::fin::core::scene::base THIS;

typedef weak_ptr<neb::fnd::core::actor::base>			wbase;

THIS::base()
{
}
void			THIS::init(parent_t * const & p)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	setParent(p);
	
	neb::fnd::core::scene::base::__init(p);
	neb::phx::core::scene::base::__init(p);
	//neb::gfx::core::scene::base::__init(p);
}
void			THIS::release()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	neb::fnd::core::scene::base::__release();
	neb::phx::core::scene::base::__release();
	//neb::gfx::core::scene::base::__release();
}
void			THIS::step(gal::etc::timestep const & ts)
{
	//std::cout << __PRETTY_FUNCTION__ << std::endl;
	neb::fnd::core::scene::base::step(ts);
	neb::phx::core::scene::base::step(ts);
}
void			THIS::__init(parent_t * const & p)
{
}
void			THIS::__release()
{
}
void			THIS::__step(gal::etc::timestep const & ts)
{
}
wbase		neb::fin::core::scene::base::createActorBase(neb::fnd::math::pose pose)
{

	auto self(dynamic_pointer_cast<neb::fin::core::scene::base>(shared_from_this()));

	typedef neb::fin::core::actor::base T;

	std::shared_ptr<T> actor(new T(), gal::stl::deleter<T>());

	actor->pose_ = pose;

	insert(actor);

	actor->init(this);

	return actor;
}
wbase		neb::fin::core::scene::base::createActorRigidStaticUninitialized()
{
	LOG(lg, neb::fnd::core::scene::sl, debug) << __PRETTY_FUNCTION__;

	auto self(dynamic_pointer_cast<neb::fin::core::scene::base>(shared_from_this()));

	typedef neb::fin::core::actor::rigidstatic::base T;

	std::shared_ptr<T> actor(new T(), gal::stl::deleter<T>());

	neb::fnd::core::actor::util::parent::insert_no_init(actor);
	
	// filtering
	actor->simulation_.word0 = phx::filter::filter::type::STATIC;
	actor->simulation_.word1 = phx::filter::filter::RIGID_AGAINST;
	actor->simulation_.word2 = phx::filter::filter::type::STATIC;
	actor->simulation_.word3 = phx::filter::filter::type::PROJECTILE;

	return actor;
}
wbase		neb::fin::core::scene::base::createActorRigidDynamicUninitialized()
{
	LOG(lg, neb::fnd::core::scene::sl, debug) << __PRETTY_FUNCTION__;

	auto self(dynamic_pointer_cast<neb::fin::core::scene::base>(shared_from_this()));

	typedef neb::fin::core::actor::rigiddynamic::base T;

	std::shared_ptr<T> actor(new T(), gal::stl::deleter<T>());

	neb::fnd::core::actor::util::parent::insert(actor);

	actor->simulation_.word0 = phx::filter::filter::type::DYNAMIC;
	actor->simulation_.word1 = phx::filter::filter::RIGID_AGAINST;
	actor->simulation_.word2 = phx::filter::filter::type::DYNAMIC;
	actor->simulation_.word3 = phx::filter::filter::type::PROJECTILE;

	return actor;

}
wbase			neb::fin::core::scene::base::createActorRigidDynamic()
{
	LOG(lg, neb::fnd::core::scene::sl, debug) << __PRETTY_FUNCTION__;

	auto self(dynamic_pointer_cast<neb::fin::core::scene::base>(shared_from_this()));

	typedef neb::fin::core::actor::rigiddynamic::base T;

	std::shared_ptr<T> actor(new T(), gal::stl::deleter<T>());

	neb::fnd::core::actor::util::parent::insert(actor);

	actor->simulation_.word0 = phx::filter::filter::type::DYNAMIC;
	actor->simulation_.word1 = phx::filter::filter::RIGID_AGAINST;
	actor->simulation_.word2 = phx::filter::filter::type::DYNAMIC;
	actor->simulation_.word3 = phx::filter::filter::type::PROJECTILE;

	actor->init(this);

	return actor;
}
wbase			neb::fin::core::scene::base::createActorRigidDynamic(
		neb::fnd::core::actor::rigiddynamic::Desc const * const & desc)
{
	LOG(lg, neb::fnd::core::scene::sl, debug) << __PRETTY_FUNCTION__;

	auto self(dynamic_pointer_cast<neb::fin::core::scene::base>(shared_from_this()));

	typedef neb::fin::core::actor::rigiddynamic::base T;

	std::shared_ptr<T> actor(new T(), gal::stl::deleter<T>());

	neb::fnd::core::actor::util::parent::insert(actor);

	actor->simulation_.word0 = phx::filter::filter::type::DYNAMIC;
	actor->simulation_.word1 = phx::filter::filter::RIGID_AGAINST;
	actor->simulation_.word2 = phx::filter::filter::type::DYNAMIC;
	actor->simulation_.word3 = phx::filter::filter::type::PROJECTILE;

	actor->init(this);

	return actor;
}

typedef neb::fnd::core::scene::base Base1;
typedef neb::phx::core::scene::base Base2;

void		THIS::load(boost::archive::polymorphic_iarchive & ar, unsigned int const & version)
{
	LOG(lg, neb::fnd::core::scene::sl, debug) << __PRETTY_FUNCTION__;

	//BOOST_SERIALIZATION_BASE_OBJECT_NVP(Base1);
	//BOOST_SERIALIZATION_BASE_OBJECT_NVP(Base2);
	BOOST_SERIALIZATION_BASE_OBJECT_NVP(neb::fnd::core::scene::base);
	BOOST_SERIALIZATION_BASE_OBJECT_NVP(neb::phx::core::scene::base);

	neb::fnd::core::scene::base::load(ar, version);
	neb::phx::core::scene::base::load(ar, version);
}
void		THIS::save(boost::archive::polymorphic_oarchive & ar, unsigned int const & version) const
{
	LOG(lg, neb::fnd::core::scene::sl, debug) << __PRETTY_FUNCTION__;

	//BOOST_SERIALIZATION_BASE_OBJECT_NVP(Base1);
	//BOOST_SERIALIZATION_BASE_OBJECT_NVP(Base2);
	BOOST_SERIALIZATION_BASE_OBJECT_NVP(neb::fnd::core::scene::base);
	BOOST_SERIALIZATION_BASE_OBJECT_NVP(neb::phx::core::scene::base);

	neb::fnd::core::scene::base::save(ar, version);
	neb::phx::core::scene::base::save(ar, version);
}
void			THIS::drawPhysxVisualization(
		neb::fnd::RenderDesc const & desc)
{
	//auto app = get_fin_app();

	if(!flag_.all(neb::fnd::core::scene::util::flag::PHYSX_VISUALIZATION)) return;

	// visual debugging
	if(px_scene_)
	{
		// get the data

		neb::fnd::DebugBuffer db = get_debug_buffer();
		
		if(_M_graphics_object)
			_M_graphics_object->draw_debug_buffer(db);

		//auto e = neb::could_be<neb::gfx::environ::base, neb::gfx::environ::three>(context->environ_);
		//if(e)
	}
}

