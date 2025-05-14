#include "pill.h"
#include <iostream>

Pill::Pill():Medication(){}

Pill::Pill(string Name, string Dosage, int Freq, bool Status)
    : Medication(Name, Dosage, Freq, Status){}

string Pill::getType()const 
{
    return "Pill";
}

// display function inherit from class medication

void Pill::display()const{
    cout<<"Pill:"<<'\n';
    cout<<"Name: "<<name<<'\n';     
    cout<<"Dosage: "<<dosage<<'\n';
    cout<<"Time taken per day: "<<frequency_per_day<<'\n';
    cout<<"Status: "<<(taken_today? "Yes":"No")<<'\n';
    cout<<" "<<endl;
}
