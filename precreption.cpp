#include<iostream>
#include "precreption.h"

using namespace std;

precreption:: precreption() {
		cost = 50;
	}
void precreption::illnessCost(string x) {
		if (x == "Arrhythmia") cost += 150;
		else if (x == "Coronary Artery Disease") cost += 250;
		else if (x == "Hypertension ") cost += 100;
		else if (x == "Migraine") cost += 120;
		else if (x == "Epilepsy") cost += 300;
		else if (x == "Stroke") cost += 400;
		else if (x == "Acne") cost += 50;
		else if (x == "Psoriasis") cost += 150;
		else if (x == "Eczema") cost += 100;
		else if (x == "Childhood Asthma") cost += 200;
		else if (x == "Growth Delay") cost += 180;
		else if (x == "Ear Infection") cost += 90;
		else if (x == "Bone Fracture") cost += 300;
		else if (x == "Arthritis") cost += 250;
		else if (x == "Slipped Disc") cost += 270;
		else if (x == "Anxiety") cost += 150;
		else if (x == "Depression") cost += 180;
		else if (x == "Bipolar Disorder") cost += 250;
		else if (x == "Common Cold") cost += 20;
		else if (x == "Fever") cost += 30;
		else if (x == "Fatigue") cost += 25;
	}

void precreption::doctorCost(string x) {
		if (x == "Cardiologist") cost += 500;
		else if (x == "Neurologist") cost += 600;
		else if (x == "Dermatologist") cost += 300;
		else if (x == "Pediatrician") cost += 250;
		else if (x == "Orthopedic") cost += 400;
		else if (x == "Psychiatrist ") cost += 550;
		else if (x == "General Practitioner") cost += 200;
	}

int precreption::totalCost() {
		return cost;
	}