#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

class Engine;

namespace NT {
	class InputServer
	{
	public:
		void Init(GLFWwindow* window);
		void ShutDown();

	private:
		static void KeyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void MousePositionCallBack(GLFWwindow* window, double xPos, double yPos);

	private:
		static double lastX, lastY;
		static bool firstMouse;

	};

	class Input 
	{
	public:
		inline static float GetMouseDeltaX() { return mouseDeltaX; }
		inline static float GetMouseDeltaY() { return mouseDeltaY; }

	private:
		static float mouseDeltaX, mouseDeltaY;

		friend class InputServer;
	};
}
