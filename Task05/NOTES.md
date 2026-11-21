# Task 5 notes

The complete program demonstrates direct object access, pointer access with `->`, reference access, and dynamic allocation followed by `delete`. `this` is the address of the current object; `*this` is the current object itself. Returning `Cart&` enables chained calls without copying the object. If `add()` returned `Cart` by value, each call would return a copy; the next chained call would operate on that temporary copy rather than the original cart.

The assignment's chained example should print `324.00` because (60 + 120 + 180) receives a 10% discount.

Finding the maximum total in an array of n cart pointers takes O(n) time and O(1) extra space. A vector of Cart objects also takes O(n) to scan. A vector may move its elements when it grows, invalidating pointers/references/iterators to its elements; a vector of pointers has different ownership and lifetime considerations.
