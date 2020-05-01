#include "Task2.h"

double sum(vector<double>& x){
    double sum{0.0};
    for (int i = 0; i<x.size(); ++i){
        sum += x[i];
    }
    return sum;
}

double mean(vector<double>& x){
    double s = sum(x);
    return s/static_cast<double>(x.size());
}

void read_csv(string filename, vector<double>& x, vector<double>& y){
    ifstream ist{filename};
    if (!ist) throw runtime_error("Coouldn't read file "+filename);
    string line;
    while(getline(ist, line)){
        double xVal, yVal;
        istringstream is{line};
        is >> xVal >> yVal;
        x.push_back(xVal);
        y.push_back(yVal);
    }
}

pair<double, double> linreg(vector<double>& x, vector<double>& y){
    assert(x.size() == y.size()); //antar at de er like store, noe de må være for at matematikken skal stemme også!
    double yAvg = mean(y);
    double xAvg = mean(x);
    double cov{0.0};
    double var{0.0};
    
    for (int i = 0; i<x.size()-1; ++i){
        var += pow(x[i]-xAvg,2);
        cov += (x[i]-xAvg)*(y[i]-yAvg);

    }

    double a = cov/var;
    double b = yAvg - a*xAvg;
    return {a,b}; //Utilize implicit conversion. 
}

vector<double> linpred(vector<double>& x, double a, double b){
    vector<double> y;
    for (auto xi : x){
        y.push_back(a*xi+b);
    }
    return y;
}

double r2(vector<double>& y, vector<double>& y_pred){
    assert(y.size() == y_pred.size()); //Samme antagelse om lik str på y-er hele veien! (Dette er tilfelle her siden y_pred er laget fra y)
    double rSquared{1.0};
    double up{0.0};
    double down{0.0};
    double yAvg = mean(y);
    for (int i = 0; i<y_pred.size(); ++i){
        up += pow(y[i]-y_pred[i],2);
        down += pow(y[i]-yAvg,2);
    }
    return rSquared -= up/down;
}

