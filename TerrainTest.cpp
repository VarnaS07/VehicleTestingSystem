#pragma once

#include <iostream>
#include "TestScenario.cpp"
using namespace std;

class TerrainTest : public TestScenario
{
    public:
        TerrainTest(Vehicle *v): TestScenario("Terrain Test",v)
        {

        }

        TestResult runTest() override
        {
            if(vehicle->getTerrainType()=="offRoad")
            {
                TestResult result("Pass");
                result.addMetric("offRoad:", 0.5);
                result.addSuggestion("Good off road capability!");
                return result;
            }
            else
            {
                TestResult result("Fail");
                result.addMetric("onRoad:", 0.2);
                result.addSuggestion("Not suitable for off road!");
                return result;  
            }
        }
};