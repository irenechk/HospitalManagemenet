#include<iostream>
using namespace std;

class Patient {
    private:
    int id;
    int age;
    string name[50];
    string disease [50];
    string doctor [50];


    public:
    void addPatient() {

        cout << "Enter Patient ID: ";
        cin >> id;
        cout << "Enter Patient Name: ";
        cin >> name;
        cout << "Enter Patient age: ";
        cin >> age;
        cout << "Enter Disease: ";
        cin >> disease;
        cout << "Enter doctor Name: ";
        cin >> doctor;
        cout << "Patient added sucessfully!" << endl;
    }

    void displayPatient() {
        cout << "Patient ID: " << id << endl;
        cout << "Patient Name: " << name << endl;
        cout << "Patient age: " << age << endl;
        cout << "Disease: " << disease << endl;
        cout << "Doctor: " << doctor << endl;
    } 
};

class Billing{
    public:
    void generateBill() {
        int patientID;
        float days;
        int chargePerDay = 1500;
        cout << "Enter Patient ID for billing: ";
        cin >> patientID;
        cout << "Enter number of days admitted: ";
        cin >> days;
        cout << "Total Bill for Patient ID: " << patientID << " is " << days*chargePerDay << endl;
    }
};

int main() {
    Patient *p[10];
    Billing *b;
    int count = 0;
    int choice;

    b = new Billing();

    do {
        cout << "Hospital Management System" << endl;
        cout << "1. Add Patient" << endl;
        cout << "2. Display Patient" << endl;
        cout << "3. Generate Bill" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
            if (count < 10) {
                p[count] = new Patient();
                p[count]->addPatient();
                count++;
            } else {
                cout << "Patient limit reached!" << endl;
            }
            break;

            case 2:
            if (count == 0) {
                cout << "No patient record found: " << endl;
            } else {
                for (int i=0; i<count; i++) {
                    cout << "Patient" << (i+1) << ":" << endl;
                    p[i]->displayPatient();

                }
            }
            break;

            case 3:
            b->generateBill();
            break;

            case 4:
            cout << "Exiting..." << endl;
            break;

            default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    for (int i =0; i<count; i++) {
        delete p[i];
    }
    delete b;

    return 0;
}