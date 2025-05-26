#include "UI.h"
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <cstdlib>

using namespace std;

UI::UI(System& sys, LoginWindow& login) : system(sys), loginWindow(login) {
    system.initialize();
}

void UI::start() {
    while (true) {
        if (!loginWindow.isUserLoggedIn()) {
            if (!loginWindow.login()) {
                continue;
            }
        }
        while (loginWindow.isUserLoggedIn()) {
            displayMainMenu();
        }
    }
}

void UI::displayMainMenu() {
    while (true) {
        cout << "\n=== Hospital Management System ===" << endl;
        cout << "1. Doctor Operations" << endl;
        cout << "2. Patient Operations" << endl;
        cout << "3. Admin Operations" << endl;
        cout << "4. Logout" << endl;
        cout << "5. Exit" << endl;
        int choice = getIntInput("Enter your choice: ");
        switch (choice) {
        case 1:
            handleDoctorMenu();
            break;
        case 2:
            handlePatientMenu();
            break;
        case 3:
            handleAdminMenu();
            break;
        case 4:
            loginWindow.logout();
            return;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice!" << endl;
        }
    }
}

void UI::handleDoctorMenu() {
    while (true) {
        cout << "\n=== Doctor Operations ===" << endl;
        cout << "1. Add Doctor" << endl;
        cout << "2. View Schedule" << endl;
        cout << "3. Add Prescription" << endl;
        cout << "4. Set Available Times" << endl;
        cout << "5. Back to Main Menu" << endl;
        int choice = getIntInput("Enter your choice: ");
        switch (choice) {
        case 1:
            addDoctor();
            break;
        case 2:
            viewDoctorSchedule();
            break;
        case 3:
            addPrescription();
            break;
        case 4:
            setDoctorTimes();
            break;
        case 5:
            return;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
}

void UI::handlePatientMenu() {
    while (true) {
        cout << "\n=== Patient Operations ===" << endl;
        cout << "1. Add Patient" << endl;
        cout << "2. Remove Patient" << endl;
        cout << "3. Book Appointment" << endl;
        cout << "4. View Medical History" << endl;
        cout << "5. Add Medical History" << endl;
        cout << "6. Back to Main Menu" << endl;
        int choice = getIntInput("Enter your choice: ");
        switch (choice) {
        case 1:
            addPatient();
            break;
        case 2:
            removePatient();
            break;
        case 3:
            bookAppointment();
            break;
        case 4:
            viewPatientHistory();
            break;
        case 5:
            addPatientMedicalHistory();
            break;
        case 6:
            return;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
}

void UI::handleAdminMenu() {
    while (true) {
        cout << "\n=== Admin Operations ===" << endl;
        cout << "1. View All Doctors" << endl;
        cout << "2. View All Patients" << endl;
        cout << "3. System Management" << endl;
        cout << "4. Back to Main Menu" << endl;
        int choice = getIntInput("Enter your choice: ");
        switch (choice) {
        case 1:
            viewAllDoctors();
            break;
        case 2:
            viewAllPatients();
            break;
        case 3:
            manageSystem();
            break;
        case 4:
            return;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
}

void UI::addDoctor() {
    string id, name;
    cout << "Enter Doctor ID: ";
    cin >> id;
    cout << "Enter Doctor Name: ";
    cin >> name;

    Doctor doctor(id, name);
    system.addDoctor(doctor);
    cout << "Doctor added successfully!" << endl;
}

void UI::viewDoctorSchedule() {
    int index;
    cout << "Enter doctor index: ";
    cin >> index;
    if (index < 0 || index >= system.getDoctorCount()) {
        cout << "Invalid doctor index!" << endl;
        return;
    }
    Doctor& doctor = system.getDoctor(index);
    cout << doctor.getScheduleInfo() << endl;
}

void UI::addPrescription() {
    int index;
    string patientID, prescription;

    cout << "Enter doctor index: ";
    cin >> index;
    if (index < 0 || index >= system.getDoctorCount()) {
        cout << "Invalid doctor index!" << endl;
        return;
    }
    cout << "Enter patient ID: ";
    cin >> patientID;
    cout << "Enter prescription: ";
    cin.ignore();
    getline(cin, prescription);

    Doctor& doctor = system.getDoctor(index);
    doctor.addPrescription(patientID, prescription);
    cout << "Prescription added successfully!" << endl;
}

void UI::setDoctorTimes() {
    int index;
    cout << "Enter doctor index: ";
    cin >> index;
    if (index < 0 || index >= system.getDoctorCount()) {
        cout << "Invalid doctor index!" << endl;
        return;
    }
    int count;
    cout << "Enter number of times (max 10): ";
    cin >> count;
    vector<string> times;
    cout << "Enter available times:" << endl;
    for (int i = 0; i < count; i++) {
        string t;
        cout << "Time " << (i + 1) << ": ";
        cin >> t;
        times.push_back(t);
    }
    Doctor& doctor = system.getDoctor(index);
    doctor.setTimes(times);
    cout << "Available times updated successfully!" << endl;
}

void UI::addPatient() {
    string id, name, contact;
    int age;

    cout << "Enter patient ID: ";
    cin >> id;
    cout << "Enter patient name: ";
    cin >> name;
    cout << "Enter patient age: ";
    cin >> age;
    cout << "Enter contact info: ";
    cin >> contact;

    Patient patient(id, name, age, contact);
    system.addPatient(patient);
    cout << "Patient added successfully!" << endl;
}

void UI::removePatient() {
    int index;
    cout << "Enter patient index to remove: ";
    cin >> index;
    if (index < 0 || index >= system.getPatientCount()) {
        cout << "Invalid patient index!" << endl;
        return;
    }
    system.removePatient(index);
    cout << "Patient removed successfully!" << endl;
}

void UI::bookAppointment() {
    int patientIndex, doctorIndex;
    string time;

    cout << "Enter patient index: ";
    cin >> patientIndex;
    if (patientIndex < 0 || patientIndex >= system.getPatientCount()) {
        cout << "Invalid patient index!" << endl;
        return;
    }
    cout << "Enter doctor index: ";
    cin >> doctorIndex;
    if (doctorIndex < 0 || doctorIndex >= system.getDoctorCount()) {
        cout << "Invalid doctor index!" << endl;
        return;
    }
    cout << "Enter appointment time: ";
    cin >> time;

    Patient& patient = system.getPatient(patientIndex);
    Doctor& doctor = system.getDoctor(doctorIndex);

    doctor.addAppointment(patient.getName(), time);
    patient.bookAppointment("Appointment with Dr. " + doctor.getName() + " at " + time);
    cout << "Appointment booked successfully!" << endl;
}

void UI::viewPatientHistory() {
    int index;
    cout << "Enter patient index: ";
    cin >> index;
    if (index < 0 || index >= system.getPatientCount()) {
        cout << "Invalid patient index!" << endl;
        return;
    }
    Patient& patient = system.getPatient(index);
    cout << patient.getMedicalHistory() << endl;
}

void UI::addPatientMedicalHistory() {
    int index;
    cout << "Enter patient index: ";
    cin >> index;
    if (index < 0 || index >= system.getPatientCount()) {
        cout << "Invalid patient index!" << endl;
        return;
    }
    string record;
    cout << "Enter medical record to add: ";
    cin.ignore();
    getline(cin, record);
    Patient& patient = system.getPatient(index);
    patient.addMedicalRecord(record);
    cout << "Medical history added successfully!" << endl;
}

void UI::viewAllDoctors() {
    cout << "\n=== All Doctors ===" << endl;
    const auto& doctors = system.getAllDoctors();
    for (size_t i = 0; i < doctors.size(); ++i) {
    cout << "Doctor " << i << ": " << doctors[i].getName() << " (ID: " << doctors[i].getID() << ")" << endl;
    }
}

void UI::viewAllPatients() {
    cout << "\n=== All Patients ===" << endl;
    const auto& patients = system.getAllPatients();
    for (size_t i = 0; i < patients.size(); ++i) {
    cout << patients[i].getPatientInfo() << endl;
    }
}

void UI::manageSystem() {
    cout << "\n=== System Management ===" << endl;
    cout << "1. Reset All Schedules" << endl;
    cout << "2. Back" << endl;
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;

    if (choice == 1) {
        for (int i = 0; i < system.getDoctorCount(); i++) {
            Doctor& doctor = system.getDoctor(i);
            if (doctor.getName() != "") {
                doctor.resetSchedule();
            }
        }
        cout << "All schedules have been reset!" << endl;
    }
}

int UI::getIntInput(const  string& prompt) {
    int input;
    while (true) {
        cout << prompt;
        if (cin >> input) {
            clearInputBuffer();
            return input;
        }
        clearInputBuffer();
        displayError("Invalid input. Please enter a number.");
    }
}

string UI::getStringInput(const string& prompt) {
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
}

char UI::getCharInput(const string& prompt) {
    char input;
    while (true) {
        cout << prompt;
        if (cin >> input) {
            clearInputBuffer();
            return input;
        }
        clearInputBuffer();
        displayError("Invalid input. Please enter a single character.");
    }
}

double UI::getDoubleInput(const string& prompt) {
    double input;
    while (true) {
        cout << prompt;
        if (cin >> input) {
            clearInputBuffer();
            return input;
        }
        clearInputBuffer();
        displayError("Invalid input. Please enter a number.");
    }
}

void UI::displayMessage(const string& message) {
    cout << message << endl;
}

void UI::displayError(const string& error) {
    cout << "Error: " << error << endl;
}

void UI::displaySuccess(const string& success) {
    cout << "Success: " << success << endl;
}

void UI::displayMenu(const string& title, const vector<string>& options) {
    printHeader(title);
    for (size_t i = 0; i < options.size(); ++i) {
        cout << (i + 1) << ". " << options[i] << endl;
    }
    printDivider();
}

void UI::waitForEnter() {
    cout << "Press Enter to continue...";
    cin.get();
}

void UI::printLine(const string& line) {
    cout << line << endl;
}

void UI::printHeader(const string& header) {
    printDivider('=');
    cout << "\t" << header << endl;
    printDivider('=');
}

void UI::printDivider(char character, int length) {
    cout << string(length, character) << endl;
}

void UI::clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}