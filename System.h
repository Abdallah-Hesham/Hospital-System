#pragma once
#include <vector>
#include <string>
#include "Doctor.h"
#include "Patient.h"
#include "FileManager.h"
using namespace std;

class Admin;

class System {
private:
	vector <Doctor> doctors;
	vector <Patient> patients;
	Admin* admin;
	FileManager fileManager;
	bool isInitialized;
	string systemName;

public:
	System();
	System(const string& name);
	~System();

	void initialize();
	void saveAllData();

	void addDoctor(const Doctor& doctor);
	void removeDoctor(const string& id);
	int getDoctorCount() const;
	Doctor& getDoctor(int index);
	const Doctor& getDoctor(int index) const;
	const vector<Doctor>& getAllDoctors() const { return doctors; }

	void addPatient(const Patient& patient);
	void removePatient(const string& id);
	void removePatient(int index);
	int getPatientCount() const;
	Patient& getPatient(int index);
	const Patient& getPatient(int index) const;
	const vector<Patient>& getAllPatients() const { return patients; }

	bool validateUser(const string& username, const string& password, const string& role);
	void addUser(const string& username, const string& password, const string& role);
	bool userExists(const string& username);

	string getSystemName() const { return systemName; }
};