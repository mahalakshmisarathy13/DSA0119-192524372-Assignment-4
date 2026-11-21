# Task 6 notes

## Testable requirements represented in the code
1. Every vehicle stores a registration number and daily rate.
2. Every concrete vehicle calculates its own rental charge.
3. Motor vehicles store a fuel/charge level and service due date.
4. Cars store seating capacity.
5. Electric cars store battery capacity and use a per-kWh price component.
6. The fleet can list, rent and return vehicles through base-class pointers.
7. A late return adds a late charge.
8. A new concrete type (`ElectricBus`) can be added by deriving from `Vehicle` without editing existing vehicle classes.

## Hierarchy
`Vehicle` is abstract because `rentalCharge()` and `list()` are pure virtual. `Bicycle`, `TwoWheeler`, `Car`, `ElectricCar`, and `ElectricBus` publicly derive from it directly or through `MotorVehicle`/`Car`. `MotorVehicle` is an intermediate abstract class that stores common motor-vehicle data.

## Pseudocode
RENT(vehicle):
- invoke vehicle.rent()
- calculate charge = vehicle.rentalCharge(numberOfDays)
- store/print the rental transaction

RETURN(vehicle, daysLate):
- calculate lateCharge = vehicle.returnCharge(daysLate)
- total = rentalCharge + lateCharge
- mark vehicle as available (availability state can be added to a production version)

This is an educational implementation. The assignment does not specify exact business formulas for every vehicle category or late fees, so the code uses clearly visible illustrative formulas that can be changed to match faculty instructions.
