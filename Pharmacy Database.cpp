//Database for a pharmacy
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//Structure for the medicine
struct Medicine
{
	int ID;
	string name;
	string manufacturer;
	string expiry_date;
};
//Global arrat for medicine type
Medicine medicines[3];
//Function to input medicine array
void Input_MedicineArray()
{
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter medicine information "<< i + 1 << ":" << endl;
		cout << "ID: ";
		cin >> medicines[i].ID;
		cout << "Name: ";
		cin >> medicines[i].name;
		cout << "Manufacture: ";
		cin >> medicines[i].manufacturer;
		cout << "Expiry Date: ";
		cin >> medicines[i].expiry_date;
	}
}
//Function to write medice array to a file
void Write_MedicineArray_To_File()
{
	ofstream outFile("pharmacy_database.txt");
	if (outFile.is_open())
	{
		for (int i = 0; i < 3; i++)
		{
			outFile << "Medicine: " << i + 1 << " Information: " << endl;
			outFile << "ID: " << medicines[i].ID << endl;
			outFile << "Name: " << medicines[i].name << endl;
			outFile << "Manufacturer: " << medicines[i].manufacturer << endl;
			outFile << "Expiry Date: " << medicines[i].expiry_date << endl;
			outFile << endl;
		}
		outFile.close();
		cout << "Data has been successfully written" << endl;
	}
	else 
	{
		cout << "Unable to open the file." << endl;
	}
}
int main()
{
	Input_MedicineArray();  //Call the function to input medicine array
	Write_MedicineArray_To_File(); // Call the function to write medicine array to file
	return 0;
}