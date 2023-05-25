#include "Admin.h"
#include "VaccineSystem.h"
#include <unordered_map>
#include <vector>
#include <algorithm>
#include<iostream>
#include <string>
#include<queue>
#include<cmath>
using namespace std;

int choice;
Admin::Admin(void) {}

void Admin::A_ViewRecords()
{
	string n_id;
	User u;


	do {
		cout << "Do You want to view: " << endl;
		cout << "1-Specific user: " << endl << "2-All Records: " << endl << "3-Return to menu:" << endl;
		cin >> choice;
		cout << "\n";
		system("cls");
		switch (choice)
		{
		case 1:

			cout << "Enter national id for specific record: ";
			cin >> n_id;
			u = allUsers.at(n_id);
			system("cls");
			User::DisplayInfo(u);
			back_to_menu();
			cout << "\n";


			break;
		case 2:
			for (auto i = allUsers.begin(); i != allUsers.end(); i++) {
				u = allUsers.at(i->first);
				User::DisplayInfo(u);
				cout << "-----------\n";
			}
			cout << "========================\n\n";
			back_to_menu();
			break;
		case 3:
			AdminMenu();
			break;
		default:
		{
			cout << "Invalid choice, choose from the menu..\n\n";
			User::intval();
			choice = -1;
			Sleep(800);
			system("cls");
			A_ViewRecords();
		}
		}
	} while (choice != 3);
}
void Admin::A_DeleteRecords()
{
	string n_id;
	char x;
	
	do {
		system("cls");
		cout << "Do You want to Delete: " << endl;
		cout << "1-Specific user: " << endl << "2-All Records: " << endl << "3-Return to menu:\n";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
		case 1:
			cout << "Enter national id for specific record: ";
			cin >> n_id;
			User::DisplayInfo(allUsers[n_id]);
			cout << "\nIs this the user you want to delete?(y/n)\n";
			cin >> x;
			if (x == 'y' || x == 'Y')
			{
				allUsers.erase(n_id);
				cout << "User Deleted...\n";
				Sleep(700);
			}

			break;
		case 2:
			allUsers.clear();
			break;
		case 3:
			AdminMenu();
			break;
		default:
			cout << "Invalid choice, choose from the menu..\n\n";
			User::intval();
			choice = -1;
			Sleep(800);
			system("cls");
			A_DeleteRecords();
		}
	} while (choice != 3);

}
void Admin::A_ViewByNumOfDoses()
// More than one record will be diplayed because number of doses is repeated
{
	User u;
	string numdoses;
	do {
		cout << "Enter number of doses you want to display or enter 9 to return to menu: " << endl;
		cin >> numdoses;
		cout << "\n";

		if (numdoses == "0" || numdoses == "1" || numdoses == "2") {
			for (auto i = allUsers.begin(); i != allUsers.end(); i++) {
				if (i->second.hasNumOfDoses() == numdoses) {
					u = allUsers.at(i->first);
					cout << "---------------\n";
					User::DisplayInfo(u);
					cout << "=============================\n\n";
				}
				else { continue; }
			}
		}
		else if (numdoses == "9")
			break;
		else {
			cout << "Invalid number of doses, enter 0, 1 or 2..\n";

			Sleep(500);
		}
	} while (true);
	AdminMenu();
}
bool Admin::A_CompareByAge(User& value1, User& value2)
{
	return value1.getAge() < value2.getAge();
}
void Admin::A_ViewByAge()
{
	User u;
	vector<User>Uage;
	for (auto i = allUsers.begin(); i != allUsers.end(); i++) {
		if (i->second.hasNumOfDoses() =="1" || i->second.hasNumOfDoses() == "2")
		{
			Uage.push_back(i->second);
		}
		
	}
	sort(Uage.begin(), Uage.end(), A_CompareByAge);
	for (int i = 0; i < Uage.size(); i++)
	{
		u = Uage[i];
		cout << "-------------\n";
		User::DisplayInfo(u);
	}
	cout << "=============================\n\n";
	do {
		cout << "Enter 9 to go back to menu \n";
		cin >> choice;
		if (choice == 9) {
			AdminMenu();
			break;
		}
		else {
			cout << "Invalid choice. Please enter 9 to go back to menu.\n";
			User::intval();
			choice = -1;
		}
	} while (choice != 9);
	
}

