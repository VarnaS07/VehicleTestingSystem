#pragma once 

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class TestResult
{
    private:
        string status;
        map<string, double> performanceMetrics;
        vector<string> suggestions;
        
    public:
        TestResult(string stat) : status(stat) 
        {

        }

        void addMetric(string key, double value) 
        { 
            performanceMetrics[key] = value; 
        }

        void addSuggestion(string suggestion) 
        { 
            suggestions.push_back(suggestion); 
        }

        string getStatus() const 
        { 
            return status; 
        }

        map<string, double> getPerformanceMetrics() const 
        { 
            return performanceMetrics; 
        }

        vector<string> getSuggestions() const 
        {
             return suggestions; 
        }

};