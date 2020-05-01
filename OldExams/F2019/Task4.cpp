#include "Task4.h"

RingBuf::RingBuf(int capacity):
buf{new char[capacity]}, capacity{capacity},start{0}, size{0}{}

RingBuf::RingBuf(const RingBuf& other):RingBuf(other.capacity){
    copy(other.buf, other.buf + other.size, buf);
    start = other.start;
    size = other.size;
}

RingBuf::~RingBuf(){
    delete[] buf;
}

RingBuf::RingBuf(RingBuf&& other):
buf{other.buf}, capacity{other.capacity}, start{other.start}, size{other.size}{
    other.buf = nullptr;
    other.capacity = 0;
    other.size = 0;
    other.start = 0;
}

RingBuf& RingBuf::operator=(RingBuf rhs){
    swap(buf, rhs.buf);
    swap(capacity, rhs.capacity);
    swap(start, rhs.start);
    swap(size, rhs.size);
    return *this;
}

void RingBuf::write(char c){
    buf[start] = c;
    if (start == capacity) start = 0;
    else start++;
    if (!(size==capacity)) size++;
    //Glemte å ta hensyn til at verdien må skrives til etter start+size!
    //kan gjøres ved å skrive:
    if (size == capacity){
        buf[start] = c;
        start++;
        if (start == capacity) start = 0;
    } else{
        buf[(start+size)%capacity] = c;
        size++;
    }
}

char RingBuf::read(){
    if (size==0) throw "The buffer is empty";
    char c = buf[start];
    if (start == capacity) start = 0;
    else start++;
    size--;
    return c;
}

void RingBuf::write(string s){
    istringstream is{s};
    char c;
    while (is >> c){
        write(c);
    }
}

string RingBuf::read(int count){
    string str;
    if (count == -1 || count > size){
        for (int i = start; i<size; ++i){
            str.push_back(read());
        }
    } else{
        for (int i = start; i<count;++i){
            str.push_back(read());
        }
    }
    return str;
}

string RingBuf::peek(){
    string str = read(-1);
    return str;
}

void testRingBuf(){
    RingBuf rb{5};
    assert(rb.size == 0 && rb.start == 0);
    string p = rb.peek();
    assert(p == "");

    rb.write("ABC");
    assert(rb.size == 3 && rb.start == 0);
    p = rb.peek();
    assert(p == "ABC");

    rb.write("DEF");
    assert(rb.size == 5 && rb.start == 1);
    p = rb.peek();
    assert(p == "FBCDE");

    string s = rb.read(3);
    assert(rb.size == 2 && rb.start == 1);
    p = rb.peek();
    assert(p == "FE");

    s = rb.read(-1);
    assert(rb.size == 0 && rb.start == 1);
    p = rb.peek();
    assert(p == "");

}