void Admin::A_ViewStat()
{
	float count, Fcount, Mcount;
	float Percentage, Mpercentage, Fpercentage;
	do {
		count = 0; Fcount = 0; Mcount = 0;
		cout << "Choose Your Desired Option" << endl;
		cout << "1- Show Perecntage of People With One Dose" << endl;
		cout << "2- Show Perecntage of People With Two Doses" << endl;
		cout << "3- Show Perecntage of People Who AREN'T vaccinated" << endl;
		cout << "4- Show Percentage of Males & Females\n";
		cout << "5- Show age ranges percentages in different doses\n";
		cout << "6- Show Percentage of doses taken in Males and Females\n";
		cout << "7- Show Percentage of doses taken in major governorates\n";
		cout << "press 9 to Return to menu\n";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			system("cls");

			for (auto i = allUsers.begin(); i != allUsers.end(); i++) {
				if (i->second.hasNumOfDoses() == "1") {
					count++;
				}
			}

			Percentage = (count / allUsers.size()) * 100;
			cout << "\nPercentage of people With One Dose Is = " << " " << Percentage << " %\n\n";
			break;
		}
		case 2:
		{			system("cls");

			for (auto i = allUsers.begin(); i != allUsers.end(); i++) {
				if (i->second.hasNumOfDoses() == "2") {
					count++;
				}
			}

			Percentage = (count / allUsers.size()) * 100;
			cout << "\nPercentage of people With Two Doses Is = " << " " << Percentage << " %\n\n";
			break;
		}
		case 3:
		{			system("cls");

		for (auto i = allUsers.begin(); i != allUsers.end(); i++) {
			if (i->second.hasNumOfDoses() == "0") {
				count++;
			}
		}

		Percentage = (count / allUsers.size()) * 100;
		cout << "\nPercentage of people With Two Doses Is = " << " " << Percentage << " %\n\n";
		break;
		}
		case 4:
		{			system("cls");

			for (auto i : allUsers) {
				if (i.second.getGender() == 'M' || i.second.getGender() == 'm')
				{
					Mcount++;
				}
				else { Fcount++; }
			}

			Mpercentage = (Mcount / allUsers.size()) * 100;
			Fpercentage = (Fcount / allUsers.size()) * 100;

			cout << "\nThe percentage Of Males Registered Is = " << " " << Mpercentage << " %\n";
			cout << "The percentage Of Females Registered Is = " << " " << Fpercentage << " %\n\n";
			break;
		}
		case 5: {			system("cls");

			age_vaccinedose();
			break;
		}
		case 6: {			system("cls");

			gender_avaccinedose();
			break;
		}
		case 7: {			system("cls");

			governorate_vaccinedose();
			break;
		}
		case 9: {			system("cls");

			AdminMenu();
			break; }
		default:
		{
			cout << "Invalid choice, choose from the menu..\n\n";
			Sleep(800);
			system("cls");
			A_ViewStat();
		}
		}
	} while (choice != 9);
}
void Admin::AdminMenu()
{
	int choice;
	system("cls");
	cout << "Enter your choice: " << endl;
	cout << "1-View Record\n2-Delete Record\n3-View Records Filtered By Number Of Doses \n4-View Next In Witing List\n5-View Users By Age\n6-View Basic or Advanced Statistics\n7-Logout \n";
	cin >> choice;
	cout << "\n";

	switch (choice)
	{
	case 1:
		system("cls");
		A_ViewRecords();
		break;
	case 2:
		system("cls");
		A_DeleteRecords();
		break;
	case 3:
		system("cls");
		A_ViewByNumOfDoses();
		break;
	case 4:
		system("cls");
		A_ViewFromWaitingList();
		break;
	case 5:
		system("cls");
		A_ViewByAge();
		break;
	case 6:
		system("cls");
		A_ViewStat();
		break;
	case 7:
		
		system("cls");
		VaccineSystem::login();
		break;
	default:
	{
		cout << "Invalid choice, choose from the menu..\n\n";
		User::intval();
		choice = -1;
		Sleep(800);
		system("cls");
		AdminMenu();
	}
	}
}

