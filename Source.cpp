#include<iostream>
#include <cstdlib>
#include "Doctor.h"
#include "precreption.h"
#include "System.h"
#include "Admin.h"
#include "Patient.h"
using namespace std;

/* Specialists | Illness | cost
* Cardiologist 500$:
* Arrhythmia 150$
* Coronary Artery Disease 250$
* Hypertension 100$
*
* Neurologist 600$:
* Migraine 120$
* Epilepsy 300$
* Stroke 400$
*
* Dermatologist 300$:
* Acne 50$
* Psoriasis 150$
* Eczema 100$
*
* Pediatrician 250$:
* Childhood Asthma 200$
* Growth Delay 180$
* Ear Infection 90$
*
* Orthopedic 400$:
* Bone Fracture 300$
* Arthritis 250$
* Slipped Disc 270$
*
* Psychiatrist 550$:
* Anxiety 150$
* Depression 180$
* Bipolar Disorder 250$
*
* General Practitioner 200$:
* Common Cold 20$
* Fever 30$
* Fatigue 25$
*
*/

string usernames[20], password[20], role[20];
const float EMPTY = -1;

int loginWindow() {
	int logNum;
	string tempUser, tempPass;

	cin >> logNum;

	switch (logNum) {

	case 1: {
		cout << "\n=== Login ===" << endl;
		cout << "Enter username: ";
		cin >> tempUser;
		cout << "Enter password: ";
		cin >> tempPass;

		for (int i = 0; i < 20; i++) {
			if (usernames[i] == tempUser) {
				if (password[i] == tempPass) {
					cout << "Login successful!" << endl;
					cout << "Welcome, " << tempUser << " (" << role[i] << ")" << endl;
					return (i + 1);
				}
				else {
					cout << "Wrong password!" << endl;
					return 0;
				}
			}
		}
		cout << "User not found!" << endl;
		return 0;
	}
	case 2:
		cout << "Thank you for using the Hospital Management System!" << endl;
		exit(0);
	default:
		cout << "Invalid choice! Please enter a number 1 or 2." << endl;
		return loginWindow();
	}
}