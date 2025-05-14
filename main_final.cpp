#include "medlog.h"
#include "medication.h"
#include "user.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    User user;
    MedLogSystem log;
    int main_choice;
    int session_choice;
    string line;
    string temp;
    bool found = false;


    cout<<"==========================="<<'\n';
    cout<<"     MEDLOG MAIN MENU    "<<'\n';
    cout<<"==========================="<<'\n';
    cout<<"1. Load User Profile"<<'\n';
    cout<<"2. Create New User"<<'\n';
    cout<<"3. Exit"<<'\n';
    cout<<" "<<'\n';

    cin>>main_choice;
    cout<<" "<<'\n';
    while (main_choice!=3){
        if (main_choice ==1)
        {
            string username;

            cout<<"Please enter your username: ";
            cin>>username;     //assuming each user name is unique to one user

            ifstream file(username+".txt"); // check if the username is correct to what is stored inside text file
            if(file.is_open()){
                found = true;
            }
    

            if (found ==true)
            {
                user.startSession();
                cout<<" "<<'\n';
                
                string filename;

                filename = username+".txt";

                cin>>session_choice;
                cout<<'\n';

                while (session_choice!=8)
                {

                    if (session_choice == 1){
                        log.addMedication();
                        cout<<'\n';

                    }
                    else if(session_choice ==2){
                        log.displayAll();
                        cout<<'\n';

                    }
                    else if(session_choice ==3){
                        log.markDosage();
                        cout<<'\n';

                    }
                    else if(session_choice ==4){
                        log.resetAll();
                        cout<<'\n';

                    }
                    else if(session_choice ==5){
                        user.saveUserData("clients.txt");
                        log.saveToFile(filename);
                        cout<<'\n';

                    }
                    else if(session_choice ==6){
                        user.loadUserData("clients.txt",username);
                        log.loadFromFile(filename);
                        cout<<'\n';

                    }
                    else if(session_choice ==7){
                        user.displayProfile();
                        cout<<'\n';
                    }

                    user.startSession();
                    cout<<'\n';
                    cin>>session_choice;
                }
                found = false;
            }

            else
            {
                cout<<"Sorry, username does not exist"<<endl; // output message indicating no such username
            }
        }
        else if(main_choice==2){
            string username, email;
            
            int age, phonenum;

            cout<<"Please enter your username: "; // assumoing each username is unique
            cin>>username;

            user.setName(username);
            
            cout<<"Please enter your age: ";
            cin>>age;
            user.setAge(age);

            cout<<"Please enter your email: ";
            cin>>email;
            user.setEmail(email);

            cout<<"Please enter your phone number: ";
            cin>>phonenum;
            user.setPhoneNum(phonenum);

            user.saveUserData("clients.txt");

            log.addMedication();
            log.saveToFile(username+".txt");
        }
        cout<<" "<<'\n';
        cout<<"==========================="<<'\n';
        cout<<"     MEDLOG MAIN MENU    "<<'\n';
        cout<<"==========================="<<'\n';
        cout<<"1. Load User Profile"<<'\n';
        cout<<"2. Create New User"<<'\n';
        cout<<"3. Exit"<<'\n';
        cout<<'\n';
        cin>>main_choice;
    }
}
