#ifndef PPM
#define PPM

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cstdint>
#include <GLFW/glfw3.h>

#include "types.h"
#include "stb/stb_image.h"

void SkipComments(std::istream &in);

GLuint ReadPPMIntoTexture(const char *filename, int *width, int *height);

#endif