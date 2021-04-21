#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "DisplayServer.h"
#include "InputServer.h"
#include "SceneServer.h"
#include "RenderServer.h"
#include "Renderer/Material.h"
#include "Renderer/Model.h"

namespace NT {

	class Engine
	{
	public:
		Engine();
		bool Init(unsigned int width, unsigned int height);
		void Run();
		void ShutDown();

		~Engine();
	public:
		static bool window_close;

	private:
		float last_time;

		DisplayServer* display_server = nullptr;
		RenderServer* render_server = nullptr;
		InputServer* input_server = nullptr;
		SceneServer scene_server;


	private:
		Camera camera;




		// Learn FrameBuffer
		unsigned int fbo;






		// Test Cube
		Model* backpack;
		Model* sphere;
		Model* man;

		DirectionalLight d_light;

		Shader shader;
		Shader skybox_shader;
		
		Texture wall;
		Texture wall_normal;
		Material material;


		Skybox* skybox;
		std::vector<const char*> faces = {
			"res/Skybox/right.jpg",
			"res/Skybox/left.jpg",
			"res/Skybox/top.jpg",
			"res/Skybox/bottom.jpg",
			"res/Skybox/front.jpg",
			"res/Skybox/back.jpg",
		};
	};
}
