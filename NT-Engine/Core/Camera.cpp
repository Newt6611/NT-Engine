#include "Camera.h"

namespace NT {

	Camera::Camera(glm::vec3 position, glm::vec3 target)
	{
		this->position = position;
		this->m_Forward = glm::normalize(target - position);

		this->right = glm::normalize(glm::cross(m_Forward, world_up));
		this->up = glm::normalize(glm::cross(m_Forward, right));
	}

	Camera::Camera(glm::vec3 position, float pitch, float yaw)
	{
		this->position = position;
		
		pitch = glm::radians(pitch);
		yaw = glm::radians(yaw);

		m_Forward.x = glm::cos(pitch) * glm::sin(yaw);
		m_Forward.y = glm::sin(pitch);
		m_Forward.z = glm::cos(pitch) * glm::cos(yaw);

		this->right = glm::normalize(glm::cross(m_Forward, world_up));
		this->up = glm::normalize(glm::cross(m_Forward, right));
	}

	glm::mat4 Camera::GetViewMatrix() const
	{
		return glm::lookAt(position, position + m_Forward, world_up);
	}
}


