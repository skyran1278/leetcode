#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

enum class VehicleType { Motorcycle, Car, Bus };
enum class SpotType { Motorcycle, Car, Bus };

class Vehicle {
 private:
  int id;

 public:
  Vehicle(int id) : id(id) {}
  int getId() const { return id; }
  virtual VehicleType type() const = 0;
  virtual ~Vehicle() = default;
};

class Motorcycle : public Vehicle {
 public:
  Motorcycle(int id) : Vehicle(id) {}
  VehicleType type() const override { return VehicleType::Motorcycle; }
};
class Car : public Vehicle {
 public:
  Car(int id) : Vehicle(id) {}
  VehicleType type() const override { return VehicleType::Car; }
};
class Bus : public Vehicle {
 public:
  Bus(int id) : Vehicle(id) {}
  VehicleType type() const override { return VehicleType::Bus; }
};

class ParkingSpot {
 private:
  SpotType type;
  Vehicle* parkedVehicle = nullptr;  // non-owning

 public:
  ParkingSpot(SpotType type) : type(type) {}
  virtual ~ParkingSpot() = default;

  // Non-copyable
  ParkingSpot(const ParkingSpot&) = delete;
  ParkingSpot& operator=(const ParkingSpot&) = delete;

  // Movable: required for vector<ParkingSpot>
  ParkingSpot(ParkingSpot&&) noexcept = default;
  ParkingSpot& operator=(ParkingSpot&&) noexcept = default;

  bool isAvailable() const { return parkedVehicle == nullptr; }

  bool canFit(const Vehicle& vehicle) const {
    if (type == SpotType::Motorcycle)
      return vehicle.type() == VehicleType::Motorcycle;
    if (type == SpotType::Car) return vehicle.type() == VehicleType::Car;
    return vehicle.type() == VehicleType::Bus;
  }

  bool park(Vehicle* vehicle) {
    if (!isAvailable()) return false;
    if (!canFit(*vehicle)) return false;

    parkedVehicle = vehicle;

    cout << "Parked vehicle " << vehicle->getId() << endl;

    return true;
  }

  Vehicle* getParkedVehicle() const { return parkedVehicle; }

  void leave() {
    cout << "Vehicle " << parkedVehicle->getId() << " left" << endl;
    parkedVehicle = nullptr;
  }
};

class ParkingLot {
 private:
  vector<ParkingSpot> spots;

 public:
  ParkingLot(const vector<SpotType>& layout) : spots() {
    spots.reserve(layout.size());
    for (auto&& type : layout) {
      spots.emplace_back(type);
    }
  }

  bool park(Vehicle* vehicle) {
    for (auto& spot : spots) {
      if (spot.park(vehicle)) {
        return true;
      }
    }
    return false;
  }
  bool leave(Vehicle* vehicle) {
    for (auto& spot : spots) {
      if (spot.getParkedVehicle() == vehicle) {
        spot.leave();
        return true;
      }
    }
    return false;
  }
};

int main() {
  ParkingLot lot(
      {SpotType::Motorcycle, SpotType::Car, SpotType::Car, SpotType::Bus});

  Motorcycle* motorcycle1 = new Motorcycle(1);
  Car* car1 = new Car(2);
  Bus* bus1 = new Bus(3);
  Bus* bus2 = new Bus(4);

  lot.park(motorcycle1);
  lot.park(car1);
  lot.park(bus1);
  lot.park(bus2);  // Should fail

  lot.leave(motorcycle1);
  lot.leave(car1);
  lot.leave(bus1);

  return 0;
}
