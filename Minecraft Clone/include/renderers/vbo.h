#pragma once
#include <glad/glad.h>

struct vbo {
	GLuint ID = 0;

	void Setup(float* dt[]);
	void Bind();
	void Unbind();
	void Delete();
};