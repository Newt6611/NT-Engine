#pragma once

#include "Shader.h"
#include "glm/glm.hpp"

namespace NT {
	class Material
	{
	public:
		Material() = default;
		Material(glm::vec3 albedo, glm::vec3 diffuse, glm::vec3 specular, float shininess);

	public:
		glm::vec3 albedo = glm::vec3(1);
		glm::vec3 diffuse = glm::vec3(1);
		glm::vec3 specular = glm::vec3(1);
		float shininess = 256;
	};
}