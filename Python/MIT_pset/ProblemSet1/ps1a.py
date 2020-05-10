annual_salary = float(input("Enter your annual salary: "))
portion_saved = float(input("Enter the percent of your salary to save, as a decimal: "))
total_cost = float(input("Enter the cost of your dream home: "))
semi_annual_salary = float(input("Enter the semi-annual raise, as a decimal: "))

monthly_salary = annual_salary/12
portion_down_payment = .25
down_payment = portion_down_payment * total_cost
current_savings = 0.0
r = .04  # annual return
months = 0.0

while current_savings < down_payment:
    current_savings = current_savings + (monthly_salary * portion_saved) + ((current_savings * r) / 12)
    months = months + 1

print("Number of months: ", int(months))
