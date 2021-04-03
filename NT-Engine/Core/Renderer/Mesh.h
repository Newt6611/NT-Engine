#pragma once

#include "glad/glad.h"

#include "glm/glm.hpp"
#include "Shader.h"
#include "Texture2D.h"
#include <vector>
#include <iostream>
#include <string>
#include <memory>

// Model Loading From LearnOpenGL Website

namespace NT {

	struct Vertex 
	{
		glm::vec3 Position;
		glm::vec3 Normal;
		glm::vec2 TexCoords;
		glm::vec3 Tangent;
		glm::vec3 Bitangent;
	};

	class Mesh 
	{
	public:
		Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<std::shared_ptr<Texture>> textures);
		
		void Draw(Shader& shader);
	
	private:
		void SetUp();

	private:
		unsigned int m_Vao, m_Vbo, m_Ibo;

		std::vector<Vertex> m_Vertices;
		std::vector<unsigned int> m_Indices;
		std::vector<std::shared_ptr<Texture>> m_Textures;
	};
}
