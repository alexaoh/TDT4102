#include "std_lib_facilities.h"
#include "Meeting.h"
#include "Graph.h"
#include "GUI.h"
#include "Window.h"
//Hva er det som egt må includes her?

using namespace Graph_lib;

//Sikkert lurt å lage constexpr-s med dimensjoner som vist i øvinga!

class MeetingWindow : public Window{

public: 
    MeetingWindow(Point xy, int w, int h, const string& title):Window{xy, w, h, title}{};

};


