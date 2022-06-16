#include <iostream>
#include "PQType.h"
#include <windows.h>
using namespace std;

struct Patient {
    string name = "";
    int priority = 0;
};

int menu;
int i, n;
int main()
{

    string a = "";
    int b = 0;

    Patient p1 = { "Nick", 1 };
    Patient p2 = { "John", 2 };
    Patient p3 = { "Mark", 3 };
    Patient p4 = { "Lucy", 5 };
    Patient patient{ a,b }; //To create a new "dummy" patient p5....p100

    PQType<Patient> PQType(100);

    //Adding instances of object Patient to the queue
    PQType.Enqueue(p1);
    PQType.Enqueue(p2);
    PQType.Enqueue(p3);
    PQType.Enqueue(p4);

    string option;

    //-----------------------MENU--------------------------------
    do
    {
        if (menu < 4 || menu > 1) // Error Handling
        {
            
            cout << "" << endl;
            cout << "===== HOSPITAL APP =====" << endl;
            cout << "" << endl;
            cout << "1. Display patients" << endl;
            cout << "2. Add new patient" << endl;
            cout << "3. Remove pateint from queue" << endl;
            cout << "4. EXIT" << endl;
            cin >> menu;

            switch (menu)
            {
            case 1:
                PQType.Print();
                break;

            case 2:
                cout << "Enter Patients Name: ";
                cin >> patient.name;

                cout << "Enter priority (1-5): ";
                cin >> patient.priority;
                if (patient.priority > 5 || patient.priority < 1) // Error Handling
                {
                    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(h, 4); // Display text in red
                    cout << "\n[ Priority can only be between 1 and 5 ]\n";
                    SetConsoleTextAttribute(h, 10);
                    break;
                }
                cout << "" << endl;
                PQType.Enqueue(patient);
                cout << "PATIENT ADDED!\n";
                cout << "" << endl;
                break;

            case 3:
                cout << "REMOVE PATIENT" << endl;
                HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(h, 4); // Display text in red             
                cout << "Are you sure you want to remove patient from queue? ( Y/N ): ";
                SetConsoleTextAttribute(h, 10);

                cin >> option;
                // Yes or No to remove a patient
                if (option == "Y")
                {
                    PQType.Dequeue(patient);
                    cout << "PATIENT REMOVED!\n";
                    break;
                }
                else if (option == "N")
                {
                    cout << "" << endl;
                    break;
                }
                break;
            }

        }
        else
        {
            cout << "Invalid Option"; // Error Handling
        }
        
    } while (menu != 4);
    return 0;
}




