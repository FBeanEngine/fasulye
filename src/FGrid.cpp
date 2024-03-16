#include "FGrid.h"

FGrid::FGrid(int width, int height)
{
    m_grid.resize(width);
    for (int x = 0; x < m_grid.size(); x++)
    {
        m_grid[x].resize(height);
    }
}

void FGrid::SetTile(int x, int y, int value)
{
    m_grid[x][y] = value;
}

int FGrid::GetTile(int x, int y)
{
    return m_grid[x][y];
}

int FGrid::GetTileWithWorldPosition(Vector2 position)
{
    int x = position.x / m_tileSize;
    int y = position.y / m_tileSize;
    return GetTile(x, y);
}

int FGrid::GetWidth() {
    return m_grid.size();
}

int FGrid::GetHeight() {
    return m_grid[0].size();
}