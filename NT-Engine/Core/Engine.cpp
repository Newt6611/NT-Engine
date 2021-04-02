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
		wood.Generate("res/Texture/wood.png", info);
		render_server.CreateShader(shader, "res/Shader/default.vert.glsl", "res/Shader/default.frag.glsl", NULL);
		projection = glm::perspective(glm::radians(45.0f), (float)display_server.GetWindowWidth() / display_server.GetWindowHeight(), 0.1f, 100.0f);
		material.albedo = {0.5,0,0};
		material.diffuse = { 0.5,0.0,0.0 };
		material.specular = { 0.7,0.6,0.6 };
		return true;
	}

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
			camera.Update(delta);

			shader.Bind();
			shader.SetMatrix4("projection", projection);
			shader.SetMatrix4("view", camera.GetViewMatrix());
			shader.SetMatrix4("model", glm::mat4(1));

			shader.SetVector3("viewPos", camera.GetPosition());
			shader.SetVector3("lightColor", { 1,1,1 });
			shader.SetVector3("lightDir", { 1, 1, -1 });
			shader.SetVector3("material.albedo", material.albedo);
			shader.SetVector3("material.diffuse", material.diffuse);
			shader.SetVector3("material.specular", material.specular);
			shader.SetFloat("material.shininess", material.shininess);
			
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