void Admin::back_to_menu() {
	int choice;
	cout << "\nEnter 9 to go back to the main menu: ";
	cin >> choice;

	while (choice != 9) {
		cout << "\nInvalid choice. Please enter 0 to go back to the main menu: ";
		cin >> choice;
	}

	if (choice == 9) {
		system("cls");
		A_ViewRecords();
	}
}
void Admin::A_ViewFromWaitingList()
{
	User u1, u2;
	
	int choice;
	queue<User> first_dose;
	queue<User> second_dose;
	for (auto i = allUsers.begin(); i != allUsers.end(); i++) {
		if (i->second.hasNumOfDoses() == "0")
		{
			first_dose.push(allUsers.at(i->first));

		}
		else if (i->second.hasNumOfDoses() == "1")
		{
			second_dose.push(allUsers.at(i->first));
		}
	}
	u1 = first_dose.front();
	u2 = second_dose.front();
	cout << " First user that has to take his first dose:  " << endl;
	User::DisplayInfo(u1);
	cout << endl;
	cout << " First user that has to take his second dose:  " << endl;
	User::DisplayInfo(u2);
	cout << endl;
	cout << "=============================\n\n";

	first_dose.pop();
	second_dose.pop();

	u1 = first_dose.front();
	u2 = second_dose.front();
	cout << "Second user that has to take his first dose:  " << endl;
	User::DisplayInfo(u1);
	cout << endl;
	cout << "Second user that has to take his second dose:  " << endl;
	User::DisplayInfo(u2);
	cout << endl;
	cout << "=============================\n\n";
	do {
		cout << "Enter 9 to go back to menu \n";
		cin >> choice;
		if (choice == 9) {
			AdminMenu();
			break;
		}
		else {
			cout << "Invalid choice. Please enter 9 to go back to menu.\n";
			User::intval();
			choice = -1;
		}
	} while (choice != 9);

}

void Admin::A_compute_dosage_percentage(float &n1, float &n2, float &n3, vector<string> row_dose,int i ,float &sum)
{
	if (row_dose[i] == "0") { n1++; }
	else if (row_dose[i] == "1") { n2++; }
	else { n3++; }
	sum = n3 + n2 + n1;
}
void Admin ::governorate_vaccinedose()
{
	//Cairo ->zero// Giza ->one // Alexandria ->two 
	vector<string>row_goverment; 
	vector<string>row_dose;
	float zero_zero = 0, zero_one = 0, zero_two = 0;
	float one_zero = 0, one_one = 0, one_two = 0;
	float two_zero = 0, two_one = 0, two_two = 0;
	float total_cairo = 0, total_giza = 0, total_alex = 0;

		for (auto i = allUsers.begin(); i != allUsers.end(); i++)
		{
			row_goverment.push_back(i->second.getGovernorate());
			row_dose.push_back(i->second.hasNumOfDoses());

		}
	for (int i = 0; i < row_goverment.size(); i++)
	{
		if (row_goverment[i] == "Cairo" || row_goverment[i] == "cairo") {
			A_compute_dosage_percentage(zero_zero, one_zero, two_zero, row_dose, i, total_cairo);
		}
		else if (row_goverment[i] == "Giza" || row_goverment[i] == "giza") {

			A_compute_dosage_percentage(zero_one, one_one, two_one, row_dose, i, total_giza);
		}
		else if (row_goverment[i] == "alexandria" || row_goverment[i] == "Alexandria") {
			A_compute_dosage_percentage(zero_two, one_two, two_two, row_dose, i, total_alex);
		}

	}

	cout << "\tNo doses" << "\t\t" << "1 dose " << "\t\t\t" << "2 dose " << endl;
	cout << "Cairo:\t" << round((zero_zero / total_cairo) * 100) << "%\t\t\t" << round((one_zero / total_cairo) * 100) << "%\t\t\t" << round((two_zero / total_cairo) * 100) << "%\n\n";
	cout << "Giza:\t" << round((zero_one / total_giza) * 100) << "%\t\t\t" << round((one_one / total_giza) * 100) << "%\t\t\t" << round((two_one / total_giza) * 100 )<< "%\n\n";
	cout << "Alex:\t" <<round((zero_two / total_alex) * 100) << "%\t\t\t" << round((one_two / total_alex) * 100 )<< "%\t\t\t" << round((two_two / total_alex) * 100) << "%\n\n";

}

