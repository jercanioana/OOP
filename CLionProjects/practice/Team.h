//
// Created by Ioana Jercan on 2019-04-08.
//

#ifndef PRACTICE_TEAM_H
#define PRACTICE_TEAM_H
#include <iostream>

class Team {
private:
    std::string name;
    std::string country;
    int score;
public:
    Team();
    Team(const std::string& name, const std::string& country, const int score);
    ~Team();
    std::string getName() const{
        return this->name;
    }
    std::string getCountry()const{
        return this->country;
    }
    int getScore()const{
        return this->score;
    }
    void setScore(int newScore){
        this->score = newScore;
    }
};




#endif //PRACTICE_TEAM_H
