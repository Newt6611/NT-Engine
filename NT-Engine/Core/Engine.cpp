#include "Engine.h"


namespace NT {
	bool Engine::window_close;

	// must init display server before camera
	bool Engine::Init(unsigned int width, unsigned int height)
	{
		// Init Servers
		display_server = DisplayServer::GetInstance();
		render_server = RenderServer::GetInstance();
		input_server = InputServer::GetInstance();
		
		if (!display_server->Init(width, height))
			return false;

		// Todo: Make Camera More Scence //
		camera = Camera({ 0,0,10 }, 0, 180);

		render_server->Init();


		input_server->Init(display_server->window, &camera);


		scene_server.Init();

		window_close = false;


		// Test
		backpack = render_server->CreateModel("res/Model/backpack/backpack.obj", false);
		sphere = render_server->CreateSphere();
		TextureInfo info;
		wall.Generate("res/Texture/brickwall.jpg", info);
		wall_normal.Generate("res/Texture/brickwall_normal.jpg", info);

		skybox = new Skybox(faces);
		render_server->CreateShader(shader, "res/Shader/default.vert.glsl", "res/Shader/default.frag.glsl", NULL);
		render_server->CreateShader(skybox_shader, "res/Shader/skybox.vert.glsl", "res/Shader/skybox.frag.glsl", NULL);
		
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
			shader.SetMatrix4("projection", camera.GetProjection());
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
			
			skybox->Draw(skybox_shader, camera);

			glfwSwapBuffers(display_server->window);
			glfwPollEvents();
		}
	}

	void Engine::ShutDown()
	{
		glfwTerminate();

		display_server->ShutDown();
		render_server->ShutDown();
		input_server->ShutDown();
		scene_server.ShutDown();
	}


	Engine::~Engine()
	{
		delete display_server;
		delete render_server;
		delete input_server;
	}
}