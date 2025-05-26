#include "UI.h"
#include "LoginWindow.h"
#include "System.h"

int main() {
    System hospitalSystem("Hospital Management System");
    LoginWindow loginWindow;
    UI userInterface(hospitalSystem, loginWindow);

    userInterface.start();
    return 0;
}