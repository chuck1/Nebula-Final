#ifndef NEB_FIN_WINDOW_H__
#define NEB_FIN_WINDOW_H__

#include <neb/gfx/window/Base.hh>

#include <neb/fin/context/util/parent.hpp>

namespace neb { namespace fin { namespace window {
	/***/
	class base:
		virtual public neb::gfx::window::base,
		virtual public neb::fin::context::util::parent
	{
		public:
			/*
			typedef neb::gfx::context::window C_W;

			virtual std::weak_ptr<neb::gfx::context::fbo>		createContextFBO() = 0;
			virtual std::weak_ptr<neb::gfx::context::fbo_multi>	createContextFBOMulti() = 0;
			virtual std::weak_ptr<C_W>				createContextWindow() = 0;
			virtual std::weak_ptr<C_W>				createContextVisDepth() = 0;
			*/
			/*
			   typedef neb::gfx::window::util::parent parent_t;
			   typedef neb::fnd::util::parent<neb::gfx::context::base, neb::gfx::context::util::parent> contexts;


			   base();
			   virtual ~base();
			   virtual void				init(parent_t * const & p);
			   virtual void				release();

			   virtual glm::vec2			getCursorPosNDC();

			   virtual void				render();
			   virtual void				step(gal::etc::timestep const & ts);
			   void					resize();

			   void					callback_window_pos_fun(GLFWwindow*,int,int);
			   void					callback_window_size_fun(GLFWwindow*,int,int);
			   void					callback_window_close_fun(GLFWwindow*);
			   void					callback_window_refresh_fun(GLFWwindow*);
			   void					callback_mouse_button_fun(GLFWwindow*,int,int,int);
			   void					callback_key_fun(GLFWwindow*,int,int,int,int);
			   void					callbackCharFun(GLFWwindow*,unsigned int);

			   std::weak_ptr<neb::gfx::context::window>	createContextTwo();
			   std::weak_ptr<neb::gfx::context::window>	createContextThree();
			   std::weak_ptr<neb::gfx::context::window>	createContextNormalMap();

			   void						makeCurrent();

			   void						printScreen();
			   public:
			   */
	};
}}}


#endif








