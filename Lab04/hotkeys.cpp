#include "hotkeys.hpp"

void processInput(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS || action == GLFW_REPEAT) {
		if(key == GLFW_KEY_SPACE) {
			if (states.wireframe)
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			else
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

			states.wireframe = !states.wireframe;
		}
		else if (key == GLFW_KEY_ESCAPE) {
			glfwSetWindowShouldClose(window, true);
		}
		else if (key == GLFW_KEY_1) {
			states.exercise = 1;
			states.cameraPosition = { 0.0f, 15.0f, 120.0f };

			processObjects();
		}
		else if (key == GLFW_KEY_2) {
			states.exercise = 2;
			states.cameraPosition = { 0.0f, 15.0f, 120.0f };

			processObjects();
		}
		else if (key == GLFW_KEY_3) {
			states.exercise = 3;
			states.cameraPosition = { 0.0f, 7.0f, 0.0f };

			processObjects();
		}
		else if (key == GLFW_KEY_4) {
			states.exercise = 4;
			states.cameraPosition = { 0.0f, 15.0f, 120.0f };
			
			processObjects();
		}
		else if (key == GLFW_KEY_O) {
			if (states.exercise == 4) {
				objectsToRender[1].translation[2] += 1.0f;
				objectsToRender[2].translation[1] += 1.0f;
				objectsToRender[3].translation[2] -= 1.0f;
				objectsToRender[4].translation[1] -= 1.0f;
				objectsToRender[5].translation[0] -= 1.0f;
				objectsToRender[6].translation[0] += 1.0f;
			}
		}
		else if (key == GLFW_KEY_P) {
			if (states.exercise == 4) {
				objectsToRender[1].translation[2] -= 1.0f;
				objectsToRender[2].translation[1] -= 1.0f;
				objectsToRender[3].translation[2] += 1.0f;
				objectsToRender[4].translation[1] += 1.0f;
				objectsToRender[5].translation[0] += 1.0f;
				objectsToRender[6].translation[0] -= 1.0f;
			}
		}
		else if (key == GLFW_KEY_Y) {
			if (states.exercise == 2) {
				objectsToRender[1].rotation.vec = { 1.0f, 0.0f, 0.0f };
				objectsToRender[1].rotation.radians = sin(states.speed * states.pi / 180) + objectsToRender[1].rotation.radians;
			}
		}
		else if (key == GLFW_KEY_UP) {
			if (states.exercise == 2) {
				GLfloat posX = objectsToRender[1].translation[0];
				GLfloat posZ = objectsToRender[1].translation[2] - states.speed;
				GLfloat posY = objectsToRender[1].translation[1];

				GLfloat posObstacleX = objectsToRender[2].translation[0];
				GLfloat posObstacleZ = objectsToRender[2].translation[2];
				GLfloat posObstacleY = objectsToRender[2].translation[1];

				if (posZ >= posObstacleZ - 10.0f && posZ <= posObstacleZ + 10.0f && posX >= posObstacleX - 10.0f && posX <= posObstacleX + 10.0f && posY == posObstacleY) {
					objectsToRender[1].translation[1] = 16.0f;
				}
				else {
					objectsToRender[1].translation[2] = objectsToRender[1].translation[2] - states.speed;
				}

				if (posZ < posObstacleZ - 10.0f) {
					objectsToRender[1].translation[1] = 6.0f;
				}
			}
			else {
				states.cameraPosition[0] = states.cameraPosition[0] - (GLfloat)sin(states.cameraRotation * states.pi / 180);
				states.cameraPosition[2] = states.cameraPosition[2] + (GLfloat)cos(states.cameraRotation * states.pi / 180);
			}
		}
		else if (key == GLFW_KEY_DOWN) {
			if (states.exercise == 2) {
				GLfloat posX = objectsToRender[1].translation[0];
				GLfloat posZ = objectsToRender[1].translation[2] + states.speed;
				GLfloat posY = objectsToRender[1].translation[1];

				GLfloat posObstacleX = objectsToRender[2].translation[0];
				GLfloat posObstacleZ = objectsToRender[2].translation[2];
				GLfloat posObstacleY = objectsToRender[2].translation[1];

				if (posZ >= posObstacleZ - 10.0f && posZ <= posObstacleZ + 10.0f && posX >= posObstacleX - 10.0f && posX <= posObstacleX + 10.0f && posY == posObstacleY) {
					objectsToRender[1].translation[1] = 16.0f;
				}
				else {
					objectsToRender[1].translation[2] = objectsToRender[1].translation[2] + states.speed;
				}

				if (posZ > posObstacleZ + 10.0f) {
					objectsToRender[1].translation[1] = 6.0f;
				}
			}
			else {
				states.cameraPosition[0] = states.cameraPosition[0] + (GLfloat)sin(states.cameraRotation * states.pi / 180);
				states.cameraPosition[2] = states.cameraPosition[2] - (GLfloat)cos(states.cameraRotation * states.pi / 180);
			}
		}
		else if (key == GLFW_KEY_LEFT) {
			if (states.exercise == 2) {
				GLfloat posX = objectsToRender[1].translation[0] - states.speed;
				GLfloat posZ = objectsToRender[1].translation[2];
				GLfloat posY = objectsToRender[1].translation[1];

				GLfloat posObstacleX = objectsToRender[2].translation[0];
				GLfloat posObstacleZ = objectsToRender[2].translation[2];
				GLfloat posObstacleY = objectsToRender[2].translation[1];

				if (posZ >= posObstacleZ - 10.0f && posZ <= posObstacleZ + 10.0f && posX >= posObstacleX - 10.0f && posX <= posObstacleX + 10.0f && posY == posObstacleY) {
					objectsToRender[1].translation[1] = 16.0f;
				}
				else {
					objectsToRender[1].translation[0] = objectsToRender[1].translation[0] - states.speed;
				}

				if (posX < posObstacleX - 10.0f) {
					objectsToRender[1].translation[1] = 6.0f;
				}
			}
			else {
				states.cameraPosition[0] = states.cameraPosition[0] + (GLfloat)sin((states.cameraRotation + 90.0f) * states.pi / 180);
				states.cameraPosition[2] = states.cameraPosition[2] - (GLfloat)cos((states.cameraRotation + 90.0f) * states.pi / 180);
			}
		}
		else if (key == GLFW_KEY_RIGHT) {
			if (states.exercise == 2) {
				GLfloat posX = objectsToRender[1].translation[0] + states.speed;
				GLfloat posZ = objectsToRender[1].translation[2];
				GLfloat posY = objectsToRender[1].translation[1];

				GLfloat posObstacleX = objectsToRender[2].translation[0];
				GLfloat posObstacleZ = objectsToRender[2].translation[2];
				GLfloat posObstacleY = objectsToRender[2].translation[1];
				
				if (posZ >= posObstacleZ - 10.0f && posZ <= posObstacleZ + 10.0f && posX >= posObstacleX - 10.0f && posX <= posObstacleX + 10.0f && posY == posObstacleY) {
					objectsToRender[1].translation[1] = 16.0f;
				}
				else {
					objectsToRender[1].translation[0] = objectsToRender[1].translation[0] + states.speed;
				}

				if (posX > posObstacleX + 10.0f) {
					objectsToRender[1].translation[1] = 6.0f;
				}
			}
			else {
				states.cameraPosition[0] = states.cameraPosition[0] + (GLfloat)sin((states.cameraRotation - 90.0f) * states.pi / 180);
				states.cameraPosition[2] = states.cameraPosition[2] - (GLfloat)cos((states.cameraRotation - 90.0f) * states.pi / 180);
			}
		}
	}
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
	states.eye[0] = (GLfloat)sin(xpos * states.pi / 180);
	states.eye[2] = (GLfloat)cos(xpos * states.pi / 180) * -1;

	states.cameraRotation = (GLfloat)xpos;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
	if (action == GLFW_PRESS || action == GLFW_REPEAT) {
		if (button == GLFW_MOUSE_BUTTON_LEFT) {
			if (states.exercise == 4) {
				objectsToRender[1].rotation.radians = objectsToRender[1].rotation.radians - sin(states.speed * states.pi / 180);
				objectsToRender[2].rotation.radians = objectsToRender[2].rotation.radians - sin(states.speed * states.pi / 180);
				objectsToRender[3].rotation.radians = objectsToRender[3].rotation.radians - sin(states.speed * states.pi / 180);
			}
		}
		else if (button == GLFW_MOUSE_BUTTON_RIGHT) {
			if (states.exercise == 4) {
				objectsToRender[1].rotation.radians = objectsToRender[1].rotation.radians + sin(states.speed * states.pi / 180);
				objectsToRender[2].rotation.radians = objectsToRender[2].rotation.radians + sin(states.speed * states.pi / 180);
				objectsToRender[3].rotation.radians = objectsToRender[3].rotation.radians + sin(states.speed * states.pi / 180);
			}
		}
	}
}