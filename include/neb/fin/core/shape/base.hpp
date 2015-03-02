#ifndef NEB_FIN_CORE_SHAPE_BASE_HPP
#define NEB_FIN_CORE_SHAPE_BASE_HPP

#include <neb/fnd/core/shape/base.hpp>

namespace neb { namespace fin { namespace core { namespace shape {
	class base:
		virtual public neb::fnd::core::shape::base
	{
		public:
			typedef neb::fnd::core::light::base LIGHT;
			//virtual std::weak_ptr<LIGHT>		createLightPoint();
			virtual std::weak_ptr<LIGHT>		createLightSpot(glm::vec3);
			virtual std::weak_ptr<LIGHT>		createLightDirectional(glm::vec3);
			virtual void	load(ba::polymorphic_iarchive & ar, unsigned int const &);
			virtual void	save(ba::polymorphic_oarchive & ar, unsigned int const &) const;
			virtual void				v_set_pose_data(
					gal::math::pose const & pose_global);
	};
}}}}

#endif

