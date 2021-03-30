#pragma once


#include "NT.h"

#include "glm/glm.hpp"

#include <vector>

namespace NT {

	struct Vertex 
	{
		glm::vec3 Position;
		glm::vec3 Normal;
	};

	class Mesh 
	{
	public:
		inline void SetVertices(std::vector<Vertex> v) { this->m_Vertices = v; }
		inline void SetIndices(std::vector<unsigned int> i) { this->m_indices = i; }

		void SetUp();
		void Draw();

	private:
		Mesh();

		unsigned int vao, vbo, ibo;

		std::vector<Vertex> m_Vertices;
		std::vector<unsigned int> m_Indices;
	};
}
