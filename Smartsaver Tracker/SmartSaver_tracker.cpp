#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    float balance = 0, interest_rate = 0, widthdrawal = 0, deposit = 0, monthly_interest = 0;
    float total_deposit = 0, total_widthdrawal = 0, total_interest = 0;
    int months;

    cout << "💼 How many months have passed since the opening of account?: ";
    cin >> months;

    cout << "💰 Enter the starting balance of the account: $";
    cin >> balance;

    cout << "📈 Enter the interest rate: ";
    cin >> interest_rate;

    monthly_interest = interest_rate / 12 / 100;


    for(int i = 0; i < months; i++)
    {
        bool dflag = false;
        bool wflag = false;

        cout << "\n====Month " << i + 1 << " =====\n";

        do
        {
            cout << "Enter deposit amount: $";
            cin >> deposit;

            if(deposit < 0)
            {
                cout << "Error: Deposit cannot be negative. ";
            }
            else 
            {
                dflag = true;
                total_deposit+=deposit;
                balance += deposit;
            }
        } while (!dflag);
        
        do
        {
            cout << "Enter widthdrawal amount: $";
            cin >> widthdrawal;
            if(widthdrawal < 0)
            {
                cout << "Error: Widthdrawal cannot be negative. ";
            }
            else if(widthdrawal > balance)
            {
                cout << "Error: Withdrawl exceeds current balance." << endl;
                continue;
            }
            else 
            {
                wflag = true;
                total_widthdrawal+= widthdrawal;
                balance-= widthdrawal;
            }
        } while (!wflag);


        if(balance < 0)
        {
            cout << "Account has been closed due to insufficient funds" << endl;
            break;
        }
        
        double interest = balance * monthly_interest;
        balance+=interest;
        total_interest+=interest;

        cout << "Interest earned this month " << interest << endl; 
        cout << endl;
    }
    cout << endl;
    cout << "\n================= ACCOUNT SUMMARY =====================\n";
    cout << "Final Balance     :$" << balance << endl;
    cout << "Total Interest    :$" << total_interest << endl;
    cout << "Total Deposit     :$" << total_deposit << endl;
    cout << "Total Widthdrawal :$" << total_widthdrawal << endl;
    cout << "=========================================================\n";
    return 0;
}