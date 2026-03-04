#include <iostream>
#include <cctype>
#include "Theater.h"
#include "SalesManager.h"

using namespace std;

bool isValidInput(const string &input)
{
    
    if (input.length() < 2) return false;

    char row = toupper(input[0]);


    if (row < 'A' || row > 'H')
        return false;

   
    for (int i = 1; i < input.length(); i++)
    {
        if (!isdigit(input[i]))
            return false;
    }

    int col = stoi(input.substr(1));

    
    if (col < 1 || col > 10)
        return false;

    return true;
}

int main()
{
    SalesManager sales("sales_log.txt");
    Theater theater(sales);

    string input;

    while (true)
    {
        theater.displaySeats();
        cout << "\nEnter a seat (ex: A5) or X1 to exit: ";
        cin >> input;

        if (input == "X1" || input == "x1")
        {
            theater.saveInventory();
            cout << "\nExiting program... inventory saved.\n";
            break;
        }

        
        if (!isValidInput(input))
        {
            cout << "\nInvalid seat format. Try again.\n";
            continue;
        }

        char row = toupper(input[0]);
        int col = stoi(input.substr(1)) - 1;

        if (theater.purchaseSeat(row, col))
        {
            cout << "\nSeat " << row << (col+1) << " purchased successfully!\n";
        }
        else
        {
            cout << "\nSeat is already sold or unavailable. Try again.\n";
        }

        if (theater.isSoldOut())
        {
            cout << "\nTHEATER SOLD OUT! Clearing inventory and closing...\n";
            remove("seating_inventory.txt");
            break;
        }
    }

    return 0;
}
