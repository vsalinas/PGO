#include "assessData.h"
#include <iostream>

using namespace std;


void analyze(SleepData arr[], int count){
    double sleepTotal = 0;

    for(int i = 0; i < count; i++){
        sleepTotal += arr[i].sleepDuration;
    }

    cout << "Average time slept: " << (sleepTotal/count) << " hours\n";

    cout << "-----------------------------------------------------------------------";

    cout << "\nStress And Sleep Levels:\n";

    for(int i = 0; i < count; i++){
        SleepData& d = arr[i];

        string stress;
        if(d.stressLevel > 5){
            stress = "High Stress";
        } else{
            stress = "Low Stress";
        }

        string sleep;

        if(d.sleepDuration < 6){
            sleep = "Low Sleep";
        } else {
            sleep = "Good Sleep";
        }

        cout << d.occupation << ": " << stress << " + " << sleep << "\n";

    }

    cout << "-----------------------------------------------------------------------";

}

void process(SleepData arr[], int count){
    long long sleepDebtTotal = 0;
    long long sleepQuality = 0;
    long long totalSleepScore = 0;

    //heavy computation > this is what makes our program run so long
    for(int year = 0; year < 1000; year++){

        for(int i = 0; i < count; i++){
            double baseSleep = arr[i].sleepDuration;
            int stressAmount = arr[i].stressLevel;
            int activity = arr[i].physicalActivity;
            int baseQuality = arr[i].sleepQuality;

            double sleepDebt = 0;

            //multuply by 10 to change rating from 1-10 to 0-100
            double quality = baseQuality * 10.0;

            double deepSleep = 0;

            double totalSleep = 0;

            //calculates one year > 365 days of data
            for(int day = 0; day < 365; day++){
                

            }

        }


    }

}