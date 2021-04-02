#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

#include <unordered_map>
#include <string>

namespace NT {
	class Shader
	{
	public:
		Shader() = default;
		~Shader();

		void Generate(const char* vertFile, const char* fragFile, const char* geomeFile);

		void Bind() const;
		void UnBind() const;
		void Compile(const char* vertexCode, const char* fragmentCode, const char* geomeCode);
		void SetInt(const char* name, int value);
		void SetFloat(const char* name, float value);
		void SetVector2(const char* name, glm::vec2 value);
		void SetVector3(const char* name, glm::vec3 value);
		void SetVector4(const char* name, glm::vec4 value);
		void SetMatrix4(const char* name, glm::mat4 value);

	private:
		unsigned int m_Id;

		void CheckCompileError(unsigned int object, std::string type);

		std::unordered_map<std::string, unsigned int> uniformCache;
		unsigned int GetUniformCache(std::string name);
	};
}