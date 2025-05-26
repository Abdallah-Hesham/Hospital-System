#pragma once
#include <string>
#include <vector>
using namespace std;

struct Appointment {
    string patientID;
    string time;
};

struct Prescription {
    string patientID;
    string prescription;
};

class Doctor {
private:
    string id;
    string name;
    string specialty;
    vector<string> availableTimes;
    vector<Appointment> schedule;
    vector<Prescription> prescriptions;
    string minAvailableTime;
    string maxAvailableTime;

    void saveToFile();
public:
    Doctor();
    Doctor(string id, string name);
    void removePatient(string patientID);
    string getScheduleInfo() const;
    void addPrescription(string patientID, string prescription);
    void setTimes(vector<string> times);
    void setSpecialty(string specialty);
    string getID() const;
    string getName() const;
    string getSpecialty() const;
    int getScheduleCount() const;
    Appointment getSchedule(int index) const;
    int getAvailableTimesCount() const;
    string getAvailableTime(int index) const;
    void addAppointment(string patientID, string time);
    void resetSchedule();
    void setMinAvailableTime(string time);
    void setMaxAvailableTime(string time);
    string getMinAvailableTime() const;
    string getMaxAvailableTime() const;
    bool checkSpecialty(string requestedSpecialty) const;
    string getSchedule() const;
    int getPrescriptionCount() const;
    Prescription getPrescription(int index) const;
};