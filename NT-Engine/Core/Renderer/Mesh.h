#pragma once

#include "glad/glad.h"

#include "glm/glm.hpp"

#include <vector>
#include <iostream>

namespace NT {

	struct Vertex 
	{
		glm::vec3 Position;
		glm::vec3 Normal;
	};

	class Mesh 
	{
	public:
		Mesh() = default;
		inline void SetVertices(std::vector<Vertex>& v) { this->m_Vertices = v; }
		inline void SetIndices(std::vector<unsigned int>& i) { this->m_Indices = i; }

		void SetUp();
		void Draw();

	private:
		unsigned int vao, vbo, ibo;

		std::vector<Vertex> m_Vertices;
		std::vector<unsigned int> m_Indices;
	};
}
