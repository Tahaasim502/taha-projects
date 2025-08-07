# 💼 Monthly Bank Account Simulator

A simple C++ console-based application that simulates a savings account over a series of months. It tracks deposits, withdrawals, interest earned, and generates a final account summary.

---

## 🛠 Features

- Takes user input for:

- Starting balance

- Annual interest rate

- Number of months since account opening

- Monthly user input for:

- Deposits (validates non-negative)

- Withdrawals (validates non-negative)

- Calculates monthly interest based on balance

- Automatically ends simulation if balance goes below 0

- Provides a full account summary at the end

---

## 📦 What You’ll Learn

- Input validation in C++

- Use of loops (for, do-while)

- Boolean flags for control flow

- Arithmetic and financial calculations

- Interest compounding logic

- Output formatting with iomanip

---

# 📸 Demo Snapshot:

💼 How many months have passed since the opening of account?: 2

💰 Enter the starting balance of the account: $1000

📈 Enter the interest rate: 5

====Month 1 =====

Enter deposit amount: $100

Enter widthdrawal amount: $50

Interest earned this month 4.375


====Month 2 =====

Enter deposit amount: $150

Enter widthdrawal amount: $20

Interest earned this month 4.9349



================= ACCOUNT SUMMARY =====================

Final Balance     :$1189.31

Total Interest    :$9.30989

Total Deposit     :$250

Total Widthdrawal :$70

=========================================================
