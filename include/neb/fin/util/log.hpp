#ifndef NEB_FIN_UTIL_LOG_HPP
#define NEB_FIN_UTIL_LOG_HPP

#include <gal/log/log.hpp>

namespace neb { namespace fin {
	namespace app
	{
		extern severity_level	sl;
	}
	namespace core
	{
		namespace scene {
			extern severity_level	sl;
		}
		namespace actor {
			extern severity_level	sl;
		}
		namespace shape {
			extern severity_level	sl;
		}
		namespace light {
			extern severity_level	sl;
		}
	}
	extern severity_level	sl;
}}

#endif

