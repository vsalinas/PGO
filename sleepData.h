#ifndef SLEEP_DATA_H
#define SLEEP_DATA_H

//Header for sleep data from the .csv file


#include <string>
using namespace std;

struct SleepData{
    string gender;
    string occupation;
    int age;
    double sleepDuration;
    int sleepQuality;
    int stressLevel;
    int physicalActivity;

};


#endif