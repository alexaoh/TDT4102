#include "Task3.h"

bool operator<(const Food& lhs, const Food& rhs){
    return lhs.price < rhs.price;
}

void addPrice(map<string, set<Food>>& db, Food fp){
    db[fp.name].insert(fp);
}

void printAllPrices(const map<string, set<Food>>& db){
    for (const auto pair : db){
        cout << pair.first << ":" << endl;
        for (const auto x : pair.second)
            cout << x.price << " " << x.where << endl;
    }
}

void bestPrice(const map<string, set<Food>>& db, string name){
    auto it = db.find(name);
    if (it != db.end()){
        cout << "Best price for " << name << " is " << it->second.begin()->price << " at " << it->second.begin()->where;
    } else {
        cout << "No price for " << name;
    }
}
