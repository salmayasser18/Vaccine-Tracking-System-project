#pragma once
#include "User.h"
using namespace std;
class Admin
{
public:
	Admin();

	static void  A_ViewRecords();
	static void  A_DeleteRecords();
	static void  A_ViewByNumOfDoses();
	static bool  A_CompareByAge(User& value1, User& value2);
	static void  A_ViewByAge();
	static void  A_ViewStat();
	static void AdminMenu();
	static void back_to_menu();
	static void A_ViewFromWaitingList();
	static void  A_compute_dosage_percentage(float&, float&, float&, vector<string>, int, float&);
	static void governorate_vaccinedose();
	static void gender_avaccinedose();
	static void age_vaccinedose();


};