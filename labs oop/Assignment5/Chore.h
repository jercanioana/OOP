//
// Created by Ioana Jercan on 2019-03-22.
//

#ifndef ASSIGNMENT5_CHORE_H
#define ASSIGNMENT5_CHORE_H
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

class Chore {
private:
    std::string title;
    std::string type;
    std::string lastPerformed;
    int timesPerformed;
    std::string vision;
public:
    Chore();
    Chore(const std::string& title, const std::string& type, const std::string& lastPerformed,const int& timesPerformed, const std::string& vision);
    ~Chore();

    friend std::istream& operator>>(std::istream& istream, Chore& chore);
    friend std::ostream& operator<<(std::ostream& ostream, const Chore& chore);
    std::string GetTitle() const {
        return this->title;
    }
    std::string GetLastDatePerformed() const{
        return this->lastPerformed;
    }
    std::string GetType() const{
        return this->type;
    }
    int GetTimesPerformed() const{
        return this->timesPerformed;
    }
    std::string GetVision() const{
        return this->vision;
    }

};

#endif //ASSIGNMENT5_CHORE_H
