#include "Task2.h"

ostream& operator<<(ostream& o, Tile t){
    if (static_cast<int>(t) == 0) o << "*";
    else if (static_cast<int>(t) == 1) o << "R";
    else if (static_cast<int>(t) == 2) o << "Y";
    return o;
}

ostream& operator<<(ostream& o, Board b){
    for (int y = 0; y<ROWS; ++y){
        for (int x = 0; y<COLS; ++x){
            o << setw(2) << b[y][x];
        }
        o << endl;
    }
    return o;
}

int findLowestPlace(Board board, int column){
    //Antar at det er i orden å returnere rad-indexen ovenfra, siden det ikke spesifiseres annerledes. 
    for (int y = ROWS-1; y>=0; --y){
        if (board[y][column] == Tile::EMPTY) return y;
    }
    return -1;
}

int put(Board board, int column, Tile tile){
    int id = findLowestPlace(board, column);
    if (id != -1) board[id][column] = tile;
    return id;
}

bool isOutOfBound(int row, int column){
    return row<0 || row>=ROWS || column<0 || column>=COLS;
}

int countTiles(Board board, int row, int column, int dr, int dc){
    Tile start = board[row][column];
    if (start == Tile::EMPTY) return 0;
    int tiles{1};
    for (int y = row; y<ROWS; y += dr){
        for (int x = column; x<COLS; x += dc){
            if (board[y][x] == start) tiles++;
            else return tiles;
        }
    }
    return tiles;
}

bool fourInARow(Board board, int row, int column){
    if (countTiles(board, row, column, 0, 1) + countTiles(board, row, column, 0, -1) > 4){
        return true;
    } //etc;
    return false;
}       

bool playerTurn(Board board, Tile tile){
    int col{-1};
    cout << "Hilken kolonne vil du legge brikken din i?" << endl;
    cin >> col;
    int row = put(board, col, tile);
    return fourInARow(board,row, col);
}

bool machineTurn(Board board, Tile tile){
    srand(static_cast<unsigned int>(time(nullptr)));
    int col;
    int row;
    do {
        col = rand() % COLS;
    } while ((row = put(board, col, tile) == -1));
    return fourInARow(board,row, col);
}
