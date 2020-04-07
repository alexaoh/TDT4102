#include "Task2.h"
#include "Task3.h"
#include "Task4.h"

int main(){
	//Task 2: 
	/*
	Plant Orkidé{"Orkidé", "Her", 1, 10, 25};
	Plant Kaktus{"Kaktus", "her", 2, 5, 10};
	Plant Basilikum{"Basilikum", "her", 3, 25, 50};
	Plant Mynte{"Mynte", "her", 4, 20, 50};

	Garden myGarden{"myGarden"};
	myGarden.addPlant(Orkidé);
	myGarden.addPlant(Kaktus);
	myGarden.addPlant(Basilikum);
	myGarden.addPlant(Mynte);
	myGarden.monitor(5*60);
	*/

	//Task 3: 
	//3e)
	/*
	int ledd{0};
	double epsilon{0.000001};
	int max{0};
	int maxAngle{0};
	for (int angle = 0; angle <=180; ++angle){
		ledd = testTaylor(angle, epsilon);
		if (ledd >= max){
			max = ledd; 
			maxAngle = angle;
		}
	}
	std::cout << maxAngle << " : " << max << " ledd " << std::endl;
	*/

}
