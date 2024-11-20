val = int(input())
answer = 0

for i in range(val - 1):
    # print(i)
    if(i % 2 == 1):
        answer = answer * 2 - 1;
    else:
        answer = answer * 2 + 1;
print(answer);