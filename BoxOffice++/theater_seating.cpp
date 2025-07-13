#include<iostream>
#include<iomanip>
using namespace std;

#define RESET "\033[0m"
#define GREEN  "\033[32m"
#define RED  "\033[31m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"

const int row = 15;
const int column = 30;



//Displays seat prices and validates input
void seatPrice(double price[])
{
    cout << CYAN << "Enter the seat price for each row: " << RESET  << endl;
    for(int i = 0; i < row; i++)
    {
        cout << "Row " << i + 1 << " row: ";
        cin >> price[i];
        while(price[i] < 0)
        {
            cout << YELLOW << "Invalid. Please enter a non-ngeative price for Row: " << i + 1 << RESET <<  " : $";
            cin >> price[i];
        }
    }
    cout << endl;
    cout << CYAN << "============ SEAT Prices ===============" << RESET << endl;
    for(int i = 0; i < row; i++)
    {
        cout << "Row" << setw(2) << i + 1 << ": $" << fixed << setprecision(2) << price[i] <<endl;
    }
    cout << CYAN << "============================================" << RESET << endl;
}


//Shows how many seats are available per row and in total
void seatAvailability(char seat[row][column])
{
    int totalAvailable = 0;
    cout << "======== SEAT Availability ========" << endl;
    for(int i = 0; i < row; i++)
    {
        int availableinRow = 0;
        for(int j = 0; j < column; j++)
        {
            if(seat[i][j] == '#')
            {
                availableinRow++;
            }
        }
        totalAvailable += availableinRow;
        cout << "Row" << setw(2) << i + 1 << ": " << availableinRow << " seats available" << endl;
    }
    cout << "Total seats available: " << totalAvailable << endl;
    cout << "===================================" << endl;
}

//Seating Plan
void displaySeating(char seat[row][column])
{
    cout << CYAN << "=========== Seating Plan ==========" << RESET << endl;
    for(int i = 0; i < row; i++)
    {
        cout << "Row " << setw(2) << i + 1 << ": ";
        for(int j = 0; j < column; j++)
        {
            if(seat[i][j] == '*')
            {
                cout << RED << seat[i][j] << RESET;
            }
            else 
            {
                cout << GREEN << seat[i][j] << RESET;
            }
        }
        cout << endl;
    }
    cout << CYAN << "===================================" << RESET << endl;
}
//Main Booking
void seatingPlan()
{
    char seating[row][column] = {
    {'*','*','*','#','#','#','*','*','*','#','#','#','*','#','#','#','#','#','#','#','#','*','*','*','*','*','#','#','#','#'},
    {'#','#','#','#','*','*','*','*','*','*','*','*','*','*','*','*','*','#','#','#','#','*','*','*','*','*','*','*','#','#'},
    {'*','*','#','#','#','*','*','*','*','*','*','*','*','*','*','#','#','#','#','#','#','#','#','*','*','*','*','#','#','#'},
    {'*','*','#','#','#','#','#','#','*','*','*','*','*','*','*','*','*','*','*','*','*','*','#','#','*','*','*','*','*','*'},
    {'*','*','*','*','*','*','*','*','#','#','#','#','#','*','*','*','*','*','*','*','*','*','#','#','#','#','#','#','#','#'},
    { '#','#','#','#','#','#','#','#','#','#','#','#','*','*','*','*','*','*','*','*','*','*','*','*','#','#','#','#','#','#' },
    { '#','#','#','#','#','#','#','*','*','*','*','*','*','*','*','*','*','*','*','#','#','#','#','#','#','#','#','#','#','#' },
    { '*','*','*','*','*','*','*','*','#','#','*','*','*','*','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' },
    { '#','#','#','#','#','#','#','#','#','*','*','*','*','*','#','#','#','#','#','#','#','#','#','#','#','#','#','*','*','*' },
    { '#','#','#','#','#','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','#','#','#','#','#','#','#','#','#','#' },
    { '#','*','*','*','*','*','*','*','*','*','*','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','*','*','#' },
    { '#','#','#','#','#','#','#','#','#','#','#','*','*','*','*','*','*','*','*','*','*','*','*','#','#','#','#','#','#','*' },
    { '#','#','#','*','*','*','*','*','*','*','*','*','#','#','#','#','#','#','#','#','*','*','#','#','#','#','#','#','#','#' },
    { '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }
    };
    int rowNum = 0, seatNum = 0;
    char again, choice;
    int total_price = 0, seat_sold = 0;  
    double price_array[row];

    displaySeating(seating);
    seatPrice(price_array);

    cout << endl;

    do
    {
        cout << "Enter the row number(0-14) and seat number(0-29) you would like to select: ";
        cin >> rowNum >> seatNum;
        while(seating[rowNum][seatNum] == '*' || rowNum < 0 || rowNum >= row || seatNum < 0 || seatNum >= column)
        {
            cout << YELLOW << "Invalid or already taken. Try again: " << RESET;
            cin >> rowNum >> seatNum;
        }
        seating[rowNum][seatNum] = '*';
        cout << GREEN << "Seat booked sucessfully!" << RESET << endl;
        displaySeating(seating);
        cout << "Do you wish to book another seat? (Y|N): ";
        cin >> again;
        total_price += price_array[rowNum];
        seat_sold +=1;
    } while (again == 'y' || again == 'Y');

    cout << endl;

    cout << "Show the total amount collected? (Y|N): ";
    cin >> choice;
    if(choice == 'y' || choice == 'Y')
    {
        cout << "Total Amount: $" << fixed << setprecision(2) << total_price << endl;
    }

    cout << "Show the total amount of seats sold? (Y|N): ";
    cin >> choice;
    if(choice == 'y' || choice == 'Y')
    {
        cout << "Seats Sold: " << seat_sold << endl;
    }

    seatAvailability(seating);
}

int main()
{
    seatingPlan();
    return 0;
}