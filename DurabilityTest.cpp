#pragma once
#include <iostream>
#include "TestScenario.cpp"
using namespace std;

class DurabilityTest : public TestScenario 
{
public:
    DurabilityTest(shared_ptr<Vehicle> v) : TestScenario("Durability Test",v) {}

    TestResult runTest() override 
    {
        double wearAndTear = 0.0;      
        
        if (vehicle->getLoadCapacity() > 5000) 
        {
            wearAndTear = 80; 
        } else {
            wearAndTear = 50; 
        }

        string status = (wearAndTear < 60) ? "Pass" : "Fail";
        TestResult result(status);
        result.addMetric("Wear & Tear:", wearAndTear);
        
        if (status == "Fail") {
            result.addSuggestion("Consider reducing load or improving materials.");
        } else {
            result.addSuggestion("Durability is satisfactory.");
        }
        return result; 
    }
};
