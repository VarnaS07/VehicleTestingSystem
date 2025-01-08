#pragma once

#include<string>
#include "Vehicle.cpp"
#include "TestResult.cpp"
using namespace std;
class TestScenario
{
    protected:
        string scenarioName;
        Vehicle *vehicle;
    public:
        TestScenario(std::string name, Vehicle* v): scenarioName(name), vehicle(v) {}
        
        string getScenarioName() const 
        { 
            return scenarioName; 
        }

        virtual TestResult runTest() = 0;

        virtual ~TestScenario() {} // Virtual destructor
};