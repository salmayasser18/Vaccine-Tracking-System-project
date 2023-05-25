
#include "FileHandlerfinal.h"

using namespace std;

vector<string> FileHandlerfinal::split(string fulline)
{
	vector<string>info;
	stringstream line(fulline);
	string part;
	while (getline(line, part, ','))
	{
		info.push_back(part);
	}
	return info;
}
User FileHandlerfinal::parseToUser(string line)
{
	vector <string> userInfo = split(line);
	User u;
	u.setNationalID(userInfo[0]);
	u.setName(userInfo[1]);
	u.setPassword(userInfo[2]);
	u.setGender(userInfo[3].at(0));
	u.setAge(stoi(userInfo[4]));
	u.setGovernorate(userInfo[5]);
	u.setVaccinated(userInfo[6]);
	u.setNumOfDoses((userInfo[7])); 
	return u;
}
void FileHandlerfinal::readFromFile(string fileName)
{
	fstream file;
	file.open(fileName, ios::in);  
	string line;
	while (getline(file, line))
	{
		User u = FileHandlerfinal::parseToUser(line);
		allUsers[u.getNationalID()] = u;
	}
	file.close();
}
void FileHandlerfinal::saveToFile(string fileName)
{
	fstream file;
	file.open(fileName, ios::out);
	for (auto i = allUsers.begin(); i != allUsers.end(); i++)
	{
		if (i->second.getNationalID() != "0")
			file << i->second.getNationalID() << "," << i->second.getName() << "," << i->second.getPassword() << "," << i->second.getGender() << "," << i->second.getAge() << "," << i->second.getGovernorate() << "," << i->second.isVaccinated() << "," << i->second.hasNumOfDoses() << endl;
	}
	file.close();
}
void FileHandlerfinal::removeAllUsers(string fileName)
{
	fstream file;
	file.open(fileName, ios::out);
	file.close();
}
