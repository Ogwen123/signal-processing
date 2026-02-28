#include "denoise.h"

/// @brief takes in a texture ID, copies it, populates it with noise and stores it in its own texture, used for testing denoising functions
/// @param texture glTexture id
/// @param width image width
/// @param height image height
/// @param density value between 0-100 for the noise density, a density of 100 will completely populate the image with noise
/// @return
GLuint PopulateNoise(GLuint texture, int width, int height, float density)
{
    if (density < 0 || density > 100)
    {
        throw std::runtime_error("PopulateNoise density must be between 0 and 100 (inclusive)");
    }

    const int channels = 4;
    glBindTexture(GL_TEXTURE_2D, texture);

    std::vector<unsigned char> pixels(width * height * channels);

    glGetTexImage(
        GL_TEXTURE_2D,
        0,
        GL_RGBA,
        GL_UNSIGNED_BYTE,
        pixels.data());

    std::srand(std::time({}));

    for (int i = 0; i < width * height; i++)
    {
        const int show_noise = std::round(std::rand() / (RAND_MAX / 100));

        if (show_noise == density)
        {
            unsigned char colour = 255 * std::rand() / RAND_MAX;
            pixels[i * 4] = colour;
            pixels[i * 4 + 1] = colour;
            pixels[i * 4 + 2] = colour;
            pixels[i * 4 + 3] = (unsigned char)1;
        }
    }

    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels.data());

    return textureID;
}