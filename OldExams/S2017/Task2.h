#include <iostream>
#include <vector>
#include <iterator>

enum class PlantStatus{
    HAPPY_PLANT, WATER_LOW, WATER_HIGH, SENSOR_ERROR
};

class Plant{    
    std::string name;
    std::string location;
    int sensorId;
    float humidityMin;
    float humidityMax;
    float humidity;
public:
    Plant(std::string nam, std::string loc, int id, float humMax, float humMin):name{nam}, 
    location{loc}, sensorId{id}, humidityMin{humMin}, humidityMax{humMax}, humidity{-1.0}{};

    void setName(const std::string nam){ name = nam; }
    std::string getName() const { return name; }

    float readHumidity();
    float readSensor();
    PlantStatus getStatus() const;

    bool operator==(Plant &rhs);

    friend std::ostream &operator<<(std::ostream& out, const Plant &p);
};

class Garden{
    std::string name;
    std::vector<Plant> plants;
public:
    Garden(std::string nam):name{nam}, plants(){};
    void addPlant(const Plant p);
    void removePlant(Plant p);

    std::vector<Plant> needsHelp();
    void monitor(int interval);
    void sleep(int seconds); //Definert i oppgaven og derfor ikke implementert av meg!

};  
