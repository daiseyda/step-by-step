from random import randrange

n = randrange(1, 101)
print('Угадайте число от 1 до 100')
x = int(input())
while x != n:
    if x > n:
        print('Слишком много, попробуйте еще раз')
    if x < n:
        print('Слишком мало, попробуйте еще раз')
    x = int(input())
print('Вы угадали, поздравляем!')
