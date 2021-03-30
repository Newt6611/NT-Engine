#pragma once

namespace NT {

	class Scene 
	{
	public:
		void Init(unsigned int id);
		
		void Enable();
		void Disable();

		void Update(float ts);
		void Render();

		void ShutDown();

		inline unsigned int GetSceneId() const{ return m_Id; }

	protected:
		unsigned int m_Id;
	};
}