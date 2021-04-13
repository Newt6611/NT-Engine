#include "DirectionalLight.h"


namespace NT {
	DirectionalLight::DirectionalLight(glm::vec3 direction, glm::vec3 color)
		: m_Direction(direction), m_Color(color)
	{}
}