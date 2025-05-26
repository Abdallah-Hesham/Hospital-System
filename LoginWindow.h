#pragma once
#include <string>
using namespace std;

class LoginWindow {
private:
    string username;
    string password;
    bool isLoggedIn;

public:
    LoginWindow();
    bool login();
    bool logout();
    bool isUserLoggedIn() const;
    string getCurrentUser() const;
};