#include "MinesweeperWindow.h"
#include <random>

MinesweeperWindow::MinesweeperWindow(Point xy, int width, int height, int mines, const string& title) :
	Graph_lib::Window{xy, width * cellSize, height*cellSize, title}, width{width}, height{height}, mines{mines}, 
	won{Point{20,20},width * cellSize-50, height*cellSize/10, ""}, lost{Point{20,20},width * cellSize-50, height*cellSize/10, ""}, 
	numOfMines{Point{10,10}, width * cellSize/20, height*cellSize/20, "Num of mines unflagged:"},  
	restartBtn{Point{50,100}, 50,50, "Restart", cb_restart}, 
	quitBtn{Point{0,100}, 50, 50, "Quit", cb_quit}, xy{xy}, title{title}
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

	attach(numOfMines);
	numOfMines.hide();

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
			crossMinesWhenLoser();
			this->redraw();
			gameEnded = true;
		}		
	}
	if (tilesOpened==(tiles.size()-mines)){ //Game is won. 
		attach(won);
		won.put("Congratz, you just won the entire game my friend!");
		flagMinesWhenWinner();
		this->redraw();
		gameEnded = true;
	}
	
}

void MinesweeperWindow::flagTile(Point xy) {
	Tile& tile = at(xy);
	int minesLeft{0}; //Used to count number of mines left, that are not flagged.
	if (tile.getState() != Cell::open){
		if (tile.getState() == Cell::flagged){
			tilesFlagged--;
		}
		else{
			tilesFlagged++;
		}
		tile.flag();
		if (tile.getIsMine()){
			//Need to find remaining mines:
			for (auto x : tiles){
				if (x->getIsMine() && x->getState() == Cell::closed){ 
					minesLeft++;
				}
			}
			numOfMines.put(minesLeft);
			numOfMines.redraw();
			numOfMines.show();
		}
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

	if (win.gameEnded){
		win.attach(win.quitBtn);
		win.attach(win.restartBtn);
		win.redraw();
	}
	win.flush();
}

void MinesweeperWindow::cb_restart(Address, Address pw){
	reference_to<MinesweeperWindow>(pw).restart();
}

void MinesweeperWindow::cb_quit(Address, Address pw){
	reference_to<MinesweeperWindow>(pw).quit();
}

void MinesweeperWindow::flagMinesWhenWinner(){
	for (auto x : tiles){
		if (x->getIsMine() && x->getState() != Cell::flagged){
			flagTile(x->loc);
		}
	}

}
void MinesweeperWindow::crossMinesWhenLoser(){ //Burde satt sammen disse til samme funk. 
	for (auto x : tiles){
		if (x->getIsMine() ){
			openTile(x->loc);
		}
	}
}

void MinesweeperWindow::quit(){
	this->hide();
}

int MinesweeperWindow::restart(){
	this->hide();
	MinesweeperWindow win{xy,width, height, mines, title};
	return gui_main();
}
