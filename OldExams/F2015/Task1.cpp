#include "Task1.h"


bool isAnagram(const string& a, const string& b){
    string ac;
    string bc;
    //Dette virker ikke av ev en eller annen grunn!? Kjør brute force i stedet. 
    /*
    copy_if(a.begin(), a.end(), ac.begin(), [](char c){ return true; });
    copy_if(b.begin(), b.end(), bc.begin(), [](char c){ return isalpha(c); });
    cout << ac << bc << endl;
    transform(ac.begin(), ac.end(), ac.begin(), [](char c) { return tolower(c); });
    transform(bc.begin(), bc.end(), bc.begin(), [](char c) { return tolower(c); });
    sort(ac.begin(), ac.end());
    sort(bc.begin(), bc.end());
    return (ac == bc);
    */

    for (auto x : a){ //Dette burde jo bare være en enkel copy!?
        if (isalpha(x)) ac.push_back(tolower(x));
    }
    for (auto x : b){
        if (isalpha(x)) bc.push_back(tolower(x));
    }
    cout << ac << " " << bc << endl;
    sort(ac.begin(), ac.end());
    sort(bc.begin(), bc.end());
    cout << ac << " " << bc << endl;
    return (ac == bc);
}

bool isPalindrome(const string& str){
    string strCopy; //Gets reversed
    string strCopy2; //Not reversed
    for (auto x : str){
        if (isalpha(x)){
            strCopy.push_back(tolower(x));
            strCopy2.push_back(tolower(x));
        }
    }
    reverse(strCopy.begin(), strCopy.end());
    return strCopy == strCopy2;
}

void printWordStatistics(const string& filename){
    ifstream ist{filename};
    if (!ist) throw runtime_error("Cannot open file "+filename);
    map<string, int> values;
    for (string word; cin >> word; ){
        ++values[word];
    }
    for (auto pair : values){
        cout << pair.first << ": " << pair.second << endl;
    }

}

double mean(double arr[], int size){
    double sum = accumulate(arr, arr + size, 0);
    return sum/size;
}

double median(int arr[], int size){
    if (size % 2 == 0){
        return (arr[(size-2)/2]+arr[(size)/2])/2.0;
    } else {
        return arr[size/2];
    }
}

double round(double num, int precision){
    //Dette dekker kun positive tall, men vil ikke bruke supplied round her, for det vil gi noe rart. 
    int prec = pow(10, precision);
    int rounded = (num * prec) + 0.5;
    return rounded/static_cast<double>(prec);
}



