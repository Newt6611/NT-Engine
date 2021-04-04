#pragma once

#include "Texture2D.h"
#include "Shader.h"
#include "stbi_image/stbi_image.h"
#include "Camera.h"

namespace NT {
	class Skybox 
	{
	public:
		Skybox() = default;
		Skybox(std::vector<const char*> faces);
		~Skybox();

		void Draw(Shader& shader, Camera& camera);

	private:
		void InitCube();
		unsigned int m_Vao, m_Vbo, m_Ibo;
		unsigned int m_Id;
	};
}