#include "RenderServer.h"

namespace NT {
    RenderServer* RenderServer::m_Instance = 0;

    RenderServer* RenderServer::GetInstance()
    {
        if (m_Instance == 0)
        {
            m_Instance = new RenderServer;
            return m_Instance;
        }
        return m_Instance;
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
        for (int i = 0; i < models.size(); i++)
            delete models[i];
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

    Model* RenderServer::CreateModel(const char* filePath, bool gama = false)
    {
        Model* model = new Model(filePath, gama);
        return model;
    }
}

