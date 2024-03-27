#pragma once
#include <glad/glad.h>
#include <vbo.h>

struct vao {
	GLuint ID = 0;

	void Setup();
	void LinkTo(int location, int size, vbo VBO);
	void Bind();
	void Unbind();
	void Delete();
};