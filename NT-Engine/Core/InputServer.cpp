#include "InputServer.h"
#include "RenderServer.h"
#include "Engine.h"

namespace NT {
	// InputServer Class
	bool InputServer::firstMouse;
	double InputServer::lastX;
	double InputServer::lastY;

	void InputServer::Init(GLFWwindow* window)
	{
		glfwSetKeyCallback(window, InputServer::KeyCallBack);
		glfwSetCursorPosCallback(window, InputServer::MousePositionCallBack);

		firstMouse = true;
	}

	void InputServer::ShutDown()
	{

	}

	void InputServer::KeyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			Engine::window_close = true;
	}
	void InputServer::MousePositionCallBack(GLFWwindow* window, double xPos, double yPos)
	{
		if (firstMouse)
		{
			lastX = xPos;
			lastY = yPos;
			firstMouse = false;
		}

		double deltaX, deltaY;
		deltaX = xPos - lastX;
		deltaY = yPos - lastY;

		Input::mouseDeltaX = deltaX;
		Input::mouseDeltaX = deltaY;
		
		lastX = xPos;
		lastY = yPos;
	}


	// Ipnut Class
	float Input::mouseDeltaX;
	float Input::mouseDeltaY;
}