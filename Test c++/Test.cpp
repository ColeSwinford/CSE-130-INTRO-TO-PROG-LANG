#include <iostream>
using namespace std;

class Student
{
    public:
        int Name(string, string)
        {
            cout << "Name:\nFirst: " << string << "\nLast: " << string << endl;

            return 0;
        }
};

int main()
{
    string firstName = "Cole";
    string lastName = "Swinford";

    Student Stu;
    Stu.Name(firstName, lastName);

    return 0;
}
