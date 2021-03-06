#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace NT {
	class DisplayServer 
	{
	public:
		DisplayServer(const DisplayServer&) = delete;
		static DisplayServer* GetInstance();

		bool Init(unsigned int width, unsigned int height);
		
		void ShutDown();

		inline float GetWindowWidth() const { return static_cast<float>(m_Win_Width); }
		inline float GetWindowHeight() const { return static_cast<float>(m_Win_Height); }

	private:
		DisplayServer() = default;
		bool InitOpenGL();
		bool CreateWindow();


	public:
		GLFWwindow* window;

	private:
		static DisplayServer* m_Instance;
		unsigned int m_Win_Width;
		unsigned int m_Win_Height;
	};
}