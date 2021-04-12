#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Camera.h"

class Engine;

namespace NT {
	class InputServer
	{
	public:
		InputServer(const InputServer&) = delete;
		static InputServer* GetInstance();

		void Init(GLFWwindow* window, Camera* viewCamera);
		void ShutDown();

	private:
		InputServer() = default;
		static void KeyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void MousePositionCallBack(GLFWwindow* window, double xPos, double yPos);

	private:
		static InputServer* m_Instance;
		static Camera* viewCamera;
		static double lastX, lastY;
		static bool firstMouse;

	};

	class Input 
	{
	public:
		inline static float GetMouseDeltaX() { return mouseDeltaX; }
		inline static float GetMouseDeltaY() { return mouseDeltaY; }
		static bool GetKey(unsigned int key);
		static bool GetKeyDown(unsigned int key);
	private:
		static float mouseDeltaX, mouseDeltaY;
		static bool keys[1024];
		static bool keyUp[1024];
		friend class InputServer;
	};
}
