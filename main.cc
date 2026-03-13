#include <iostream>
#include "importData.h"
#include "assessData.h"

using namespace std;



int main(){
    //loads the csv file
    SleepData arr[1000];
    int count = importFile("sleep.csv", arr, 1000);

    //print to confirm file loaded
    cout << "File loaded successfully.\n";

    //analyzes data
    analyze(arr, count);

    //process and run a test to see any interesting data
    process(arr, count);

    return 0;
}