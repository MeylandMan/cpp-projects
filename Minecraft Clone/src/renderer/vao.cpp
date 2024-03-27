#include <vao.h>
#include <vbo.h>

void vao::Setup() {
	glGenVertexArrays(1, &ID);
	Bind();
}
void vao::LinkTo(int location, int size, vbo VBO) {
	Bind();
	VBO.Bind();

	glVertexAttribPointer(location, size, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(location);
}
void vao::Bind() {
	glBindVertexArray(ID);
}

void vao::Unbind() {
	glBindVertexArray(0);
}

void vao::Delete() {
	glDeleteVertexArrays(1, &ID);
}
