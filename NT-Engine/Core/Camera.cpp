#include "Camera.h"
#include "InputServer.h"
#include "DisplayServer.h"
#include <iostream>
namespace NT {


	Camera::Camera(glm::vec3 position, glm::vec3 target)
		: pitch(0), yaw(0)
	{
		this->position = position;
		this->m_Forward = glm::normalize(target - position);

		this->right = glm::normalize(glm::cross(m_Forward, world_up));
		this->up = glm::normalize(glm::cross(m_Forward, right));
		
		m_Projection = glm::perspective(glm::radians(45.0f), DisplayServer::GetInstance()->GetWindowWidth() / DisplayServer::GetInstance()->GetWindowHeight(), 0.1f, 100.0f);
	}

	Camera::Camera(glm::vec3 position, float pitch, float yaw)
	{
		this->position = position;
		
		this->pitch = glm::radians(pitch);
		this->yaw = glm::radians(yaw);

		UpdateCameraVector();
		m_Projection = glm::perspective(glm::radians(45.0f), DisplayServer::GetInstance()->GetWindowWidth() / DisplayServer::GetInstance()->GetWindowHeight(), 0.1f, 100.0f);
	}

	glm::mat4 Camera::GetViewMatrix() const
	{
		return glm::lookAt(position, position + m_Forward, world_up);
	}

	glm::mat4 Camera::GetProjection() const
	{
		return m_Projection;
	}

	void Camera::Update(float ts)
	{
		if (Input::GetKey(GLFW_KEY_W))
			position += this->m_Forward * 5.f * ts;
		if (Input::GetKey(GLFW_KEY_S))
			this->position -= this->m_Forward * 5.f * ts;
		if (Input::GetKey(GLFW_KEY_D))
			this->position += this->right * 5.f * ts;
		if (Input::GetKey(GLFW_KEY_A))
			this->position -= this->right * 5.f * ts;

		if (Input::GetKey(GLFW_KEY_LEFT_SHIFT))
			this->position += this->up * 6.f * ts;
		if (Input::GetKey(GLFW_KEY_SPACE))
			this->position -= this->up * 6.f * ts;
	}

	void Camera::ProcessCursorMovement(float deltaX, float deltaY)
	{
		this->pitch -= deltaY * 0.003f;
		this->yaw -= deltaX * 0.003f;
		UpdateCameraVector();
	}


	void Camera::UpdateCameraVector()
	{
		m_Forward.x = glm::cos(this->pitch) * glm::sin(this->yaw);
		m_Forward.y = glm::sin(this->pitch);
		m_Forward.z = glm::cos(this->pitch) * glm::cos(this->yaw);

		this->right = glm::normalize(glm::cross(m_Forward, world_up));
		this->up = glm::normalize(glm::cross(m_Forward, right));
	}
}


