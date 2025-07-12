#include<iostream>
#include<string>
#include<ctime>
using namespace std;

int daysSpent()
{
    int days;
    cout << "Please, Enter how many days you have spent on the trip?: ";
    cin >> days;
    while(days < 1)
    {
        cout << "Invalid, Please make sure the days entered is greater than 1: ";
        cin >> days;
    }
    return days;
}

void displayTripTime()
{
    int tm_hour_dep, tm_min_dep;
    int tm_hour_arr, tm_min_arr;
    cout << "Enter the time of departure on the first day trip?: ";
    cin >> tm_hour_dep >> tm_min_dep;
    while(tm_hour_dep < 0 || tm_hour_dep > 23)
    {
        cout << "Error make sure the hour time is represented between 0-23 time format: ";
        cin >> tm_hour_dep;
    }
    while(tm_min_dep < 0 || tm_min_dep > 59)
    {
        cout << "Error make sure the minute time is represented between 0-59 time format: ";
        cin >> tm_min_dep; 
    }
    cout << endl;
    cout << "Time of departure on the first day trip: " << endl;
    cout << (tm_hour_dep < 10 ? "0" : "") << tm_hour_dep << " : " << (tm_min_dep < 10 ? "0" : "") << tm_min_dep << endl;
    cout << endl;
    cout << "Enter the time of arrival on the last day trip?: ";
    cin >> tm_hour_arr >> tm_min_arr;
    while(tm_hour_arr < 0 || tm_hour_arr > 23)
    {
        cout << "Error make sure the hour time is represented between 0-23 time format: ";
        cin >> tm_hour_arr;
    }
    while(tm_min_arr < 0 || tm_min_arr > 59)
    {
        cout << "Error make sure the minute time is represented between 0-59 time format: ";
        cin >> tm_min_arr; 
    }
    cout << endl;
    cout << "Time of arrival on the last day trip: " << endl;
    cout << (tm_hour_arr < 10 ? "0" : "") << tm_hour_arr << " : " << (tm_min_arr < 10 ? "0" : "") << tm_min_arr << endl;
}

int roundTrip()
{
    int round_fareamount = 0;
    char choice;
    cout << "Is there any amount for any round-trip fare (Y|N)?: ";
    cin >> choice;
    if(choice == 'y' || choice == 'Y')
    {
        cout << "Please, enter that amount: ";
        cin >> round_fareamount;
        while(round_fareamount < 0)
        {
            cout << "Please, make sure a valid amount is entered: ";
            cin >> round_fareamount;
        }
    }
    return round_fareamount;
}

int carRental()
{
    int car_rentalamount = 0;
    char choice;
    cout << "Is there any amount for any car-rental (Y|N)?: ";
    cin >> choice;
    if(choice == 'y' || choice == 'Y')
    {
        cout << "Please, enter that amount: ";
        cin >> car_rentalamount;
        while(car_rentalamount < 0)
        {
            cout << "Please, make sure a valid amount is entered: ";
            cin >> car_rentalamount;
        }
    }
    else
    {
        car_rentalamount = 0;
    }
    return car_rentalamount;
}

float milesDriven()
{
    float expense = 0.27, final_amount;
    int miles;
    char choice;
    cout << "Was there any private vehicle used (Y|N): ";
    cin >> choice;
    if(choice == 'y' || choice == 'Y')
    {
        cout << "How many miles were driven: ";
        cin >> miles;
        while(miles < 0)
        {
            cout << "Error, please make sure a number greater than 0 is entered: ";
            cin >> miles;
        }
        final_amount = expense * miles;
    }
    else
    {
        final_amount = 0;
    }
    return final_amount;
}

int conferenceFess()
{
    int extra_fees;
    char choice;
    cout << "Did you attented any conference or seminar (Y|N): ";
    cin >> choice;
    if(choice == 'y' || choice == 'Y')
    {
        cout << "Please, enter the total amount that costed: ";
        cin >> extra_fees;
        while(extra_fees < 0)
        {
            cout << "Error, please make sure a number greater than 0 is entered: ";
            cin >> extra_fees;
        }
    }
    else
    {
        extra_fees = 0;
    }
    return extra_fees;
}


