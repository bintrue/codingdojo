#include "Board.hpp"
#include "GridBoard.hpp"

minesweeper::GridBoard::GridBoard(size_t width, size_t height, size_t mineCount)
: Board( width * height, mineCount)
{
}

