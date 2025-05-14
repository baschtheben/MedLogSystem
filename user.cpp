#include "user.h"
#include <fstream>
#include <iostream>
#include <sstream>

//default constructor
User::User(){};

//overloaded constructor
User::User(string _username, int _age, string _email, int _phoneNum){
    userName = _username;
    age = _age;
    email = _email;
    phoneNum = _phoneNum;
}

// setters"
void User::setName(string _userName){
    userName = _userName;
}

void User::setAge(int _age){
    age = _age;
}

void User::setEmail(string _email){
    email = _email;
}

void User::setPhoneNum(int _phoneNum){
    phoneNum = _phoneNum;
}

//getters:
string User::getName(){
    return userName;
}

int User::getAge(){
    return age;
}

string User::getEmail(){
    return email;
}

int User::getPhoneNum(){
    return phoneNum;
}

// is called after function loadUserData is called
void User::displayProfile(){
    cout<<" "<<'\n';
    cout<<"Username: "<<User::getName()<<'\n';
    cout<<"Age: "<<User::getAge()<<'\n';
    cout<<"Email: "<<User::getEmail()<<'\n';
    cout<<"Phone number: "<<User::getPhoneNum()<<'\n';
}

//save user personal information - name, age, email, phone number
void User::saveUserData(string filename){  
    ofstream file(filename);            // open a text file to write
    
    //write user personal information on one single line, each info is separated with a comma
    if(file.is_open()){

        file<<getName()<<',';
        file<<getAge()<<',';
        file<<getEmail()<<',';
        file<<getPhoneNum()<<'\n';

        file.close();

    }
    else{
        cout<<"Eror, file not found!"<<'\n';
    }
}   


// is used after saveUserData is called
void User::loadUserData(string filename, string username){
    string line;
    string temp;
    long int phonenum;

    ifstream file(filename);

    if(file.is_open()){
        while(getline(file, line)){

            // string stream allow a singe string to be separated into differnt string value
            stringstream ss(line);  // pass the very first line in the text file into variable ss


            getline(ss, temp, ',');    //string value in ss from beginning to before comma is passed on to variable temp 
            if(temp ==username){            
                setName(temp);            
            }

            getline(ss, temp, ',');   
            setAge(stoi(temp));   // change the data type of temp variable from string to integer

            getline(ss, temp, ',');
            setEmail(temp);

            getline(ss, temp, ',');
            phoneNum = stoi(temp);
            setPhoneNum(phonenum);
        }
    }
    else{
        cout<<"Error, file not found!"<<'\n';
    }
    file.close();
}

// called after function loadUserData is called
// output menu for user after their username is verified
void User::startSession(){
    cout<<'\n';
    cout<<"==========================="<<'\n';
    cout<<"     MEDICATION MANAGER      "<<'\n';
    cout<<"==========================="<<'\n';
    cout<<"1. Add medication"<<'\n';
    cout<<"2. View medications"<<'\n';
    cout<<"3. Mark dosage as taken"<<'\n';
    cout<<"4. Reset for new day"<<'\n';
    cout<<"5. Save"<<'\n';
    cout<<"6. Load"<<'\n';
    cout<<"7. View User Profile"<<'\n';
    cout<<"8. Return to Main Menu"<<'\n';

}