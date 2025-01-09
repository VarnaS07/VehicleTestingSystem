#include <iostream>
#include <fstream>
#include <memory>
#include "Vehicle.cpp"
#include "TestResult.cpp"
#include "LoadTest.cpp"
#include "TerrainTest.cpp"
#include "DurabilityTest.cpp"
using namespace std;

class LightDutyTrucks : public Vehicle, public enable_shared_from_this<LightDutyTrucks>
{
    public:
        LightDutyTrucks(double id, string mk, string mdl, string terrain, int yr, int capacity, int current): Vehicle(id,mk, mdl,"onRoad",yr, capacity,current)
        {

        }

        void performTest() override
        {
            cout<<"\n Light Duty Trucks Testing.....";
            LoadTest loadTest(shared_from_this());
            TerrainTest terrainTest(shared_from_this());
            DurabilityTest durabilityTest(shared_from_this());

            TestResult loadResult = loadTest.runTest();
            TestResult terrainResult = terrainTest.runTest();
            TestResult durabilityResult=durabilityTest.runTest();

            cout<<"\nLoad Test Result: "<<loadResult.getStatus();
            cout<<"\nTerrain Test Result: "<<terrainResult.getStatus();
            cout<<"\nDurability Test Result:"<<durabilityResult.getStatus();

            saveAllResultsToCSV(loadResult, terrainResult, durabilityResult);
        }

        void saveAllResultsToCSV(const TestResult& loadResult, const TestResult& terrainResult, const TestResult& durabilityResult)
        {
            
            ofstream outFile(R"(C:\Users\suresv5\VSCODE\projects\VehicleTestingSystem\LightDutyTrucks_test_results.csv)", ios::app);
            if (outFile.is_open()) 
            {
                static bool headerWritten = false;
                if (!headerWritten) 
                {
                    outFile << "Make,Model,VehicleID,Test Name,Status,Metric,Suggestion\n";
                    headerWritten = true; 
                }
                outFile << getMake() << ","
                        << getModel() << ","
                        << getVehicleId()<< ","
                        << "Load Test," 
                        << loadResult.getStatus() << ","
                        << loadResult.getPerformanceMetrics().begin()->first << " "
                        << loadResult.getPerformanceMetrics().begin()->second << ","
                        << (loadResult.getSuggestions().empty() ? "N/A" : loadResult.getSuggestions().front()) << "\n";

        
                outFile << getMake() << ","
                        << getModel() << ","
                        << getVehicleId()<< ","
                        << "Terrain Test," 
                        << terrainResult.getStatus() << ","
                        << terrainResult.getPerformanceMetrics().begin()->first << " "
                        << terrainResult.getPerformanceMetrics().begin()->second << ","
                        << (terrainResult.getSuggestions().empty() ? "N/A" : terrainResult.getSuggestions().front()) << "\n";

                outFile << getMake() << ","
                        << getModel() << ","
                        << getVehicleId()<< ","
                        << "Durability Test," 
                        << durabilityResult.getStatus() << ","
                        << durabilityResult.getPerformanceMetrics().begin()->first << " "
                        << durabilityResult.getPerformanceMetrics().begin()->second << ","
                        << (durabilityResult.getSuggestions().empty() ? "N/A" : durabilityResult.getSuggestions().front()) << "\n";

                outFile.close();
                cout << "\nResults saved to test_results.csv" << endl;
            } 
            else
            {
                cerr << "\nUnable to open file for writing." << endl;
            }
        }
};