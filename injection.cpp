#include "injection.h"
#include <iostream>

Injection::Injection() : Medication(){}

Injection::Injection(string Name, string Dosage, int Freq, bool Status) 
    : Medication(Name, Dosage, Freq, Status){}

string Injection::getType()const 
{
    return "Injection";
}

//display function inherit from medication super class
void Injection::display()const
{
    cout<<"Injection:"<<'\n';
    cout<<"Name: "<<name<<'\n';
    cout<<"Dosage: "<<dosage<<'\n';
    cout<<"Time taken per day: "<<frequency_per_day<<'\n';
    cout<<"Status: "<<(taken_today? "Yes":"No");
    cout<<'\n';
}