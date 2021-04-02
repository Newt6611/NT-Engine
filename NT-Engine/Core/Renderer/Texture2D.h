#pragma once

#pragma once

#include "glad/glad.h"

#include <iostream>
#include "stbi_image/stbi_image.h"

struct TextureInfo 
{
	unsigned int Wrap_S = GL_REPEAT;
	unsigned int Wrap_T = GL_REPEAT;
	unsigned int Filter_Min = GL_LINEAR;
	unsigned int Filter_Max = GL_LINEAR;
};

class Texture
{
public:
	Texture() = default;
	~Texture();

	void Generate(const char* fileName, TextureInfo texInfo);
	void Bind(unsigned int slot) const;

	inline unsigned int GetWidth() { return m_Width; }
	inline unsigned int GetHeight() { return m_Height; }

public:
	unsigned int id;
	std::string type;
	std::string path;
private:
	unsigned int m_Width, m_Height;
	TextureInfo info;
};