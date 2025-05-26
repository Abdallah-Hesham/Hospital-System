#pragma once
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <cstdlib>
#include "System.h"
#include "LoginWindow.h"
#include "Doctor.h"
#include "Patient.h"
using namespace std;

class UI {
private:
    System& system;
    LoginWindow& loginWindow;

    void displayMainMenu();
    void handleDoctorMenu();
    void handlePatientMenu();
    void handleAdminMenu();

    void addDoctor();
    void viewDoctorSchedule();
    void addPrescription();
    void setDoctorTimes();

    void addPatient();
    void removePatient();
    void bookAppointment();
    void viewPatientHistory();
    void addPatientMedicalHistory();

    void viewAllDoctors();
    void viewAllPatients();
    void manageSystem();
    void clearInputBuffer();

public:
    UI(System& sys, LoginWindow& login);

    int getIntInput(const string& prompt);
    string getStringInput(const string& prompt);
    char getCharInput(const string& prompt);
    double getDoubleInput(const string& prompt);

    void displayMessage(const string& message);
    void displayError(const string& error);
    void displaySuccess(const string& success);
    void displayMenu(const string& title, const vector<string>& options);
    void clearScreen();
    void waitForEnter();

    void printLine(const string& line);
    void printHeader(const string& header);
    void printDivider(char character = '-', int length = 50);

    void start();
};