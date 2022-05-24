#include "MazeSolver.hpp"
#include "Utils.hpp"

MazeSolver::MazeSolver(const vector<shared_ptr<Tile>>& roadTiles)
{
    set<string> roadSet;
    
    for (size_t i = 0; i < roadTiles.size(); ++i)
    {
        
        if (roadTiles[i]->getType() == TileType::ENTRY) startCoordinate = Utils::getMatrixCoords(roadTiles[i]->getX(), roadTiles[i]->getY(), Window::TILE_WIDTH);
        else if (roadTiles[i]->getType() == TileType::EXIT) endCoordinate = Utils::getMatrixCoords(roadTiles[i]->getX(), roadTiles[i]->getY(), Window::TILE_WIDTH);
        
        roadSet.insert(Utils::getMatrixCoords(roadTiles[i]->getX(), roadTiles[i]->getY(), Window::TILE_WIDTH));
    }

    grid.resize(8);
    for (int i = 0; i < 8; ++i) grid[i].resize(8);
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (roadSet.count(coordinateToString(i, j)))
            {
                grid[i][j] = 0;
            }
            else
            {
                grid[i][j] = 1;
            }
        }
    }
    
    
    solveGridBFS();
    printGrid();
    printAllSolutions();

}

MazeSolver::MazeSolver(const vector<vector<int> >& grid, const string& startCoordinate, const string& endCoordinate, bool isSubMaze)
{
    this->grid = grid;
    this->startCoordinate = startCoordinate;
    this->endCoordinate = endCoordinate;
    this->isSubMaze = isSubMaze;
}

void MazeSolver::printGrid() const  {
    cout << "\nMAZE:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (coordinateToString(i, j) == startCoordinate) cout << "S ";
            else if (coordinateToString(i, j) == endCoordinate) cout << "E ";
            else cout<<(grid[i][j] == 1 ? '!' : '_')<<' ';
        }
        cout << endl;
    } cout << endl;
}

void MazeSolver::printSolutionGrid(const vector<string>& path) const {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(find(path.begin(), path.end(), coordinateToString(i, j)) == path.end()) {
                cout<<(grid[i][j] == 1 ? '!' : '_')<< ' ';
            } else {
                cout<<"* ";
            }
        }
        cout<<endl;
    }
}

void MazeSolver::printAllSolutions() const
{
    cout << "SHORTEST PATH: " << endl;
    printSolutionGrid(shortestPath);
    cout<<"STEPS: "<<shortestPath.size()<<endl;
    cout << "\nLONGEST PATH: " << endl;
    printSolutionGrid(longestPath);
    cout<<"STEPS: "<<longestPath.size()<<endl << endl;
}

void MazeSolver::solveGridBFS()
{
    /* Build a graph of all grid positions using an "Adjacency list" */
    map<string, vector<string> > mapPaths = getAdjacentPaths();
    
    string s = startCoordinate;
    queue<string> q;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1) continue;
            
            string pointStr = coordinateToString(i,j);
            if (!isSubMaze) used[pointStr] = false;

            d[pointStr] = INT16_MAX;
            p[pointStr] = "";
        }
    }

    q.push(s);
    used[s] = true;
    d[s] = 0;
    p[s] = "-1";

    while(!q.empty()) {
        
        string point = q.front();
        q.pop();

        for(string neighbour : mapPaths[point]) {
            if(!used[neighbour]) {
                
                used[neighbour] = true;
                q.push(neighbour);
                d[neighbour] = d[point] + 1;
                p[neighbour] = point;
                
                if (!isSubMaze)
                {
                    MazeSolver m(grid, neighbour, endCoordinate, true);
                    
                    vector<string> currentPath;
                    for(string a = neighbour; a != "-1";  a = p[a])
                    {
                        m.getUsed()[a] = true;
                        currentPath.push_back(a);
                    }
                    m.solveGridBFS();
                    
                    vector<string> nextPath = m.getShortestPath();
                    
                    if (nextPath.size() != 0) {
                        nextPath.erase(nextPath.begin());
                        if (nextPath.size() + currentPath.size() > longestPath.size()) {
                            reverse(currentPath.begin(), currentPath.end());
                            longestPath = currentPath;
                            longestPath.insert(longestPath.end(), nextPath.begin(), nextPath.end());

                        }
                    }
                }
            }
        }
    }

    /* If path does not exist */
    if(!used[endCoordinate] ) return;

    for(string point = endCoordinate; point != "-1";  point = p[point])
    {
        shortestPath.push_back(point);
    }
    reverse(shortestPath.begin(), shortestPath.end());
    
}

map<string, vector<string> > MazeSolver::getAdjacentPaths()
{
    map<string, vector<string> > mapPaths;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            
            if(grid[i][j] == 1) continue;

            vector<string> paths;

            if(i - 1 >= 0 && grid[i - 1][j] == 0) paths.push_back(coordinateToString(i - 1, j));
            if(i + 1 < n && grid[i + 1][j] == 0) paths.push_back(coordinateToString(i + 1, j));
            if(j - 1 >= 0 && grid[i][j - 1] == 0) paths.push_back(coordinateToString(i, j - 1));
            if(j + 1 < n && grid[i][j + 1] == 0) paths.push_back(coordinateToString(i, j + 1));
            
            mapPaths[coordinateToString(i,j)] = paths;
        }
    }

    return mapPaths;
}

string MazeSolver::coordinateToString(int x, int y) const
{
    return to_string(x) + "," + to_string(y);
}

map<string, bool>& MazeSolver::getUsed()
{
    return used;
}

vector<string> MazeSolver::getShortestPath() const
{
    return shortestPath;
}

vector<string> MazeSolver::getLongestPath() const
{
    return longestPath;
}

