#pragma once

// Include Graph_lib library files that holds declarations needed for Window,
// and Shape derivatives.
#include "Graph.h"
#include "GUI.h"



using namespace Graph_lib;

// An abstract class. Concrete classes derived from this base class
// has to implement the member function attach_to().
class Emoji
{
public:
	// Disable copying. Disable slicing, etc.
	Emoji(const Emoji&) = delete;
	Emoji& operator=(const Emoji&) = delete;

	// Deleting the copy constructor also deletes the default constructor.
	// Emoji needs a default constructor.
	Emoji() {}
	// Emoji() = default; // is an alternative way of achieving the same.

	// The pure virtual function that has to be overriden for a deriving class
	// to be instantiable. Every class deriving from Emoji is supposed to
	// attach all its Shapes to a window. This makes the class abstract.
	virtual void attach_to(Graph_lib::Window&) = 0;

	// Relevant because Vector_ref can own Emojis and automatically cleans up.
	// Subject will be visited later in the course.
	virtual ~Emoji() {}
};

class Face : public Emoji{
	Point co; 
	int const ro; 
	Circle face{co,ro};

public: 
	Face(Point c, int const r, Color f):co{c},ro{r} { face.set_fill_color(f), face.set_style(Line_style(Line_style::solid, 3)); }
	virtual void attach_to(Graph_lib::Window&) override = 0;
	int getRadius() const { return ro; }
	Point getCentrePoint() const { return co; }
};

class EmptyFace : public Face {
	Point cEye1;
	int rEye1;
	Point cEye2; 
	int rEye2;
	Circle eye1{cEye1, rEye1};
	Circle eye2{cEye2, rEye2};
public: 
	EmptyFace(Point faceCentre, int const faceRadius, Color faceColor, Color eyeColor);
	virtual void attach_to(Graph_lib::Window&) override = 0;

};

class SmilingFace : public EmptyFace {
	Point faceC;
	int const faceR;
	Arc mouth{Point{faceC.x, faceC.y + 10}, faceR, faceR, 180, 360};
public: 
	SmilingFace(Point faceCentre, int const faceRadius, Color faceColor, Color eyeColor):EmptyFace{faceCentre, faceRadius, faceColor, eyeColor}, faceC{faceCentre},
	faceR{faceRadius}{};
	void attach_to(Graph_lib::Window&) override;
};

class SadFace : public EmptyFace {
	Point faceC;
	int const faceR;
	Arc mouth{Point{faceC.x, faceC.y + 40}, faceR, faceR, 0, 180};
public: 
	SadFace(Point faceCentre, int const faceRadius, Color faceColor, Color eyeColor):EmptyFace{faceCentre, faceRadius, faceColor, eyeColor}, faceC{faceCentre},
	faceR{faceRadius}{};
	void attach_to(Graph_lib::Window&) override;
};

class AngryFace : public Face {
	Point cEye1;
	int rEye1;
	Point cEye2; 
	int rEye2;
	Circle eye1{cEye1, rEye1};
	Circle eye2{cEye2, rEye2};
	Point faceC;
	int const faceR;
	Arc upperLip{Point{faceC.x, faceC.y + 40}, faceR, faceR-20, 20, 160};
	Arc lowerLip{Point{faceC.x, faceC.y + 40}, faceR, faceR-40, 20, 160};
	Line eyebrowLeft;
	Line eyebrowRight;
public:
	AngryFace(Point faceCentre, int const faceRadius, Color faceColor, Color eyeColor);
	void attach_to(Graph_lib::Window&) override;

};

void attachAllEmojis(Vector_ref<Emoji>& emojis, Graph_lib::Window& win);
