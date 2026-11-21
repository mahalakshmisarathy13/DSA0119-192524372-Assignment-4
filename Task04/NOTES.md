# Task 4 notes

The original defects are: `rate()` is non-virtual, so a base pointer calls `Account::rate()`; the base destructor is non-virtual, so deleting a derived object through `Account*` has undefined behaviour and may skip the derived destructor; the derived raw array needs correct ownership; and copying `SeniorAccount` into an `Account` slices off the derived part.

The corrected code makes `rate()` virtual, marks the derived implementation `override`, and gives `Account` a virtual destructor. `std::unique_ptr<Account>` in a vector manages object lifetime automatically.

The prediction program in the assignment prints `3.5 4 3.5`: `p->rate()` is statically bound because `rate()` is non-virtual; `p->vrate()` dispatches virtually to `SeniorAccount`; `copy.vrate()` uses the copied base object, whose dynamic type is `Account`.

Use `-fsanitize=address` if supported by your g++ installation. Sanitizer availability and diagnostics depend on compiler/runtime platform.
