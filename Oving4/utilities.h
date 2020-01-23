int incrementByValueNumTimes(int startValue, int increment, int numTimes);
int incrementByValueNumTimesRef(int& startValue, int& increment, int& numTimes);
void swapNumbers(int& num1, int& num2);
void randomizeVector(vector<int>& vec, int n);
void sortVector(vector<int>& vec);
double medianOfVector(const vector<int>& vec);

struct Student {
    string name;
    string studyProgram;
    int age;
};

void printStudent(Student student);

string randomizeString(int characters, char lowerLimit, char upperLimit);
string readInputToString(int characters, char lowerLimit, char upperLimit);
int countChar(string text, char letter);
