#pragma once
#include <vector>
#include "raylib.h"

class FGrid
{ 
    public:
    FGrid(int width, int height); // as tile size
    void SetTile(int x, int y, int value);
    int GetTile(int x, int y);
    int GetTileWithWorldPosition(Vector2 position);
    int GetWidth();
    int GetHeight();
    private:
    int m_tileSize = 32; // as pixel size
    std::vector<std::vector<int>> m_grid;
};