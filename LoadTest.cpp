#pragma once

#include <iostream>
#include "TestScenario.cpp"
using namespace std;

class LoadTest: public TestScenario
{
    public:
        LoadTest(shared_ptr<Vehicle> v) : TestScenario("Load Test",v)
        {

        }

        TestResult runTest() override
        {
            if(vehicle->getCurrentLoad() > (vehicle->getLoadCapacity()/2))
            {
                TestResult result("Pass");
                result.addMetric("load cpty:",vehicle->getLoadCapacity());
                result.addSuggestion("Good load capacity!");
                return result;
            }
            else
            {
                TestResult result("Fail");
                result.addMetric("load cpty:",vehicle->getLoadCapacity());
                result.addSuggestion("Increase load capacity!");
                return result;
            }


        }
};

