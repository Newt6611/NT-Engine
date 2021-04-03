#pragma once

#include "Mesh.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Texture2D.h"
#include <memory>

namespace NT {
	class Model 
	{
	public:
		Model() = default;
		Model(const char* path, bool gama);
		~Model();

		void Draw(Shader& shader);

	private:
		void LoadModel(std::string path);
		void ProcessNode(aiNode* node, const aiScene* scene);
		Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene);
		std::vector<std::shared_ptr<Texture>> LoadMaterialTexture(aiMaterial* material, aiTextureType type, std::string typeName);
	private:
		std::vector<std::shared_ptr<Texture>> m_Texture_loaded;
		std::vector<Mesh> m_Meshs;
		std::string m_Directory;
		bool gammaCorrection;
	};
}