import csv

students = []

with open("students.csv") as file:
    reader = csv.reader(file)
    for name, home in reader:
        students.append({"name": name, "home": home})


for student in sorted(students, key=lambda student: student["name"]):  #key=lambda(anonymous function) student(this function is called in everone of the students(dictionaries) in that list) 
    print(f"{student['name']} is in {student['home']}")               #student:name(i want to recall given a "student" i want to index into that dictionary and access their "name")