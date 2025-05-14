#ifndef MEDLOG_H
#define MEDLOG_H

#include <vector>
#include "medication.h"

using namespace std;

class MedLogSystem
{
private:
    vector<Medication*> meds;
public:
    void addMedication();
    
    void displayAll();

    void markDosage();

    void resetAll();

    void saveToFile(string filename);

    void loadFromFile(string filename);

    ~MedLogSystem();  //destructor
};


#endif