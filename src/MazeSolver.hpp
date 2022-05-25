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

/// \brief Class for solving the maze given by the vector of road tiles
///
/// Class implements standart BFS search algorithm to find the shortest path.
/// Also implements some BFS variation to get the longest path. (Needed for some types of tanks)
///
class MazeSolver
{
private:
    int n = 8;
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
    
    MazeSolver(const vector<shared_ptr<Tile>>& roadTiles);
    
    MazeSolver(const vector<vector<int> >& grid, const string& startCoordinate, const string& endCoordinate, bool isSubMaze);
    
    void solveGridBFS();
    
    void printGrid(ostream& out) const;
    
    void printSolutionGrid(const vector<string>& path, ostream& out) const;
    
    void printAllSolutions() const;

    string coordinateToString(int x, int y) const ;
    
    map<string, bool>& getUsed() ;
    
    vector<string> getShortestPath() const ;
    
    vector<string> getLongestPath() const ;
};

#endif /* MazeSolver_hpp */
