#include <iostream>
#include <string>

class Address {
    std::string city;
    int pin;

public:
    Address(const std::string& c, int p) : city(c), pin(p) {
        std::cout << "Address constructed; ";
    }
    ~Address() { std::cout << "~Address; "; }
    std::string str() const { return city + "-" + std::to_string(pin); }
};

class Course {
    std::string title;

public:
    explicit Course(const std::string& t) : title(t) {
        std::cout << "Course constructed; ";
    }
    ~Course() { std::cout << "~Course; "; }
    const std::string& getTitle() const { return title; }
};

class Person {
protected:
    std::string name;
    int age;

public:
    Person(const std::string& n, int a) : name(n), age(a) {
        std::cout << "Person constructed; ";
    }
    virtual ~Person() { std::cout << "~Person; "; }
};

class Student : public Person {
    long long regNo;
    Address home;
    Course course;

public:
    // Completed TODO 1: base and member objects are initialized in this list.
    Student(const std::string& n, int a, long long reg,
            const std::string& city, int pin, const std::string& courseName)
        : Person(n, a), regNo(reg), home(city, pin), course(courseName) {
        std::cout << "Student constructed; ";
    }

    ~Student() override { std::cout << "~Student; "; }

    void print() const {
        std::cout << "\n" << regNo << " " << name << " (" << age << ") "
                  << home.str() << " Course=" << course.getTitle() << '\n';
    }
};

int main() {
    {
        Student s("Kavya", 19, 192311001, "Salem", 636001, "OOP with C++");
        s.print();
        std::cout << "Leaving scope; ";
    }
    std::cout << '\n';
    return 0;
}
