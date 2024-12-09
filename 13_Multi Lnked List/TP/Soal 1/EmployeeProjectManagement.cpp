#include "EmployeeProjectManagement.h"
#include <iostream>
using namespace std;

EmployeeProjectManagement::EmployeeProjectManagement() {
    head = nullptr;
}

void EmployeeProjectManagement::addEmployee(string name, string emp_id) {
    Employee* newEmployee = new Employee();
    newEmployee->name = name;
    newEmployee->emp_id = emp_id;
    newEmployee->projects = nullptr;
    newEmployee->next = head;
    head = newEmployee;
}

void EmployeeProjectManagement::addProject(string emp_id, string project_name, int duration) {
    Employee* current = head;
    while (current != nullptr) {
        if (current->emp_id == emp_id) {
            Project* newProject = new Project();
            newProject->name = project_name;
            newProject->duration = duration;
            newProject->next = current->projects;
            current->projects = newProject;
            return;
        }
        current = current->next;
    }
    cout << "Employee with ID " << emp_id << " not found.\n";
}

void EmployeeProjectManagement::removeProject(string emp_id, string project_name) {
    Employee* current = head;
    while (current != nullptr) {
        if (current->emp_id == emp_id) {
            Project* prev = nullptr;
            Project* currProject = current->projects;

            while (currProject != nullptr) {
                if (currProject->name == project_name) {
                    if (prev == nullptr) {
                        current->projects = currProject->next;
                    } else {
                        prev->next = currProject->next;
                    }
                    delete currProject;
                    cout << "Project " << project_name << " removed from employee " << emp_id << ".\n";
                    return;
                }
                prev = currProject;
                currProject = currProject->next;
            }
            cout << "Project " << project_name << " not found.\n";
            return;
        }
        current = current->next;
    }
    cout << "Employee with ID " << emp_id << " not found.\n";
}

void EmployeeProjectManagement::displayData() {
    Employee* current = head;
    while (current != nullptr) {
        cout << "Employee: " << current->name << " (ID: " << current->emp_id << ")\n";
        Project* proj = current->projects;
        while (proj != nullptr) {
            cout << "  - Project: " << proj->name << ", Duration: " << proj->duration << " months\n";
            proj = proj->next;
        }
        current = current->next;
    }
}
