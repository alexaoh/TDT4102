#include "Emoji.h"
#include "Graph.h"
#include "GUI.h"

using namespace Graph_lib;

void Face::attach_to(Graph_lib::Window& win){
    win.attach(face);
    return;
}

EmptyFace::EmptyFace(Point faceCentre, int const faceRadius, Color faceColor, Color eyeColor):Face{faceCentre, faceRadius, faceColor},
	cEye1{Point{faceCentre.x-faceRadius/2, faceCentre.y-faceRadius/3}}, 
	rEye1{faceRadius/6}, cEye2{Point{faceCentre.x+faceRadius/2, faceCentre.y-faceRadius/3}}, rEye2{faceRadius/4}
	{ eye1.set_fill_color(eyeColor), eye2.set_fill_color(eyeColor); }

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

AngryFace::AngryFace(Point faceCentre, int const faceRadius, Color faceColor, Color eyeColor):Face{faceCentre, faceRadius, faceColor},
	cEye1{Point{faceCentre.x-faceRadius/2+5, faceCentre.y-faceRadius/3+5}}, 
	rEye1{faceRadius/6}, cEye2{Point{faceCentre.x+faceRadius/2-5, faceCentre.y-faceRadius/3+5}}, rEye2{faceRadius/6}, 
    faceC{faceCentre}, faceR{faceRadius}, eyebrowLeft(Point{faceCentre.x-faceRadius/2+25, faceCentre.y-faceRadius/3}, Point{faceCentre.x-faceRadius/2, faceCentre.y-faceRadius/3-15}),
    eyebrowRight(Point{faceCentre.x+faceRadius/2-25, faceCentre.y-faceRadius/3}, Point{faceCentre.x+faceRadius/2, faceCentre.y-faceRadius/3-15}){ 
    eye1.set_fill_color(eyeColor);
    eye2.set_fill_color(eyeColor); 
    
}


void AngryFace::attach_to(Graph_lib::Window& win){
    Face::attach_to(win);
    win.attach(upperLip);
    win.attach(lowerLip);
    win.attach(eye1);
    win.attach(eye2);
    win.attach(eyebrowRight);
    win.attach(eyebrowLeft);
    
    return;
}

void attachAllEmojis(Vector_ref<Emoji>& emojis, Graph_lib::Window& win){
    for (int i = 0; i<emojis.size(); i++){
        emojis[i].attach_to(win);
    }
}
