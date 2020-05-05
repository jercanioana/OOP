//
// Created by Ioana Jercan on 2019-03-23.
//

#ifndef ASSIGNMENT5_SERVICE_H
#define ASSIGNMENT5_SERVICE_H

#include "Repository.h"
#include "FileManager.h"
#include <algorithm>

class Service {
private:
//    FileManager fileManager;
//    HTMLFileManager htmlFileManager;
//    CSVFileManager csvFileManager;
    Repository repository;
public:
    //explicit Service(FileManager& fileManager, HTMLFileManager& htmlFileManager, CSVFileManager& csvFileManager): fileManager(fileManager), htmlFileManager(htmlFileManager), csvFileManager(csvFileManager) {}
    explicit Service(Repository* repository) : repository{} {}
    void Add(const std::string &title, const std::string &type, const std::string &lastPerformed,
             const int &timesPerformed, const std::string &vision);
    void Remove(const std::string &title);

    void Update(const std::string &title, const std::string &newType, const std::string &newLastPerformed,
                const int &newTimesPerformed, const std::string &newVision);
    std::vector<Chore> GetAll();
    void SaveChore(const std::string &title);
    std::vector<Chore> GetMyList();
    //void ChangePathForTextFile(const std::string& newPath);
    int Size();
    int SizeOfList();
    std::vector<Chore> FilterByTypeAndTimesPerformed(std::string type, int timesPerformed);
    int ExistingChore(const std::string& title);
    //std::string GetPathHTML() { return this->htmlFileManager.GetPath();}
    //std::string GetPathCSV() { return this->csvFileManager.GetPath();}
    //void ChangePathForHTML(const std::string& newPath);
    //void ChangePathForCSV(const std::string& newPath);
};


#endif //ASSIGNMENT5_SERVICE_H
