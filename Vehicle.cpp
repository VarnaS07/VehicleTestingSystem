#pragma once

#include <iostream>
#include<string>
using namespace std;

class Vehicle
{
    protected: 
        double vehicleId;
        string make;
        string model;
        string terrainType;
        int year;
        int loadCapacity;
        int currentLoad;

    public:
        Vehicle(double id, string mk, string mdl, string terrain, int yr, int capacity, int current): vehicleId(id), make(mk), model(mdl), terrainType(terrain),year(yr), loadCapacity(capacity), currentLoad(current)
        {

        }
        string getMake() const
        {
            return make;
        }
        string getModel() const
        {
            return model;
        }
        int getVehicleId() const
        {
            return vehicleId;
        }
        int getLoadCapacity() const
        {
            return loadCapacity;
        }
        string getTerrainType() const
        {
            return terrainType;
        }
        int getCurrentLoad() const
        {
            return currentLoad;
        }
        bool isOverLoaded()
        {
            return currentLoad>loadCapacity;
        }

        virtual void performTest()=0;

        virtual ~Vehicle(){}
};