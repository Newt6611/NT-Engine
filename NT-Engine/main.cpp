
#include "../Core/NT.h"

int main()
{
	NT::Engine engine;

	if (engine.Init(1280, 760))
	{
		engine.Run();
	}
	else 
	{
		std::cout << "Engine Init Error" << std::endl;
	}
	
	engine.ShutDown();

	return 0;
}