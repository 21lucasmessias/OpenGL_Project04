#ifndef STATE_H
#define STATE_H

#include "main.hpp"

typedef struct States {
	GLint exercise;
	GLfloat pi;
	GLboolean wireframe;
	GLfloat speed;

	glm::vec3 eye;
	glm::vec3 center;
	glm::vec3 up;

	glm::vec3 cameraPosition;
	GLfloat cameraRotation;
} States;

extern States states;

#endif