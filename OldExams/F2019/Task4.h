#include <iostream>
#include <string>
#include <algorithm> //kanskje disse trengs for konstruktørene
#include <utility>
#include <sstream>
#include <cassert>

using namespace std;

class RingBuf{
    char* buf;
    int capacity; 
    int start;
    int size;
public:
    RingBuf(int capacity);
    RingBuf(const RingBuf& other);
    RingBuf(RingBuf&& other);
    ~RingBuf();
    RingBuf& operator=(RingBuf rhs);
    void write(char c);
    void write(string s);
    char read();
    string read(int count);
    string peek();
    friend void testRingBuf();
};

void testRingBuf();
