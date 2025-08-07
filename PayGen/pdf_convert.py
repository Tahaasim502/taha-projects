from fpdf import FPDF


#create the PDF
pdf = FPDF(orientation='P', format='A4')
pdf.set_auto_page_break(auto=True, margin=15)
pdf.add_page()

#Add a header
pdf.set_font("Arial", 'B', 16)
pdf.cell(0, 10, 'EMPLOYEES PAYROLL REPORT', ln=True, align='C')
pdf.set_font("Arial", "", 10)
pdf.ln(10)

#Read and write the data
pdf.set_font("Courier", size=10)
with open('employee_report.txt', 'r', encoding="utf-8") as file: 
    for line in file:
        line = line.strip()
        if line == "==":
            pdf.ln(5)
            pdf.cell(0, 5, "-" * 50, ln = True)
            pdf.ln(5)
        elif line:
            pdf.cell(0, 5, line, ln=True)
            if(line.startswith("FICA Withholdings:")):
                pdf.ln(5)  # Add extra space after Employee ID
         
pdf.output('employee_payroll_report.pdf')
