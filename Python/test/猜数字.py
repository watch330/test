import random
flag = 0
count = 3
while 1:
    if count == 0:
        break
    if flag == 1:
        num = random.randint(1, 10)
        flag = 0
    num = random.randint(1, 10)
    while flag == 0:
        temp = input("请输入一个数字来猜测我在想什么数字!")
        guess = int(temp)
        if guess < num:
            print("小了")
            continue
        if guess > num:
            print("大了")
            continue
        if guess == num:
            print("猜对了")
            flag = 1
            count -= 1
    continue
