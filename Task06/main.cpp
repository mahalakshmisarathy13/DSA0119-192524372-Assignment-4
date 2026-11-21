#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Vehicle {
protected:
    std::string registration;
    double dailyRate;

public:
    Vehicle(const std::string& reg, double rate)
        : registration(reg), dailyRate(rate) {}
    virtual ~Vehicle() = default;

    const std::string& getRegistration() const { return registration; }
    virtual double rentalCharge(int days) const = 0;
    virtual void list() const = 0;
    virtual void rent() const {
        std::cout << registration << " rented\n";
    }
    virtual double returnCharge(int daysLate) const {
        return daysLate > 0 ? daysLate * dailyRate * 0.5 : 0.0;
    }
};

class Bicycle : public Vehicle {
public:
    Bicycle(const std::string& reg, double rate) : Vehicle(reg, rate) {}
    double rentalCharge(int days) const override { return days * dailyRate; }
    void list() const override {
        std::cout << "Bicycle " << registration << " daily rate=" << dailyRate << '\n';
    }
};

class MotorVehicle : public Vehicle {
protected:
    double fuelOrChargeLevel;
    std::string serviceDueDate;

public:
    MotorVehicle(const std::string& reg, double rate, double level,
                 const std::string& due)
        : Vehicle(reg, rate), fuelOrChargeLevel(level), serviceDueDate(due) {}
};

class TwoWheeler : public MotorVehicle {
public:
    TwoWheeler(const std::string& reg, double rate, double fuel,
               const std::string& due)
        : MotorVehicle(reg, rate, fuel, due) {}
    double rentalCharge(int days) const override { return days * dailyRate * 1.05; }
    void list() const override {
        std::cout << "Two-wheeler " << registration << " fuel=" << fuelOrChargeLevel
                  << " service due=" << serviceDueDate << '\n';
    }
};

class Car : public MotorVehicle {
protected:
    int seatingCapacity;

public:
    Car(const std::string& reg, double rate, double fuel,
        const std::string& due, int seats)
        : MotorVehicle(reg, rate, fuel, due), seatingCapacity(seats) {}
    double rentalCharge(int days) const override { return days * dailyRate; }
    void list() const override {
        std::cout << "Car " << registration << " seats=" << seatingCapacity
                  << " fuel=" << fuelOrChargeLevel
                  << " service due=" << serviceDueDate << '\n';
    }
};

class ElectricCar : public Car {
    double batteryCapacityKWh;
    double pricePerKWh;

public:
    ElectricCar(const std::string& reg, double rate, double chargeLevel,
                const std::string& due, int seats, double batteryKWh,
                double kWhPrice)
        : Car(reg, rate, chargeLevel, due, seats),
          batteryCapacityKWh(batteryKWh), pricePerKWh(kWhPrice) {}
    double rentalCharge(int days) const override {
        return days * dailyRate + batteryCapacityKWh * pricePerKWh;
    }
    void list() const override {
        std::cout << "Electric car " << registration << " seats=" << seatingCapacity
                  << " battery level=" << fuelOrChargeLevel
                  << " battery capacity=" << batteryCapacityKWh
                  << " kWh; service due=" << serviceDueDate << '\n';
    }
};

// New type added without modifying Vehicle or the existing concrete classes.
class ElectricBus : public Vehicle {
    int seats;
    double batteryKWh;
    double pricePerKWh;

public:
    ElectricBus(const std::string& reg, double rate, int seatCount,
                double capacity, double kWhPrice)
        : Vehicle(reg, rate), seats(seatCount),
          batteryKWh(capacity), pricePerKWh(kWhPrice) {}
    double rentalCharge(int days) const override {
        return days * dailyRate + batteryKWh * pricePerKWh;
    }
    void list() const override {
        std::cout << "Electric bus " << registration << " seats=" << seats
                  << " battery=" << batteryKWh << " kWh\n";
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(2);
    std::vector<std::unique_ptr<Vehicle>> fleet;
    fleet.push_back(std::make_unique<Bicycle>("CYC-101", 100));
    fleet.push_back(std::make_unique<TwoWheeler>("TN-01-BB-1234", 250, 80, "2027-01-15"));
    fleet.push_back(std::make_unique<Car>("TN-01-CC-5678", 1200, 60, "2027-02-01", 5));
    fleet.push_back(std::make_unique<ElectricCar>("TN-01-EE-9999", 1500, 90,
                                                  "2027-03-01", 5, 50, 8));
    fleet.push_back(std::make_unique<ElectricBus>("TN-01-EB-2026", 3000, 30, 120, 8));

    std::cout << "FLEET LIST\n";
    for (const auto& vehicle : fleet) {
        vehicle->list();
    }

    std::cout << "\nRENTAL AND RETURN DEMONSTRATION (3 days, 1 day late)\n";
    for (const auto& vehicle : fleet) {
        vehicle->rent();
        const double base = vehicle->rentalCharge(3);
        const double late = vehicle->returnCharge(1);
        std::cout << "Registration: " << vehicle->getRegistration()
                  << " rental=" << base << " late charge=" << late
                  << " total=" << base + late << "\n";
        std::cout << "Returned\n";
    }
    return 0;
}
