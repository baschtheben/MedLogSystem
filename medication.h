#ifndef MEDICATION_H
#define MEDICATION_H

#include <string>
using namespace std;

class Medication 
{
protected: 
    string name;
    string dosage;
    int frequency_per_day;
    bool taken_today;

public:
    Medication();
    Medication(string Name, string Dosage, int Freq, bool Status);

    void markAsTaken();
    void resetForNewDay();

    //setters to set up the value or each of the below variables
    void setName(string Name);
    void setDosage(string Dosage);
    void setFreq(int Freq);
    void setStatus(bool Status);

    //getters, return value of each variable
    string getName()const;
    string getDosage()const;
    int getFreq()const;     
    bool getStatus()const;
 
    //pure virtual functions
    virtual void display()const = 0;
    virtual string getType()const=0;

};




#endif