#include "Texture2D.h"

Texture::~Texture()
{
	glDeleteTextures(1, &m_Id);
}

void Texture::Generate(const char* fileName, TextureInfo texInfo)
{
	stbi_set_flip_vertically_on_load(true);
	int w, h, c;
	unsigned char* data = stbi_load(fileName, &w, &h, &c, 0);

	if (data)
	{
		// Generate 
		m_Width = w;
		m_Height = h;
		this->info = info;

		glGenTextures(1, &m_Id);
		glBindTexture(GL_TEXTURE_2D, m_Id);
		glTexImage2D(GL_TEXTURE_2D, 0, info.Internal_Fromat, m_Width, m_Height, 0, info.Image_Format, GL_UNSIGNED_BYTE, data);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, info.Wrap_S);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, info.Wrap_T);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, info.Filter_Min);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, info.Filter_Min);

		glBindTexture(GL_TEXTURE_2D, 0);
	}
	else
		std::cout << "Generate Texture Error ! " << fileName << std::endl;
}

void Texture::Bind(unsigned int slot) const
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, m_Id);
}
