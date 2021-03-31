#pragma once

#include "Renderer/Shader.h"
#include "Renderer/Texture2D.h"
#include "Renderer/Mesh.h"
#include "Camera.h"

namespace NT {

	class RenderServer 
	{
	public:
		RenderServer() = default;
		RenderServer(const RenderServer&) = delete;
		static RenderServer& GetInstance();

		void Init();
		void ShutDown();


		bool CreateShader(Shader& shader, const char* vertexFile, const char* fragmentFile, const char* geometryFile);
		bool CreateTexture(Texture& texture, const char* fileName, TextureInfo texInfo);

		Mesh* CreateCube();


	private:
		static RenderServer* m_Instance;

		std::vector<Mesh*> meshs;
	};

}