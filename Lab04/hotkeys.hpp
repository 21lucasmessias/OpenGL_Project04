#ifndef HOTKEYS_H
#define HOTKEYS_H

#include "main.hpp"

#define EXERCISE_1 1

void processInput(GLFWwindow* window, int key, int scancode, int action, int mods);
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

#endif