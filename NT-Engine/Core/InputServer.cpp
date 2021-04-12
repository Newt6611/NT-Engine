#include "InputServer.h"
#include "RenderServer.h"
#include "Engine.h"

namespace NT {
	// InputServer Class
	Camera* InputServer::viewCamera;
	bool InputServer::firstMouse;
	double InputServer::lastX;
	double InputServer::lastY;

	InputServer* InputServer::m_Instance = 0;

	InputServer* InputServer::GetInstance()
	{
		if (m_Instance == 0)
		{
			m_Instance = new InputServer();
			return m_Instance;
		}
		return m_Instance;
	}

	void InputServer::Init(GLFWwindow* window, Camera* viewCamera)
	{
		glfwSetKeyCallback(window, InputServer::KeyCallBack);
		glfwSetCursorPosCallback(window, InputServer::MousePositionCallBack);

		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

		this->viewCamera = viewCamera;

		firstMouse = true;
	}

	void InputServer::ShutDown()
	{

	}

	void InputServer::KeyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			Engine::window_close = true;

		if (key >= 0 && key <= 1024 && action == GLFW_PRESS)
			Input::keys[key] = true;

		if (key >= 0 && key <= 1024 && action == GLFW_RELEASE)
		{
			Input::keys[key] = false;
			Input::keyUp[key] = false;
		}

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

		viewCamera->ProcessCursorMovement(deltaX, deltaY);
		
		lastX = xPos;
		lastY = yPos;
	}


	// Ipnut Class
	float Input::mouseDeltaX;
	float Input::mouseDeltaY;
	bool Input::keys[1024];
	bool Input::keyUp[1024];

	bool Input::GetKey(unsigned int key)
	{
		return keys[key];
	}

	bool Input::GetKeyDown(unsigned int key)
	{
		if (!keyUp[key] && keys[key])
		{
			keyUp[key] = true;
			return true;
		}
		else
			return false;
	}
}