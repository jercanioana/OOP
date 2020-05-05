//
// Created by Ioana Jercan on 2019-04-12.
//
#include "Tests.h"
#include "assert.h"


void Tests::testChore() {
    Chore chore{"cleanup", "merchant room clean spill", "01-13-1248", 5, "sparkling room"};
    assert(chore.GetTitle() == "cleanup");
    assert(chore.GetType() == "merchant room clean spill");
    assert(chore.GetLastDatePerformed() == "01-13-1248");
    assert(chore.GetTimesPerformed() == 5);
    assert(chore.GetVision() == "sparkling room");
}

void Tests::testRepository() {
    std::vector<Chore> chores;
    std::vector<Chore> myList;
    Repository repository {chores, myList};
    Chore chore{"cleanup", "merchant room clean spill", "01-13-1248", 5, "sparkling room"};
    repository.AddElement(chore);
    Chore testChore = repository.FindByTitle("cleanup");
    assert(testChore.GetTitle() == chore.GetTitle() && testChore.GetType() == chore.GetType());
    testChore = repository.FindByTitle("no");
    assert(testChore.GetTitle() == "");
    repository.RemoveElement("cleanup");
    assert(repository.Size() == 0);
    repository.AddElement(chore);
    assert(repository.Size() == 1);
    repository.SaveElement("cleanup");
    assert(repository.SizeOfMyList() == 1);
    repository.RemoveElement("cleanup");
}


void Tests::testService() {
    std::vector<Chore> chores;
    std::vector<Chore> myList;
    FileManager repository{"", chores, myList };
    HTMLFileManager htmlFileManager{"", chores,myList};
    CSVFileManager csvFileManager{"", chores, myList};
    Service service{ repository, htmlFileManager, csvFileManager };

    std::vector<Chore> chores1 = service.GetAll();
    std::vector<Chore> myList1 = service.GetMyList();
    service.ExistingChore("cleanup");
    service.ChangePathForTextFile("");
    assert(service.ExistingChore("nothing") == 0);
    service.Add("cleanup", "merchant room clean spill", "01-13-1248", 5, "sparkling room");
    assert(service.Size() == 1);
    assert(service.ExistingChore("cleanup") == 1);
    service.FilterByTypeAndTimesPerformed("merchant room clean spill", 4);
    service.Update("cleanup", "m", "0", 4, "s");
    service.SaveChore("cleanup");
    assert(service.SizeOfList() == 1);
    service.Remove("cleanup");
    assert(service.Size() == 0);
    service.Add("", "", "", -8, "");
    service.Add(" ", "", "", -8, "");
    service.Add(" ", " ", "", -8, "");
    service.Add(" ", " ", " ", -8, "");
    service.Add(" ", " ", " ", 10, "");
}

void Tests::testServiceGetAllFunction() {
    std::vector<Chore> chores;
    std::vector<Chore> myList;
    FakeRepository fakerepository(chores, myList);
    FakeCSVRepository fakeCSVRepository(chores, myList);
    FakeHTMLRepository fakeHTMLRepository(chores, myList);
    Service service(fakerepository, fakeHTMLRepository, fakeCSVRepository);
    service.Add("cleanup", "merchant room clean spill", "01-13-1248", 5, "sparkling room");
    assert(service.ExistingChore("cleanup") == 1);

}
void Tests::testFileManager() {
    std::vector<Chore> chores;
    std::vector<Chore> myList;
    FileManager fileRepository {"Test.txt", chores, myList};
    Chore chore{"cleanup", "merchant room clean spill", "01-13-1248", 5, "sparkling room"};
    fileRepository.ChangePath("Test.txt");
    fileRepository.AddElement(chore);
    //assert(fileRepository.Size() == 2);
    Chore testChore = fileRepository.FindByTitle("cleanup");
    //assert(testChore.GetTitle() == chore.GetTitle() && testChore.GetType() == chore.GetType());
    fileRepository.SaveElement("cleanup");
    assert(fileRepository.SizeOfMyList() == 1);
    fileRepository.RemoveElement("cleanup");

}

void Tests::testAll() {
    testChore();
    testRepository();
    testService();
    testFileManager();
    testServiceGetAllFunction();
}