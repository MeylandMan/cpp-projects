#include <textureVBO.h>
#include <stb_image/stb_image.h>
#include <string.h>

texture::texture(const std::string& path, int slot)
    : ID(0), filepath(path), m_LocalBuffer(nullptr),
      m_width(0), m_height(0), m_BPP(0) 
{
    glGenTextures(1, &ID);

    // Activate the texture in the unit
    glActiveTexture(GL_TEXTURE0);
    Bind(slot);

    // --- TEXTURES PARAMETERS
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //Load The Image
    stbi_set_flip_vertically_on_load(1);
    m_LocalBuffer = stbi_load(path.c_str(), &m_width, &m_height, &m_BPP, 4);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer);

    Unbind();

    if (m_LocalBuffer)
        stbi_image_free(m_LocalBuffer);
}

void texture::Bind(unsigned int slot) const {
    glActiveTexture(GL_TEXTURE0 * slot);
	glBindTexture(GL_TEXTURE_2D, ID);
}

void texture::Unbind() const {
	glBindTexture(GL_TEXTURE_2D, 0);
}

void texture::Delete() {
	glDeleteTextures(1, &ID);
}
