#include <normalsVBO.h>

void normals::Setup(float* dt[]) {

	glGenBuffers(1, &ID);
	int getLength = sizeof(&dt) / sizeof(float);

	Bind();
	glBufferData(GL_ARRAY_BUFFER, getLength * sizeof(float), &dt, GL_STATIC_DRAW);
}
void normals::Bind() {
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void normals::Unbind() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void normals::Delete() {
	glDeleteBuffers(1, &ID);
}