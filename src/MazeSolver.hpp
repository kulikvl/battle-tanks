#ifndef MazeSolver_hpp
#define MazeSolver_hpp

#include <functional>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <queue>

#include "Tile.hpp"
#include "Log.hpp"
#include "Utils.hpp"

using namespace std;

/// \brief Class for solving the maze given by the vector of road tiles.
///
/// @note Class implements standart BFS search algorithm to find the shortest path.
///
/// @note Also implements some BFS variation to get the longest path. (Needed for some types of tanks)
///
class MazeSolver
{
private:
    const int n = 8;
    
    bool isSubMaze = false;
    
    vector<vector<int> > grid;
    
    string startCoordinate;
    string endCoordinate;
    
    vector<string> longestPath;
    vector<string> shortestPath;
    
    map<string, int> d;
    map<string, string> p;
    map<string, bool> used;
    
    map<string, vector<string> > getAdjacentPaths();
    
public:
    
    /// Init solver with the game road tiles.
    MazeSolver(const vector<shared_ptr<Tile>>& roadTiles);

    /// Init solver another way.
    /// @note Used in inner calls of the object while solving the BFS longest path version.
    MazeSolver(const vector<vector<int> >& grid, const string& startCoordinate, const string& endCoordinate, bool isSubMaze);
    
    /// Solve the maze using BFS.
    void solveGridBFS();
    
    /// Print the initial grid.
    void printGrid(ostream& out) const;
    
    /// Print the solved grid.
    void printSolutionGrid(const vector<string>& path, ostream& out) const;
    
    /// Print all the solved grids.
    void printAllSolutions() const;

    /// @note To use in map container.
    string coordinateToString(int x, int y) const ;
    
    /// Get used paths.
    /// @note For future calls of solving BFS.
    map<string, bool>& getUsed() ;
    
    /// Get the shortest path.
    /// @note It's a strings formatted like: 1,1 -> 1,2 -> ...
    vector<string> getShortestPath() const ;
    
    /// Get the shortest path.
    /// @note It's a strings formatted like: 1,1 -> 1,2 -> ...
    vector<string> getLongestPath() const ;
};

#endif /* MazeSolver_hpp */
