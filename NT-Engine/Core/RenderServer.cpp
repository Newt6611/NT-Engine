#include "RenderServer.h"

namespace NT {
    RenderServer* RenderServer::m_Instance = new RenderServer();

    RenderServer& RenderServer::GetInstance()
    {
        return *m_Instance;
    }


    void RenderServer::Init()
	{
        cube = new Model("res/Model/cube/cube.obj", false);
        sphere = new Model("res/Model/sphere/sphere.obj", false);
        plane = new Model("res/Model/plane/plane.obj", false);
	}

	void RenderServer::ShutDown()
	{
        delete cube;
        delete sphere;
        delete plane;
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

    Model* RenderServer::CreateCube()
    {
        return cube;
    }

    Model* RenderServer::CreateSphere()
    {
        return sphere;
    }

    Model* RenderServer::CreatePlane()
    {
        return plane;
    }
}

