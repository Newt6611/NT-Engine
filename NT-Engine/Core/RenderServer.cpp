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
        ///////////////
        /// For Test //
        ///////////////
        
        float vertices[] = {
            -1.0f, -1.0f, -1.0f,
            -1.0f, -1.0f,  1.0f,
            -1.0f,  1.0f,  1.0f,
            1.0f, 1.0f,-1.0f, 
            -1.0f,-1.0f,-1.0f,
            -1.0f, 1.0f,-1.0f,
            1.0f,-1.0f, 1.0f, 
            -1.0f,-1.0f,-1.0f,
            1.0f,-1.0f,-1.0f, 
            1.0f, 1.0f,-1.0f, 
            1.0f,-1.0f,-1.0f, 
            -1.0f,-1.0f,-1.0f,
            -1.0f,-1.0f,-1.0f,
            -1.0f, 1.0f, 1.0f,
            -1.0f, 1.0f,-1.0f,
            1.0f,-1.0f, 1.0f, 
            -1.0f,-1.0f, 1.0f,
            -1.0f,-1.0f,-1.0f,
            -1.0f, 1.0f, 1.0f,
            -1.0f,-1.0f, 1.0f,
            1.0f,-1.0f, 1.0f, 
            1.0f, 1.0f, 1.0f, 
            1.0f,-1.0f,-1.0f, 
            1.0f, 1.0f,-1.0f, 
            1.0f,-1.0f,-1.0f, 
            1.0f, 1.0f, 1.0f, 
            1.0f,-1.0f, 1.0f, 
            1.0f, 1.0f, 1.0f, 
            1.0f, 1.0f,-1.0f, 
            -1.0f, 1.0f,-1.0f,
            1.0f, 1.0f, 1.0f, 
            -1.0f, 1.0f,-1.0f,
            -1.0f, 1.0f, 1.0f,
            1.0f, 1.0f, 1.0f, 
            -1.0f, 1.0f, 1.0f,
            1.0f,-1.0f, 1.0f
        };

        std::vector<Vertex> vertexs;

        for (int i = 0; i < 36*3; i+=3)
        {
            Vertex vertex;
            glm::vec3 v;
            v.x = vertices[i];
            v.y = vertices[i + 1];
            v.z = vertices[i + 2];
            vertex.Position = v;
            vertex.Normal = glm::vec3(0);
            vertexs.push_back(vertex);
        }


        Mesh* m = new Mesh();
        m->SetVertices(vertexs);
        m->SetUp();
        meshs.push_back(m);
		return m;
	}
}

