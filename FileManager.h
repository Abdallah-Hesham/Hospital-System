#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "Doctor.h"
#include "Patient.h"
#include "Admin.h"
using namespace std;
class FileManager {
private:
    const string DOCTORS_FILE = "doctors.txt";
    const string PATIENTS_FILE = "patients.txt";
    const string APPOINTMENTS_FILE = "appointments.txt";
    const string USERS_FILE = "users.txt";
    const string MEDICAL_RECORDS_FILE = "medical_records.txt";
    const string PRESCRIPTIONS_FILE = "prescriptions.txt";

    bool fileExists(const string& filename);
    void createFileIfNotExists(const string& filename);
    string serializeDoctor(const Doctor& doctor);
    string serializePatient(const Patient& patient);
    Doctor deserializeDoctor(const string& line);
    Patient deserializePatient(const string& line);

public:
    FileManager();
    ~FileManager();

    void loadDoctors(vector<Doctor>& doctors);
    void loadPatients(vector<Patient>& patients);
    void loadAppointments(vector<Doctor>& doctors, vector<Patient>& patients);
    void loadMedicalRecords(vector<Patient>& patients);
    void loadPrescriptions(vector<Doctor>& doctors, vector<Patient>& patients);
    bool validateUser(const string& username, const string& password, const string& role);

    void saveDoctors(const vector<Doctor>& doctors);
    void savePatients(const vector<Patient>& patients);
    void saveAppointments(const vector<Doctor>& doctors);
    void saveMedicalRecords(const vector<Patient>& patients);
    void savePrescriptions(const vector<Doctor>& doctors);

    void addUser(const string& username, const string& password, const string& role);
    bool userExists(const string& username);
}; 