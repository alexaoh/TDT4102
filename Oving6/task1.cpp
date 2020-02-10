#include "std_lib_facilities.h"
#include "task1.h"

void writeToFile(){
	cout << "Write the name of the file ypu want to write to: " << endl;
	string oname;
	cin >> oname; 
	ofstream ost{oname}; //Opens file with name oname
	if (!ost) error("Can't open output file ", oname);

	string text;
	do{
		cout << "Write something to the file " << oname << "; ";
		cin >> text;
		if (text == "quit"){
			break;
		}
		ost << text << endl;
	} while (text != "quit");
	
}

void linenumber(){
    cout << "Enter input file name " << endl; 
    string iname;
    cin >> iname;
    ifstream ist{iname};
    if (!ist) error("Can't open input file, ", iname);
    vector<string> inputs;
    string in;
    while (getline(ist, in)){
        inputs.push_back(in); //save each line in a vector for now
    }

    cout << "Enter output file name " << endl; 
    string oname;   
    cin >> oname; 
    ofstream ost{oname};
    if (!ost) error("Can't open output file, ", oname);

    //write each line from the vector to another file
    for (int i = 0; i<inputs.size(); ++i){
        ost << i+1 << " " << inputs[i] << endl; 
    }


}
