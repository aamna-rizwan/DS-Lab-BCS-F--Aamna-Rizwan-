#include <iostream>
using namespace std;

int main()
{
    int students;
    cout << "Enter the number of students: ";
    cin >> students;
    int **marks = new int *[students];
    int *num_course = new int[students];
    for (int i = 0; i < students; i++)
    {
        cout << "Enter the number of courses of student " << i+1 << ": ";
        cin >> num_course[i];
    }
    for (int i = 0; i < students; i++)
    {
        marks[i] = new int[num_course[i]];
    }
    for (int i = 0; i < students; i++)
    {
        cout << "Student " << i+1 << endl;
        for (int j = 0; j < num_course[i]; j++)
        {
            cout << "Enter the marks of course " << j+1 << ": ";
            cin >> marks[i][j];
        }
    }
    int sum = 0;
    cout << "Average Marks: " << endl;
    for (int i = 0; i < students; i++)
    {
        cout << "Student " << i+1 << ": ";
        for (int j = 0; j < num_course[i]; j++)
        {
            sum += marks[i][j];
        }
        int avg = sum / num_course[i];
        cout << avg << endl;
    }
}
