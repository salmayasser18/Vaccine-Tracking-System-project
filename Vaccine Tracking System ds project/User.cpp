#include "Validation.h"
#include "VaccineSystem.h"


using namespace std;

 unordered_map<string, User> allUsers;



User::User()
{

	Name = "";
	NationalID = "";
	Password = "";
	Gender = ' ';
	Age = 0;
	Governorate = "";
	Vaccinated = "No";
	NumOfDoses = "0";
}
User::User(string Name, string NationalID, string Password, char Gender, int Age, string Governorate, string Vaccinated, string NumOfDoses) {
	setName(Name);
	setNationalID(NationalID);
	setPassword(Password);
	setGender(Gender);
	setAge(Age);
	setGovernorate(Governorate);
	setVaccinated(Vaccinated);
	setNumOfDoses(NumOfDoses);
}


// Getter methods
string User::getName() {
	return this->Name;
}
string User::getNationalID() {
	return this->NationalID;
}
string User::getPassword() {
	return this->Password;
}
char User::getGender() {
	return this->Gender;
}
int User::getAge() {
	return this->Age;
}
string User::getGovernorate() {
	return this->Governorate;
}
string User::isVaccinated() {
	return this->Vaccinated;
}
string User::hasNumOfDoses() {
	return this->NumOfDoses;
}


// Setter methods
void User::setName(string Name) {
		this->Name = Name;
}
void User::setNationalID(string NationalID) {
		this->NationalID = NationalID;
}
void User::setPassword(string Password) {
		this->Password = Password;
}
void User::setGender(char Gender) {
	this->Gender = Gender;
}
void User::setAge(int Age) {
		this->Age = Age;
}
void User::setGovernorate(std::string Governorate) {
		this->Governorate = Governorate;
}
void User::setVaccinated(string Vaccinated) {
	this->Vaccinated = Vaccinated;
}
void User::setNumOfDoses(string NumOfDoses) {
		this->NumOfDoses = NumOfDoses;
}

// functions
void User::intval() {
	cin.clear();
	cin.ignore(10000, '\n');

}

User& User::operator= (const User& user)
{
	// do the copy
	setName(user.Name);
	setNationalID(user.NationalID);
	setPassword(user.Password);
	setGender(user.Gender);
	setAge(user.Age);
	setGovernorate(user.Governorate);
	setVaccinated(user.Vaccinated);
	setNumOfDoses(user.NumOfDoses);
	// return the existing object so we can chain this operator
	return *this;
}


void User::DisplayInfo(User u)
{
	cout << "User Name: " << u.getName() << endl;
	
	cout << "User Gender: " << u.getGender() << endl;
	cout << "User Age: " << u.getAge() << endl;
	cout << "User Governorate: " << u.getGovernorate() << endl;
	cout << "Is User Vaccinated? " << u.isVaccinated() << endl;
	cout << "How many Doses Did the user take? " << u.hasNumOfDoses() << endl;
}
void User::viewrecord(int caller)
{
	int c = 0;
	do
	{
		
		cout << "[1] User Name: " << getName() << endl;
		cout << "[2] User Gender: " << getGender() << endl;
		cout << "[3] User Age: " << getAge() << endl;
		cout << "[4] User Governorate: " << getGovernorate() << endl;
		cout << "[5] Is User Vaccinated? " << isVaccinated() << endl;
		cout << "[6] How many Doses Did the user take? " << hasNumOfDoses() << endl;
		cout << "Enter 9 to go back..\n";
		if (caller == 0)
		{
			cin >> c;
			if (c == 9)
			{
				system("cls");
				VaccineSystem::userMenu();
			}
			else
			{
				cout << "The details shown are only for display, you can go back to menu if you want to update values \n";
				Sleep(3000);
				system("cls");
			}
		}

	} while (c != 9 && caller == 0);

}
void User::update()
{
	int choice;
	string strV;
	int intV;
	char g;

	do {
		bool flag = false;
		viewrecord(1);
		cout << "\n\nWhich value do you want to Update?\n";
		cin >> choice;
		cin.ignore();

		switch (choice) {
		case 1 : {
			cout << "Enter updated name: \n";
			getline(cin, strV);
			setName(strV);
			flag = true;
			break;
		}
		case 2: {
			cout << "Enter updated gender: \n";
			cin >> g;
			setGender(g);
			flag = true;
			break;
		}
		case 3: {
			cout << "Enter updated age: \n";
			cin >> intV;
			setAge(intV);
			flag = true;
			break;
		}
		case 4: {
			cout << "Enter updated governorate: \n";
			cin >> strV;
			setGovernorate(strV);
			flag = true;
			break;
		}
		case 5: {
			cout << "Enter update vaccine status (yes/no): ";
			cin >> strV;
			setVaccinated(strV);

			while (strV != "yes" && strV != "Yes" && strV != "no" && strV != "No") {
				cout << "Invalid input. Please enter either 'yes' or 'no': ";
				cin >> strV;
				setVaccinated(strV);
			}

			if (strV == "yes" || strV == "Yes") {
				do {
					cout << "Enter the number of doses you have received (1 or 2): ";
					cin >> strV;
					if (!Validation::numOfDoses_validation(strV)) {
						cout << "Invalid input. Please enter either 1 or 2.\n";
					}
				} while (!Validation::numOfDoses_validation(strV));
				setNumOfDoses(strV);
			}
			else if (strV == "no" || strV == "No") {
				setNumOfDoses("0");
			}

			flag = true;
			break;
		}
		case 6: {
			cout << "Enter updated number of doses: \n";
			cin >> strV;
			setNumOfDoses(strV);
			if(strV=="0")
			{
				Validation::numOfDoses_validation(strV);
				setVaccinated("No");
			}
			flag = true;
			break;
		}
		case 9: {
			system("cls");
			VaccineSystem::userMenu();
			break;
		}
		default:
			cout << "Invalid choice, choose from the menu..\n\n";
			Sleep(800);
			system("cls");
			update();
		}
		if (flag)
		{
			system("cls");

			cout << "Updated Record:\n";
		}
	} while (choice != 9);
}

