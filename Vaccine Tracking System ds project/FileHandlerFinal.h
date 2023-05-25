#pragma once
#include "Validation.h"
#include <fstream>
#include <sstream>

class FileHandlerfinal
{
public:
	static vector<string> split(string fulline);
	static User parseToUser(string line);
	static void readFromFile(string fileName);
	static void saveToFile(string fileName);
	static void removeAllUsers(string fileName);
};

