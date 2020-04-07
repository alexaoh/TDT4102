#include "Task2.h"
float Plant::readHumidity(){
    humidity = readSensor(); //Kode fra oppgaven. Denne har jeg derfor ikke implementert. 
    return humidity;
}   

PlantStatus Plant::getStatus() const {
    if (humidity < 0) return PlantStatus::SENSOR_ERROR;
    else if (humidity > humidityMax) return PlantStatus::WATER_HIGH;
    else if (humidity < humidityMin) return PlantStatus::WATER_LOW;
    else return PlantStatus::HAPPY_PLANT;
}

bool Plant::operator==(Plant &rhs){
    return sensorId == rhs.sensorId;
}

std::ostream &operator<<(std::ostream& out, const Plant &p){
    out << p.name << " @ " << p.location;
    return out;
}

void Garden::addPlant(const Plant p){
    plants.push_back(p);
}

void Garden::removePlant(Plant p){
    std::vector<Plant>::iterator it = plants.begin();
    while (it != plants.end()){
        if (*it == p) it = plants.erase(it);
        else ++it;
    }
}

std::vector<Plant> Garden::needsHelp(){
    std::vector<Plant> danger;
    for (auto x : plants){
        x.readHumidity();
        if (x.getStatus() != PlantStatus::HAPPY_PLANT){
            danger.push_back(x);
        }
    }
    return danger;
}

void Garden::monitor(int interval){
    std::vector<Plant> needHelp = needsHelp();
    for (auto x : needHelp){
        std::cout << x << ": ";
        if (x.getStatus() == PlantStatus::WATER_LOW) std::cout << "trenger vann!";
        else if (x.getStatus() == PlantStatus::WATER_HIGH) std::cout << "har for mye vann!";
        else std::cout << "sensorfeil";
        std::cout << "\n";
        sleep(interval); //Definert i oppgaven og derfor ikke implementert av meg!
    }
}
