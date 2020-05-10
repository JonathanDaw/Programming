annual_salary = float(input("Enter the starting salary: "))
portion_saved = float(input("Enter the percent of your salary to save, as a decimal: "))

goal_months = 36
semi_annual_salary = .07
total_cost = 1000000
monthly_salary = annual_salary/12
portion_down_payment = .25
down_payment = portion_down_payment * total_cost
current_savings = 0.0
r = .04  # annual return
months = 0.0

while current_savings < down_payment:
    current_savings = current_savings + (monthly_salary * portion_saved) + ((current_savings * r) / 12)
    months += 1
    if months % 6 == 0:
        annual_salary += annual_salary * semi_annual_salary
        monthly_salary = annual_salary/12

print("Number of months: ", int(months))
print("Best savings rate: ")
print("Steps in bisection search: ")
