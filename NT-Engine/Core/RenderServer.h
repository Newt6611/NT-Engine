#pragma once

#include "Renderer/Shader.h"
#include "Renderer/Texture2D.h"
#include "Renderer/Mesh.h"

namespace NT {

	class RenderServer 
	{
	public:
		RenderServer(const RenderServer&) = delete;
		static RenderServer& Instance() { return m_Instance; }

		bool Init();
		void ShutDown();

		Shader& CreateShader(const char* vertexFile, const char* fragmentFile, const char* geometryFile);
		Texture& CreateTexture(const char* fileName, TextureInfo texInfo);

		Mesh* CreateCube();



	private:
		RenderServer() {}
		static RenderServer m_Instance;



		std::vector<Mesh*> meshs;
	};

}