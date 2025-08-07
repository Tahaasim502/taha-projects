#include "Employee.hh"
#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>  
using namespace std;

double getValidInput(string const &prompt, double max = -1.0)
{
    double value;
    while(true)
    {
        cout << prompt;
        cin >> value;
        if(cin.fail())
        {
            cout << "Invalid Input: Non-numeric data entered. \n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        
        bool isvalid = value >= 0;
        if(max >= 0)
        {
            isvalid = isvalid && (value <= max);
        }

        if(isvalid)
        {
            return value;
        }
        
        cout << "Error detected! Must be ";
        if(max >= 0)
        {
            cout << "between $0 and $" << max << endl;
        }
        else
        {
            cout << "a positive number" << endl;
        }
        cout << "Try again" << endl;
    }
}

void writeToFile(ofstream &file, const string &msg, const string &text)
{
    if(file.is_open())
    {
        file << fixed << setprecision(2);
        file << msg << text << endl;
    }
    else 
    {
        cout << "Error writing to the file" << endl;
    }
}

string formatCurrency(double value)
{
    ostringstream oss;
    oss << fixed << setprecision(2) << value;
    return oss.str();
}

int main()
{
    vector<Employee> employees;
    double totalGpay = 0, totalStateTax = 0, totalFederalTax = 0, totalFICA = 0, totalNetPay = 0;
    ofstream file("employee_report.txt");

    if(!file.is_open())
    {
        cout << "Error, cannot open the file";
        return 1;   
    }
    
    file << "=======EMPLOYEES PAYROLL REPORT=======" << endl;
    while(true) 
    {
        int empNum;
        double gpay, stax, ftax, fica; 
        cout << "Enter Employee Number(0 to stop): ";
        cin >> empNum;

        while (empNum < 0)
        {
            cout << "Employee Number cannot be negative" << endl;
            cin >> empNum;
        }

        if(empNum == 0)
        {
            break;
        }
        
        gpay = getValidInput("Enter Gross Pay: $");
        stax = getValidInput("Enter State Tax: $", gpay);
        ftax = getValidInput("Enter Federal Tax: $", gpay);
        fica = getValidInput("Enter FICA Withholdings: $", gpay);
        
       
        writeToFile(file, "Employee ID: ", to_string(empNum));
        writeToFile(file, "Gross Pay: $", formatCurrency(gpay));
        writeToFile(file, "State Tax: $", formatCurrency(stax));
        writeToFile(file, "Federal Tax: $", formatCurrency(ftax));
        writeToFile(file, "FICA Withholdings: $", formatCurrency(fica));
        file << endl;

        Employee Employee(empNum, gpay, stax, ftax, fica);
        employees.push_back(Employee);

        totalGpay += gpay;
        totalStateTax += stax;
        totalFederalTax += ftax;
        totalFICA += fica;
        totalNetPay += gpay - (stax + ftax + fica);
    }
    
    file.close();
    
    if(employees.empty())
    {
        cout << "No employees were entered. Exiting";
        return 0;
    }


    cout << "\n===== PAY ROLL REPORT ======\n";
    for(auto &employee : employees)
    {
        employee.display();
    }
    cout << "\n============================\n";

    cout << setw(25) << left << "Total Gross Pay:" << "$" << totalGpay << endl; 
    cout << setw(25) << left << "Total State Tax:" << "$" << totalStateTax << endl;
    cout << setw(25) << left << "Total Federal Tax:" << "$" << totalFederalTax << endl;
    cout << setw(25) << left << "Total FICA WithHoldings:" << "$" << totalFICA << endl;
    cout << setw(25) << left << "Total Net Pay:" << "$" << totalNetPay << endl;
    
    ofstream file2("payroll_summary.txt");
    
    if(!file2.is_open())
    {
        cout << "Error, cannot open the total pay file" << endl;
        return 1;
    }

    file2 << "=======SUMMARY OF PAYROLL TOTALS =======" << endl;
    writeToFile(file2, "Total Gross Pay: $", formatCurrency(totalGpay));
    writeToFile(file2, "Total State Tax: $", formatCurrency(totalStateTax));
    writeToFile(file2, "Total Federal Tax: $", formatCurrency(totalFederalTax));
    writeToFile(file2, "Total FICA Withholdings: $", formatCurrency(totalFICA));
    writeToFile(file2, "Total Net Pay: $", formatCurrency(totalNetPay));
    file2.close();

    return 0;
}