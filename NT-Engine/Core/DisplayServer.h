#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace NT {
	class DisplayServer 
	{
	public:
		DisplayServer() = default;
		DisplayServer(const DisplayServer&) = delete;
		static DisplayServer& GetInstance();

		bool Init(unsigned int width, unsigned int height);
		
		void ShutDown();

		inline unsigned int GetWindowWidth() const { return m_Win_Width; }
		inline unsigned int GetWindowHeight() const { return m_Win_Height; }

	private:
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