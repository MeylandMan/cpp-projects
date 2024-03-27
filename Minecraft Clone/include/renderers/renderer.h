#pragma once
#include <glad/glad.h>


struct renderer {
private:
	vao* vv;
	float vertices[];
	unsigned int indices[];
	float texCoords[];
	float Normals[];
	float Colors[];
	std::string texturePath;

	void setupRenderer(float vertex[], unsigned int index[], float texCoord[], float normal[], float color[], std::string path);
	void drawRenderer();
public:
	void createSquare();
};