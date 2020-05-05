#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Vector {
    int *elems;
    int size;

public:
    Vector() : size{0} {
        elems = new int[10];
    }

    void add(int elem) {
        elems[size++] = elem;
    }

    int &operator[](int pos) {
        if (pos < 0 || pos >= size) {
            throw runtime_error("Index out of bounds.");
        }

        return elems[pos];
    }

    ~Vector() {
        delete [] elems;
    }
};

int main() {
    vector<string> v{"she", "sells", "sea", "shells" ,"by", "the", "sea", "shore"};
    auto it = v.end() - 3;
    //cout<<*it;
    v.erase(it);
    it = v.end() - 2- count_if(v.begin(), v.end(), [] (string x) {return x[0] != 's';});
    v.erase(it);
    v.pop_back();
    v.pop_back();
    it = v.end() - 4;
    *it = "susan";
    it++; it++;
    it = find_if(v.begin(), v.end(), [] (string x) {return (x == "sea") ;});
    *it = "susan";
    for(auto i:v)
        cout<< i << " ";
    return 0;
}