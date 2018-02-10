while True:
    grade = int(input("please enter your grade(1-100) or enter -1 to quit:"))
    if grade == -1:
        break
    if grade > 100 or grade < 0:
        print("Error!")
    elif grade >= 90:
        print("A")
    elif grade >= 80:
        print("B")
    elif grade >= 60:
        print("C")
    elif grade >= 0:
        print("D")
