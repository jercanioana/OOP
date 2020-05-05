//
// Created by Ioana Jercan on 2019-05-18.
//

#include "FakeRepository.h"

FakeRepository::FakeRepository(std::vector<Chore> chores, std::vector<Chore> myList) : FileManager("", chores, myList){

}

std::vector<Chore> FakeRepository::GetElements() {
    return Repository::GetElements();
}

FakeRepository::~FakeRepository() {

}

FakeCSVRepository::FakeCSVRepository(std::vector<Chore> chores, std::vector<Chore> myList) : CSVFileManager("", chores, myList) {

}

std::vector<Chore> FakeCSVRepository::GetElements() {
    return Repository::GetElements();
}

FakeCSVRepository::~FakeCSVRepository() {

}


FakeHTMLRepository::FakeHTMLRepository(std::vector<Chore> chores, std::vector<Chore> myList): HTMLFileManager(" ", chores, myList) {

}

std::vector<Chore> FakeHTMLRepository::GetElements() {
    return Repository::GetElements();
}

FakeHTMLRepository::~FakeHTMLRepository() {

}