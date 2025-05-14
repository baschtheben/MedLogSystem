#include "medlog.h"
#include "medication.h"
#include "pill.h"
#include "injection.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

// prompt and ask user to type in the medication they want to add
void MedLogSystem::addMedication()
{
    string type;  
    string name;
    string dosage;
    int frequency;
    Medication* med = nullptr;
    bool nostop = true;
    string proceed;

    // allow user to type in new medication until they want to stop
    while (nostop){
        cout<<'\n';
        cout<<"Please enter the type of medication (pill or injection): ";
        cin>>type;
        cin.ignore();  //to skip the next line and allow the next value to be input
        cout<<'\n';

        cout<<"Please enter the name of medication: ";
        getline(cin, name);
        cout<<'\n';

        cout<<"Please enter the dosage amount: ";
        getline(cin, dosage);
        cout<<'\n';

        cout<<"Please enter the time taken per day: ";
        cin>>frequency; 
        cin.ignore();
        cout<<'\n';

        if(type =="pill")  // check if type is pill
        {
            med = new Pill(name, dosage, frequency, false);   //new location created for object pill  and is stored by med pointer
            meds.push_back(med);                              // append the new location to meds vector
            cout<<"Added successfully"<<'\n';
        }

        else if (type=="injection")
        {
            med = new Injection(name, dosage, frequency, false);
            meds.push_back(med);
            cout<<"Added successfully"<<'\n';
        }
        cout<<"Do you wish to add more (yes or no): ";    //assume user exactly type yes or no

        getline(cin, proceed); // check whether user wish to continue adding
        if (proceed == "yes"){
            nostop = true;
        }
        else{
            nostop = false;
        }
    }
}

// display all the medications of user. Called after function loadFromFile is called
void MedLogSystem::displayAll()  
{
    for (int i = 0; i<meds.size(); i++)
    {
        if (meds.at(i)!=nullptr)   //check for null pointer if null pointer then there is no value to display
        {
            meds.at(i)->display();  
        }
    }
}

void MedLogSystem::markDosage( )
{
    string MedName;
    cout<<"Please enter the name of the medication you want to mark take: "; 
    cin>>MedName;

    for (int i=0; i<meds.size(); i++){     // loop through each object stored in the meds vector
        if(meds.at(i)!=nullptr){            // check if the pointer is pointing to any object
            if(meds.at(i)->getName()==MedName){   // look for the medication asked by user
                meds.at(i)->markAsTaken();        // once found the medication, set its taking status to true
                cout<<"Mark successfullyt!"<<'\n';
            }
        }
    }
}

void MedLogSystem::resetAll()
{
    for (int i=0; i<meds.size(); i++){     // loop through vector meds
        if (meds.at(i)!=nullptr){                   // check if the pointer is pointing to any object
            meds.at(i)->resetForNewDay();               // set taken status to false
        }
    }
    cout<<"Reset successfully!"<<'\n';   
}

void MedLogSystem::saveToFile(string filename)
{
    ofstream file(filename); // create a new file to input user medication

    if(file.is_open()) // check if the file is open
    {
        for (int i=0; i<meds.size();i++){  // loop through the vector meds to access each object
            if (meds.at(i)!=nullptr){   // check whether the pointer is pointing to any address

    // write into the text file in one single line the medication info and each info is separated with a comma
                file<<meds.at(i)->getType()<<',';    
                file<<meds.at(i)->getName()<<',';
                file<<meds.at(i)->getDosage()<<',';
                file<<meds.at(i)->getFreq()<<',';
                file<<meds.at(i)->getStatus()<<endl;
            }   
        }
        file.close();
    }

    else
    {
        cout<<"Error, file not found!";   //return this when file is not found
        file.close();
    }
}

void MedLogSystem::loadFromFile(string filename)
{   

    Medication* med;

    if(med!=nullptr){
        for (Medication* med : meds){
            delete med;
        }
    }
    meds.clear();

    ifstream file(filename);

    if(file.is_open())
    {
        string line;   //stores each line of medication
        string temp;     //temporarily hold value for name and dosage
        char status;      //hold value for taking status
        int freq;           //hold value for amount taking per day

        while (getline(file,line))
        {
            stringstream ss(line);

            getline(ss,temp,',');

            // set pill object
            if (temp =="Pill")
            {
                med = new Pill(); // pointer med point to the memory locaiton of newly created Pill object 

                // read name from string and set it into Pill object
                getline(ss,temp,',');
                med->setName(temp);

                // read dosage from string and set it into Pill object
                getline(ss,temp,',');
                med->setDosage(temp);

                // read frequency from string and set it into Pill object
                getline(ss,temp,',');
                freq = stoi(temp);
                med-> setFreq(freq);

                // read status from string and set it into Pill object
                getline(ss,temp);
                status = temp[0];
                if (status =='0'){
                    med->setStatus(false);
                }else{
                    med->setStatus(true);
                }
                meds.push_back(med);  // store the pointer to the Pill object in vector meds

            }

            // set Injection object
            else if (temp =="Injection")
            {
                med = new Injection(); // pointer med point to the memory locaiton of newly created Injection object 

                // read name from string and set it into Pill object
                getline(ss,temp,',');
                med->setName(temp);

                // read dosage from string and set it into Pill object
                getline(ss,temp,',');
                med->setDosage(temp);

                // read frequency from string and set it into Pill object
                getline(ss,temp,',');
                freq = stoi(temp);
                med-> setFreq(freq);

                // read status from string and set it into Pill object
                getline(ss,temp);
                status = temp[0];
                if (status =='0'){
                    med->setStatus(false);
                }else{
                    med->setStatus(true);
                }

                meds.push_back(med); // store the pointer to the Injection object in vector meds
            }
        }
    }

    else
    {
        cout<<"Error file not found!";
    }
    file.close();
}

MedLogSystem::~MedLogSystem()  // used to free up unused memory address
{
    for(Medication* med:meds){
        if (med!=nullptr){
            delete med;
            med = nullptr;
        }
    }
}
