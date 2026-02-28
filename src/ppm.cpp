#include "ppm.h"

void SkipComments(std::istream &in)
{
    char ch;
    while (in >> std::ws && in.peek() == '#')
    {
        std::string line;
        std::getline(in, line);
    }
}

GLuint ReadPPMIntoTexture(const char *filename, int *width, int *height)
{
    int channels;
    if (!stbi_info(filename, width, height, &channels))
    {
        throw std::runtime_error("Failed to read image info");
    }

    unsigned char *data = stbi_load(filename, width, height, &channels, STBI_rgb_alpha);
    if (!data)
        return 0;

    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, *width, *height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

    stbi_image_free(data);
    return textureID;
}