// Assignment 3 - Open Assignment

//Please add your code in this file. If you need to include more files, add them in the same folder as this file.
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include "Graph.h"
#include "Window.h"

using namespace std;
using namespace Graph_lib;

vector<Point> readFromFile();
vector<Point> readSequenceFromConsole();
void drawLine(vector<Point> vec);

int main(){
    cout << endl << "------------------------------------------" << endl;
    cout << endl << "               Hovedmeny                " << endl;
    cout << endl << "------------------------------------------" << endl;
    cout << "Valg:" << endl;
    cout << "Skriv \'1\' for å hente punkter fra fil" << endl;
    cout << "Skriv \'2\' for å skrive inn en sekvens av tall" << endl;
    //kan ha en løkke som kjører helt til man får gyldig input også!
    int valg; 
    cin >> valg;
    switch(valg){ //legg ved unntakshåndtering her senere, hvis tid!
        case 1: {
            vector<Point> vec = readFromFile();
            drawLine(vec);
            break;
        }
        case 2: {
            vector<Point> vec = readSequenceFromConsole();
            drawLine(vec);
            break;
        }
        default: {
            cout << "Du kan kun velge mellom \'1\' og \'2\' i denne menyen";
            break;
        }
    }
}

vector<Point> readFromFile(){
    string filename;
    cout << "Skriv inn ønsket filnavn" << endl;
    cin >> filename;
    ifstream ist{filename};
    if (!ist) throw runtime_error("Cannot open file "+filename);
    //Mye av denne koden er lik som i funskjonen under! Burde samles, men rekker ikke nå!
    int x;
    char comma1;
    int y; 
    char comma2;
    vector<Point> vec;
    while (ist >> x >> comma1 >> y){
        if (comma1 != ',') throw runtime_error("Coordinates must be separated by a comma");
        if (!y) throw runtime_error("Must have an even amount of x- and y- coordinates!");
        Point xy{x,y};
        vec.push_back(xy);
        ist >> comma2;
    }   
    return vec;
}

vector<Point> readSequenceFromConsole(){
    cout << "Skriv inn din egen sekvens" << endl;
    string line;
    cin.ignore();
    getline(cin, line);
    stringstream ss{line};
    int x;
    char comma1;
    int y; 
    char comma2;
    vector<Point> vec;
    while (ss >> x >> comma1 >> y >> comma2){
        if (comma1 != ',' || comma2 != ',') throw runtime_error("Coordinates must be separated by a comma");
        Point xy{x,y};
        vec.push_back(xy);
    }   
    
    return vec;
}

void drawLine(vector<Point> vec){
    Point tl{100, 100};
    Window win{tl, 500, 500, "Lines"};
    Lines lines;
    for (int i = 1; i<vec.size(); ++i){
        lines.add(vec[i-1], vec[i]);
    }
    lines.draw_lines();
    win.attach(lines); //rakk ikke mer :(
    gui_main();
}
