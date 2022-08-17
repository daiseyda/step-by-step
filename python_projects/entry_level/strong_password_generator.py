from random import sample, shuffle, choice


def pass_generate(required_characters_list, del_characters_list, pass_length):  # функция генерации пароля
    digits = '0123456789'
    lowercase_letters = 'abcdefghijklmnopqrstuvwxyz'
    uppercase_letters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    punctuation = '!#$%&*+-=?@^_.'
    for i in range(len(del_characters_list)):
        digits = digits.replace(del_characters_list[i], '')
        lowercase_letters = lowercase_letters.replace(del_characters_list[i], '')
        uppercase_letters = uppercase_letters.replace(del_characters_list[i], '')
        punctuation = punctuation.replace(del_characters_list[i], '')
    chars = digits + lowercase_letters + uppercase_letters + punctuation
    new_pass = list(required_characters_list) + [choice(digits)] + [choice(lowercase_letters)] + [
        choice(uppercase_letters)] + [choice(punctuation)]
    if len(new_pass) < pass_length:
        new_pass += sample(chars, pass_length - len(new_pass))
    shuffle(new_pass)
    print(''.join(new_pass))


def symbols_string_list_creation(symbols_string):  # функция зоздания списка символов ввиде строки
    new_string_list = ''
    for i in range(len(symbols_string)):
        if symbols_string[i] not in new_string_list and symbols_string[i] != ' ':
            new_string_list += symbols_string[i]
    return new_string_list


def is_answer_valid(user_answer):
    while user_answer != 'y' and user_answer != 'n':
        print("\nНекорректное значение, введите 'y' или 'n'.\n")
        user_answer = input()
    if user_answer == 'y':
        return True
    if user_answer == 'n':
        return False


def is_valid(num):
    if num.isdigit():
        return True


print('Приветствуем в генераторе сложных паролей!\n\nСколько паролей необходимо будет сгенерировать?\n')
pass_quantity = input()
while not is_valid(pass_quantity) or int(pass_quantity) < 1:
    print('\nНекорректное значение, введите натуральное число больше 0.\n')
    pass_quantity = input()
pass_quantity = int(pass_quantity)
print('\nВведите длину паролей (длина должна быть не менее 8 и не более 16 символов).\n')
pass_length = input()
while not is_valid(pass_length) or int(pass_length) < 8 or int(pass_length) > 16:
    print('\nНекорректное значение, введите натуральное число в пределах от 8 до 16.\n')
    pass_length = input()
pass_length = int(pass_length)
print(
    f'\nВы можете добавить символы, которые будут включены во все пароли (для пропуска нажмите ввод). '
    f'Для данного размера пароля можно добавить {pass_length - 4} символа.\n')
required_characters = input()
required_characters_list = symbols_string_list_creation(required_characters)
while len(required_characters_list) > pass_length - 4:
    print(
        f"\nКол-во обязательных символов превышает {pass_length - 4}! Пожалуйста, "
        f"введите не более {pass_length - 4} символов.\n")
    required_characters = input()
    required_characters_list = symbols_string_list_creation(required_characters)
print('\nСимволы, которые будут добавлены в пароли:', *required_characters_list)
print('\nКакие символы исключить из паролей?\n')
del_characters = input()
del_characters_list_new = del_characters_list = symbols_string_list_creation(del_characters)
for i in range(len(del_characters_list)):
    if del_characters_list[i] in required_characters_list:
        print(
            f'\nВведенный символ "{del_characters_list[i]}" находится в списке обязательных к добавлению в пароли. '
            f'Его действительно необходимо удалить (y/n)?\n')
        user_answer = input()
        if is_answer_valid(user_answer):
            required_characters_list = required_characters_list.replace(del_characters_list[i], '')
        else:
            del_characters_list_new = del_characters_list_new.replace(del_characters_list[i], '')
print('\nСимволы, которые не будут добавлены в пароли:', *del_characters_list_new, '\n')
print('\nСписок паролей:\n')
for i in range(pass_quantity):
    pass_generate(required_characters_list, del_characters_list_new, pass_length)
