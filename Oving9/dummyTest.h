class Dummy {
public: 
    int* num;
    Dummy(){
        num = new int{0};
    }
    Dummy(const Dummy&); //Copy constructor --> skrev ikke ut noe annerledes etter implementasjon av denne!
    Dummy& operator=(const Dummy&); //Assignment operator

    ~Dummy(){
        delete num;
    }
};

void dummyTest();
