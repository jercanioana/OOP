//
// Created by Ioana Jercan on 2019-04-08.
//

#include "Service.h"
void Service::add(const std::string &name, const std::string &country, const int score) {
    Team team = {name, country, score};
    this->repository.add(team);
}
DynamicVector<Team> Service::list() {
    return this->repository.list();
}

int Service::size() {
    return this->repository.size();
}

Team Service::findByName(const std::string &name) {
    return this->repository.findByName(name);
}
Service::~Service() {

}