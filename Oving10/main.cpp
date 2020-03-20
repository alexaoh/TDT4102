#include "MinesweeperWindow.h"

int main()
{

	Fl::background(200, 200, 200);
	constexpr int width = 15;
	constexpr int height = 15;
	constexpr int mines = 5;
	srand(static_cast<unsigned int>(time(nullptr)));
	
	Point startPoint{ 200,300 };
	MinesweeperWindow mw{ startPoint, width, height, mines, "Minesweeper" };
	return gui_main();

}
 