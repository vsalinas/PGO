//this file uses iostream and sstream to grab the data from the CSV file

#include "importData.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;


int importFile(string& filename, SleepData arr[], int size){
    ifstream file(filename);
    if(!file.is_open()){
        cout << "Unable to open file\n";
        return 0;
    }

    string line;
    getline(file, line);

    int count = 0;

    //parsing the csv file
    while (getline(file, line) && count < size){
        stringstream ss(line);
        SleepData d;
        string temp;

        getline(ss, d.gender, ',');
        getline(ss, temp, ',');
        d.age = stoi(temp);
        getline(ss, d.occupation, ',');
        getline(ss, temp, ',');
        d.sleepDuration = stod(temp);

        getline(ss, temp, ',');
        d.sleepQuality = stoi(temp);

        getline(ss, temp, ',');
        d.physicalActivity = stoi(temp);

        getline(ss, temp, ',');
        d.stressLevel = stoi(temp);

        arr[count++] = d;

    }

    return count;


}
