#include <iostream>  //iostream.h -> iostream
using namespace std; //added this line

enum TEmploymentStatus
{
    esFullTime,
    esPartTime,
    esContractor,
    esNS
};

int main()
{
    int EmplStatus; //added ";" at the end

    cout << "Employee's Contract Status: ";
    cout << "\n0 - Full Time | 1 - Part Time"
         << "\n2 - Contractor | 3 - Other"
         << "\nStatus: ";
    cin >> EmplStatus;
    cout << endl;

    switch (EmplStatus)
    {
    case esFullTime:
        cout << "Employment Status: Full Time\n";
        cout << "Employee's Benefits: Medical Insurance\n"
             << " Sick Leave\n"
             << " Maternal Leave\n"
             << " Vacation Time\n"
             << " 401K\n";
        break;

    case esPartTime: //added ":" after esPartTime
        cout << "Employment Status: Part Time\n";
        cout << "Employee's Benefits: Sick Leave\n"
             << " Maternal Leave\n";
        break;

    case esContractor:
        cout << "Employment Status: Contractor\n";
        cout << "Employee's Benefits: None\n"; //added ";" at the end 
        break;

    case esNS:
        cout << "Employment Status: Other\n";
        cout << "Status Not Specified\n";
        break;

    default:
        cout << "Unknown Status\n";
    }
    return 0;
}