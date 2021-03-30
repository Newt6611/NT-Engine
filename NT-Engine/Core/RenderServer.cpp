#include "RenderServer.h"

namespace NT {

	bool RenderServer::Init()
	{
		return false;
	}

	void RenderServer::ShutDown()
	{
		if (meshs.size() != 0)
		{
			for (int i = 0; i < meshs.size(); i++)
				delete meshs[i];
		}
	}

	Shader& RenderServer::CreateShader(const char* vertexFile, const char* fragmentFile, const char* geometryFile = NULL)
	{
		Shader shader(vertexFile, fragmentFile, geometryFile);
		return shader;
	}

	Texture& RenderServer::CreateTexture(const char* fileName, TextureInfo texInfo)
	{
		Texture texture(fileName, texInfo);
		return texture;
	}

	Mesh* RenderServer::CreateCube()
	{

		return nullptr;
	}
}

