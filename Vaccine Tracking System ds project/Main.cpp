#include "VaccineSystem.h"

using namespace std;


int main()
{
    
    cout << "Start------\n\n";
        
   FileHandlerfinal::readFromFile("Users.txt");

   //just to refer for nationalid and password
   for (auto i : allUsers) {
       cout << i.second.getNationalID() << "\t" << i.second.getName() << "\t" << i.second.getPassword() << "\t" << i.second.getGender() << "\t" << i.second.getAge() << "\t" << i.second.getGovernorate() << "\t" << i.second.isVaccinated() << "\t" << i.second.hasNumOfDoses() << endl;
   }

   cout << "Map size: " << allUsers.size() << endl;
   VaccineSystem::login();
   FileHandlerfinal::saveToFile("Users.txt");

   cout << "End\n\n";
  
    return 0;
}