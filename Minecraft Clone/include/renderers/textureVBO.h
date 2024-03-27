#pragma once
#include <glad/glad.h>
#include <string>

struct texture {
private:
	GLuint ID = 0;
	std::string filepath;
	unsigned char* m_LocalBuffer;
	int m_width, m_height, m_BPP;
public:
	texture(const std::string& path, int slot);
	void Bind(unsigned int slot /*= 0*/) const;
	void Unbind() const;
	void Delete();
};