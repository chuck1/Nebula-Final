//#include <neb/fin/gfx_phx/util/log.hpp>

#include <gal/stl/deleter.hpp>

#include <neb/core/util/log.hpp>

#include <neb/gfx/RenderDesc.hpp>
#include <neb/gfx/camera/proj/base.hpp>
#include <neb/gfx/camera/view/Base.hh>
#include <neb/gfx/free.hpp>

#include <neb/phx/util/log.hpp>

#include <neb/fin/app/base.hpp>
#include <neb/fin/core/actor/rigidstatic/base.hpp>
#include <neb/fin/core/actor/rigiddynamic/base.hpp>
#include <neb/fin/core/scene/base.hpp>

typedef neb::fin::core::scene::base THIS;

typedef weak_ptr<neb::core::core::actor::base>			wbase;

THIS::base()
{
}
void			THIS::init(parent_t * const & p)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	setParent(p);
	
	neb::core::core::scene::base::__init(p);
	neb::phx::core::scene::base::__init(p);
	neb::gfx::core::scene::base::__init(p);
}
void			THIS::release()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	neb::core::core::scene::base::__release();
	neb::phx::core::scene::base::__release();
	neb::gfx::core::scene::base::__release();
}
void			THIS::step(gal::etc::timestep const & ts)
{
	//std::cout << __PRETTY_FUNCTION__ << std::endl;
	neb::core::core::scene::base::step(ts);
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
wbase		neb::fin::core::scene::base::createActorBase(neb::core::math::pose pose)
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
	LOG(lg, neb::core::core::scene::sl, debug) << __PRETTY_FUNCTION__;

	auto self(dynamic_pointer_cast<neb::fin::core::scene::base>(shared_from_this()));

	typedef neb::fin::core::actor::rigidstatic::base T;

	std::shared_ptr<T> actor(new T(), gal::stl::deleter<T>());

	neb::core::core::actor::util::parent::insert(actor);

	actor->simulation_.word0 = phx::filter::filter::type::STATIC;
	actor->simulation_.word1 = phx::filter::filter::RIGID_AGAINST;
	actor->simulation_.word2 = phx::filter::filter::type::STATIC;
	actor->simulation_.word3 = phx::filter::filter::type::PROJECTILE;

	return actor;
}
wbase		neb::fin::core::scene::base::createActorRigidDynamicUninitialized()
{
	LOG(lg, neb::core::core::scene::sl, debug) << __PRETTY_FUNCTION__;


	auto self(dynamic_pointer_cast<neb::fin::core::scene::base>(shared_from_this()));

	typedef neb::fin::core::actor::rigiddynamic::base T;

	std::shared_ptr<T> actor(new T(), gal::stl::deleter<T>());

	neb::core::core::actor::util::parent::insert(actor);

	actor->simulation_.word0 = phx::filter::filter::type::DYNAMIC;
	actor->simulation_.word1 = phx::filter::filter::RIGID_AGAINST;
	actor->simulation_.word2 = phx::filter::filter::type::DYNAMIC;
	actor->simulation_.word3 = phx::filter::filter::type::PROJECTILE;

	return actor;

}
wbase			neb::fin::core::scene::base::createActorRigidDynamic(
		neb::core::core::actor::rigiddynamic::desc const * const & desc
		)
{
	LOG(lg, neb::core::core::scene::sl, debug) << __PRETTY_FUNCTION__;


	auto self(dynamic_pointer_cast<neb::fin::core::scene::base>(shared_from_this()));

	typedef neb::fin::core::actor::rigiddynamic::base T;

	std::shared_ptr<T> actor(new T(), gal::stl::deleter<T>());

	neb::core::core::actor::util::parent::insert(actor);

	actor->simulation_.word0 = phx::filter::filter::type::DYNAMIC;
	actor->simulation_.word1 = phx::filter::filter::RIGID_AGAINST;
	actor->simulation_.word2 = phx::filter::filter::type::DYNAMIC;
	actor->simulation_.word3 = phx::filter::filter::type::PROJECTILE;

	actor->init(this);

	return actor;

}

typedef neb::core::core::scene::base Base1;
typedef neb::phx::core::scene::base Base2;

