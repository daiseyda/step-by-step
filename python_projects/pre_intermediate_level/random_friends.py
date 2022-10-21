import random

list_of_friends = [input() for i in range(int(input()))]  # на вход поступает ФИ людей, из которых необходимо сделать
new_d = {}                                                # рандомные пары по принципу тайного Санты
for i in list_of_friends:
    new_list_of_friends = list_of_friends[:]              # новый лист нужен для более быстрой проверки 
    new_list_of_friends.remove(i)
    x = random.choice(list_of_friends)
    while x in new_d.values() and len(new_list_of_friends) != 0:
        x = random.choice(new_list_of_friends)
        if x in new_d.values():
            new_list_of_friends.remove(x)
    new_d[i] = x
for i in new_d:
    print(i, '-', new_d[i])
