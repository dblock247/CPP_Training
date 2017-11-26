#include <iostream>
#include <stdio.h>
#include <string>

#include <boost/optional.hpp>

using namespace std;
using namespace boost;

class Person {
public:
    Person(string firstName, string lastName) : firstName(std::move(firstName)), lastName(std::move(lastName)) {}

    string firstName, lastName;
    optional<string> middleName;
};

int main(int argc, char *argv[]) {

    Person p { "John", "Watson" };
    p.middleName = "Hamish";

    if (p.middleName)
        cout << *p.middleName << endl;

    getchar();
    return 0;
}