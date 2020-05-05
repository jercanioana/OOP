//
// Created by Ioana Jercan on 2019-04-10.
//

#include "FileManager.h"
#include "vector"
using namespace std;

FileManager::FileManager(const std::string &filename, std::vector<Chore> &chores, std::vector<Chore> &myList): Repository(chores, myList) {
    this->filePath.assign(filePath);
    this->LoadFromFile();
}

void FileManager::AddElement(const Chore &chore) {
    Repository::AddElement(chore);
    this->WriteToFile();
}

void FileManager::RemoveElement(const std::string &title) {
    Repository::RemoveElement(title);
    this->WriteToFile();
}

void FileManager::UpdateElement(const Chore& chore) {
    Repository::UpdateElement(chore);
    this->WriteToFile();
}

void FileManager::LoadFromFile() {
    ifstream inputFile(this->filePath);
    Chore inputChore;
    if (!inputFile.is_open())
        return;
    while (inputFile >> inputChore)
    {
        chores.push_back(inputChore);
    }

}

void FileManager::WriteToFile() {
    ofstream outputFile(this->filePath);
    if(!outputFile.is_open())
        return;

    for(auto & chore : chores) {
        outputFile << chore;
    }
    outputFile.close();
}
void FileManager::ChangePath(const std::string& newPath) {
    this->filePath.assign(newPath);
    this->chores.clear();
    this->LoadFromFile();
}

void HTMLFileManager::SaveElement(const std::string &title) {
    Repository::SaveElement(title);
    this->WriteToFile();
}
HTMLFileManager::HTMLFileManager(const std::string &filePath, std::vector<Chore> &chores, std::vector<Chore> &myList): Repository(chores, myList) {
    this->filePath.assign(filePath);

}
Chore HTMLFileManager::FindByTitle(const std::string &title) {
    Chore chore = Repository::FindByTitle(title);
    return chore;
}

void HTMLFileManager::WriteToFile() {
    ofstream outputFile(this->filePath);
    outputFile << "<!DOCTYPE html>" << endl;
    outputFile << "<html>" << endl;
    outputFile << "<head><title>Chores</title></head>" << endl;

    outputFile << "<body>" << endl;
    outputFile << "<table border='1'>" << endl;
    outputFile << "<tr>" << endl;
    outputFile << "<td>Title</td>" << endl;
    outputFile << "<td>Type</td>" << endl;
    outputFile << "<td>Last Date Performed</td>" << endl;
    outputFile << "<td>Times Performed</td>" << endl;
    outputFile << "<td>Vision</td>" << endl;
    outputFile << "</tr>" << endl;

    for (const auto& element : myList) {
        outputFile << "<tr>" << endl;
        outputFile << "<td>" << element.GetTitle() << "</td>" << endl;
        outputFile << "<td>" << element.GetType() << "</td>" << endl;
        outputFile << "<td>" << element.GetLastDatePerformed() << "</td>" << endl;
        outputFile << "<td>" << element.GetTimesPerformed() << "</td>" << endl;
        outputFile << "<td>" << element.GetVision() << "</td>" << endl;
        outputFile << "</tr>" << endl;
    }

    outputFile << "</table>" << endl;
    outputFile << "</body>" << endl;
    outputFile << "</html>" << endl;
}
void HTMLFileManager::ChangePath(const std::string &newPath) {
    this->filePath.assign(newPath);
    this->myList.clear();

}

Chore CSVFileManager::FindByTitle(const std::string &title) {
    Chore chore = Repository::FindByTitle(title);
    return chore;
}
CSVFileManager::CSVFileManager(const std::string &filePath,std::vector<Chore> &chores, std::vector<Chore> &myList): Repository(chores, myList) {
    this->filePath.assign(filePath);
}
void CSVFileManager::WriteToFile() {
    ofstream outputFile(this->filePath);
    if(!outputFile.is_open())
        return;

    for(auto & chore : chores) {
        outputFile << chore;
    }
    outputFile.close();
}

void CSVFileManager::ChangePath(const std::string &newPath) {
    this->filePath.assign(newPath);
    this->myList.clear();
}

void CSVFileManager::SaveElement(const std::string &title) {
    Repository::SaveElement(title);
    this->WriteToFile();

}

void HTMLFileManager::AddElement(const Chore &chore) {
    Repository::AddElement(chore);
}

void CSVFileManager::AddElement(const Chore &chore) {
    Repository::AddElement(chore);
}

FileManager::~FileManager() {

}

HTMLFileManager::~HTMLFileManager() {

}

CSVFileManager::~CSVFileManager() {

}