#include <iostream>
#include <iomanip>
#include <fstream>
#include <exception>
#include <sstream>
#include <vector>

const double MAX_WIND = 10.0; //e.g
int checkAlarm(const double value, const double threshold);
void printAlarm(const int id, const double wind, const int dir);

struct sample{
    int id;
    double wind;
    int dir;
};

std::ostream& operator<<(std::ostream& out, const sample& s); 

const int N_MILLS = 278;
const int N_SAMPLES = 10;
sample measurements[N_MILLS][N_SAMPLES];

void readMeasurements(const char* filename);

std::vector<sample> calcStats();
bool operator<(const sample& lhs, const sample& rhs);
int checkMeasurements();
void repairMeasurements();
