#include "DisplayServer.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>	


namespace NT {

	DisplayServer* DisplayServer::m_Instance = 0;
	
	DisplayServer* DisplayServer::GetInstance()
	{
		if (m_Instance == 0)
		{
			m_Instance = new DisplayServer();
			return m_Instance;
		}

		return m_Instance;
	}

	bool DisplayServer::Init(unsigned int width, unsigned int height)
	{
		m_Win_Width = width;
		m_Win_Height = height;

		if (!InitOpenGL())
			return false;

		return true;
	}

	void DisplayServer::ShutDown()
	{

	}

	bool DisplayServer::InitOpenGL()
	{
		if (!glfwInit())
			return false;
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		if (!CreateWindow())
			return false;
		
		// Init Glad
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			return false;
		}

		return true;
	}

	bool DisplayServer::CreateWindow()
	{
		window = glfwCreateWindow(m_Win_Width, m_Win_Height, "NT Engine", NULL, NULL);
		if (window == NULL)
		{
			std::cout << "Create Window Error ! " << std::endl;
			glfwTerminate();
			return -1;
		}

		glfwMakeContextCurrent(window);

		return true;
	}
}