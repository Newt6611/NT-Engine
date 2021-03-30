#include "SceneServer.h"

namespace NT {
	void SceneServer::Init() 
	{
		Scene default_scene;
		current_scene = &default_scene;
		PushScene(&default_scene);
	}

	void SceneServer::ShutDown()
	{
		for (int i = 0; i < scenes.size(); i++) 
		{
			scenes[i]->ShutDown();
			delete scenes[i];
		}
	}

	void SceneServer::PushScene(Scene* scene)
	{
		scene->Init(scene_id);
		scenes.push_back(scene);
		scene_id++;
	}

	bool SceneServer::LoadScene(unsigned int scene_id)
	{
		for (int i = 0; i < scenes.size(); i++)
		{
			if (i + 1 == scene_id) 
			{
				current_scene->Disable();
				current_scene = scenes[i];
				current_scene->Enable();
				return true;
			}
		}

		return false;
	}

	void SceneServer::Update(float ts)
	{
		current_scene->Update(ts);
	}

	void SceneServer::Render()
	{
		current_scene->Render();
	}
}