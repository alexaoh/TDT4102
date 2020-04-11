#include "Task2.h"

int checkAlarm(const double value, const double threshold){
    if (value > threshold && value <= MAX_WIND) return 1;
    else if (value < 0 || value > MAX_WIND) return -1;
    else return 0;
}

void printAlarm(const int id, const double wind, const int dir){
    std::string heavenDir;
    if (dir >= 45 && dir <= 135) heavenDir = "Øst";
    else if (dir >= 135 && dir <= 224) heavenDir = "Syd";
    else if (dir >= 225 && dir <= 314) heavenDir = "Vest";
    else heavenDir = "Nord";

    std::cout << "ALARM " << id << ": " << std::fixed << std::setprecision(2) << wind << " fra " << heavenDir << std::endl;
}

std::ostream& operator<<(std::ostream& out, const sample& s){
    out << s.id << " " << s.wind << " " << s.dir;
    return out;
}

void readMeasurements(const char* filename){
    std::ifstream ist{filename};
    if (!ist) throw std::runtime_error("cannot open input file");
    sample newSample;
    std::string line;
    int i = 0;
    while (getline(ist, line)){
        std::stringstream ss{line};
        ss >> newSample.id >> newSample.wind >> newSample.dir;
        measurements[newSample.id-1][i] = newSample;
        if (newSample.id == N_SAMPLES) i++;
    }
}

std::vector<sample> calcStats(){
    std::vector<sample> vec;
    for (int i = 0; i < N_MILLS; ++i){
        sample s;
        sample s_max;
        int sum{0};
        s_max.dir = measurements[i][0].dir;
        for (int e = 0; e < N_SAMPLES; ++e){
            if (measurements[i][e].dir >= s_max.dir) s_max.dir = measurements[i][e].dir;
            sum += measurements[i][e].wind;
        }
        s.wind = sum/N_SAMPLES;
        s.id = i;
        s.dir = s_max.dir;
        vec.push_back(s);
    }  
    return vec;
}

bool operator<(const sample& lhs, const sample& rhs){
    return lhs.wind < rhs.wind;
}

int checkMeasurements(){
    int total{0};
    for (int i = 0; i < N_MILLS; ++i){
        int totalPerMill{0};
        for (int e = 0; e < N_SAMPLES; ++e){
            if (measurements[i][e].wind == -1.0){
                totalPerMill++;
                total++;
            }
            if (totalPerMill > 1){
                throw measurements[i][e].id;
            }
        }
    }
    return total;
}

void repairMeasurements(){
    for (int i = 0; i < N_MILLS; ++i){
        for (int e = 0; e < N_SAMPLES; ++e){
            if (measurements[i][e].wind == -1.0){
                if (e == 0) measurements[i][e].wind = measurements[i][e+1].wind;
                else if (e == N_SAMPLES-1) measurements[i][e].wind = measurements[i][e-1].wind;
                else{
                    double windLeft = measurements[i][e-1].wind;
                    double windRight = measurements[i][e+1].wind;
                    measurements[i][e].wind = (windLeft + windRight)/2.0;
                } 
            }
        }
    }
}
