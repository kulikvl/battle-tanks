#include "Utils.hpp"
#include <sstream>   // sstream
#include <algorithm> // find_if
#include <utility>   // C++11
#include <random>    // C++11
#include <limits>

namespace Utils
{
    namespace Random
    {
        std::mt19937 engine;
    };
};

void Utils::Random::seed()
{
    engine.seed((unsigned int)time(nullptr));
}

int Utils::Random::between(int min, int max)
{
    std::uniform_int_distribution<int> distance(min, max);
    return distance(engine);
}

float Utils::Random::fbetween(float min, float max)
{
    std::uniform_real_distribution<float> distance(min, max);
    return distance(engine);
}

bool Utils::Random::boolean()
{
    std::uniform_int_distribution<int> distance(0, 10);

    return ((distance(engine) % 2) == 0);
}

string Utils::getMatrixCoords(int x, int y, int blockWidth)
{
    return to_string( (y - blockWidth) / blockWidth) + "," + to_string(x / blockWidth);
}

void Utils::getGameCoords(string strCoords, int blockWidth, int offsetFromTop, float& outX, float& outY)
{
    stringstream s;
    s << strCoords;
    s >> outY;
    outY += offsetFromTop;
    outY *= blockWidth;
    char symbol;
    s >> symbol;
    s >> outX;
    outX *= blockWidth;
}

bool Utils::areEqual(float a, float b)
{
    return fabs(a - b) <= numeric_limits<float>::epsilon();
}


