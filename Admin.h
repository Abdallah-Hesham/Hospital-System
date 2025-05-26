#pragma once
#include <string>
using namespace std;

class System;
class Doctor;
class Patient;

class Admin {
private:
	string username;
	string password;

public:
	Admin();
	Admin(const string& username, const string& password);
	
	void addDoctor(System& system, const Doctor& doctor);
	void removeDoctor(System& system, const string& id);
	
	void addPatient(System& system, const Patient& patient);
	void removePatient(System& system, const string& id);
	void removePatient(System& system, int index);
	
	void checkForRequests(System& system);
	void viewAllDoctors(const System& system);
	void viewAllPatients(const System& system);
	
	string getUsername() const { return username; }
	string getPassword() const { return password; }
};