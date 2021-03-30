#include "Engine.h"


namespace NT {

	bool Engine::window_close;

	bool Engine::Init(unsigned int width, unsigned int height)
	{
		// Init Servers
		if (!display_server.Init(width, height))
			return false;

		if (!input_server.Init(display_server.window))
			return false;

		window_close = false;

		return true;
	}

	void Engine::Run()
	{
		while (!window_close)
		{
			glClearColor(0, 0, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);



			glfwSwapBuffers(display_server.window);
			glfwPollEvents();
		}
	}

	void Engine::ShutDown()
	{
		display_server.ShutDown();
		input_server.ShutDown();
		glfwTerminate();
	}
}