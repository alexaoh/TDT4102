#include "Window.h"
#include <iostream>
#include <sstream>
#include <string>
#include "Graph.h"
#include <vector>

using namespace std;
using namespace Graph_lib;

void drawPointsOnWindow(vector<Point*> points); //make window, attach points from vector there and draw lines. 
vector<Point*> getInputFromStream(istream& is);
void PlotinputFromFile(string filename);
void PlotinputFromConsole();

int main(){
	cout << "Welcome to the program!" << endl;
	cout << "-----------------------" << endl;
	cout << "Please choose one of the following options: " << endl;
	cout << "1: Give input from file" << endl;
	cout << "2: Give input from console" << endl;
	int choice{-1};
	cin >> choice;
	//Fikse slik at den håndterer feil også!
	switch (choice){
		case 1: {
			string filename;
			cout << "Please enter the desired filename: ";
			cin >> filename;
			PlotinputFromFile(filename);
			break;
		}
		case 2: {
			cout << "Please enter ypur stream of points: ";
			PlotinputFromConsole();
			break;
		}
		default: {
			cout << "Thank you, see you next time." << endl;
			break;
		}
	}
}


vector<Point*> getInputFromStream(istream& is){
	vector<Point*> points;
	int x; 
	int y;
	while (is >> x >> y){
		//need to handle bad input!
		points.push_back(new Point{x,y});
	}
	return points;
}

void PlotinputFromFile(string filename){
	auto ist = ifstream(filename);
	if (!ist) throw runtime_error("Could not open file "+filename);
	vector<Point*> input = getInputFromStream(ist);
	drawPointsOnWindow(input);
}

void PlotinputFromConsole(){
	string line;
	cin.ignore();
	getline(cin, line);
	istringstream ss{line};
	vector<Point*> input = getInputFromStream(ss);
	drawPointsOnWindow(input);
}

void drawPointsOnWindow(vector<Point*> points){
	Window win{1000, 1000, "Graphing Lines"};
	
	Open_polyline poly;

	for (auto point : points){
		poly.add(*point);
	}
	win.attach(poly);
	//Fl::wait();
	gui_main();
}

/*
Copied from int_input --> check 10.7 to clean this code up and use with my switch-case!
constexpr int quit = 9;
int choice = 0;
while (choice != quit) {
	cout << "Menu V3:\n"
		"1: option A\n" //
		"2: option B\n"
		"3: option C\n"
		<< quit << ": Quit\n> ";
	cin >> choice;
	if (cin) { // we got an integer since cin returns true, now check it
		if ((1 <= choice) && (choice <= 3)) {
			cout << "Option " << choice << " selected\n";
			// branch to right option and do it
			continue;
		}
		if (choice != quit) {
			cout << "sorry, try again\n";
		}
	}
	else if (cin.fail()) {
		cin.clear(); // set the state back to good
		cout << "not a number, try again\n";
		for (char c; (cin >> c) && !isdigit(c); ) // throw away non-digits 
			 do nothing ;  // for loop terminates when first digit is read
		cin.unget(); // put digit back, so that we can read the number
	}
}
*/
