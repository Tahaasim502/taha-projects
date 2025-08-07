#ifndef EMPLOYEE_HH
#define EMPLOYEE_HH
#include<iostream>
#include<iomanip>
using namespace std;
class Employee {
    private:
        int emp_number;
        double gross_pay, state_tax, federal_tax, FICA;
    public:
        Employee(int empNumb, double gpay, double stateTax, double fTax, double fica)
        {
            emp_number = empNumb;
            gross_pay = gpay;
            state_tax = stateTax;
            federal_tax = fTax;
            FICA = fica;
        }
        int getEmpNumb()
        {
            return emp_number;
        }
        double getGpay()
        {
            return gross_pay;
        }
        double getStateTax()
        {
            return state_tax;
        }
        double getFederalTax()
        {
            return federal_tax;
        }
        double getFICA()
        {
            return FICA;
        }
        double getNetpay()
        {
            return gross_pay - (state_tax + federal_tax + FICA);
        }
        void display()
        {
            int r1 = getEmpNumb();
            double r2 = getGpay(), r3 = getStateTax(), r4 = getFederalTax(), r5 = getFICA(), r6 = getNetpay();
            cout << fixed << setprecision(2) << endl;
            cout << "Employee Number: " << r1 << endl;
            cout << "Gross Pay: $" << r2 << endl;
            cout << "State tax: $" << r3 << endl;
            cout << "Federal tax: $" << r4 << endl;
            cout << "FICA Holdings: $" << r5 << endl;
            cout << "Net Pay: $" << r6 << endl;
        }
};
#endif