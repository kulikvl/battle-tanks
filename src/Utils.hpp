#ifndef Utils_hpp
#define Utils_hpp

#include <string>

using namespace std;

/// \brief Class for useful functions used in the project.
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

    // These 2 functions below are general-purpose but only for the local use in this game

    /// Get matrix coordinates.
    /// @param[in] x In-game (real pixel) coordinate of X
    /// @param[in] y In-game (real pixel) coordinate of Y
    /// @param[in] blockWidth Tile width in the game
    /// @return String formatted as "x,y"
    string      getMatrixCoords(int x, int y, int blockWidth);

    /// Get In-game (real pixel) coordinates.
    /// @param[in] strCoords Matrix coordinates formatted as "x,y"
    /// @param[in] blockWidth Tile width in the game
    /// @param[in] offsetFromTop Amount of steps to move down from top
    /// @param[out] outX In-game (real pixel) coordinate X
    /// @param[out] outY In-game (real pixel) coordinate Y
    void        getGameCoords(string strCoords, int blockWidth, int offsetFromTop, float& outX, float& outY);

    /// Function for comparing floats on equality.
    /// @note Using epsilon constant
    bool        areEqual(float a, float b);
};

#endif /* Utils_hpp */
