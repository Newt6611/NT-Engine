#pragma once

#include "DisplayServer.h"
#include "InputServer.h"


namespace NT {

	class Engine
	{
	public:
		bool Init(unsigned int width, unsigned int height);
		void Run();
		void ShutDown();


	public:
		static bool window_close;

	private:
		DisplayServer display_server;
		InputServer input_server;
	};
}
