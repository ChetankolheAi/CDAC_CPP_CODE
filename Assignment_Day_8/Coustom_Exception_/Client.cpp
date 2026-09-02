#include <iostream>
#include "Wallet.h"
#include "InvalidAmountException.h"
#include "InsufficientBalanceException.h"

using namespace std;

int main()
{
    Wallet w;
    int choice;
    double amount;

    do
    {
        cout << "\n===== DIGITAL WALLET =====\n";
        cout << "1. Create Wallet\n";
        cout << "2. Add Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Display Wallet Details\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        try
        {
            switch (choice)
            {
            case 1:
                cin >> w;
                cout << "\nWallet created successfully!\n";
                cout << w;
                break;

            case 2:
                cout << "Enter amount to add: ";
                cin >> amount;

                w.depositMoney(amount);

                cout << "Money added successfully!\n";
                cout << w;
                break;

            case 3:
                cout << "Enter amount to withdraw: ";
                cin >> amount;

                w.withdrawMoney(amount);

                cout << "Withdrawal successful!\n";
                cout << w;
                break;

            case 4:
                cout << w;
                break;

            case 5:
                cout << "Thank you!\n";
                break;

            default:
                cout << "Invalid choice!\n";
            }
        }
        catch (InvalidAmountException& e)
        {
            cout << "Exception: " << e << endl;
        }
        catch (InsufficientBalanceException& e)
        {
            cout << "Exception: " << e << endl;
        }

    } while (choice != 5);

    return 0;
}