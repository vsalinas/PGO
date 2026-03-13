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

    cout << "                 \nStress And Sleep Levels:\n\n";

    cout << "-----------------------------------------------------------------------";


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

        //will output occupation, levels of stress and sleep
        //shows correlation
        cout << d.occupation << ": " << stress << " + " << sleep << "\n";

    }

    cout << "-----------------------------------------------------------------------";

}

void process(SleepData arr[], int count){
    long long sleepDebtTotal = 0;
    long long sleepQuality = 0;
    long long totalSleepScore = 0;

    //heavy computation!!! > this is what makes our program run so long
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

            //calculates one year -> 365 days of data
            for(int day = 0; day < 365; day++){
                //variation in sleep needed b/c people dont get the same amount of sleep everyday
                double currentSleep = baseSleep + ((day % 3) - 1) * 0.5;
                //variation of 0.5 hours

                //cant have negative sleeps
                if(currentSleep < 0){
                    currentSleep = 0;
                }

                //adds current sleep to the total amount of sleep so far
                totalSleep += currentSleep;

                // 7 hours is rec good, effective sleep
                if(currentSleep < 7){
                    //if less than 7 hrs sleep then they accumulate sleep debt
                    //low sleep + high stress = more debt
                    if(stressAmount > 5 ){
                        sleepDebt += (7 - currentSleep) * 1.6;
                        quality -= 0.4;
                    } else {
                        //low sleep + low stress = less debt
                        sleepDebt += (7 - currentSleep);
                        quality -= 0.2;
                    }

                } else {
                    //more sleep + higher stress = less effective sleep
                    if (stressAmount > 5){
                        sleepDebt -= 0.1;
                        quality += 0.1;
                    } else {
                        sleepDebt -= -0.3;
                        quality += 0.3;
                    }
                }

                //Physical activity and sleep relations
                if(activity > 45){
                    quality += 0.2;
                    //more physical activity = higher quality sleep
                } else if(activity < 15){
                    quality -= 0.2; //less physical acvitiy = less quality sleep
                }

                //Stress and sleep relation
                if (stressAmount > 5){
                    deepSleep += currentSleep * 0.6;
                } else {
                    deepSleep += currentSleep * 0.85;
                }

                //these prevent impossible numbers
                //cant have negative sleep debt, quality and more than 100 quality
                if (sleepDebt < 0){
                    sleepDebt = 0;
                }

                if(quality < 0){
                    quality = 0;
                }

                if(quality > 100){
                    quality = 100;
                }

            }

            //finds how effective sleep is overall
            double effectiveSleep = deepSleep / totalSleep;

            //getting totals after running computations
            sleepDebtTotal += (long long)sleepDebt;
            sleepQuality += (long long)quality;
            totalSleepScore += (long long)(effectiveSleep * 1000);

        }


    }

    cout << "\n--------------------------------------------------\n";
    cout << "            Sleep and Lifestyle Findings            \n";
    cout << "\n--------------------------------------------------\n";

    cout << "Total Sleep Debt: \t" << sleepDebtTotal << "\n";
    cout << "Total Sleep Quality: \t" << sleepQuality << "\n";
    cout << "Total Restorative Sleep: \t" << totalSleepScore << "\n";



}