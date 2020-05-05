//
// Created by Ioana Jercan on 2019-04-10.
//

#ifndef ASSIGNMENT5_FILEMANAGER_H
#define ASSIGNMENT5_FILEMANAGER_H

#include "Repository.h"

class FileManager: public Repository{
private:
    std::string filePath;
public:
    FileManager(const std::string& filePath, std::vector<Chore>& chores, std::vector<Chore> &myList);
    void LoadFromFile();
    void WriteToFile();
    void AddElement(const Chore& chore) override;
    void RemoveElement(const std::string& title) override;
    void UpdateElement(const Chore& chore) override;

    void ChangePath(const std::string& newPath);
    ~FileManager();
};
class HTMLFileManager: public Repository{

private:
    std::string filePath;
public:

    HTMLFileManager(const std::string& filePath,std::vector<Chore> &chores, std::vector<Chore>& myList);
    std::string GetPath(){ return this->filePath;}
    void WriteToFile();
    Chore FindByTitle(const std::string& title) override;
    void SaveElement(const std::string& title) override;
    void AddElement(const Chore& chore) override;
    void ChangePath(const std::string& newPath);
    ~HTMLFileManager();
};

class CSVFileManager: public Repository{
private:
    std::string filePath;
public:
    CSVFileManager(const std::string& filePath,std::vector<Chore> &chores, std::vector<Chore>& myList);
    void WriteToFile();
    std::string GetPath(){ return this->filePath;}
    Chore FindByTitle(const std::string& title) override;
    void AddElement(const Chore& chore) override;
    void SaveElement(const std::string& title) override;
    void ChangePath(const std::string& newPath);
    ~CSVFileManager();
};
#endif //ASSIGNMENT5_FILEMANAGER_H
