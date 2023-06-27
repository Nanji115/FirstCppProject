#include<iostream>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<fstream>
#include<cmath>
#include<string>

using namespace std;
void RandPassGen();

int main(){
    fstream PassFile;
    cout << "Hello, what you wanna do?"<< endl;

    while (true){
        cout << "1. Login (If u have alr registered) \n"
            "2. Register (If you are new here) \n"
            "3. Random Password generator (Let the computer recommends you a password) \n";

        int UserInput = getch();
        string UserName, PassWord, line;
        int checked = 0;

        switch(UserInput){
            case '1':
                cout << "You chose 1 \n";
                system("cls");
                cout << "User? "; cin >> UserName;
                cout << "Password? "; cin >> PassWord;

                PassFile.open("PassWord.txt");

                while (getline(PassFile, line)){
                    if (line == UserName && checked == 0){
                            checked = 1;
                            continue;
                    }
                    if (checked == 1){
                        if (line == PassWord){
                            system("cls");
                            checked = 2;
                            cout << "Access Granted!\n";
                            break;
                        }
                    }
                    cout << "Error, Wrong Password or UserName\n\nMaybe You haven't registered, how about choosing 2?\n\n";
                    break;
                }
                PassFile.close();

                if (checked == 2){
                    break;
                } else {
                    continue;
                }
            case '2':
                cout << "You chose 2 \n";
                system("cls");
                PassFile.open("PassWord.txt");

                cout << "Create a UserName: ";
                cin >> UserName;

                cout << "Create a PassWord: ";
                cin >> PassWord;

                if (PassFile.is_open()){
                    PassFile << UserName << endl;
                    PassFile << PassWord << endl;
                    PassFile.close();
                }

                system("cls");
                cout << "Account created successfullly \nReturning...\n\n";
                cout << "Choose again!!\n";
                continue;

            case '3':
                cout << "You chose 3 \n";
                system("cls");
                cout << "PassWord Generated was:...\n" << endl;
                RandPassGen();//Func
                cout << "\nChoose again!!\n";
                continue;

            default:
                cout << "Sorry, that is not a valid input \nPlease type again\n";
                continue;
        }
        break; // break out of while true
    }


    return 0;
}

void RandPassGen(){
    string RandPass;
    //seed the random number
    time_t now;
    time(&now);
    srand(now);
    RandPass.append("X");
    RandPass.append(to_string(rand()/100));
    RandPass.append("Y");
    RandPass.append(to_string(rand()/100));
    RandPass.append("P");
    RandPass.append(to_string(rand()/100));
    cout << RandPass << endl;
}

