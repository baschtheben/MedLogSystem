#include "medication.h"
#include "user.h"
#include <string>
#include <iostream>


Medication::Medication(){}

Medication::Medication(string Name, string Dosage, int Freq, bool Status)
{
    name = Name;
    dosage = Dosage;
    frequency_per_day = Freq;
    taken_today = Status;
}

void Medication::markAsTaken()
{
    setStatus(true);
}

void Medication::resetForNewDay()
{
    setStatus(false);
}

void Medication::setName(string Name)
{
    name = Name;
}   

void Medication::setDosage(string Dosage)
{
    dosage = Dosage;
}

void Medication::setFreq(int Freq)
{
    frequency_per_day = Freq;
}

void Medication::setStatus(bool Status){
    taken_today = Status;
}

string Medication::getName()const{
    return name;
}

string Medication::getDosage()const{
    return dosage;
}

int Medication::getFreq()const{
    return frequency_per_day;
}

bool Medication::getStatus()const
{
    return taken_today;
}


