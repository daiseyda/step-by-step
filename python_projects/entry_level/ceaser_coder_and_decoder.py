def is_answer_valid(user_answer):
    while user_answer != 'y' and user_answer != 'n':
        print("\nНекорректное значение, введите 'y' или 'n'.\n")
        user_answer = input()
    if user_answer == 'y':
        return True
    if user_answer == 'n':
        return False


def is_valid_for_alpha(string):
    if string.isalpha():
        return True


def is_valid_for_num(num):
    if num.isdigit():
        return True


def accepting_variables():
    print('\nВведите "1" для шифрования или "2" для дешифрования.\n')
    action = input()
    while not is_valid_for_num(action) or (int(action) != 1 and int(action) != 2):
        print('\nОшибка ввода, пожалуйста, введите "1" для шифрования или "2" для дешифрования.\n')
        action = input()
    action = int(action)
    print('\nВведите "ru", если сообщение на русском языке, или "en", если на английском.\n')
    language = input()
    while not is_valid_for_alpha(language) or (language != 'ru' and language != 'en'):
        print(
            '\nОшибка ввода, пожалуйста, введите "ru", '
            'если сообщение на русском языке, или "en", если на английском.\n')
        language = input()
    if language == 'ru':
        basis = 32
    else:
        basis = 26
    print('\nВведите велечину шага шифра.\n')
    step_size = input()
    while not is_valid_for_num(step_size) or int(step_size) < 0:
        print('\nОшибка ввода, пожалуйста, введите целое число больше или равное 0.\n')
        step_size = input()
    step_size = int(step_size)
    if action == 1:
        print('\nВведите текст для зашифровки.\n')
        text = input()
    else:
        print('\nВведите текст для дешифровки.\n')
        text = input()
    return action, basis, step_size, text


def caesar_cipher(basis, step_size, text):
    if basis == 26:
        for i in range(len(text)):
            if 65 <= ord(text[i]) <= 90:
                if ord(text[i]) + step_size % basis > 90:
                    print(chr(ord(text[i]) - basis + step_size % basis), end='')
                else:
                    print(chr(ord(text[i]) + step_size % basis), end='')
            elif 97 <= ord(text[i]) <= 122:
                if ord(text[i]) + step_size % basis > 122:
                    print(chr(ord(text[i]) - basis + step_size % basis), end='')
                else:
                    print(chr(ord(text[i]) + step_size % basis), end='')
            else:
                print(text[i], end='')
        print()
    else:
        for i in range(len(text)):
            if 1072 <= ord(text[i]) <= 1103:
                if ord(text[i]) + step_size % basis > 1103:
                    print(chr(ord(text[i]) - basis + step_size % basis), end='')
                else:
                    print(chr(ord(text[i]) + step_size % basis), end='')
            elif 1040 <= ord(text[i]) <= 1071:
                if ord(text[i]) + step_size % basis > 1071:
                    print(chr(ord(text[i]) - basis + step_size % basis), end='')
                else:
                    print(chr(ord(text[i]) + step_size % basis), end='')
            else:
                print(text[i], end='')
        print()


def caesar_anti_cipher(basis, step_size, text):
    if basis == 26:
        for i in range(len(text)):
            if 65 <= ord(text[i]) <= 90:
                if ord(text[i]) - step_size % basis < 65:
                    print(chr(ord(text[i]) + basis - step_size % basis), end='')
                else:
                    print(chr(ord(text[i]) - step_size % basis), end='')
            elif 97 <= ord(text[i]) <= 122:
                if ord(text[i]) - step_size % basis < 97:
                    print(chr(ord(text[i]) + basis - step_size % basis), end='')
                else:
                    print(chr(ord(text[i]) - step_size % basis), end='')
            else:
                print(text[i], end='')
        print()
    else:
        for i in range(len(text)):
            if 1072 <= ord(text[i]) <= 1103:
                if ord(text[i]) - step_size % basis < 1072:
                    print(chr(ord(text[i]) + basis - step_size % basis), end='')
                else:
                    print(chr(ord(text[i]) - step_size % basis), end='')
            elif 1040 <= ord(text[i]) <= 1071:
                if ord(text[i]) - step_size % basis < 1040:
                    print(chr(ord(text[i]) + basis - step_size % basis), end='')
                else:
                    print(chr(ord(text[i]) - step_size % basis), end='')
            else:
                print(text[i], end='')
        print()


def main():
    action, basis, step_size, text = accepting_variables()
    if action == 1:
        caesar_cipher(basis, step_size, text)
    else:
        caesar_anti_cipher(basis, step_size, text)
    print('\nЗапустить (де)шифровальщик Цезаря по новой (y/n)?\n')
    users_answer = input()
    if is_answer_valid(users_answer):
        main()
    else:
        print("\nСпасибо, что воспользовались (де)шифровальщиком Цезаря!\n")


print('Добро пожаловать в (де)шифровальщик Цезаря!\n')
main()
