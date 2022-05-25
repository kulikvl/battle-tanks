#ifndef Utils_hpp
#define Utils_hpp

#include <string>
#include <vector>

#define PI 3.14159265

/// \brief Class for useful functions used in the project
namespace Utils
{
    /// Better random number generator.
    namespace Random
    {
        /// Must be called.
        void seed();

        /// Random number between `min` and `max`.
        int between(int min, int max);

        /// Random float number between `min` and `max`.
        float fbetween(float min, float max);

        /// Random boolean.
        bool boolean();
    };

    std::string getMatrixCoords(int x, int y, int blockWidth);
    void        getGameCoords(const std::string& strCoords, int blockWidth, int offsetFromTop, float& outX, float& outY);
    bool        areEqual(float a, float b);
};

#endif /* Utils_hpp */
