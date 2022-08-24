def is_answer_valid(user_answer):
    while user_answer != 'y' and user_answer != 'n':
        print("\nНекорректное значение, введите 'y' или 'n'.\n")
        user_answer = input()
    if user_answer == 'y':
        return True
    if user_answer == 'n':
        return False


def is_valid_for_num(num):
    if num.isdigit():
        return True


def is_valid_based_on_initial_notation(num, initial_notation):
    if initial_notation != 16:
        if num.isdigit():
            num = int(num)
            while num:
                if num % 10 >= initial_notation:
                    return False
                num //= 10
            else:
                return True
        else:
            return False
    else:
        for i in range(len(num)):
            if num[i] not in '0123456789ABCDEF':
                return False
        else:
            return True


def transfer_to_decimal_number_system(initial_notation, num):
    qty_of_digits = len(num)
    rez = 0
    if initial_notation != 16:
        num = int(num)
        for i in range(qty_of_digits):
            rez += num % 10 * initial_notation ** i
            num //= 10
    else:
        j = 0
        i = qty_of_digits - 1
        while i >= 0:
            if num[i].isdigit():
                rez += int(num[i]) * initial_notation ** j
            else:
                rez += (ord(num[i]) - 55) * initial_notation ** j
            i -= 1
            j += 1
    return rez


def transfer_to_new_number_system(final_notation, num):
    rez = []
    if final_notation != 16:
        while num >= final_notation:
            rez.insert(0, num % final_notation)
            num //= final_notation
        rez.insert(0, num)
    else:
        while num >= final_notation:
            if 15 >= num % final_notation >= 10:
                rez.insert(0, chr(num % final_notation + 55))
            else:
                rez.insert(0, num % final_notation)
            num //= final_notation
        rez.insert(0, num)
    return ''.join(map(str, rez))


def accepting_variables():
    print('\nВведите основание текущей системы счисления числа (от 1 до 60).\n')
    initial_notation = input()
    while not is_valid_for_num(initial_notation) or int(initial_notation) < 1 or int(initial_notation) > 60:
        print('\nОшибка ввода, пожалуйста, введите натуральное число от 1 до 60.\n')
        initial_notation = input()
    initial_notation = int(initial_notation)
    print('\nВведите основание системы счисления, в которую необходимо перевести число (от 1 до 60).\n')
    final_notation = input()
    while not is_valid_for_num(final_notation) or int(final_notation) < 1 or int(final_notation) > 60:
        print('\nОшибка ввода, пожалуйста, введите натуральное число от 1 до 60.\n')
        final_notation = input()
    final_notation = int(final_notation)
    print('\nВведите число для перевода.\n')
    num = input()
    while not is_valid_based_on_initial_notation(num, initial_notation):
        print(
            f'\nОшибка ввода, пожалуйста, введите число в ситсеме счисления '
            f'по указанному основанию {initial_notation}.\n')
        num = input()
    return initial_notation, final_notation, num


def main():
    initial_notation, final_notation, num = accepting_variables()
    num = transfer_to_decimal_number_system(initial_notation, num)
    print("\nРезультат:", transfer_to_new_number_system(final_notation, num))
    print('\nЗапустить калькулятор систем счисления по новой (y/n)?\n')
    users_answer = input()
    if is_answer_valid(users_answer):
        main()
    else:
        print("\nСпасибо, что воспользовались калькулятором систем счисления!\n")


print('Добро пожаловать в калькулятор систем счисления!\n')
main()
