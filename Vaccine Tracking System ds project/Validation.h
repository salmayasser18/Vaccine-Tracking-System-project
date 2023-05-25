#pragma once
#include "Admin.h"

using namespace std;

static class Validation
{
public:
	static bool name_validation(string name);
	static bool password_validation(string password);
	static bool nationalID_validation(string nationalID);  
	static bool age_validation(int age);
	static bool governorate_validation(string governorate);
	static bool numOfDoses_validation(string doses);
	static bool vaccinated_validation(string vaccine);
	static User logInVal(string natID, string password);
	
};