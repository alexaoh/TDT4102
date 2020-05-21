#include <map>
#include <set>
#include <string>
#include <iostream>

using namespace std;

struct Food{
    string name; 
    double price;
    string where;
};

bool operator<(const Food& lhs, const Food& rhs);
void addPrice(map<string, set<Food>>& db, Food fp);
void printAllPrices(const map<string, set<Food>>& db);
void bestPrice(const map<string, set<Food>>& db, string name);
