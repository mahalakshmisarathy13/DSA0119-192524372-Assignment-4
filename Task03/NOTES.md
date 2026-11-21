# Task 3 notes

The complete program demonstrates base-class initialization (`Person(n, a)`) and member-object initialization (`home(city, pin)` and `course(courseName)`) in the initializer list.

Construction order is: virtual bases first (if present), direct base classes in declaration order, data members in their declaration order, then the constructor body. Destruction happens in reverse order: destructor body, members in reverse declaration order, then base classes in reverse construction order.

For the assignment's `Car : Vehicle` with member `Engine e`, expected construction output is:
`Vehicle Engine Car | ~Car ~Engine ~Vehicle`

Swapping initializer-list entries does not change actual initialization order. With `-Wall -Wextra`, compilers commonly warn that the written initializer order differs from member declaration order (`-Wreorder`).
