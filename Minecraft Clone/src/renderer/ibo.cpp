#include <ibo.h>

void ibo::Setup(float* dt[]) {

	glGenBuffers(1, &ID);
	int getLength = sizeof(&dt) / sizeof(float);

	Bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, getLength * sizeof(GLuint), &dt, GL_STATIC_DRAW);
}
void ibo::Bind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

void ibo::Unbind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void ibo::Delete() {
	glDeleteBuffers(1, &ID);
}