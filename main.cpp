#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "LightDutyTrucks.cpp"
#include "HeavyDutyTrucks.cpp"
using namespace std;

Vehicle* getDataFromCSV(const string& line) 
{
    stringstream ss(line);
    string vehicleType;
    getline(ss, vehicleType, ','); 

    double id;
    ss >> id;
    ss.ignore(); 
    string make;
    getline(ss, make, ','); 

    string model;
    getline(ss, model, ','); 

    string terrainType;
    getline(ss, terrainType, ','); 

    int year;
    ss >> year;
    ss.ignore(); 

    int loadCapacity;
    ss >> loadCapacity;
    ss.ignore(); 

    int currentLoad;
    ss >> currentLoad;

    if (vehicleType == "LightDutyTruck") {
        return new LightDutyTrucks(id, make, model, terrainType, year, loadCapacity, currentLoad);
    } else if (vehicleType == "HeavyDutyTruck") {
        return new HeavyDutyTrucks(id, make, model, terrainType, year, loadCapacity, currentLoad);
    }

    return nullptr; 
}
int main()
{
   ifstream inputFile(R"(C:\Users\suresv5\VSCODE\projects\VehicleTestingSystem\vehicle_data.csv)");
    
    if (!inputFile.is_open()) 
    {
        cerr << "Error opening file!" << endl;
        return 1; 
    }

    string line;
    getline(inputFile,line);

    while (getline(inputFile,line)) 
    {
        Vehicle* vehicle = getDataFromCSV(line);
        if (vehicle) 
        {
            vehicle->performTest(); 
            delete vehicle; 
        }
    }

    inputFile.close();
    
    return 0;

   //Vehicle* LightTruck = new LightDutyTrucks(24,"CAT","772","onRoad",2025,5000,2500);
   //Vehicle* HeavyTruck = new HeavyDutyTrucks(454,"CAT","799","offRoad",2025,10000,9800);
   //LightTruck->performTest();
   //HeavyTruck->performTest();

}
