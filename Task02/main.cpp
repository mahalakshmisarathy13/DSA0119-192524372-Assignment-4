#include <iostream>
#include <string>

class Person {
protected:
    std::string name;
    int id;
    std::string phone;

public:
    Person(const std::string& n, int i, const std::string& p)
        : name(n), id(i), phone(p) {
        std::cout << "Person constructed; ";
    }
    virtual ~Person() = default;
    void showPerson() const {
        std::cout << name << " ID=" << id << " Phone=" << phone;
    }
};

class Student : virtual public Person {
protected:
    std::string programme;
    double cgpa;

public:
    Student(const std::string& n, int i, const std::string& p,
            const std::string& prog, double grade)
        : Person(n, i, p), programme(prog), cgpa(grade) {
        std::cout << "Student constructed; ";
    }
};

class Staff : virtual public Person {
protected:
    std::string department;
    double salary;

public:
    Staff(const std::string& n, int i, const std::string& p,
          const std::string& dept, double pay)
        : Person(n, i, p), department(dept), salary(pay) {
        std::cout << "Staff constructed; ";
    }
};

class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant(const std::string& n, int i, const std::string& p,
                      const std::string& prog, double grade,
                      const std::string& dept, double pay)
        : Person(n, i, p),
          Student(n, i, p, prog, grade),
          Staff(n, i, p, dept, pay) {
        std::cout << "TeachingAssistant constructed; ";
    }

    void show() const {
        showPerson();
        std::cout << " Programme=" << programme << " CGPA=" << cgpa
                  << " Department=" << department << " Salary=" << salary << '\n';
    }
};

class ResearchScholar : public Student {
private:
    double fellowship;

public:
    ResearchScholar(const std::string& n, int i, const std::string& p,
                    const std::string& prog, double grade, double amount)
        : Person(n, i, p), Student(n, i, p, prog, grade), fellowship(amount) {}
    void showFellowship() const {
        showPerson();
        std::cout << " Fellowship=" << fellowship << '\n';
    }
};

int main() {
    TeachingAssistant ta("Kavya", 501, "9876543210", "CSE", 8.7,
                         "Computer Science", 25000);
    ta.show();

    ResearchScholar scholar("Arun", 502, "9876500000", "AI&DS", 9.1, 18000);
    scholar.showFellowship();
    return 0;
}
