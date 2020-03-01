#include "std_lib_facilities.h"
#include "MeetingWIndow.h"

void MeetingWindow::cb_quit(Address, Address pw){ reference_to<MeetingWindow>(pw).hide(); }
void MeetingWindow::cb_new_person(Address, Address pw){ reference_to<MeetingWindow>(pw).addPerson(); }
void MeetingWindow::cb_persons(Address, Address pw){ reference_to<MeetingWindow>(pw).showPersonPage(); }
void MeetingWindow::cb_meetings(Address, Address pw){ reference_to<MeetingWindow>(pw).showMeetingPage(); }

MeetingWindow::MeetingWindow(Point xy, int w, int h, const string& title):Window{xy, w, h, title}, 
quitBtn(Point{this->x_max()-pad-btnW, pad}, btnW, btnH, "Quit", cb_quit),
personNewBtn{Point{fieldPad, 4*pad + 3*fieldH}, btnW, btnH, "Add person", cb_new_person},
personName(Point{fieldPad, pad}, fieldW, fieldH, "Name: "), 
personEmail{Point{fieldPad, 2*pad + fieldH}, fieldW, fieldH, "Email: "}, 
personSeats{Point{fieldPad, 3*pad + 2*fieldH}, fieldW, fieldH, "Add seats in car: "}, 
data{Point{2*fieldPad, this->y_max()-4*fieldH-pad-2*btnH}, fieldW*2, fieldH*4, "People: "}, 
pageMenu{Point{this->x_max()-2*btnW-pad, this->y_max()-btnH-pad}, btnW, btnH, Menu::Kind::horizontal, "People or meetings"}, 
meetingSubject{Point{fieldPad, pad}, fieldW, fieldH, "Subject: "},
meetingDay{Point{fieldPad, 2*pad + fieldH}, fieldW, fieldH, "Day: "},
meetingStart{Point{fieldPad, 3*pad + 2*fieldH}, fieldW, fieldH, "Start: "}, 
meetingEnd{Point{fieldPad, 4*pad + 3*fieldH}, fieldW, fieldH, "End: "}, 
meetingLocation{Point{fieldPad, 5*pad + 4*fieldH}, fieldW, fieldH, "Location: "},
meetingLeader{Point{fieldPad, 6*pad + 5*fieldH}, fieldW, fieldH, "Leader: "}

{
    
    attach(quitBtn);
    attach(personNewBtn);
    attach(personEmail);
    attach(personName);
    attach(personSeats);
    attach(data);
    pageMenu.attach(new Button{Point{0,0}, 0, 0, "Persons", cb_persons});
    pageMenu.attach(new Button{Point{0,0}, 0, 0, "Meetings", cb_meetings});
    attach(pageMenu);
    attach(meetingSubject);
    attach(meetingDay);
    attach(meetingStart);
    attach(meetingEnd);

    //ikke en veldig god løsning!
    string trndh{"Trondheim"}; 
    string gjvk{"Gjøvik"}; 
    string als{"Ålesund"};
    meetingLocation.add(trndh);
    meetingLocation.add(gjvk);
    meetingLocation.add(als);

    for (auto x : leaders){
        string leaderOption{x->getName()};
        meetingLeader.add(leaderOption);
    }

    showPersonPage();
}

void MeetingWindow::addPerson(){
    string name{personName.get_string()};
    string email{personEmail.get_string()};
    int carSeats{personSeats.get_int()};
    Car* carPtr = nullptr;
    if (carSeats > 0){
        Car car{carSeats};
        car.reserveFreeSeat();
        carPtr = &car;
        cars.push_back(carPtr);
        if (carSeats > 1){
            leaders.push_back(new Person{name, email, carPtr});
        }
    }
    people.push_back(new Person{name, email, carPtr});
        
    personName.clear_value();
    personEmail.clear_value();
    personSeats.clear_value(); 
    displayPeople();
}

void MeetingWindow::printPeople(){
    cout << "The people added are: " << endl;
    for (auto x : people){
        cout << *x << endl;
    }
}

void MeetingWindow::displayPeople(){
    stringstream ss;
    for (auto x : people){
        ss << *x << endl;
    }
    
    data.put(ss.str());
}   

void MeetingWindow::showPersonPage(){
    quitBtn.show();
    personSeats.show();
    personNewBtn.show();
    personEmail.show();
    personName.show();
    meetingSubject.hide();
    meetingDay.hide();
    meetingStart.hide();
    meetingEnd.hide();
    meetingLocation.hide();
    meetingLeader.hide();
    displayPeople();
}

void MeetingWindow::showMeetingPage(){
    quitBtn.show();
    personSeats.hide();
    personNewBtn.hide();
    personName.hide();
    personEmail.hide();
    meetingSubject.show();
    meetingDay.show();
    meetingStart.show();
    meetingEnd.show();
    meetingLocation.show();
    meetingLeader.show();
    displayPeople();
    
}
