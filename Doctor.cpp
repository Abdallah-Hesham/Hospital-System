#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Doctor.h"
#include <vector>

using namespace std;

void Doctor::saveToFile() {}

Doctor::Doctor() {
    id = "";
    name = "";
    specialty = "";
    minAvailableTime = "";
    maxAvailableTime = "";
}

Doctor::Doctor(string id, string name) {
    this->id = id;
    this->name = name;
    specialty = "";
    minAvailableTime = "";
    maxAvailableTime = "";
}

void Doctor::removePatient(string patientID) {
    for (int i = 0; i < schedule.size(); ) {
        if (schedule[i].patientID == patientID) {
            schedule.erase(schedule.begin() + i);
        } else {
            i++;
        }
    }
}

string Doctor::getScheduleInfo() const {
    stringstream ss;
    ss << "Schedule for Dr. " << name << ":\n";
    for (int i = 0; i < schedule.size(); i++) {
        ss << "Patient: " << schedule[i].patientID << ", Time: " << schedule[i].time << "\n";
    }
    return ss.str();
}

void Doctor::addPrescription(string patientID, string prescription) {
    Prescription p;
    p.patientID = patientID;
    p.prescription = prescription;
    prescriptions.push_back(p);
}

void Doctor::setTimes(vector<string> times) {
    availableTimes = times;
}

void Doctor::setSpecialty(string specialty) {
    this->specialty = specialty;
}

string Doctor::getID() const { return id; }
string Doctor::getName() const { return name; }
string Doctor::getSpecialty() const { return specialty; }
int Doctor::getScheduleCount() const { return schedule.size(); }
Appointment Doctor::getSchedule(int index) const { return schedule[index]; }
int Doctor::getAvailableTimesCount() const { return availableTimes.size(); }
string Doctor::getAvailableTime(int index) const { return availableTimes[index]; }
void Doctor::addAppointment(string patientID, string time) {
    Appointment a;
    a.patientID = patientID;
    a.time = time;
    schedule.push_back(a);
}
void Doctor::resetSchedule() { schedule.clear(); }
void Doctor::setMinAvailableTime(string time) { minAvailableTime = time; }
void Doctor::setMaxAvailableTime(string time) { maxAvailableTime = time; }
string Doctor::getMinAvailableTime() const { return minAvailableTime; }
string Doctor::getMaxAvailableTime() const { return maxAvailableTime; }
bool Doctor::checkSpecialty(string requestedSpecialty) const { return specialty == requestedSpecialty; }
string Doctor::getSchedule() const { return getScheduleInfo(); }
int Doctor::getPrescriptionCount() const {
    return prescriptions.size();
}

Prescription Doctor::getPrescription(int index) const {
    return prescriptions[index];
}
