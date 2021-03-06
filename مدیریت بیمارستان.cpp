// مدیریت بیمارستان.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<conio.h>
#include<fstream>
#include<map>
using namespace std;
multimap <int, string> savedsicks;
class Person {
protected:
	string name, family, address, phone;
	int age;

public:

	Person() {}
	Person(string name, string family,int age,string phone, string address) {

		this->name = name;
		this->family = family;
		this->address = address;
		this->phone = phone;
		this->age = age;
	
	}
	void setName(string name) {
		this->name = name;
	}
	void setFamily(string family) {
		this->family = family;
	}
	void setAge(int age) {
		this->age = age;
	}
	void setPhone(string phone) {
		this->phone = phone;
	}
	void setAddress(string address) {
		this->address = address;
	}
	
	string getName() const {
		return name;
	}
	string getFamily()const {
		return family;
	}
	int getAge()const {
		return age;
	}
	string getPhone()const {
		return phone;
	}
	string getAddress()const {
		return address;
	}
	void report() const {

		cout << name << setw(6)  << family <<setw(4) << age << setw(10) << phone << setw(4) << address <<  endl;

	}
};
class Sick : public Person {
private:	
	string name_D,family_D,disease;
	int cod_D ;
public:
	Sick() {}
	Sick(string name, string family, int age,string phone,string address,int cod_D, string  name_D,string family_D,string disease) :Person(name, family,age ,phone,address) {
		this->cod_D = cod_D;
		this->name_D = name_D;
		this->family_D = family_D;
		this->disease = disease;	
	}
	void Doctor_sicks();
	void setcod_D(int cod_D) {
		this->cod_D;
	}
	void setname_D(int name_D) {

		this->name_D = name_D;

	}
	void setfamily_D(int family_D) {

		this->family_D = family_D;

	}
	void setdisease(string disease) {

		this->disease = disease;

	}

	string getname_D()const {

		return name_D; 
	}
	string setfamily_D()const {

		return  family_D;

	}
    string getdisease()const {

		return disease;

	}
	int getcod_D()const {
		return cod_D;
	}
	void report()const {

		cout << name << setw(6) << " " << family << setw(4) << age<<setw(5)<<  phone<< setw(4) <<address <<setw(10) << cod_D << setw(4) << name_D << setw(4) <<family_D<<setw(5)<< disease << endl;

	}


};
int countsick = 0;
class Doctor :public Person {

private:
	string expertise;
	int code;
	
public:
	Doctor() {}
	Doctor(string name, string family,int age,string phone,string address, string expertise,int code) :Person(name, family,age,phone,address) {

		this->expertise = expertise;
		this->code = code;
		
	}
	
	void setExpertise(int expertise) {

		this->expertise = expertise;
	}
	void setCode(int code) {
		this->code = code;
	}
	string getExpertise()const {

		return expertise;
	}
	int getCode()const {
		return code;
	}
	void report()const  {
		
		cout << name << setw(16) << family <<setw(11) << age <<  setw(4)<<phone << setw(18) << 
			address << setw(16) << expertise<<setw(11)<<code << endl;
	}
};
int countdoctor = 0;

//########### SICK  ###########

