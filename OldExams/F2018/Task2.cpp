#include "Task2.h"

std::vector<Obs> readObservations(){
    std::ifstream ist{"input.txt"};
	if (!ist) throw  std::invalid_argument("Cannot open \'input.txt\'");
	std::string line;
    std::vector<Obs> observations;
	while(getline(ist, line)){
		std::stringstream ss{line};
		int num1{0};
		int num2{0};
		ss >> num1 >> num2;
		if (num1 >= 0){
            Obs newObs;
            newObs.x = num1;
            newObs.y = num2;
            observations.push_back(newObs);
        }
	}
    return observations;
}

bool operator<(Obs lhs, Obs rhs){
    if (lhs.x == rhs.x) return lhs.y < rhs.y;
    return lhs.y < rhs.y;
}

void report(std::vector<Obs> vec, int threshold){
    std::map<Obs, int> obsNum;
    for (auto x : vec){
        obsNum[x] += 1;
    }

    for (auto x : obsNum){
        int num = x.second;
        if (num > threshold){
            std::cout << x.first.x << " " << x.first.y << " " << num << std::endl;
        }
    }
}
