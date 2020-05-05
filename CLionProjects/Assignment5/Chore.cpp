//
// Created by Ioana Jercan on 2019-03-22.
//

#include "Chore.h"

using namespace std;

Chore::Chore() : title { "" }, type { "" }, lastPerformed { "" }, timesPerformed{}, vision { "" }
{
}
Chore::Chore(const std::string& newTitle, const std::string& newType, const std::string& newLastPerformed, const int& newTimesPerformed, const std::string& newVision):
    title{newTitle}, type{newType}, lastPerformed {newLastPerformed}, timesPerformed{newTimesPerformed}, vision{newVision} {
}
Chore::~Chore() {
}

vector<string> tokenize(string basicString, char delimiter)
{
    vector <string> result;
    stringstream string_stream(basicString);
    string token;
    while (getline(string_stream, token, delimiter))
        result.push_back(token);

    return result;
}

std::istream & operator>>(std::istream & istream, Chore & chore)
{
    string line;
    getline(istream, line);
    vector<string> tokens = tokenize(line, ',');
    if (tokens.size() != 5)
        return istream;
    chore.title = tokens[0];
    tokens[1].replace(0, 1, "");
    chore.type = tokens[1];
    tokens[2].replace(0, 1, "");
    chore.lastPerformed = tokens[2];
    tokens[3].replace(0, 1, "");
    chore.timesPerformed = atoi(tokens[3].c_str());
    tokens[4].replace(0, 1, "");
    chore.vision = tokens[4];
    return istream;
}

std::ostream & operator<<(std::ostream & ostream, const Chore & chore)
{
    ostream << chore.title << ", " << chore.type << ", " << chore.lastPerformed << ", " << chore.timesPerformed << ", " << chore.vision << "\n";
    return ostream;
}
