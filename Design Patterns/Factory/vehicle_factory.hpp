#ifndef vehicle_factory_hpp
#define vehicle_factory_hpp

#include <iostream>
#include "car.hpp"
#include "bike.hpp"
using namespace std;

class VehicleFactory {
public:
    // static because I don't need to create an object to access this func
    static Vehicle* getVehicle(string vehicleType);
};

#endif