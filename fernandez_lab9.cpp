#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX = 5;
const int COURSE_COUNT = 3;

// Function prototypes
void calculateStudent(int i, double Score[][3], double& total, double& average);
void displayAll(int n, string NameArr[], double Score[][3]);
int findTopStudent(int n, double Score[][3]);

int main()
{
    // Test data stored directly in main()
    int n = 3;
    string NameArr[MAX] = { "Alice", "Bob", "Carl" };
    double Score[MAX][3] = {
        {90, 85, 95},
        {70, 80, 75},
        {88, 92, 84}
    };

    cout << fixed << setprecision(2);

    // 1. print title
    cout << "Student Grade Report\n";
    cout << "---------------------\n";

    // 2. display all students
    displayAll(n, NameArr, Score);

    // 3. find top student
    int topIndex = findTopStudent(n, Score);

    // 4. calculate top student's total
    double total, avg;
    calculateStudent(topIndex, Score, total, avg);

    // 5. print top student info
    cout << "\nTop Student: " << NameArr[topIndex]
        << " | Total Score: " << total << endl;

    return 0;
}

// Calculate total and average for one student
void calculateStudent(int i, double Score[][3], double& total, double& average)
{
    total = 0;

    for (int j = 0; j < COURSE_COUNT; j++)
    {
        total += Score[i][j];
    }

    average = total / COURSE_COUNT;
}

// Display all students' information
void displayAll(int n, string NameArr[], double Score[][3])
{
    for (int i = 0; i < n; i++)
    {
        double total, avg;

        // reuse function
        calculateStudent(i, Score, total, avg);

        cout << NameArr[i] << " | ";

        for (int j = 0; j < COURSE_COUNT; j++)
        {
            cout << Score[i][j] << " ";
        }

        cout << "| Total: " << total
            << " | Avg: " << avg << endl;
    }
}

// Find the index of the student with the highest total score
int findTopStudent(int n, double Score[][3])
{
    int topIndex = 0;
    double maxTotal = 0;

    for (int i = 0; i < n; i++)
    {
        double total, avg;

        // reuse function
        calculateStudent(i, Score, total, avg);

        if (i == 0 || total > maxTotal)
        {
            maxTotal = total;
            topIndex = i;
        }
    }

    return topIndex;
}