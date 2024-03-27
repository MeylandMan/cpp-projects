#include <colorsVBO.h>

void colors::Setup(float* dt[]) {

	glGenBuffers(1, &ID);
	int getLength = sizeof(&dt) / sizeof(float);

	Bind();
	glBufferData(GL_ARRAY_BUFFER, getLength * sizeof(float), &dt, GL_STATIC_DRAW);
}
void colors::Bind() {
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void colors::Unbind() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void colors::Delete() {
	glDeleteBuffers(1, &ID);
}