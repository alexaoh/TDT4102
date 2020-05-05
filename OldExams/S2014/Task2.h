#include <iostream>
#include <string>
#include <iomanip>
#include <random>
#include <time.h>

using namespace std;

enum class Tile {EMPTY, RED, YELLOW};
constexpr int ROWS = 6;
constexpr int COLS = 7;

using Board = Tile[ROWS][COLS];


ostream& operator<<(ostream& o, Tile t);
ostream& operator<<(ostream& o, Board b);
int findLowestPlace(Board board, int column);
int put(Board board, int column, Tile tile);
bool isOutOfBound(int row, int column);
int countTiles(Board board, int row, int column, int dr, int dc);
bool fourInARow(Board board, int row, int column);
bool playerTurn(Board board, Tile tile);
bool machineTurn(Board board, Tile tile);
