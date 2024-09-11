// BROCKMAN-RACHEL-CGT215-LAB4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

void printMenu() {
    cout << "Please Select which operation to perform:" << endl;
    cout << "\t1. Factorial" << endl;
    cout << "\t2. Arithmetic Series" << endl;
    cout << "\t3. Geometric Series" << endl;
    cout << "\t4. Exit" << endl;
    cout << "Your Selection: ";
}

void myfunc() {
    int myParam;
    do {
        cout << "Enter a positive number to calculate its factorial: ";
        cin >> myParam;
        if (cin.fail() || myParam < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a positive number: ";
        }
    } while (myParam < 0);

    unsigned long long result = 1;
    for (int i = 1; i <= myParam; i++) {
        result *= i;
    }

    cout << "Factorial of " << myParam << " is: " << myParam << "! = ";
    for (int i = 1; i <= myParam; i++) {
        cout << i;
        if (i < myParam) {
            cout << " * ";
        }
    }
    cout << " = " << result << endl;
}

void arithmetic() {
    int difference, start, numElements;

    cout << "Enter a number to start at: ";
    cin >> start;

    cout << "Enter a number to add each time: ";
    cin >> difference;

    do {
        cout << "Enter the number of elements in the series: ";
        cin >> numElements;
        if (cin.fail() || numElements <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a positive number of elements: ";
        }
    } while (numElements <= 0);

    int sum = 0;
    cout << "The arithmetic series is: ";
    for (int i = 0; i < numElements; i++) {
        int currentTerm = start + i * difference;
        cout << currentTerm;
        sum += currentTerm;

        if (i < numElements - 1) {
            cout << " + ";
        }
    }

    cout << " = " << sum << endl;
    cout << "Sum of arithmetic series: S = (" << numElements << " / 2) * (2 * " << start << " + (" << numElements - 1 << ") * " << difference << ") = " << sum << endl;
}

void geometric() {
    int numElements, start;
    double ratio;

    cout << "Enter a number to start at: ";
    cin >> start;

    cout << "Enter a number to multiply by each time: ";
    cin >> ratio;

    do {
        cout << "Enter the number of elements in the series: ";
        cin >> numElements;
        if (cin.fail() || numElements <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a positive number of elements: ";
        }
    } while (numElements <= 0);

    double sum = 0;
    cout << "The geometric series is: ";
    for (int i = 0; i < numElements; i++) {
        double currentTerm = start * pow(ratio, i);
        cout << currentTerm;
        sum += currentTerm;

        if (i < numElements - 1) {
            cout << " + ";
        }
    }

    cout << " = " << sum << endl;
    if (ratio == 1) {
        cout << "Sum of geometric series: S = " << start << " * " << numElements << " = " << sum << endl;
    }
    else {
        cout << "Sum of geometric series: S = " << start << " * (1 - " << ratio << "^" << numElements << ") / (1 - " << ratio << ") = " << sum << endl;
    }
}

int main() {
    int choice;
    char again;

    do {
        bool validChoice = false;
        while (!validChoice) {
            printMenu();
            cin >> choice;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number between 1 and 4.\n";
            }
            else if (choice >= 1 && choice <= 3) {
                validChoice = true;
            }
            else if (choice == 4) {
                return 0;
            }
            else {
                cout << "Invalid choice. Please select a valid option (1-4).\n";
            }
        }

        if (choice == 1) {
            myfunc();
        }
        else if (choice == 2) {
            arithmetic();
        }
        else if (choice == 3) {
            geometric();
        }

        cout << "Go Again? [Y/N] ";
        cin >> again;
    } while (again == 'y' || again == 'Y');

    return 0;
}








// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
