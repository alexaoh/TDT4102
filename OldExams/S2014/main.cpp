#include "Task2.h"

int main(){
	//Task 2:
	Board board{};
	cout << board;	
	Tile playerColor = Tile::YELLOW;
	Tile machineColor = Tile::RED;
	while (1){
		if (playerTurn(board, playerColor)){
			cout << "Congratz! You won!";
			break;
		} else if (machineTurn(board, machineColor)){
			cout << "The computer won!";
			break;
		}
	}	
	//Burde sjekke uavgjort (når brettet er fullt) også!
}
