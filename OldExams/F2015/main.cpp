#include <iostream>
#include <iomanip>

#include "Task1.h"
#include "Task2.h"

int main(){
	string s1 = "Kama Sutra";
	string s2 = "Austmarka";
	bool val = isAnagram(s1, s2);
	cout << boolalpha << val << endl;

	string s3 = "Agnes i senga";
	cout << isPalindrome(s3) << endl;

	double arra[] = {1,2,3,4,5,6,7,8,9,10};
	double mea = mean(arra, 10);
	cout << mea << endl;
}

