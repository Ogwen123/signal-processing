#ifndef DENOISE
#define DENOISE

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <GLFW/glfw3.h>
#include "ppm.h"

GLuint PopulateNoise(GLuint original_tex, float density); // add random noise to be denoised
GLuint Denoise(GLuint original_tex);

#endif