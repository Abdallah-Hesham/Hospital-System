#include "LoginWindow.h"
#include <iostream>
#include <string>

using namespace std;

LoginWindow::LoginWindow() : isLoggedIn(false) {}

bool LoginWindow::login() {
	cout << "=== Login ===" << endl;
	cout << "Username: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;

	if (username == "admin" && password == "admin123") {
		isLoggedIn = true;
		cout << "Login successful!" << endl;
		return true;
	}

	cout << "Invalid credentials!" << endl;
	return false;
}

bool LoginWindow::logout() {
	if (isLoggedIn) {
		isLoggedIn = false;
		username = "";
		password = "";
		cout << "Logged out successfully!" << endl;
		return true;
	}
	return false;
}

bool LoginWindow::isUserLoggedIn() const {
	return isLoggedIn;
}

string LoginWindow::getCurrentUser() const {
	return username;
}