vector <Sick> sick, sick2;
fstream outputfile;
void Entersick() {

	string name, family, address, phone,name_D, family_D,disease;
	int age, cod_D;

	cout << "\n Enter the name of sick: ";
	cin >> name;
	cout << "\n Enter the family of sick: ";
	cin >> family;
	cout << "\n Enter the age of sick: ";
	cin >> age;
	cout << "\n Enter the phone of sick: ";
	cin >> phone;
	cout << "\n Enter the address of sick: ";
	cin >> address;
	cout << "\n Enter the cod of doctor's sick: ";
	cin >> cod_D;
	cout << "\n Enter the name doctor's sick: ";
	cin >> name_D;
	cout << "\n Enter the family doctor's sick: ";
	cin >> family_D;
	cout << "\n Enter the disease sick: ";
	cin >> disease;
	
	
	sick.push_back(Sick(name, family,  age, phone, address,cod_D, name_D, family_D,disease));

	outputfile.open("student.csv", ios::app);
	outputfile << name + "," + family + "," + to_string(age) +"," + phone  +","+ address + "," + to_string(cod_D) + ","
		+ name_D + "," + family_D +","+ disease << endl;
	countsick++;
}
void DisplayAllsicks() {
	system("cls");
	cout << "\n\n\t\t\t\t((INFORMATION SICK))  \n\n";
	cout << "Name     Family     age     Phone    Address    Cod      NameDoctor     Disease" << endl;
	cout << "=======================================================================================\n";
	for (int i = 0; i < sick.size(); i++)
	{

		sick[i].report();
	}
	cout << "\n Number of Sick is:" << countsick << "\n";
}
void DisplayOnesick(int cod) {

	system("cls");
	cout << "\n\n\t\t\t\t((INFORMATION SICK))  \n\n";
	cout << "Name     Family     age     Phone    Address    Cod      NameDoctor     Disease" << endl;
	cout << "=======================================================================================\n";

	for (int i = 0; i < sick.size(); i++)
	{
		if (sick[i].getcod_D() == cod) {
			sick[i].report();
		}
		else
			cout << "cod of doctor's sick is false";
	}

}
void Editsick(int cods) {
	string name, family, address, phone, name_D, disease;
	int age, cod_D;
	int a;
	for (int i = 0; i < sick.size(); i++)
	{
		if (sick[i].getcod_D() == cods) {
			cout << "\n\n\n\tSELECT MENU";
			cout << "\n\n\n\t1.NAME";
			cout << "\n\n\t2.FAMILY";
            cout << "\n\n\t3.AGE";
            cout << "\n\n\t4.PHONE";
            cout << "\n\n\t5.ADDRESS";
			cout << "\n\n\t6.COD_Doctor";
			cout << "\n\n\t7.NAME DOCTOR";
			cout << "\n\n\t8.DISEASE";
			cout << "\n\n\n\tEnter Choice (1/2/3)? ";
			cin >> a;
			switch (a)
			{
			case 1: cout << "Enter a name" << endl; cin >> name; sick[i].setName(name); break;
			case 2: cout << "Enter a family" << endl; cin >> family; sick[i].setFamily(family); break;
            case 3: cout << "Enter a age" << endl; cin >> age; sick[i].setAge(age); break;
	        case 4: cout << "Enter a phone" << endl; cin >> phone; sick[i].setPhone(phone); break;
            case 5: cout << "Enter a address" << endl; cin >> address; sick[i].setFamily(address); break;
			case 6: cout << "Enter a cod_doctor" << endl; cin >> cod_D; sick[i].setcod_D(cod_D); break;
			case 7: cout << "Enter a name_doctor" << endl; cin >> name_D; sick[i].setName(name_D); break;
			case 8: cout << "Enter a disease" << endl; cin >> disease; sick[i].setFamily(disease); break;
			


			}

		}
	}

}
void deleteAllsick() {

	sick.clear();
	countsick = 0;
}
void deleteOnesick(int cods) {


	for (int i = 0; i < sick.size(); i++) {

		if (sick[i].getcod_D() != cods) {

			sick2.push_back(sick[i]);
		}
		
	}
countsick--;
	sick = sick2;
	vector<Sick>().swap(sick2);


}
vector<Sick> datasick() {
	return sick;	
}
multimap <int, string> savedSicks() {
	return savedsicks;
}
void create_list_of_Sick(int idnumber) {

	for (int i = 0; i < sick.size(); i++) {

		if (sick[i].getcod_D() == idnumber) {

			sick[i].Doctor_sicks();
		}
		cout << "Creat list Doctor's Sicks";
	}
}
void Sick::Doctor_sicks() {		

		cout << "Enter the code of doctor for Creat list Doctor's Sicksr" << endl;
	
		vector<Sick> listcourse = datasick();
		for (int i = 0; i < listcourse.size(); i++) {

			savedsicks.insert(pair<int, string>(cod_D, name + "    " + family +"    "+ disease));
			}

}

//##########  DOCTOR  ##########

