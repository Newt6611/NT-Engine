#include "InputServer.h"

#include "Engine.h"

namespace NT {

	bool InputServer::Init(GLFWwindow* window)
	{
		glfwSetKeyCallback(window, InputServer::KeyCallBack);

		return true;
	}

	void InputServer::ShutDown()
	{

	}

	void InputServer::KeyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			Engine::window_close = true;
	}
}