# Task 1 notes

**Design diagnosis:** duplicated `name`, `id`, and `basic` fields; public data; inconsistent `nm`/`code`; unused `da`; magic number `0.42`; repeated DA calculation; guest faculty uses a different pay rule; no common polymorphic processing loop.

**Hierarchy:** `Staff` is an abstract base class. `Professor`, `LabAssistant`, and `GuestFaculty` publicly inherit from it and override `pay()`. `std::vector<std::unique_ptr<Staff>>` permits one loop over all staff.

**Defence (under 100 words):** Common identity and basic-pay data are stored once in `Staff`. Each staff category implements its own `pay()` through an override. A new category can derive from `Staff` and implement `pay()` without editing the existing derived classes or the processing loop. This reduces duplication and supports runtime polymorphism.

**Alternative:** a type-code class uses a switch. Both approaches calculate one pay value in O(1). The single class may reserve fields unused by a particular type. Adding a type requires changing the enum/type definition, constructor or data layout, and switch statement; the hierarchy adds a new derived class instead.
