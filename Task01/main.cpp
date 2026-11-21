#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Staff {
private:
    std::string name_;
    int id_;
    double basic_;

protected:
    const std::string& name() const { return name_; }
    double basic() const { return basic_; }

public:
    Staff(const std::string& name, int id, double basic)
        : name_(name), id_(id), basic_(basic) {}
    virtual ~Staff() = default;
    int id() const { return id_; }
    virtual double pay() const = 0;
    virtual void print() const {
        std::cout << name_ << " (ID " << id_ << "): ";
    }
};

class Professor : public Staff {
private:
    double researchAllowance_;

public:
    Professor(const std::string& name, int id, double basic, double research)
        : Staff(name, id, basic), researchAllowance_(research) {}
    double pay() const override { return basic() * 1.42 + researchAllowance_; }
    void print() const override {
        Staff::print();
        std::cout << "Professor pay = " << pay() << '\n';
    }
};

class LabAssistant : public Staff {
public:
    LabAssistant(const std::string& name, int id, double basic)
        : Staff(name, id, basic) {}
    double pay() const override { return basic() * 1.42; }
    void print() const override {
        Staff::print();
        std::cout << "Lab assistant pay = " << pay() << '\n';
    }
};

class GuestFaculty : public Staff {
private:
    double hours_;
    double hourlyRate_;

public:
    GuestFaculty(const std::string& name, int id, double hours, double rate)
        : Staff(name, id, 0.0), hours_(hours), hourlyRate_(rate) {}
    double pay() const override { return hours_ * hourlyRate_; }
    void print() const override {
        Staff::print();
        std::cout << "Guest faculty pay = " << pay() << '\n';
    }
};

// Alternative concept: one class with a type field and a switch.
class StaffWithType {
public:
    enum class Type { Professor, LabAssistant, GuestFaculty };

private:
    Type type_;
    double basic_;
    double research_;
    double hours_;
    double hourlyRate_;

public:
    StaffWithType(Type type, double basic, double research,
                  double hours, double hourlyRate)
        : type_(type), basic_(basic), research_(research),
          hours_(hours), hourlyRate_(hourlyRate) {}

    double pay() const {
        switch (type_) {
        case Type::Professor: return basic_ * 1.42 + research_;
        case Type::LabAssistant: return basic_ * 1.42;
        case Type::GuestFaculty: return hours_ * hourlyRate_;
        }
        return 0.0;
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(2);
    std::vector<std::unique_ptr<Staff>> staff;
    staff.push_back(std::make_unique<Professor>("Anita", 101, 50000, 8000));
    staff.push_back(std::make_unique<LabAssistant>("Bala", 102, 30000));
    staff.push_back(std::make_unique<GuestFaculty>("Charan", 103, 40, 750));

    for (const auto& person : staff) {
        person->print();
    }

    StaffWithType alternative(StaffWithType::Type::Professor, 50000, 8000, 0, 0);
    std::cout << "Alternative switch-based professor pay = "
              << alternative.pay() << '\n';
    return 0;
}
