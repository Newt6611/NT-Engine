#include "Shader.h"

#include <fstream>
#include <sstream>
#include <iostream>

namespace NT {
	Shader::Shader(const char* vertFile, const char* fragFile, const char* geomeFile = NULL)
	{
		std::string vertCode, fragCode, geomeCode;

		try
		{
			std::ifstream vertexFile(vertFile);
			std::ifstream fragmentFile(fragFile);
			std::stringstream vShaderStream, fShaderStream;
			vShaderStream << vertexFile.rdbuf();
			fShaderStream << fragmentFile.rdbuf();

			vertexFile.close();
			fragmentFile.close();

			vertCode = vShaderStream.str();
			fragCode = fShaderStream.str();

			// geometry
			if (geomeFile != NULL)
			{
				std::ifstream geomeFile(geomeFile);
				std::stringstream gShaderStream;
				gShaderStream << geomeFile.rdbuf();
				geomeFile.close();
				geomeCode = gShaderStream.str();
				Compile(vertCode.c_str(), fragCode.c_str(), geomeCode.c_str());
			}
			else
				Compile(vertCode.c_str(), fragCode.c_str(), NULL);
		}
		catch (std::exception e)
		{
			std::cout << "Load Shader Failed ! " << std::endl;
		}
	}

	Shader::~Shader()
	{
		glDeleteShader(m_Id);
	}

	void Shader::Bind() const
	{
		glUseProgram(m_Id);
	}

	void Shader::UnBind() const
	{
		glUseProgram(0);
	}


	void Shader::SetInt(const char* name, int value)
	{
		glUniform1i(GetUniformCache(name), value);
	}

	void Shader::SetInt(const char* name, int count, int* value)
	{
		glUniform1iv(GetUniformCache(name), count, value);
	}

	void Shader::SetFloat(const char* name, float value)
	{
		glUniform1f(GetUniformCache(name), value);
	}

	void Shader::SetVector2(const char* name, glm::vec2 value)
	{
		glUniform2f(GetUniformCache(name), value.x, value.y);
	}

	void Shader::SetVector3(const char* name, glm::vec3 value)
	{
		glUniform3f(GetUniformCache(name), value.x, value.y, value.z);
	}

	void Shader::SetVector4(const char* name, glm::vec4 value)
	{
		glUniform4f(GetUniformCache(name), value.x, value.y, value.z, value.w);
	}

	void Shader::SetMatrix4(const char* name, glm::mat4 value)
	{
		glUniformMatrix4fv(GetUniformCache(name), 1, false, glm::value_ptr(value));
	}




	void Shader::Compile(const char* vertexCode, const char* fragmentCode, const char* geomeCode = NULL)
	{
		unsigned int sVertex, sFragment, sGeometry;

		sVertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(sVertex, 1, &vertexCode, NULL);
		glCompileShader(sVertex);
		CheckCompileError(sVertex, "VERTEX");

		sFragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(sFragment, 1, &fragmentCode, NULL);
		glCompileShader(sFragment);
		CheckCompileError(sFragment, "FRAGMENT");

		if (geomeCode != NULL)
		{
			sGeometry = glCreateShader(GL_GEOMETRY_SHADER);
			glShaderSource(sGeometry, 1, &geomeCode, NULL);
			glCompileShader(sGeometry);
			CheckCompileError(sGeometry, "GEOMETRY");
		}

		this->m_Id = glCreateProgram();
		glAttachShader(this->m_Id, sVertex);
		glAttachShader(this->m_Id, sFragment);

		if (geomeCode != NULL)
			glAttachShader(this->m_Id, sGeometry);

		glLinkProgram(this->m_Id);
		CheckCompileError(this->m_Id, "PROGRAM");

		glDeleteShader(sVertex);
		glDeleteShader(sFragment);
		if (geomeCode != NULL)
			glDeleteShader(sGeometry);
	}

	unsigned int Shader::GetUniformCache(std::string name)
	{
		if (uniformCache.find(name) == uniformCache.end())
			return uniformCache[name];
		unsigned int location = glGetUniformLocation(m_Id, name.c_str());
		uniformCache[name] = location;
		return location;
	}

	void Shader::CheckCompileError(unsigned int object, std::string type)
	{
		int success;
		char infoLog[1024];
		if (type == "PROGRAM")
		{
			glGetProgramiv(object, GL_LINK_STATUS, &success);
			if (!success)
			{
				glGetProgramInfoLog(object, 1024, NULL, infoLog);
				std::cout << "| ERROR::SHADER: Compile-time error: Type: " << type << "\n"
					<< infoLog << "\n -- --------------------------------------------------- -- "
					<< std::endl;
			}
		}
		else
		{
			glGetShaderiv(object, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(object, 1024, NULL, infoLog);
				std::cout << "| ERROR::Shader: Link-time error: Type: " << type << "\n"
					<< infoLog << "\n -- --------------------------------------------------- -- "
					<< std::endl;
			}
		}
	}
}