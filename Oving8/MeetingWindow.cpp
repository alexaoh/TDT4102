#include "std_lib_facilities.h"
#include "MeetingWIndow.h"

void MeetingWindow::cb_quit(Address, Address pw){ reference_to<MeetingWindow>(pw).hide(); }
void MeetingWindow::cb_new_person(Address, Address pw){ reference_to<MeetingWindow>(pw).addPerson(); }

MeetingWindow::MeetingWindow(Point xy, int w, int h, const string& title):Window{xy, w, h, title}, 
quitBtn(Point{this->x_max()-pad-btnW, pad}, btnW, btnH, "Quit", cb_quit),
personNewBtn{Point{fieldPad, 3*pad + 2*fieldH}, btnW, btnH, "Add person", cb_new_person},
personName(Point{fieldPad, pad}, fieldW, fieldH, "Name: "), 
personEmail{Point{fieldPad, 2*pad + fieldH}, fieldW, fieldH, "Email: "}

{
    
    attach(quitBtn);
    attach(personNewBtn);
    attach(personEmail);
    attach(personName);
}

void MeetingWindow::addPerson(){
    string name{personName.get_string()};
    string email{personEmail.get_string()};
    people.push_back(new Person{name, email}); 
    personName.clear_value();
    personEmail.clear_value();
}

void MeetingWindow::printPeople(){
    cout << "The people added are: " << endl;
    for (auto x : people){
        cout << *x << endl;
    }
}
