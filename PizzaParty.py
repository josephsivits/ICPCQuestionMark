c = int(input())

pizza = []

for i in range(c):
    order = [x for x in input().split()]

    if len(order) == 1:
        if order[0] not in pizza:
            pizza.append(order[0])
    
print(len(pizza))