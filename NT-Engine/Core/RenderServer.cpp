#include "RenderServer.h"

namespace NT {
    RenderServer* RenderServer::m_Instance = new RenderServer();

    RenderServer& RenderServer::GetInstance()
    {
        return *m_Instance;
    }


    void RenderServer::Init()
	{
	}

	void RenderServer::ShutDown()
	{
		if (meshs.size() != 0)
		{
			for (int i = 0; i < meshs.size(); i++)
				delete meshs[i];
		}
	}


    bool RenderServer::CreateShader(Shader& shader, const char* vertexFile, const char* fragmentFile, const char* geometryFile)
    {
        shader.Generate(vertexFile, fragmentFile, geometryFile);
        return true;
    }

    bool RenderServer::CreateTexture(Texture& texture, const char* fileName, TextureInfo texInfo)
    {
        texture.Generate(fileName, texInfo);
        return true;
    }

    Mesh* RenderServer::CreateCube()
	{
        return nullptr;
	}
}

