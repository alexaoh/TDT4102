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
	int ro; 
	Circle face{co,ro};

public: 
	Face(Point c, int r, Color f):co{c},ro{r} { face.set_fill_color(f); }
	virtual void attach_to(Graph_lib::Window&) override = 0;
	int getRadius() const { return ro; }
	Point getCentrePoint() const { return co; }
};

class EmptyFace : public Face {
	Point cEye1; //tanken er å gette posisjon og radius til Face, og justere på de verdiene når øynene initialiseres. 
	int rEye1;
	Point cEye2; 
	int rEye2;
	Color eyeColor;
public: 
	EmptyFace(Point faceCentre, int faceRadius, Color faceColor, Color eyeColor):Face{faceCentre, faceRadius, faceColor}, eyeColor{eyeColor
	}{}

	virtual void attach_to(Graph_lib::Window&) = 0;

};