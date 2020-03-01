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
    static constexpr int fieldPad{120};

    Button quitBtn; 
    Button personNewBtn;
    In_box personName;
    In_box personEmail;
    Vector_ref<Person> people; 

    //Voluntary GUI expansion
    In_box personSeats;
    Vector_ref<Car> cars;
    Multiline_out_box data;
    Menu pageMenu;
    In_box meetingSubject;
    In_box meetingDay;
    In_box meetingStart;
    In_box meetingEnd;
    Choice meetingLocation;
    Choice meetingLeader;
    Vector<const Person*> leaders;

public: 
    MeetingWindow(Point xy, int w, int h, const string& title);
    void addPerson();
    static void cb_quit(Address, Address pw);
    static void cb_new_person(Address, Address pw);
    void printPeople();

    //Voluntary GUI expansion
    void displayPeople();
    void showPersonPage();
    void showMeetingPage();
    static void cb_persons(Address, Address pw);
    static void cb_meetings(Address, Address pw);

};
