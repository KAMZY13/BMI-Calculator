
#include <iostream>
#include <iomanip>
#include <limits>
#include <cctype>
using namespace std;

int main() {
    double weight, height, bmi;
    char choice;

    cout << "===== BMI CALCULATOR =====\n";

    do {
        // Get and validate weight
        while (true) {
            cout << "\nEnter your weight in kilograms: ";

            if (!(cin >> weight)) {
                cout << "Error: Please enter a numeric weight, e.g. 75.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (weight <= 0) {
                cout << "Error: Weight must be greater than zero.\n";
            } else if (weight > 500) {
                cout << "Warning: That weight seems unusually high. "
                     << "Please check it.\n";
            } else {
                break;
            }
        }

        // Get and validate height
        while (true) {
            cout << "Enter your height in metres (e.g. 1.72): ";

            if (!(cin >> height)) {
                cout << "Error: Please enter a numeric height, e.g. 1.72.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (height <= 0) {
                cout << "Error: Height must be greater than zero.\n";
            } else if (height > 3.0) {
                cout << "Error: That height seems too high in metres.\n";

                if (height >= 100 && height <= 300) {
                    cout << "Did you mean " << height / 100
                         << " metres? You may have entered centimetres.\n";
                }

                cout << "Please try again using metres, e.g. 1.72.\n";
            } else if (height < 0.5) {
                cout << "Warning: That height seems unusually low. "
                     << "Please check it.\n";
            } else {
                break;
            }
        }

        // Calculate BMI
        bmi = weight / (height * height);

        cout << fixed << setprecision(2);
        cout << "\nYour BMI is: " << bmi << '\n';

        if (bmi < 18.5) {
            cout << "Category: Underweight\n";
        } else if (bmi < 25.0) {
            cout << "Category: Normal weight\n";
        } else if (bmi < 30.0) {
            cout << "Category: Overweight\n";
        } else {
            cout << "Category: Obesity range\n";
        }

        // calculate again?
        while (true) {
            cout << "\nCalculate another BMI? (Yes/No): ";
            cin >> choice;

            choice = static_cast<char>(
                toupper(static_cast<unsigned char>(choice))
            );

            if (choice == 'Yes' || choice == 'No') {
                break;
            }

            cout << "Please enter Yes for yes or No for no.\n";
        }

    } while (choice == 'Yes');

    cout << "\nThank you for using the BMI Calculator!\n";

    return 0;
}
