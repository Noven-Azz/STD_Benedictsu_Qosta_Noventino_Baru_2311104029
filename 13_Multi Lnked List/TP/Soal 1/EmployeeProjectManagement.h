#ifndef EMPLOYEE_PROJECT_MANAGEMENT_H
#define EMPLOYEE_PROJECT_MANAGEMENT_H

#include <string>
using namespace std;

struct Project {
    string name;
    int duration;
    Project* next;
};

struct Employee {
    string name;
    string emp_id;
    Project* projects;
    Employee* next;
};

class EmployeeProjectManagement {
private:
    Employee* head;
public:
    EmployeeProjectManagement();
    void addEmployee(string name, string emp_id);
    void addProject(string emp_id, string project_name, int duration);
    void removeProject(string emp_id, string project_name);
    void displayData();
};

#endif
