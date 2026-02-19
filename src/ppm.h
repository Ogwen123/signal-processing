#include <vector>
#include <iostream>
#include <fstream>

struct Pixel
{
    int r;
    int g;
    int b;
};

typedef std::vector<Pixel> Pixels;

struct Image
{
    int width;
    int height;
    Pixels pixels;
};

const char *whitespace = "\n\t\r\f\v";

Image load(std::string file)
{
    std::fstream imagef(file);

    std::string line;
    std::vector<std::string> data;

    while (getline(imagef, line))
    {
        std::cout << line << std::endl;

        if (line[0] == '#')
            continue;
        line.erase(0, line.find_first_not_of(whitespace));
        line.erase(line.find_last_not_of(whitespace) + 1);
        if (line.length() == 0)
            continue;

        data.push_back(line);
    }

    imagef.close();

    Image image = {};

    std::cout << data.size() << std::endl;

    std::string w_str = data[0].substr(0, data[0].find_first_of({' '}) - 1);
    std::string h_str = data[0].substr(data[0].find_first_of({' '}));

    image.width = stoi(w_str);
    image.height = stoi(h_str);

    std::cout << image.height << " " << image.width << std::endl;

    return image;
}