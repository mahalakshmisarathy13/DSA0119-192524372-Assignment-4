#include <iomanip>
#include <iostream>
#include <string>

class Cart {
    std::string items[10];
    double prices[10];
    int n = 0;
    double discount = 0.0;

public:
    // Completed TODO 1: return a reference to the current object.
    Cart& add(const std::string& item, double price) {
        if (n < 10 && price >= 0.0) {
            items[n] = item;
            prices[n] = price;
            ++n;
        }
        return *this;
    }

    // Completed TODO 2: this->discount identifies the data member.
    Cart& setDiscount(double discount) {
        this->discount = discount;
        return *this;
    }

    double total() const {
        double sum = 0.0;
        for (int i = 0; i < n; ++i) {
            sum += prices[i];
        }
        return sum * (100.0 - discount) / 100.0;
    }

    void print() const {
        for (int i = 0; i < n; ++i) {
            std::cout << items[i] << ": " << prices[i] << '\n';
        }
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(2);

    // (a) Direct access by object name.
    Cart direct;
    direct.add("Notebook", 50.0);
    std::cout << "Direct object total = " << direct.total() << '\n';

    // (b) Pointer to an existing object and -> operator.
    Cart* pointer = &direct;
    pointer->add("Pen", 20.0);
    std::cout << "Pointer access total = " << pointer->total() << '\n';

    // (c) Reference to an existing object.
    Cart& reference = direct;
    reference.setDiscount(10.0);
    std::cout << "Reference access total = " << reference.total() << '\n';

    // (d) Dynamically allocated object; release it with delete.
    Cart* dynamicCart = new Cart;
    dynamicCart->add("Bag", 500.0);
    std::cout << "Dynamic object total = " << dynamicCart->total() << '\n';
    delete dynamicCart;

    // Assignment's required chained call and expected result.
    Cart c;
    c.add("Rice", 60).add("Dal", 120).setDiscount(10);
    Cart* p = &c;
    p->add("Oil", 180);
    std::cout << "Required chained total = " << p->total() << '\n';

    // Array of pointers: find the cart with the highest total.
    Cart cartA, cartB, cartC;
    cartA.add("A", 100);
    cartB.add("B", 250);
    cartC.add("C", 175);
    Cart* carts[] = {&cartA, &cartB, &cartC};
    const int count = 3;
    int best = 0;
    for (int i = 1; i < count; ++i) {
        if (carts[i]->total() > carts[best]->total()) {
            best = i;
        }
    }
    std::cout << "Highest cart total = " << carts[best]->total()
              << " at index " << best << '\n';
    return 0;
}
