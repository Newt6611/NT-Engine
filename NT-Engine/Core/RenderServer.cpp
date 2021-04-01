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
        std::vector<glm::vec3> vertices = {
            {-0.5f, -0.5f, -0.5f, },
            { 0.5f, -0.5f, -0.5f, },
            { 0.5f,  0.5f, -0.5f, },
            { 0.5f,  0.5f, -0.5f, },
            {-0.5f,  0.5f, -0.5f, },
            {-0.5f, -0.5f, -0.5f, },

            {-0.5f, -0.5f,  0.5f, },
            { 0.5f, -0.5f,  0.5f, },
            { 0.5f,  0.5f,  0.5f, },
            { 0.5f,  0.5f,  0.5f, },
            {-0.5f,  0.5f,  0.5f, },
            {-0.5f, -0.5f,  0.5f, },

            {-0.5f,  0.5f,  0.5f, },
            {-0.5f,  0.5f, -0.5f, },
            {-0.5f, -0.5f, -0.5f, },
            {-0.5f, -0.5f, -0.5f, },
            {-0.5f, -0.5f,  0.5f, },
            {-0.5f,  0.5f,  0.5f, },

            { 0.5f,  0.5f,  0.5f, },
            { 0.5f,  0.5f, -0.5f, },
            { 0.5f, -0.5f, -0.5f, },
            { 0.5f, -0.5f, -0.5f, },
            { 0.5f, -0.5f,  0.5f, },
            { 0.5f,  0.5f,  0.5f, },

            {-0.5f, -0.5f, -0.5f, },
            { 0.5f, -0.5f, -0.5f, },
            { 0.5f, -0.5f,  0.5f, },
            { 0.5f, -0.5f,  0.5f, },
            {-0.5f, -0.5f,  0.5f, },
            {-0.5f, -0.5f, -0.5f, },

            {-0.5f,  0.5f, -0.5f, },
            { 0.5f,  0.5f, -0.5f, },
            { 0.5f,  0.5f,  0.5f, },
            { 0.5f,  0.5f,  0.5f, },
            {-0.5f,  0.5f,  0.5f, },
            {-0.5f,  0.5f, -0.5f, }
        };
        
        std::vector<glm::vec3> normal = {
           {  0.0f,  0.0f, -1.0f },
           {  0.0f,  0.0f, -1.0f },
           {  0.0f,  0.0f, -1.0f },
           {  0.0f,  0.0f, -1.0f },
           {  0.0f,  0.0f, -1.0f },
           {  0.0f,  0.0f, -1.0f },
                     
           {  0.0f,  0.0f,  1.0f },
           {  0.0f,  0.0f,  1.0f },
           {  0.0f,  0.0f,  1.0f },
           {  0.0f,  0.0f,  1.0f },
           {  0.0f,  0.0f,  1.0f },
           {  0.0f,  0.0f,  1.0f },
                     
           { -1.0f,  0.0f,  0.0f },
           { -1.0f,  0.0f,  0.0f },
           { -1.0f,  0.0f,  0.0f },
           { -1.0f,  0.0f,  0.0f },
           { -1.0f,  0.0f,  0.0f },
           { -1.0f,  0.0f,  0.0f },
                     
           {  1.0f,  0.0f,  0.0f },
           {  1.0f,  0.0f,  0.0f },
           {  1.0f,  0.0f,  0.0f },
           {  1.0f,  0.0f,  0.0f },
           {  1.0f,  0.0f,  0.0f },
           {  1.0f,  0.0f,  0.0f },

           {  0.0f, -1.0f,  0.0f },
           {  0.0f, -1.0f,  0.0f },
           {  0.0f, -1.0f,  0.0f },
           {  0.0f, -1.0f,  0.0f },
           {  0.0f, -1.0f,  0.0f },
           {  0.0f, -1.0f,  0.0f },

           {  0.0f,  1.0f,  0.0f },
           {  0.0f,  1.0f,  0.0f },
           {  0.0f,  1.0f,  0.0f },
           {  0.0f,  1.0f,  0.0f },
           {  0.0f,  1.0f,  0.0f },
           {  0.0f,  1.0f,  0.0f }
        };

        
        /*std::vector<unsigned int> indices = {
            // front
            0, 1, 2,
            2, 3, 0,
            // right
            1, 5, 6,
            6, 2, 1,
            // back
            7, 6, 5,
            5, 4, 7,
            // left
            4, 0, 3,
            3, 7, 4,
            // bottom
            4, 5, 1,
            1, 0, 4,
            // top
            3, 2, 6,
            6, 7, 3
        };*/

        std::vector<Vertex> vertexs;
        for (int i = 0; i < vertices.size(); i++)
        {
            Vertex v;
            v.Position = vertices[i];
            v.Normal = normal[i];

            vertexs.push_back(v);
        }

        Mesh* m = new Mesh();
        m->SetVertices(vertexs);
        m->SetUp();
        meshs.push_back(m);
        return m;
	}
}

