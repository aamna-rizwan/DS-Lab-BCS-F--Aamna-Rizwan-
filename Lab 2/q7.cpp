#include <iostream>
using namespace std;

int main(){
    int department;
    cout << "Enter number of departments\n";
    cin >> department;
    int **salary = new int*[department];
    int *employees = new int[department];
    for(int i=0;i<department;i++){
        cout << "Enter number of employees for department " << i+1 << endl;
        cin >> employees[i];
    }
    for(int i=0;i<department;i++){
        salary[i]=new int[employees[i]];
    }
    for(int i=0;i<department;i++){
        cout << "Department : " << i+1 << endl;
        for(int j=0;j<employees[i];j++){
            cout << "Enter the salary of employee " << j+1 << endl;
            cin >> salary[i][j];
        }
    }
    cout << "Highest salary:\n";
    for(int i = 0; i < department; i++) {
        int maxSalary = salary[i][0];
        for(int j = 1; j < employees[i]; j++) {
            if(salary[i][j] > maxSalary) {
                maxSalary = salary[i][j];
            }
        }
        cout << "Department " << i+1 << ": " << maxSalary << endl;
    }
    cout << "Average salary per department:\n";
    int n;
    for (int i = 0; i < department; i++) {
    int sum = 0;
      for (int j = 0; j < employees[i]; j++) {
        sum =  sum + salary[i][j];
      }
      int maxAvg=0;
    int avg = (int) sum / employees[i];  
    cout << "Department " << i+1 << ": " << avg << endl;
       if (avg > maxAvg) {
        maxAvg = avg;
        n = i;
       }
    }
    cout << "Highest salary of : Department " << n+1 << endl;
    for(int i=0;i<department;i++){
        delete[] salary[i];
    }
    delete[] salary;
    delete[] employees;
}