void calculateTotalExpenses(int day)
{
    int total_amount_trip = 0;
    float total_expense_employee = 0;
    int round_trip_expense = roundTrip();
    cout << endl;
    int car_expense = carRental();
    cout << endl;
    float miles_expense = milesDriven();
    cout << endl;
    int extra_expense = conferenceFess();
    cout << endl;
    cout << "Parking Fees: " << endl;
    //Parking Fees
    int total_amount = 0, parking_fees;
    for(int i = 0; i < day; i++)
    {
        cout << "Enter the parking fees for " << i + 1 << " day : ";
        cin >> parking_fees;
        while(parking_fees < 0) 
        {
            cout << "Error, please make sure a valid number is entered: ";
            cin >> parking_fees; 
        }
        if(parking_fees > 6)
        {
            total_amount += parking_fees - 6;
        }
    }
    cout << endl;
    cout << "Taxi Fees: " << endl;
    //taxi fees
    int total_fees = 0, taxi_fees;
    for(int i = 0; i < day; i++)
    {
        cout << "Enter the taxi fees for " << i + 1 << " day : ";
        cin >> taxi_fees;
        while(taxi_fees < 0) 
        {
            cout << "Error, please make sure a valid number is entered: ";
            cin >> taxi_fees; 
        }
        if(taxi_fees > 10)
        {
            total_fees += taxi_fees - 10;
        }
    }
    cout << endl;
    cout << "Hotel Room Expense: " << endl;
    //hotel expense
    int total_expense = 0, hotel_expense;
    for(int i = 0; i < day; i++)
    {
        cout << "Enter the room fees for " << i + 1 << " : ";
        cin >> hotel_expense;
        while(hotel_expense < 0) 
        {
            cout << "Error, please make sure a valid number is entered: ";
            cin >> hotel_expense; 
        }
        if(hotel_expense > 90)
        {
            total_expense += hotel_expense - 90;
        }
    }
    cout << endl;
    cout << "Meal Cost Per day: " << endl;
    //meal cost
    int total_meal = 0;
    int lunch = 0, dinner = 0, breakfast = 0;
    for(int i = 0; i < day; i++)
    {
        cout << "Enter the cost for breakfast: " << i + 1 << " day : ";
        cin >> breakfast;
        while(breakfast < 0) 
        {
            cout << "Error, please make sure a valid number is entered: ";
            cin >> breakfast;
        }
        if(breakfast > 9)
        {
            total_meal += breakfast - 9;
        }
         cout << "Enter the cost for lunch: " << i + 1 << " day : ";
        cin >> lunch;
        while(lunch < 0) 
        {
            cout << "Error, please make sure a valid number is entered: ";
            cin >> lunch;
        }
        if(lunch > 12)
        {
            total_meal += lunch - 12;
        }
         cout << "Enter the cost for dinner: " << i + 1 << " day : ";
        cin >> dinner;
        while(dinner < 0) 
        {
            cout << "Error, please make sure a valid number is entered: ";
            cin >> dinner;
        }
        if(dinner > 16)
        {
            total_meal += dinner - 16;
        }
        cout << endl;
    }

    total_amount_trip = total_amount + total_fees + total_expense + total_meal;
    total_expense_employee = total_amount_trip + car_expense + round_trip_expense + extra_expense + miles_expense;
    cout << "================EXPENSE REPORT SUMMARY======================" << endl;
    cout << "The total amount spent by Employee: $" << total_expense_employee << endl;
    cout << "Total non-reimbursable (to be paid by the employee): $" << total_amount_trip << endl;
    cout << "Total reimbursable(covered by the company): $" << total_expense_employee - total_amount_trip << endl;
    cout << "============================================================" << endl;

}

void displayReport()
{
    int days = daysSpent();
    displayTripTime();
    cout << endl;
    calculateTotalExpenses(days); 
}

int main()
{
    displayReport();
    return 0;
}