#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <cassert>
#include <cmath>

using namespace std;

double sum(vector<double>& x);
double mean(vector<double>& x);
void read_csv(string filename, vector<double>& x, vector<double>& y);
pair<double, double> linreg(vector<double>& x, vector<double>& y);
vector<double> linpred(vector<double>& x, double a, double b);
double r2(vector<double>& y, vector<double>& y_pred);
