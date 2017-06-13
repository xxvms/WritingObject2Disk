#include <iostream>
#include <fstream>                                          //for file stream
class Person
{
protected:
    char name[80];                                          // person name
    short age;                                              // person age
public:
    void getData()                                          // get person data
    {
        std::cout << "Enter name: ";
        std::cin >> name;
        std::cout << "Enter age: ";
        std::cin >> age;
    }
};

int main() {

    Person person;                                          // create person
    person.getData();                                       // get data from user

    std::ofstream outfile("Person.dat", std::ios::binary);  // write it

    outfile.write(reinterpret_cast<char*>(&person), sizeof(person));

    std::cin.get();
    return 0;
}