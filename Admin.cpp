#include <iostream>
#include "Doctor.h"
#include "Patient.h"
#include "System.h"
#include "Admin.h"

using namespace std;

Admin::Admin() : username("admin"), password("admin123") {}

	Admin::Admin(const string& username, const string& password)
    : username(username), password(password) {}

void Admin::addDoctor(System& system, const Doctor& doctor) {
	system.addDoctor(doctor);
}

void Admin::removeDoctor(System& system, const string& id) {
	system.removeDoctor(id);
}

void Admin::addPatient(System& system, const Patient& patient) {
	system.addPatient(patient);
}

void Admin::removePatient(System& system, const string& id) {
	system.removePatient(id);
}

void Admin::removePatient(System& system, int index) {
	system.removePatient(index);
}

void Admin::checkForRequests(System& system) {
	cout << "Checking for pending requests..." << endl;
}

void Admin::viewAllDoctors(const System& system) {
	const auto& doctors = system.getAllDoctors();
	cout << "\n=== All Doctors ===" << endl;
	for (const auto& doctor : doctors) {
		cout << "ID: " << doctor.getID() << ", Name: " << doctor.getName() 
				  << ", Specialty: " << doctor.getSpecialty() << endl;
	}
}

void Admin::viewAllPatients(const System& system) {
	const auto& patients = system.getAllPatients();
	cout << "\n=== All Patients ===" << endl;
	for (const auto& patient : patients) {
		cout << "ID: " << patient.getID() << ", Name: " << patient.getName() 
				  << ", Age: " << patient.getAge() << endl;
	}
}

