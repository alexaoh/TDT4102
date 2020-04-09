#include "Task2.h"

int main(){
    /* //testing stringToDate() in Task2. 
	std::string string1 = "1994-12-08";
    std::string string2 = "0aaa-0b-0c"; //even though this does not give an error!?
    
    Date heisann{stringToDate(string1)};
    Date testing{stringToDate(string2)};
    std::cout << heisann.d << " " << heisann.m << " " << heisann.y << std::endl;
    std::cout << testing.d << " " << testing.m << " " << testing.y << std::endl;
    */
   Date d;
   d.y = 20;
   d.m = 2;
   d.d = 1;
   std::string hei{dateToString(d)};
   std::cout << hei;
}
