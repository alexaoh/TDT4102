#include "std_lib_facilities.h"
#include "Meeting.h"
#include "Graph.h"
#include "GUI.h"
#include "Window.h"
//Hva er det som egt må includes her?

using namespace Graph_lib;


class MeetingWindow : public Window{
    static constexpr int pad{20};
    static constexpr int btnW{70};
    static constexpr int btnH{40};
    static constexpr int fieldW{200};
    static constexpr int fieldH{40};
    static constexpr int fieldPad{50};

    Button quitBtn; 
    Button personNewBtn;
    In_box personName;
    In_box personEmail;
    Vector_ref<Person> people; 

public: 
    MeetingWindow(Point xy, int w, int h, const string& title);
    void addPerson();
    static void cb_quit(Address, Address pw);
    static void cb_new_person(Address, Address pw);
    void printPeople();


};


