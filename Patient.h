#pragma once
#include <string>
#include <vector>
using namespace std;

class Patient {
private:
    string id;
    string name;
    int age;
    string contactInfo;
    vector <string> medicalHistory;
    vector <string> appointments;
    string specialistRequest;
    string timeRequest;

public:
    Patient(const string& id, const string& name);
    Patient(const string& id, const string& name, int age, const string& contactInfo);
    
    string getID() const { return id; }
    string getName() const { return name; }
    int getAge() const { return age; }
    string getContactInfo() const { return contactInfo; }
    string getPatientInfo() const;
    string getMedicalHistory() const;
    string getSpecialistRequest() const { return specialistRequest; }
    string getTimeRequest() const { return timeRequest; }
    
    void setName(const string& patientName);
    void setAge(int patientAge);
    void setContactInfo(const string& contact);
    void updateInfo(const string& newContactInfo);
    void setSpecialistRequest(const string& request);
    void setTimeRequest(const string& request);
    
    void addMedicalRecord(const string& record);
    int getMedicalHistoryCount() const { return static_cast<int>(medicalHistory.size()); }
    string getMedicalHistory(int index) const { return medicalHistory.at(index); }
    
    void bookAppointment(const string& appointment);
    bool checkRequest() const { return !specialistRequest.empty() || !timeRequest.empty(); }
};