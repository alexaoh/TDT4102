#include "std_lib_facilities.h"
#include "cannonball.h"
#include "utilities.h"

void testDeviation(double compareOperand, double toOperand, double maxError, string name);

int main(){
	//Test hver funksjon fra main (3b)): 
	cout << "Test acc1Y(): " << acc1Y() << endl;
	cout << "Test ve1Y(): " << ve1Y(25.0, 2.5) << endl;
	cout << "Test posX(): " << posX(0.0, 50.0, 2.5) << endl;
	cout << "Test posY(): " << posY(0.0, 25.0, 2.5) << endl;
	cout << "Test printTime(): " << endl; 
	printTime(10000);
	cout << "Test flightTime(): " << flightTime(25.0) << endl;
	//the answers seem reasonable.  

	testDeviation(acc1Y(), -9.81, 0.01, "acc1Y()");
	testDeviation(ve1Y(25.0, 2.5), 0.475, 0.001, "ve1X()");
	testDeviation(posX(0.0, 50.0, 2.5), 125, 0.1, "posX()");
	testDeviation(posY(0.0, 25.0, 2.5), 31.84, 0.01, "posY()"); 

}

void testDeviation(double compareOperand, double toOperand, double maxError, string name){
	cout << "The function being tested is: " << name << ". "; 
	if (abs(compareOperand-toOperand) < maxError){
		cout << "The operands are almost identical. The values are similar to the degree of " << maxError << endl; 
	} else cout << "The operands are not within the wanted range to be considered as equal" << endl; 

	return; 
}
