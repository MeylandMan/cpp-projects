#include <vbo.h>

void vbo::Setup(float* dt[]) {

	glGenBuffers(1, &ID);
	int getLength = sizeof(&dt) / sizeof(float);

	Bind();
	glBufferData(GL_ARRAY_BUFFER, getLength * sizeof(float), &dt, GL_STATIC_DRAW);
}
void vbo::Bind() {
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void vbo::Unbind() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void vbo::Delete() {
	glDeleteBuffers(1, &ID);
}