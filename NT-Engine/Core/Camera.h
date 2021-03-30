#pragma once

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace NT {

	class Camera 
	{
	public:
		Camera(glm::vec3 position, glm::vec3 target);
		Camera(glm::vec3 position, float pitch, float yaw);

		glm::mat4 GetViewMatrix() const;

	public:
		glm::vec3 position;
		glm::vec3 world_up = glm::vec3(0, 1, 0);
		glm::vec3 right;
		glm::vec3 up;

	private:
		glm::vec3 m_Forward;

	};
}