vector <Doctor> doctor, doctor2;
fstream outputfileD;
void Enterdoctor() {

	string name, family,phone, address,  expertise;
	int age,code;
	
	
	cout << "\n Enter the name of Doctor: ";
	cin >> name;
	cout << "\n Enter the family of Doctor: ";
	cin >> family;
	cout << "\n Enter the age of Doctor: ";
	cin >> age;
	cout << "\n Enter the phone of Doctor: ";
	cin >> phone;
	cout << "\n Enter the address of Doctor: ";
	cin >> address;
	cout << "\n Enter the expertise of Doctor: ";
	cin >> expertise;
	cout << "\n Enter the code of Doctor: ";
	cin >> code;

	doctor.push_back(Doctor( name, family, age, phone,  address,  expertise,code));
	outputfileD.open("DOCTOR.csv", ios::app);
	outputfile << name + "," + family + "," + to_string(age) + "," + phone + "," +address +","+ expertise + "," + to_string(code) << endl;
	
	countdoctor++;
}
void DisplayAlldoctor() {

	system("cls");
	cout << "\n\n\t\t\t\t  ((INFORMATION DOCTORS))  \n\n";
	cout << "Name       Family     age       Phone     Address     expertise   code" << endl;
	cout << "===============================================================================\n";
	for (int i = 0; i < doctor.size(); i++)
	{

		doctor[i].report();
	}
	cout << "\n Number of Doctor is" << countdoctor << "\n";
}
void DisplayOnedoctor(int codd) {

	system("cls");
	cout << "\n\n\t\t\t\t  ((INFORMATION DOCTORS))  \n\n";
	cout << "Name       Family     age       Phone     Address     expertise   code" << endl;
	cout << "===============================================================================\n";

	for (int i = 0; i < doctor.size(); i++)
	{
		if (doctor[i].getCode() == codd) {
			doctor[i].report();
		}
	}

}
void Editdoctor(int codd) {
	string name, family, phone,address;
	int age, code;
	int a;
	for (int i = 0; i < doctor.size(); i++)
	{
		if (doctor[i].getCode() == codd) {
			cout << "\n\n\n\tSELECT MENU";
			cout << "\n\n\n\t1. NAME";
			cout << "\n\n\t2. FAMILY";
			cout << "\n\n\t3.AGE";
			cout << "\n\n\t4. PHONE";
			cout << "\n\n\t5.ADDRESS";
			cout << "\n\n\t6.COD_DOCTOR";
			cout << "\n\n\n\tEnter Choice (1/2/3)? ";
			cin >> a;
			switch (a)
			{
			case 1: cout << "Enter a name" << endl; cin >> name; doctor[i].setName(name); break;
			case 2: cout << "Enter a family" << endl; cin >> family; doctor[i].setFamily(family); break;
			case 3: cout << "Enter a age" << endl; cin >> age; doctor[i].setAge(age); break;
			case 4: cout << "Enter a phone" << endl; cin >> phone; doctor[i].setPhone(phone); break;
			case 5: cout << "Enter a address" << endl; cin >> address; doctor[i].setAddress(address); break;
			}

		}
	}

}
void deleteAlldoctor() {

	doctor.clear();
	countdoctor = 0;
}
void deleteOnedoctor(int codd) {


	for (int i = 0; i < doctor.size(); i++) {

		if (doctor[i].getCode() != codd) {

			doctor2.push_back(doctor[i]);
		}
		countdoctor--;
	}

	doctor = doctor2;
	vector<Doctor>().swap(doctor2);


}
void Show_Doctor_sickS(int code_D) {

	multimap<int, string> list = savedSicks();
	for (multimap<int, string> ::iterator it = list.begin(); it != list.end(); it++) {

		if (code_D == it->first) {
			cout << it->second<<endl;
		}
	}

}


