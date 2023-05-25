#include "VaccineSystem.h"
#include <algorithm>
using namespace std;

User currentUser;

bool updaterecord()
{
	if (allUsers.count(currentUser.getNationalID()))
	{
		currentUser.update();
		allUsers[currentUser.getNationalID()] = currentUser;
		return true;
	}
	return false;
}
bool deleterecord()
{
	if (allUsers.count(currentUser.getNationalID()))
	{
		return allUsers.erase(currentUser.getNationalID());

	}
	return false;
}
void saveNewUser(User newUser) {
	allUsers[newUser.getNationalID()] = newUser;
}
void registerUser()
{
	string vaccinated;
	string name;
	string nationalID;
	string password;
	char gender;
	int age;
	string governorate;
	string numOfDoses;

	cout << "*****\n";
	cout << "\t\t ENTER YOUR INFORMATION\t\t ";
	cout << "\n";
	cout << "*****\n\n";
	cin.ignore();
	do {
		
		cout << " Enter your First name : ";
		getline(cin, name);
		
		if (!Validation::name_validation(name)) {
			cout << "Please only enter your First name only and make sure that it's more than 3 letters long. \n";
		}
		

	} while (!Validation::name_validation(name));

	cout << "\n";

	do {
		cout << " Enter your national id :  ";
		cin >> nationalID;
		if (!Validation::nationalID_validation(nationalID)) {
			cout << "Invalid ID. Please enter a valid national ID and that there isn't already an account linked to it.\n";
		}
		// Clear the input buffer of any extra characters, including newline characters
		cin.ignore();
	} while (!Validation::nationalID_validation(nationalID));

	cout << "\n";

	do {
		cout << " Enter your password :  ";
		cin >> password;
		if (!Validation::password_validation(password)) {
			cout << "Invalid Password. Please enter a password between 8 and 20 characters.\n";
		}
	} while (!Validation::password_validation(password));

	cout << "\n";

	do {
		cout << " Enter your gender (M/F):  ";
		cin >> gender;
	} while (gender != 'M' && gender != 'm' && gender != 'F' && gender != 'f');

	cout << "\n";

	do {
		cout << " Enter your age :  ";
		cin >> age;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Invalid Age. Please enter an age between 16 and 100.\n";
			continue;
		}
		if (!Validation::age_validation(age)) {
			cout << "Invalid Age. Please enter an age between 16 and 100.\n";
		}
	} while (!Validation::age_validation(age));

	cout << "\n";

	cin.ignore(); 

	do {
		cout << " Enter your governorate :  ";
		getline(cin, governorate); 
		if (!Validation::governorate_validation(governorate)) {
			cout << "Invalid Governorate. Please enter a valid governorate name.\n";
		}
	} while (!Validation::governorate_validation(governorate));

	cout << "\n";

	do {
		cout << " Have you been vaccinated? (Yes/No) :  ";
		cin >> vaccinated;
		if (!Validation::vaccinated_validation(vaccinated)) {
			cout << "Invalid input. Please enter either Yes or No.\n";
		}
	} while (!Validation::vaccinated_validation(vaccinated));

	cout << "\n";

	if (vaccinated == "Yes" || vaccinated == "yes") {
		do {
			cout << " Enter the number of doses you have received (1, or 2) :  ";
			cin >> numOfDoses;
			if (!Validation::numOfDoses_validation(numOfDoses)|| numOfDoses == "0") {
				cout << "Invalid input. Please enter either 1 or 2.\n";
			}
		} while (!Validation::numOfDoses_validation(numOfDoses)|| numOfDoses == "0");

		cout << "\n";
	}
	else {
		numOfDoses = "0";
	}

	User u(name, nationalID, password, gender, age, governorate, vaccinated, numOfDoses);
	

	cout << "You are registered successfully.\n";
	Sleep(700);
	system("cls");
	
	saveNewUser(u);
	currentUser = u;
}
void VaccineSystem::login()
{
	cout << "////////////////// VACCINE TRACKING SYSTEM  //////////////////" << "\n" << "\n";
	cout << " \t Welcome To Login Page " << endl;

	string National_id, Password;
	int num;
	bool flag = false;

	cout << "Would you like to: " << endl;
	cout << "1-sign up" << "\t" << "2-log in" << "\t" << "3-Exit" << endl;

	do {
		cin >> num;

		if (num == 1)
		{
			registerUser();
			userMenu();
			flag = true;
		}
		else if (num == 2)
		{
			bool loginSuccess = false;

			do {
				cout << "Enter National ID: \t";
				cin >> National_id;
				cout << "Enter password: \t";
				cin >> Password;
				cout << "\n";

				if (checkIfAdmin(National_id, Password))
				{
					cout << "Login Successful, Welcome Admin\n";
					Sleep(1000);
					Admin::AdminMenu();
					loginSuccess = true;
				}
				else
				{
					User result = Validation::logInVal(National_id, Password);
					if (result.getName() != "")
					{
						cout << "========Success\n\n";
						currentUser = result;
						system("cls");
						userMenu();
						loginSuccess = true;
					}
					else
					{
						cout << "Invalid National ID or Password.\n\n";
					}
				}
			} while (!loginSuccess);

			flag = true;
		}
		else if (num == 3)
		{
			flag = true;
			exit; 
		}
		else
		{
			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Invalid option you may only choose 1, 2 or 3.\n";
				continue;
			}
		}
	} while (!flag);
}

bool VaccineSystem::checkIfAdmin(string nationalID, string password) {
	transform(nationalID.begin(), nationalID.end(), nationalID.begin(), ::tolower);
	transform(password.begin(), password.end(), password.begin(), ::tolower);

	if (nationalID == "admin" && password == "admin")
	{
		return true;
	}
	return false;
}

void VaccineSystem::userMenu()
{
	int option;
	cout << "Do you want to :" << endl;
	cout << " 1- View your record : " << endl;
	cout << " 2- Update your record : " << endl;
	cout << " 3- Delete your record : " << endl;
	cout << " 4- Logout: " << endl;


	cin >> option;

	system("cls");

	switch (option)
	{
	case 1:
	{
		currentUser.viewrecord(0);
		break;
	}
	case 2:
	{
		updaterecord();
		break;
	}
	case 3:
	{
		deleterecord();
		VaccineSystem::login();
		break;
	}
	case 4: {
		
		allUsers[currentUser.getNationalID()] = currentUser;
		VaccineSystem::login();
		break;
	}
	default:
	{
		cout << "Invalid choice, choose from the menu..\n\n";
		Sleep(800);
		system("cls");
		userMenu();
	}
	}
}



