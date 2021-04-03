#include "Engine.h"

namespace NT {

	bool Engine::window_close;

	bool Engine::Init(unsigned int width, unsigned int height)
	{
		// Todo: Make Camera More Scence //
		camera = Camera({ 0,0,10 }, 0, 180);
		



		// Init Servers
		if (!display_server.Init(width, height))
			return false;

		input_server.Init(display_server.window, &camera);

		scene_server.Init();

		render_server.Init();

		window_close = false;


		// Test
		sphere = render_server.CreateSphere();
		TextureInfo info;
		wall.Generate("res/Texture/brickwall.jpg", info);
		wall_normal.Generate("res/Texture/brickwall_normal.jpg", info);

		render_server.CreateShader(shader, "res/Shader/default.vert.glsl", "res/Shader/default.frag.glsl", NULL);
		projection = glm::perspective(glm::radians(45.0f), (float)display_server.GetWindowWidth() / display_server.GetWindowHeight(), 0.1f, 100.0f);

		return true;
	}

	float r = 0;
	void Engine::Run()
	{
		glEnable(GL_DEPTH_TEST);
		
		while (!window_close)
		{
			glClearColor(0, 0, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			float current_time = glfwGetTime();
			float delta = current_time - last_time;
			last_time = current_time;

			scene_server.Update(delta);

			scene_server.Render();



			// Render Test
			r += 1 * delta;
			camera.Update(delta);

			shader.Bind();
			shader.SetMatrix4("projection", projection);
			shader.SetMatrix4("view", camera.GetViewMatrix());
			glm::mat4 model = glm::rotate(glm::mat4(1), r, glm::vec3(0,1,0));
			shader.SetMatrix4("model", model);

			shader.SetVector3("viewPos", camera.GetPosition());
			shader.SetVector3("lightColor", { 1,1,1 });
			shader.SetVector3("lightDir", { 1, 1, 0});

			shader.SetFloat("material.shininess", material.shininess);
			shader.SetInt("material.texture_diffuse1", 0);
			shader.SetInt("material.texture_normal1", 1);
			
			wall.Bind(0);
			wall_normal.Bind(1);

			sphere->Draw(shader);


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