void		THIS::load(boost::archive::polymorphic_iarchive & ar, unsigned int const & version)
{
	LOG(lg, neb::core::core::scene::sl, debug) << __PRETTY_FUNCTION__;

	//BOOST_SERIALIZATION_BASE_OBJECT_NVP(Base1);
	//BOOST_SERIALIZATION_BASE_OBJECT_NVP(Base2);
	BOOST_SERIALIZATION_BASE_OBJECT_NVP(neb::core::core::scene::base);
	BOOST_SERIALIZATION_BASE_OBJECT_NVP(neb::phx::core::scene::base);

	neb::core::core::scene::base::load(ar, version);
	neb::phx::core::scene::base::load(ar, version);
}
void		THIS::save(boost::archive::polymorphic_oarchive & ar, unsigned int const & version) const
{
	LOG(lg, neb::core::core::scene::sl, debug) << __PRETTY_FUNCTION__;

	//BOOST_SERIALIZATION_BASE_OBJECT_NVP(Base1);
	//BOOST_SERIALIZATION_BASE_OBJECT_NVP(Base2);
	BOOST_SERIALIZATION_BASE_OBJECT_NVP(neb::core::core::scene::base);
	BOOST_SERIALIZATION_BASE_OBJECT_NVP(neb::phx::core::scene::base);

	neb::core::core::scene::base::save(ar, version);
	neb::phx::core::scene::base::save(ar, version);
}
void			THIS::drawPhysxVisualization(
		neb::gfx::RenderDesc const & desc)
{

	auto app(neb::gfx::app::__gfx_glsl::global().lock());

	if(!flag_.all(neb::core::core::scene::util::flag::PHYSX_VISUALIZATION)) return;

	// visual debugging
	if(px_scene_)
	{
		const physx::PxRenderBuffer& rb = px_scene_->getRenderBuffer();

		physx::PxU32 nblines = rb.getNbLines();
		const physx::PxDebugLine* lines = rb.getLines();

		physx::PxU32 nbtriangles = rb.getNbTriangles();
		const physx::PxDebugTriangle* triangles = rb.getTriangles();


		auto p = app->program_simple3_;
		p->use();


		//auto e = neb::could_be<neb::gfx::environ::base, neb::gfx::environ::three>(context->environ_);
		//if(e)
		{
			desc.p->load(p.get());
			desc.v->load(p.get());

			glClear(GL_DEPTH_BUFFER_BIT);


			LOG(lg, neb::phx::core::scene::sl, debug) << "Debug visualization";
			LOG(lg, neb::phx::core::scene::sl, debug) << "number of points    " << rb.getNbPoints();
			LOG(lg, neb::phx::core::scene::sl, debug) << "number of lines     " << nblines;
			LOG(lg, neb::phx::core::scene::sl, debug) << "number of triangles " << nbtriangles;


			GLint i_color = p->attrib_table_[neb::gfx::glsl::attribs::COLOR];

			glEnableVertexAttribArray(p->attrib_table_[neb::gfx::glsl::attribs::POSITION]);
			if(i_color > -1)
				glEnableVertexAttribArray(i_color);

			GLuint buf;
			glGenBuffers(1, &buf);
			glBindBuffer(GL_ARRAY_BUFFER, buf);


			// lines
			glBufferData(
					GL_ARRAY_BUFFER,
					sizeof(physx::PxDebugLine) * nblines,
					lines,
					GL_STREAM_DRAW
				    );

			glVertexAttribPointer(
					p->attrib_table_[neb::gfx::glsl::attribs::POSITION],
					3,
					GL_FLOAT,
					GL_FALSE,
					16,
					0);


			if(i_color > -1)
				glVertexAttribIPointer(
						p->attrib_table_[neb::gfx::glsl::attribs::COLOR],
						1,
						GL_UNSIGNED_INT,
						16,
						(GLvoid*)12);

			glDrawArrays(GL_LINES, 0, nblines * 2);

			checkerror("");

			// triangles
			glBufferData(
					GL_ARRAY_BUFFER,
					sizeof(physx::PxDebugTriangle) * nbtriangles,
					triangles,
					GL_STREAM_DRAW
				    );

			glVertexAttribPointer(
					p->attrib_table_[neb::gfx::glsl::attribs::POSITION],
					3,
					GL_FLOAT,
					GL_FALSE,
					16,
					0);


			if(i_color > -1)
				glVertexAttribIPointer(
						p->attrib_table_[neb::gfx::glsl::attribs::COLOR],
						1,
						GL_UNSIGNED_INT,
						16,
						(GLvoid*)12);

			glDrawArrays(GL_TRIANGLES, 0, nbtriangles * 3);

			checkerror("");

			// cleanup
			glDisableVertexAttribArray(p->attrib_table_[neb::gfx::glsl::attribs::POSITION]);
			if(i_color > -1)
				glDisableVertexAttribArray(p->attrib_table_[neb::gfx::glsl::attribs::COLOR]);

			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
	}
}