void Show_Informations() {

	int a, b, c, cod_D;
	char choice;
    system("cls");
	cout << "\n\n\n\tInformation";
	cout << "\n\n\t1. Information Sicks:" << endl;
	cout << "\n\t2. Information Doctors:" << endl;
	cout<< "\n\tPlease Enter 1_2:\n";
	cin >> b;
	switch (b)
	{
	case 1:
	{	system("cls");

	cout << "\n\n\t1. All Sicks Information";
	cout << "\n\n\t2. One Sick Information";
	cout << "\n\n\t3. Back to the Menu";
	cout << "\n\n\n\tPlease Enter 1_3:\n";
	cin >> c;
	switch (c)
	{
	case 1:  DisplayAllsicks();  _getch(); break;
	case 2: cout << "\n Enter the cod of doctor's sick: "; cin >> cod_D;
		DisplayOnesick(cod_D); _getch(); break;
	default:
		break;
	}

	break; }
	case 2:
	{	system("cls");
	cout << "\n\n\n\tSELECT";
	cout << "\n\n\t1. All Doctor Information";
	cout << "\n\n\t2. Doctor Information";
	cout << "\n\n\t3. Create_list_of_Sick";
	cout << "\n\n\t4. Show_list Doctor's Sick";
	cout << "\n\n\n\tEnter Choice (1/3)? ";
	cin >> c;
	switch (c)
	{
	case 1:  DisplayAlldoctor(); _getch(); break;
	case 2: cout << "\n Enter the code of Doctor: "; cin >> cod_D;
		DisplayOnedoctor(cod_D); _getch(); break;
	case 3:cout << "\n Enter the code of Doctor: "; cin >> cod_D;
		create_list_of_Sick(cod_D); _getch(); break;
	case 4:
		cout << "\n Enter the code of Doctor: "; cin >> cod_D;
		Show_Doctor_sickS(cod_D); _getch(); break;
	default:
		break;
	}
	break; }
	case 3:break;
	}
}
void Entry_Informations(){
	int a, num;
	char choice;
	system("cls");
	cout << "\n\n\n\t MENU";
	cout << "\n\n\t1.MENU SICK";
	cout << "\n\n\t2.MENU DOCTOR";
	cout << "\n\n\t3.BACK TO MAIN MENU";
	cout << "\n\n\tPlease Enter Your Choice (1-4) ";

	cin >> a;
	switch (a)
	{
	case 1:
	{    system("cls");
	cout << "\n\n\n\tMENU STUDENT";
	cout << "\n\n\t1.create sick";
	cout << "\n\n\t2.edit sick";
	cout << "\n\n\t3.delete  one sick";
	cout << "\n\n\t4.delete  all sicks";
	cout << "\n\n\t5.BACK TO MAIN MENU";
	cout << "\n\n\tPlease Enter Your Choice (1-5) ";
	cin >> a;
	switch (a) {
	case 1:
		do {
			Entersick();
			system("cls");
			cout << "Do you want to insert new information  sick? Y|N";
			cin >> choice;
			system("cls");
		} while (choice == 'Y' || choice == 'y');
		break;
	case 2: cout << "\n Enter the cod of doctor's sick: " << endl;
		cin >> num; Editsick(num); break;
		break;
	case 3:cout << "\n Enter the cod of doctor's sick: " << endl;
		cin >> num; deleteOnesick(num); break;
		break;
	case 4:  deleteAllsick(); break;
	case 5: break;
	}
	break;
	}
	case 2:
	{   system("cls");
	cout << "\n\n\n\tMENU DOCTOR";
	cout << "\n\n\t1.create doctor";
	cout << "\n\n\t2.edit doctor";
	cout << "\n\n\t3.delet  one doctor";
	cout << "\n\n\t4.delet  all doctors";
	cout << "\n\n\t5.BACK TO MAIN MENU";
	cout << "\n\n\tPlease Enter 1_5:\n";
	cin >> a;
	switch (a) {
	case 1:
		do {
			Enterdoctor();
			system("cls");
			cout << "Do you want to insert new information Doctor? Y|N";
			cin >> choice;
			system("cls");
		} while (choice == 'Y' || choice == 'y');
		break;
	case 2: cout << "\nEnter the code of Doctor " << endl;
		cin >> num; Editdoctor(num); break;
		break;
	case 3: cout << "\nEnter the code of Doctor " << endl;
		cin >> num; deleteOnedoctor(num); break;
		break;
	case 4:  deleteAlldoctor(); break;
	case 5: break;
	}
	break;
	}
	case 3:break;

	}

}
int main()
{
	int a;
	do {
		system("cls");
		cout << "\n\n\n\tMAIN MENU";
	    cout << "\n\n\t01. ENTR OR EDIT";
	    cout << "\n\n\t02. Show Informations";
		cout << "\n\n\t03. EXIT";
		cout << "\n\n\tPlease Enter 1_3:\n";

		cin >> a;
		system("cls");
		switch (a)
		{
		case 1:Entry_Informations();break;
		case 2:Show_Informations();
		case 3:break;
		}
	} while (a != 3);
	return 0;
}




