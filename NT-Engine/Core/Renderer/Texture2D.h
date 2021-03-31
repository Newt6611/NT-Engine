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
	unsigned int Image_Format = GL_RGB;
	unsigned int Internal_Fromat = GL_RGB;
};

class Texture
{
public:
	Texture() = default;
	~Texture();

	void Generate(const char* fileName, TextureInfo texInfo);
	void Bind(unsigned int slot = 0) const;

	inline unsigned int GetWidth() { return m_Width; }
	inline unsigned int GetHeight() { return m_Height; }

private:
	unsigned int m_Id;
	unsigned int m_Width, m_Height;
	TextureInfo info;
};