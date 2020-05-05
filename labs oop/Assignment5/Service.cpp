//
// Created by Ioana Jercan on 2019-03-23.
//

#include "Service.h"
#include "Validator.h"
void Service::Add(const std::string &title, const std::string &type, const std::string &lastPerformed,
                  const int &timesPerformed, const std::string &vision) {
    if(Validator::ValidateChore(title, type, lastPerformed, timesPerformed, vision)) {
        Chore chore{title, type, lastPerformed, timesPerformed, vision};
//        this->fileManager.AddElement(chore);
//        this->htmlFileManager.AddElement(chore);
//        this->csvFileManager.AddElement(chore);
            this->repository.AddElement(chore);
    }
}
int Service::Size()
{
    //return this->fileManager.Size();
    return this->repository.Size();
}
int Service::SizeOfList() {
    //return this->fileManager.SizeOfMyList();
    return this->repository.SizeOfMyList();
}
void Service::SaveChore(const std::string &title) {
    if(Validator::ValidateTitle(title)) {
//        this->fileManager.SaveElement(title);
//        this->htmlFileManager.SaveElement(title);
//        this->csvFileManager.SaveElement(title);
            repository.SaveElement(title);
    }
}
std::vector<Chore> Service::GetAll() {
    //return this->fileManager.GetElements();
    return repository.GetElements();
}

std::vector<Chore> Service::GetMyList() {
    //return this->fileManager.GetMyList();
    return repository.GetMyList();
}

void Service::Remove(const std::string &title) {
    if(Validator::ValidateTitle(title)) {
        this->repository.RemoveElement(title);
        //this->fileManager.RemoveElement(title);
    }
}
void Service::Update(const std::string &title, const std::string &newType, const std::string &newLastPerformed,
                     const int &newTimesPerformed, const std::string &newVision) {
    if(Validator::ValidateChore(title, newType, newLastPerformed, newTimesPerformed, newVision)) {
        Chore chore{title, newType, newLastPerformed, newTimesPerformed, newVision};
        this->repository.UpdateElement(chore);
        //this->fileManager.UpdateElement(chore);
    }
}

/*void Service::ChangePathForTextFile(const std::string& newPath) {
    this->fileManager.ChangePath(newPath);
}

void Service::ChangePathForCSV(const std::string& newPath) {
    this->csvFileManager.ChangePath(newPath);
}

void Service::ChangePathForHTML(const std::string& newPath) {
    this->htmlFileManager.ChangePath(newPath);
}*/
std::vector<Chore> Service::FilterByTypeAndTimesPerformed(std::string type, int timesPerformed) {
   // std::vector<Chore> chores = this->fileManager.GetElements();
   std::vector<Chore> chores = this->repository.GetElements();
    std::vector<Chore> filteredChores (chores.size());

    auto iterator = std::copy_if(chores.begin(), chores.end(), filteredChores.begin(), [type, timesPerformed](Chore chore){
        return !(chore.GetType() != type && chore.GetTimesPerformed() < timesPerformed);
    });
    filteredChores.resize(std::distance(filteredChores.begin(), iterator));
    return filteredChores;
}

int Service::ExistingChore(const std::string &title) {
    //Chore chore = this->fileManager.FindByTitle(title);
    Chore chore = this->repository.FindByTitle(title);
    if(chore.GetTitle().empty())
        return 0;
    else
        return 1;
}