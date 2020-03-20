#include "MinesweeperWindow.h"
#include <random>

MinesweeperWindow::MinesweeperWindow(Point xy, int width, int height, int mines, const string& title) :
	Graph_lib::Window{xy, width * cellSize, height*cellSize, title}, width{width}, height{height}, mines{mines}, 
	won{Point{0,0},width * cellSize, height*cellSize, ""}, lost{Point{0,0},width * cellSize, height*cellSize, ""}
	//Initialiser medlemsvariabler, bruker ogsaa konstruktoren til Windowsklassen
{
	// Legg til alle tiles paa vinduet
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			int y = i* cellSize,
				x = j * cellSize;
			tiles.push_back(new Tile{ Point{x, y}, cellSize, cb_click});
			attach(tiles.back());
		}
	}

	//Legg til miner paa tilfeldige posisjoner
	int placedMines{0};
	while (placedMines < mines){
		int randomNum = rand() % tiles.size();
		if (tiles[randomNum].getIsMine() == false){
			tiles[randomNum].setIsMine(true);
			placedMines++;
		}
	}

	// Fjern window reskalering
	resizable(nullptr);
	size_range(x_max(), y_max(), x_max(), y_max());
}

int MinesweeperWindow::countMines(vector<Point> points) const {
	int quantity{0};
	for (auto x : points){
		if (at(x).getIsMine()){
			quantity++;
		} 
	}
	return quantity;
};
vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}

			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}

	return points;
}

void MinesweeperWindow::openTile(Point xy) {
	Tile& tile = at(xy);
	if (tile.getState() == Cell::closed){
		tile.open();
		if (!tile.getIsMine()){
			tilesOpened++;
			vector<Point> v{adjacentPoints(xy)};
			int amountOfMines{countMines(v)};
			if (!amountOfMines){
				for (auto x : v){
					openTile(x); 
				} 
			} else tile.setAdjMines(amountOfMines);
		}
		else{ //The game is lost. 
			attach(lost);
			lost.put("OMG, you just lost my friend!");
			redraw();
			flush();
		}		
	}
	if (tilesOpened==(tiles.size()-mines)){ //Game is won. 
		attach(won);
		won.put("Congratx, you just won the entire game my friend!");
	}
	
}

void MinesweeperWindow::flagTile(Point xy) {
	Tile& tile = at(xy);
	if (tile.getState() != Cell::open){
		tile.flag();
	}
}

//Kaller opentile ved venstreklikk og flagTile ved hoyreklikk/trykke med to fingre paa mac
void MinesweeperWindow::cb_click(Address, Address pw)
{
	Point xy{ Fl::event_x(),Fl::event_y() };
	MouseButton mb = static_cast<MouseButton>(Fl::event_button());
	auto& win = reference_to<MinesweeperWindow>(pw);

	if (!win.inRange(xy)) {
		return;
	}

	switch (mb) {
	case MouseButton::left:
		win.openTile(xy);
		break;
	case MouseButton::right:
		win.flagTile(xy);
		break;
	}
	win.flush();
}

void MinesweeperWindow::cb_restart(Address, Address pw){

}
