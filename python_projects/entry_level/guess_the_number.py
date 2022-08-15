from random import randrange


def in_range(num, right_limit):
    if num in range(1, right_limit + 1):
        return True


def is_valid(num):
    if num.isdigit():
        return True


def guess_the_number():
    attempt_counter = 1
    print('Добро пожаловать в "Угадай число"!\n\nПожалуйста, введите велечину правой границы интервала, '
          'значение должно быть больше 1.')
    right_limit = input()
    while not right_limit.isdigit() or int(right_limit) < 2:
        print('Некорректное значение, введите натуральное число больше 1.')
        right_limit = input()
    random_num = randrange(1, int(right_limit) + 1)
    print(f'Угадайте число от 1 до {right_limit}.')
    users_num = input()
    while users_num != random_num:
        if is_valid(users_num) and in_range(int(users_num), int(right_limit)):
            users_num = int(users_num)
            if users_num > random_num:
                attempt_counter += 1
                print('Слишком много, попробуйте еще раз.')
            if users_num < random_num:
                attempt_counter += 1
                print('Слишком мало, попробуйте еще раз.')
            if users_num == random_num:
                print(f'Вы угадали, поздравляем!\n\nКол-во попыток: {attempt_counter}\n')
                break
        else:
            print(f'Некорректное значение, введите натуральное число от 1 до {right_limit}.')
        users_num = input()
    print('Спасибо, что играли в числовую угадайку. Сыграем еще раз? (Введите y/n).')
    restart = input()
    while restart != 'y' and restart != 'n':
        print("Некорректное значение, введите 'y' или 'n'.")
        restart = input()
    if restart == 'y':
        guess_the_number()
    if restart == 'n':
        print('Увидемся в следующий раз!')


guess_the_number()
