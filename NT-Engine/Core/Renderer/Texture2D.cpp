#include "Texture2D.h"

Texture::~Texture()
{
	glDeleteTextures(1, &id);
}

void Texture::Generate(const char* fileName, TextureInfo texInfo)
{
	stbi_set_flip_vertically_on_load(true);
	int w, h, c;
	unsigned char* data = stbi_load(fileName, &w, &h, &c, 0);
	
	glGenTextures(1, &id);
	
	if (data)
	{
		// Generate 
		m_Width = w;
		m_Height = h;
		this->info = info;
		this->path = fileName;

		unsigned int format = 0;
		if (c == 1)
			format = GL_RED;
		else if (c == 3)
			format = GL_RGB;
		else if (c == 4)
			format = GL_RGBA;

		glBindTexture(GL_TEXTURE_2D, id);

		glTexImage2D(GL_TEXTURE_2D, 0, format, m_Width, m_Height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, info.Wrap_S);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, info.Wrap_T);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, info.Filter_Min);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, info.Filter_Min);
		glBindTexture(GL_TEXTURE_2D, 0);
		stbi_image_free(data);
	}
	else
		std::cout << "Generate Texture Error ! " << fileName << std::endl;
}

void Texture::Bind(unsigned int slot = 0) const
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, id);
	std::cout << glGetError() << std::endl;
}
