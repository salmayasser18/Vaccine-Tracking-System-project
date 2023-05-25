
#include "Validation.h"
#include <algorithm>


using namespace std;

bool Validation::name_validation(string name)
{
	for (int i = 0; i < name.size(); i++)
	{
		if (!isalpha(name[i]))
		{
			return false;
		}
	}
	if (name.size() < 3)
	{
		return false;
	}
	return true;
}

bool Validation::password_validation(string password) {
	if (password.size() < 8)
	{
		return false;
	}
	else if (password.size() > 20)
	{
		return false;

	}
	return true;
}

bool Validation::nationalID_validation(string nationalID)
{
	if (nationalID.length() != 13) {
		return false;
	}
	if (allUsers.find(nationalID) != allUsers.end()) { // check if the national ID exists in the map
		return false;
	}
	return true;
}

bool Validation::age_validation(int age)
{
	if (age >= 100 || age < 16)
	{
		return false;

	}
	return true;
}

bool Validation::governorate_validation(string governorate)
{
	transform(governorate.begin(), governorate.end(), governorate.begin(), ::tolower);

	string arr[] = { "alexandria", "aswan", "assiut","beheira", "beni suef", "cairo", "dakahlia", "damietta", "fayoum", "gharbia", "giza", "ismailia", "marsa matrouh", "minya", "menofia", "new valley", "north sinai", "port said", "qualyubia", "qena", "red-sea", "sohag", "south sinai", "suez","luxor" };
	for (int i = 0; i < 27; i++) 
	{
		if (governorate == arr[i])
			return true;
	}
	return false;

}

bool Validation::numOfDoses_validation(string doses) {
	if (doses < "0" || doses > "2")
		return false;
	return true;
}

bool Validation::vaccinated_validation(string vaccine)
{
	if (vaccine != "Yes" && vaccine != "yes" && vaccine != "No" && vaccine != "no")
		return false;
	return true;
}

User Validation::logInVal(string natID, string password)
{
	try  //  currentuser = null
	{
		
		User currentUser = allUsers.at(natID);
		if (currentUser.getPassword() == password)
			return currentUser;
		return *(new User());
	}
	catch( exception ex)  
	{
		return *(new User());
	}
}
