
#include "Mesh.h"

namespace NT {

	void Mesh::SetUp()
	{
		if (m_Vertices.size() == 0)
		{
			std::cout << "You Need Init Data First !";
			return;
		}

		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);

		glGenBuffers(GL_ARRAY_BUFFER, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, m_Vertices.size() * sizeof(Vertex), &m_Vertices[0], GL_STATIC_DRAW);

		// Positions
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
		
		// Normals
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex,Normal));


		// Indices
		if (m_Indices.size() != 0)
		{
			glGenBuffers(GL_ELEMENT_ARRAY_BUFFER, &ibo);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Indices.size() * sizeof(unsigned int), &m_Indices[0], GL_STATIC_DRAW);
		}

		glBindVertexArray(0);
	}

	void Mesh::Draw()
	{
		glBindVertexArray(vao);

		if (ibo != NULL)
			glDrawElements(GL_TRIANGLES, m_Indices.size(), GL_UNSIGNED_INT, 0);
		else
			glDrawArrays(GL_TRIANGLES, 0, m_Vertices.size());

	}
}