#pragma once

#include <vector>

#include "Scene.h"

namespace NT {
	class SceneServer
	{
	public:
		void Init();
		void ShutDown();

		void Update(float ts);
		void Render();

		void PushScene(Scene* scene);

		bool LoadScene(unsigned int scene_id);

		inline Scene* GetCurrentScene() const { return current_scene; }

	private:
		Scene* current_scene;
		std::vector<Scene*> scenes;

		unsigned int scene_id = 1;
	};
}