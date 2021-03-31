#include "Engine.h"

namespace NT {

	bool Engine::window_close;

	bool Engine::Init(unsigned int width, unsigned int height)
	{
		// Init Servers
		if (!display_server.Init(width, height))
			return false;

		input_server.Init(display_server.window);

		scene_server.Init();

		render_server.Init();

		window_close = false;


		// Test //
		camera = Camera( { 0,0,10 }, 0, 180);
		cube = render_server.CreateCube();
		render_server.CreateShader(shader, "res/Shader/normal.vert.glsl", "res/Shader/normal.frag.glsl", NULL);
		projection = glm::perspective(glm::radians(45.0f), (float)display_server.GetWindowWidth() / display_server.GetWindowHeight(), 0.1f, 100.0f);

		return true;
	}

	void Engine::Run()
	{
		while (!window_close)
		{
			glClearColor(0, 0, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			float current_time = glfwGetTime();
			float delta = current_time - last_time;
			last_time = current_time;

			scene_server.Update(delta);

			scene_server.Render();





			// Render Test
			camera.Update(delta);

			shader.Bind();
			shader.SetMatrix4("projection", projection);
			shader.SetMatrix4("view", camera.GetViewMatrix());
			shader.SetMatrix4("model", glm::mat4(1));
			
			cube->Draw();






			glfwSwapBuffers(display_server.window);
			glfwPollEvents();
		}
	}

	void Engine::ShutDown()
	{
		glfwTerminate();

		display_server.ShutDown();
		input_server.ShutDown();
		scene_server.ShutDown();
		render_server.ShutDown();
	}
}