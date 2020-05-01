#include <iostream>
#include "Task2.h"

int main(){
	//Main for task 2;
	vector<double> x;
	vector<double> y;
	read_csv("data.csv", x, y);
	pair<double, double> aB = linreg(x, y);
	vector<double> pred = linpred(x, aB.first, aB.second);
	double r = r2(y, pred);
	cout << "a = " << aB.first << ", b = " << aB.second << ", R^2 = " << r << endl;
}
