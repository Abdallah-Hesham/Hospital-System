#include "System.h"
#include "Admin.h"
using namespace std;

System::System() : isInitialized(false), systemName("Hospital Management System") {
    admin = new Admin();
}

System::System(const string& name) : isInitialized(false), systemName(name) {
    admin = new Admin();
}

System::~System() {
    if (isInitialized) {
        saveAllData();
    }
    delete admin;
}

void System::initialize() {
    if (!isInitialized) {
        fileManager.loadDoctors(doctors);
        fileManager.loadPatients(patients);
        fileManager.loadAppointments(doctors, patients);
        fileManager.loadMedicalRecords(patients);
        fileManager.loadPrescriptions(doctors, patients);
        isInitialized = true;
    }
}

void System::saveAllData() {
    if (isInitialized) {
        fileManager.saveDoctors(doctors);
        fileManager.savePatients(patients);
        fileManager.saveAppointments(doctors);
        fileManager.saveMedicalRecords(patients);
        fileManager.savePrescriptions(doctors);
    }
}

void System::addDoctor(const Doctor& doctor) {
    doctors.push_back(doctor);
    saveAllData();
}

void System::removeDoctor(const string& id) {
    for (auto it = doctors.begin(); it != doctors.end(); ++it) {
        if (it->getID() == id) {
            doctors.erase(it);
            saveAllData();
            break;
        }
    }
}

int System::getDoctorCount() const {
    return static_cast<int>(doctors.size());
}

Doctor& System::getDoctor(int index) {
    return doctors.at(index);
}

const Doctor& System::getDoctor(int index) const {
    return doctors.at(index);
}

void System::addPatient(const Patient& patient) {
    patients.push_back(patient);
    saveAllData();
}

void System::removePatient(const string& id) {
    for (auto it = patients.begin(); it != patients.end(); ++it) {
        if (it->getID() == id) {
            patients.erase(it);
            saveAllData();
            break;
        }
    }
}

void System::removePatient(int index) {
    if (index >= 0 && index < static_cast<int>(patients.size())) {
        patients.erase(patients.begin() + index);
        saveAllData();
    }
}

int System::getPatientCount() const {
    return static_cast<int>(patients.size());
}

Patient& System::getPatient(int index) {
    return patients.at(index);
}

const Patient& System::getPatient(int index) const {
    return patients.at(index);
}

bool System::validateUser(const string& username, const string& password, const string& role) {
    return fileManager.validateUser(username, password, role);
}

void System::addUser(const string& username, const string& password, const string& role) {
    fileManager.addUser(username, password, role);
}

bool System::userExists(const string& username) {
    return fileManager.userExists(username);
}
