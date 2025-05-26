#include "Patient.h"
#include <sstream>
#include <iostream>
using namespace std;

Patient::Patient(const string& id, const string& name)
    : id(id), name(name), age(0), contactInfo("") {
}

Patient::Patient(const string& id, const string& name, int age, const string& contactInfo)
    : id(id), name(name), age(age), contactInfo(contactInfo) {
}

void Patient::setName(const string& patientName) {
    name = patientName;
}

void Patient::setAge(int patientAge) {
    age = patientAge;
}

void Patient::setContactInfo(const string& contact) {
    contactInfo = contact;
}

void Patient::updateInfo(const string& newContactInfo) {
    contactInfo = newContactInfo;
}

void Patient::setSpecialistRequest(const string& request) {
    specialistRequest = request;
}

void Patient::setTimeRequest(const string& request) {
    timeRequest = request;
}

void Patient::addMedicalRecord(const string& record) {
    medicalHistory.push_back(record);
}

void Patient::bookAppointment(const string& appointment) {
    appointments.push_back(appointment);
}

string Patient::getPatientInfo() const {
    stringstream ss;
     ss  << "ID: " << id << "\n"
        << "Name: " << name << "\n"
        << "Age: " << age << "\n"
        << "Contact: " << contactInfo;
    return ss.str();
}

string Patient::getMedicalHistory() const {
    stringstream ss;
    ss << "Medical History for " << name << ":\n";
    for (const auto& record : medicalHistory) {
        ss << record << "\n";
    }
    return ss.str();
} 