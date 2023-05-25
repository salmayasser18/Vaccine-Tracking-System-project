#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdlib.h>
#include <Windows.h>
using namespace std;

class User
{
private:
    string Name;
    string NationalID;
    string Password;
    char Gender;
    int Age;
    string Governorate;
    string Vaccinated;
    string NumOfDoses;
public:
   


   // Constructor
    User(string Name, string NationalID, string Password, char Gender, int Age, string Governorate, string Vaccinated, string NumOfDoses);
    User();


    //getters
    string getName();
    string getNationalID();
    string getPassword();
    char getGender();
    int getAge();
    string getGovernorate();
    string isVaccinated();
    string hasNumOfDoses();

    //setters
    void setName(string Name);
    void setNationalID(string NationalID);
    void setPassword(string Password);
    void setGender(char Gender);
    void setAge(int Age);
    void setGovernorate(string Governorate);
    void setVaccinated(string Vaccinated);
    void setNumOfDoses(string NumOfDoses);


    //user functionalities

    static void DisplayInfo(User u);
    void viewrecord(int caller);
    void update();
    static void intval();
   

    User& operator = (const User& user);  

};

extern unordered_map<string, User> allUsers;

