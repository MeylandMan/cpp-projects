#include <renderer.h>
#include <vbo.h>
#include <vao.h>
#include <textureVBO.h>
#include <normalsVBO.h>
#include <ibo.h>
#include <colorsVBO.h>

void renderer::setupRenderer(float vertex[], unsigned int index[], float texCoord[], float normal[], float color[], std::string &path, vao* va)
	:		vertices(vertex), indices(index), texCoords(texCoord), Normals(normal), Colors(color), texturePath(path), vv(va)
{
	&va.Setup();

	// Position
	vbo vb;
	vb.Setup(vertex);
	&va.LinkTo(0, 3, vb);
	vb.UnBind();

	// texture coordinates
	texture tx;
	tx.Setup(texCoord);
	&va.LinkTo(1, 2, tx);

	//normals
	normals nm;
	nm.Setup(normal);
	&va.LinkTo(2, 3, nm);
	nm.UnBind();

	//Colors
	colors cl;
	cl.Setup(color);
	&va.LinkTo(3, 4, cl);
	cl.UnBind();

	//Indices
	ibo in;
	in.Setup(index);
	in.UnBind();

	texture tex;
	tex.texture(RESOURCES_PATH "textures/" << path, 1);
}

void renderer::drawRenderer() {

	int getLength = sizeof(indices) / sizeof(unsigned int);
	&vv.Bind();
	glDrawElements(GL_TRIANGLES, getLength, GL_UNSIGNED_INT, 0);

}

void renderer::createSquare(std::string spr) {

	vertices[] = {
		 0.5f,  0.5f, 0.0f,  // top right
		 0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  // bottom left
		-0.5f,  0.5f, 0.0f   // top left 
	};

	indices[] = {  // note that we start from 0!
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
	};

	texCoords[] = {
		0f, 1f, // Red
		1f, 1f, // Green
		0f, 0f, // Black
		1f, 0f, // Yellow
	};

	Colors[]{
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f
	};

	Normals[] = {
		 1f, 0f, 0f,
		 1f, 0f, 0f,
		-1f, 0f, 0f,
		-1f, 0f, 0f
	}

	setupRenderer(vertices, indices, texCoords, Normals, Colors, spr);
}

void renderer::createCube() {


}
