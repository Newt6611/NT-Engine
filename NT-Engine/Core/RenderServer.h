#pragma once

#include "Renderer/Shader.h"
#include "Renderer/Texture2D.h"
#include "Renderer/Mesh.h"
#include "Camera.h"
#include "Renderer/Model.h"
#include "Renderer/Skybox.h"
#include "Renderer/DirectionalLight.h"

namespace NT {

	class RenderServer 
	{
	public:
		
		RenderServer(const RenderServer&) = delete;
		static RenderServer* GetInstance();

		void Init();
		void ShutDown();


		bool CreateShader(Shader& shader, const char* vertexFile, const char* fragmentFile, const char* geometryFile);
		bool CreateTexture(Texture& texture, const char* fileName, TextureInfo texInfo);

		Model* CreateCube();
		Model* CreateSphere();
		Model* CreatePlane();
		Model* CreateModel(const char* path, bool gama);
	private:
		RenderServer() = default;

		static RenderServer* m_Instance;

		Model* cube;
		Model* sphere;
		Model* plane;

		std::vector<Model*> models;
	};

}