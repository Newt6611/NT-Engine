#pragma once

#include "glm/glm.hpp"

namespace NT {
	class DirectionalLight {
	public:
		DirectionalLight() = default;
		DirectionalLight(glm::vec3 direction, glm::vec3 color = glm::vec3(1));

		glm::vec3 GetDiection() const { return m_Direction; }
		glm::vec3 GetColor() const { return m_Color; }
	private:
		glm::vec3 m_Direction;
		glm::vec3 m_Color;

	};
}