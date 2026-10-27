#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char operation;

    cout << "===== SIMPLE CALCULATOR =====" << endl;

    // Input two numbers
    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    // Choose an arithmetic operation
    cout << "\nChoose an operation (+, -, *, /): ";
    cin >> operation;

    // Perform the calculation
    switch (operation) {
        case '+':
            cout << "Result: " << num1 + num2 << endl;
            break;

        case '-':
            cout << "Result: " << num1 - num2 << endl;
            break;

        case '*':
            cout << "Result: " << num1 * num2 << endl;
            break;

        case '/':
            if (num2 != 0) {
                cout << "Result: " << num1 / num2 << endl;
            } else {
                cout << "Error: Division by zero is not allowed."
                     << endl;
            }
            break;

        default:
            cout << "Invalid operation! Please use +, -, *, or /."
                 << endl;
    }

    cout << "Thank you for using the calculator!" << endl;

    return 0;
}