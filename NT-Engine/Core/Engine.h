#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "DisplayServer.h"
#include "InputServer.h"
#include "SceneServer.h"
#include "RenderServer.h"
#include "Camera.h"
#include "Renderer/Material.h"
#include "Renderer/Model.h"

namespace NT {

	class Engine
	{
	public:
		bool Init(unsigned int width, unsigned int height);
		void Run();
		void ShutDown();


	public:
		static bool window_close;

	private:
		float last_time;

		DisplayServer display_server;
		InputServer input_server;
		SceneServer scene_server;
		RenderServer render_server;


	private:
		Camera camera;

		// Test Cube
		Model* sphere;
		Shader shader;
		Texture wall;
		Texture wall_normal;
		Material material;
		glm::mat4 projection;
	};
}
