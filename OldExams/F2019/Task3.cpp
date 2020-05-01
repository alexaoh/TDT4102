#include "Task3.h"

Location::Location(string n, Point p):name{n}, p{p}{}

string BikeStation::status() const {
    ostringstream os;
    os << bikes << " out of " << capacity;
    return os.str();
}

BikeStation::BikeStation(Location where, unsigned int cap, unsigned int numBikes):
loc{where}, capacity{cap}, bikes{numBikes}{
    
    display.push_back(new Rectangle{loc.p, dispWidth, dispHeight});
    display[display.size()-1].set_fill_color(Color::white);

    Text* txt = new Text{loc.p, loc.name};
    txt->set_color(Color::blue);
    txt->set_font_size(20);
    display.push_back(txt);

    string statement = status();
    Point location{loc.p.x+2,loc.p.y+15};
    Text* stat = new Text{location, statement};
    stat->set_color(Color::black);
    display.push_back(stat);
}

map<string, int> simulateOneDay(vector<BikeStation*> bs){
    map<string, int> declinedRides;
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int ride = 0; ride<ridesPerDay; ++ride){
        int randomNumFrom = rand() % bs.size();
        int randomNumTo = rand() % bs.size();
        //Burde sjekka om disse to random tallene er like! Ellers greit løst!
        BikeStation* randomStationFrom = bs[randomNumFrom];
        BikeStation* randomStationTo = bs[randomNumTo];
        if (!(randomStationFrom->getCapacity() > 0 && randomStationTo->getCapacity() > 0)){
            declinedRides[randomStationFrom->getName()]++;
        } else if (randomStationFrom->getCapacity() > 0 && randomStationTo->getCapacity() > 0){
            randomStationFrom->setBikes(randomStationFrom->getBikes() - 1);
            randomStationTo->setBikes(randomStationTo->getBikes() + 1);
        }
    } 
    return declinedRides;
}

void printStats(map<string, int> declined){
    cout << "Unsuccessful rides:" << endl;
    for (auto pair : declined){
        cout << pair.second << " bike trips refused at " << pair.first << endl;
    }
}
