#include "../NT-Engine/Core/Engine.h"

int main()
{
	NT::Engine engine;

	if (engine.Init(1280, 760))
	{
		engine.Run();
	}
	
	engine.ShutDown();

	return 0;
}