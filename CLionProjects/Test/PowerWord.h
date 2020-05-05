//
// Created by Ioana Jercan on 2019-04-10.
//

#ifndef TEST_POWERWORD_H
#define TEST_POWERWORD_H
#include <iostream>

class PowerWord {
private:
    std::string name;
    std::string runes;
public:
    PowerWord();
    PowerWord(const std::string& name, const std::string& runes);
    ~PowerWord();
    std::string GetName(){
        return this->name;
    }
    std::string GetRunes(){
        return this->runes;
    }
};


#endif //TEST_POWERWORD_H
