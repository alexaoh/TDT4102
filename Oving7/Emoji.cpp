#include "Emoji.h"
#include "Graph.h"
#include "GUI.h"

using namespace Graph_lib;

void Face::attach_to(Graph_lib::Window& win){
    win.attach(face);
    return;
}

void EmptyFace::attach_to(Graph_lib::Window& win){
    Face::attach_to(win);
    win.attach(eye1);
    win.attach(eye2);
    return;
}

void SmilingFace::attach_to(Graph_lib::Window& win){
    EmptyFace::attach_to(win);
    win.attach(mouth);
    return;
}

void SadFace::attach_to(Graph_lib::Window& win){
    EmptyFace::attach_to(win);
    win.attach(mouth);
    return;
}





