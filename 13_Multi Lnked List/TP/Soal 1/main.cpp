#include "EmployeeProjectManagement.h"
#include <iostream>
using namespace std;

int main() {
    EmployeeProjectManagement epm;

    // Adding employees
    epm.addEmployee("Andi", "P001");
    epm.addEmployee("Budi", "P002");
    epm.addEmployee("Citra", "P003");

    // Adding projects
    epm.addProject("P001", "Aplikasi Mobile", 12);
    epm.addProject("P002", "Sistem Akuntansi", 8);
    epm.addProject("P003", "E-commerce", 10);

    // Adding another project for Andi
    epm.addProject("P001", "Analisis Data", 6);

    // Removing a project
    epm.removeProject("P001", "Aplikasi Mobile");

    // Displaying all data
    cout << "Employee and Project Data:\n";
    epm.displayData();

    return 0;
}