void Admin::gender_avaccinedose()
{

	vector<char>row_gender;
	vector<string>row_dose;
	float zero_male = 0, zero_female = 0;
	float one_male = 0, one_female = 0;
	float two_male = 0, two_female = 0;
	float sum_male = 0, sum_female = 0;

	for (auto i = allUsers.begin(); i != allUsers.end(); i++)
	{
		row_gender.push_back(i->second.getGender());
		row_dose.push_back(i->second.hasNumOfDoses());

	}
	for (int i = 0; i < row_gender.size(); i++)
	{
		if (row_gender[i] == 'f'|| row_gender[i] == 'F') {
			A_compute_dosage_percentage(zero_female, one_female, two_female, row_dose, i, sum_female);
		}

		else if (row_gender[i] == 'M'|| row_gender[i] == 'm') {
			A_compute_dosage_percentage(zero_male, one_male, two_male, row_dose, i, sum_male);
		}
	}



	cout << "\t\tNo doses" << "\t\t" << "1 dose " << "\t\t\t" << "2 dose " << endl;
	cout << " Female:\t" << round((zero_female / sum_female) * 100 )<<"%\t\t\t" << round((one_female / sum_female) * 100) << "%\t\t\t" << round((two_female / sum_female) * 100) << "%\n\n";
	cout << " Male:  \t" << round((zero_male / sum_male) * 100) << "%\t\t\t" << round((one_male / sum_male) * 100 )<< "%\t\t\t" << round((two_male / sum_male) * 100) << "%\n\n";

}

void Admin::age_vaccinedose()
{
	//16 till 30 ->zero// 31 till 44 ->one // 45 till 58 ->two // 59+  ->3
	vector<float>row_age;
	vector<string>row_dose;
	float zero_zero = 0, zero_one = 0, zero_two = 0, zero_three = 0;
	float one_zero = 0, one_one = 0, one_two = 0, one_three = 0;
	float two_zero = 0, two_one = 0, two_two = 0, two_three = 0;
	float sum_age_zero = 0, sum_age_one = 0, sum_age_two = 0, sum_age_three = 0;

	for (auto i = allUsers.begin(); i != allUsers.end(); i++)
	{
		row_age.push_back(i->second.getAge());
		row_dose.push_back(i->second.hasNumOfDoses());

	}
	for (int i = 0; i < row_age.size(); i++)
	{
		if (row_age[i] >= 16 && row_age[i] <= 30) {
			A_compute_dosage_percentage(zero_zero, one_zero, two_zero, row_dose, i, sum_age_zero);
		}
		else if (row_age[i] > 31 && row_age[i] <= 44) {
			A_compute_dosage_percentage(zero_one, one_one, two_one, row_dose, i, sum_age_one);
		}
		else if (row_age[i] > 45 && row_age[i] <= 58) {
			A_compute_dosage_percentage(zero_two, one_two, two_two, row_dose, i, sum_age_two);
		}
		else if (row_age[i] > 58) {
			A_compute_dosage_percentage(zero_three, one_three, two_three, row_dose, i, sum_age_three);
		}

	}

	cout << "\t\tNo doses" << "\t\t" << "1 dose " << "\t\t\t" << "2 dose " << endl;
	cout << " Age(16-30):\t"  << round((zero_zero / sum_age_zero) * 100) << "%\t\t\t" << round((one_zero / sum_age_zero) * 100) << "%\t\t\t" << round((two_zero / sum_age_zero) * 100) << "%\n\n";
	cout << " Age(31-44):\t" << round((zero_one / sum_age_one) * 100) << "%\t\t\t" << round((one_one / sum_age_one) * 100 )<< "%\t\t\t" << round((two_one / sum_age_one) * 100 )<< "%\n\n";
	cout << " Age(45-58):\t" << round((zero_two / sum_age_two) * 100) << "%\t\t\t" << round((one_two / sum_age_two) * 100 )<< "%\t\t\t" << round((two_two / sum_age_two) * 100) << "%\n\n";
	cout << " Age(59+):\t" << round((zero_three / sum_age_three) * 100 )<< "%\t\t\t" << round((one_three / sum_age_three) * 100 )<< "%\t\t\t" << round((two_three / sum_age_three) * 100) << "%\n\n";
}
