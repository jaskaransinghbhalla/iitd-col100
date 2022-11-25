import os
import sys

for i in range(1,1001):
    os.system(f"./a.out < input_{i}.txt > testout_{i}.txt")
    with open(os.path.join(sys.path[0], f"output_{i}.txt" ), "r") as f :
        lines = f.readlines()

    with open(os.path.join(sys.path[0], f"testout_{i}.txt" ), "r")as f :
        lines_check = f.readlines()

    if(len(lines) == len(lines_check)):
        print("Lines match")
        counter = len(lines)
    else:
        print("Lines donot match")
        exit()

    condition = 1
    lines_with_error = []
    for c in range(counter):
        if(lines[c] == lines_check[c]):
            continue
        else:
            lines_with_error.append(c)
            condition = 0

    if(condition == 1):
        print("Congrats ",i," testcase passed")
    else:
        print(i," Testcase failed")
        for i in range(len(lines_with_error)):
            print(lines_with_error)

