#include "FileManager.h"
#include <iostream>
#include <sstream>
using namespace std;

FileManager::FileManager() {
    createFileIfNotExists(DOCTORS_FILE);
    createFileIfNotExists(PATIENTS_FILE);
    createFileIfNotExists(APPOINTMENTS_FILE);
    createFileIfNotExists(USERS_FILE);
    createFileIfNotExists(MEDICAL_RECORDS_FILE);
    createFileIfNotExists(PRESCRIPTIONS_FILE);
}

FileManager::~FileManager() {}

bool FileManager::fileExists(const string& filename) {
    ifstream file(filename);
    return file.good();
}

void FileManager::createFileIfNotExists(const string& filename) {
    if (!fileExists(filename)) {
        ofstream file(filename);
        file.close();
    }
}

string FileManager::serializeDoctor(const Doctor& doctor) {
    stringstream ss;
    ss << doctor.getID() << "|" << doctor.getName() << "|" << doctor.getSpecialty();
    return ss.str();
}

string FileManager::serializePatient(const Patient& patient) {
    stringstream ss;
    ss << patient.getID() << "|" << patient.getName() << "|" << patient.getAge() << "|" << patient.getContactInfo();
    return ss.str();
}

Doctor FileManager::deserializeDoctor(const string& line) {
    stringstream ss(line);
    string id, name, specialty;
    getline(ss, id, '|');
    getline(ss, name, '|');
    getline(ss, specialty, '|');
    
    Doctor doctor(id, name);
    doctor.setSpecialty(specialty);
    return doctor;
}

Patient FileManager::deserializePatient(const string& line) {
    stringstream ss(line);
    string id, name, ageStr, contact;
    getline(ss, id, '|');
    getline(ss, name, '|');
    getline(ss, ageStr, '|');
    getline(ss, contact, '|');
    
    Patient patient(id, name);
    patient.setAge(stoi(ageStr));
    patient.updateInfo(contact);
    return patient;
}

void FileManager::loadDoctors(vector<Doctor>& doctors) {
    ifstream file(DOCTORS_FILE);
    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            doctors.push_back(deserializeDoctor(line));
        }
    }
}

void FileManager::loadPatients(vector<Patient>& patients) {
    ifstream file(PATIENTS_FILE);
    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            patients.push_back(deserializePatient(line));
        }
    }
}

void FileManager::loadAppointments(vector<Doctor>& doctors, vector<Patient>& patients) {
    ifstream file(APPOINTMENTS_FILE);
    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            stringstream ss(line);
            string doctorId, patientId, time;
            getline(ss, doctorId, '|');
            getline(ss, patientId, '|');
            getline(ss, time, '|');
            
            // Find doctor and patient
            for (auto& doctor : doctors) {
                if (doctor.getID() == doctorId) {
                    doctor.addAppointment(patientId, time);
                    break;
                }
            }
        }
    }
}

void FileManager::loadMedicalRecords(vector<Patient>& patients) {
    ifstream file(MEDICAL_RECORDS_FILE);
    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            stringstream ss(line);
            string patientId, record;
            getline(ss, patientId, '|');
            getline(ss, record, '|');
            
            for (auto& patient : patients) {
                if (patient.getID() == patientId) {
                    patient.addMedicalRecord(record);
                    break;
                }
            }
        }
    }
}

void FileManager::loadPrescriptions(vector<Doctor>& doctors, vector<Patient>& patients) {
    ifstream file(PRESCRIPTIONS_FILE);
    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            stringstream ss(line);
            string doctorId, patientId, prescription;
            getline(ss, doctorId, '|');
            getline(ss, patientId, '|');
            getline(ss, prescription, '|');
            
            for (auto& doctor : doctors) {
                if (doctor.getID() == doctorId) {
                    doctor.addPrescription(patientId, prescription);
                    break;
                }
            }
        }
    }
}

void FileManager::saveDoctors(const vector<Doctor>& doctors) {
    ofstream file(DOCTORS_FILE);
    for (const auto& doctor : doctors) {
        file << serializeDoctor(doctor) << endl;
    }
}

void FileManager::savePatients(const vector<Patient>& patients) {
    ofstream file(PATIENTS_FILE);
    for (const auto& patient : patients) {
        file << serializePatient(patient) << endl;
    }
}

void FileManager::saveAppointments(const vector<Doctor>& doctors) {
    ofstream file(APPOINTMENTS_FILE);
    for (const auto& doctor : doctors) {
        for (int i = 0; i < doctor.getScheduleCount(); i++) {
            auto appointment = doctor.getSchedule(i);
            file << doctor.getID() << "|" << appointment.patientID << "|" << appointment.time << endl;
        }
    }
}

void FileManager::saveMedicalRecords(const vector<Patient>& patients) {
    ofstream file(MEDICAL_RECORDS_FILE);
    for (const auto& patient : patients) {
        for (int i = 0; i < patient.getMedicalHistoryCount(); i++) {
            file << patient.getID() << "|" << patient.getMedicalHistory(i) << endl;
        }
    }
}

void FileManager::savePrescriptions(const vector<Doctor>& doctors) {
    ofstream file(PRESCRIPTIONS_FILE);
    for (const auto& doctor : doctors) {
        for (int i = 0; i < doctor.getPrescriptionCount(); i++) {
            auto prescription = doctor.getPrescription(i);
            file << doctor.getID() << "|" << prescription.patientID << "|" << prescription.prescription << endl;
        }
    }
}

bool FileManager::validateUser(const string& username, const string& password, const string& role) {
    ifstream file(USERS_FILE);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string storedUsername, storedPassword, storedRole;
        getline(ss, storedUsername, '|');
        getline(ss, storedPassword, '|');
        getline(ss, storedRole, '|');
        
        if (storedUsername == username && storedPassword == password && storedRole == role) {
            return true;
        }
    }
    return false;
}

void FileManager::addUser(const string& username, const string& password, const string& role) {
    ofstream file(USERS_FILE, ios::app);
    file << username << "|" << password << "|" << role << endl;
}

bool FileManager::userExists(const string& username) {
    ifstream file(USERS_FILE);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string storedUsername;
        getline(ss, storedUsername, '|');
        if (storedUsername == username) {
            return true;
        }
    }
    return false;
} 