#include <iostream>
#include <vector>
#include <string>

class Student {
public:
    std::string name;
    int id;

    Student(std::string n, int i) {
        name = n;
        id = i;
    }
};

int main() {
    std::vector<Student> roster;

    roster.push_back(Student("Andrew", 123));
    roster.push_back(Student("Chloe", 234));
    roster.push_back(Student("Aries", 345));
    roster.push_back(Student("Max", 456));
    roster.push_back(Student("Steve", 567));

    roster.erase(roster.begin() + 2);

    for (const Student& s : roster) {
        std::cout << s.name << ": " << s.id << "\n";
    }

    return 0;
}
