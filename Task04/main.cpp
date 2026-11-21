#include <iostream>
#include <memory>
#include <vector>

class Account {
public:
    virtual double rate() const { return 3.5; }
    virtual ~Account() { std::cout << "Account destroyed\n"; }
};

class SeniorAccount : public Account {
    double* history;

public:
    SeniorAccount() : history(new double[100]{}) {}
    double rate() const override { return 4.0; }
    ~SeniorAccount() override {
        delete[] history;
        std::cout << "SeniorAccount destroyed; history released\n";
    }
};

int main() {
    std::cout << "Polymorphic raw-pointer demonstration:\n";
    Account* accounts[2] = {new Account, new SeniorAccount};
    for (Account* account : accounts) {
        std::cout << account->rate() << '\n';
    }
    for (Account* account : accounts) {
        delete account; // Safe because Account has a virtual destructor.
    }

    std::cout << "\nSlicing demonstration:\n";
    SeniorAccount senior;
    Account slicedCopy = senior; // Derived part is sliced away.
    std::cout << "Sliced base copy rate = " << slicedCopy.rate() << '\n';

    std::cout << "\nPreferred ownership with unique_ptr:\n";
    std::vector<std::unique_ptr<Account>> portfolio;
    portfolio.push_back(std::make_unique<Account>());
    portfolio.push_back(std::make_unique<SeniorAccount>());
    for (const auto& account : portfolio) {
        std::cout << account->rate() << '\n';
    }
    return 0;
}
