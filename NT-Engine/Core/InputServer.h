#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

class Engine;

namespace NT {
	class InputServer
	{
	public:
		bool Init(GLFWwindow* window);
		void ShutDown();

	private:
		static void KeyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);
	};
}
