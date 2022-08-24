from random import choice


def word_choice():
    word_rus = ['год', 'человек', 'время', 'дело', 'жизнь', 'день', 'рука', 'раз', 'работа', 'слово', 'место', 'лицо',
                'друг', 'глаз', 'вопрос', 'дом', 'сторона', 'страна', 'мир', 'случай', 'голова', 'ребенок', 'сила',
                'конец',
                'вид', 'система', 'часть', 'город', 'отношение', 'женщина', 'деньги', 'земля', 'машина', 'вода', 'отец',
                'проблема', 'час', 'право', 'нога', 'решение', 'дверь', 'образ', 'история', 'власть', 'закон', 'война',
                'бог', 'голос', 'тысяча', 'книга', 'возможность', 'результат', 'ночь', 'стол', 'имя', 'область',
                'статья',
                'число', 'компания', 'народ', 'жена', 'группа', 'развитие', 'процесс', 'суд', 'условие', 'средство',
                'начало', 'свет', 'пора', 'путь', 'душа', 'уровень', 'форма', 'связь', 'минута', 'улица', 'вечер',
                'качество', 'мысль', 'дорога', 'мать', 'действие', 'месяц', 'государство', 'язык', 'любовь', 'взгляд',
                'мама', 'век', 'школа', 'цель', 'общество', 'деятельность', 'организация', 'президент', 'комната',
                'порядок', 'момент', 'театр', 'письмо', 'утро', 'помощь', 'ситуация', 'роль', 'рубль', 'смысл',
                'состояние',
                'квартира', 'орган', 'внимание', 'тело', 'труд', 'сын', 'мера', 'смерть', 'рынок', 'программа',
                'задача',
                'предприятие', 'окно', 'разговор', 'правительство', 'семья', 'производство', 'информация', 'положение',
                'центр', 'ответ', 'муж', 'автор', 'стена', 'интерес', 'федерация', 'правило', 'управление', 'мужчина',
                'идея', 'партия', 'совет', 'счет', 'сердце', 'движение', 'вещь', 'материал', 'неделя', 'чувство',
                'глава',
                'наука', 'ряд', 'газета', 'причина', 'плечо', 'цена', 'план', 'речь', 'точка', 'основа', 'товарищ',
                'культура', 'данные', 'мнение', 'документ', 'институт', 'ход', 'проект', 'встреча', 'директор', 'срок',
                'палец', 'опыт', 'служба', 'судьба', 'девушка', 'очередь', 'лес', 'состав', 'член', 'количество',
                'событие',
                'объект', 'зал', 'создание', 'значение', 'период', 'шаг', 'брат', 'искусство', 'структура', 'номер',
                'пример', 'исследование', 'гражданин', 'игра', 'начальник', 'рост', 'тема', 'принцип', 'метод', 'тип',
                'фильм', 'край', 'гость', 'воздух', 'характер', 'борьба', 'использование', 'размер', 'образование',
                'мальчик', 'кровь', 'район', 'небо', 'армия', 'класс', 'представитель', 'участие', 'девочка',
                'политика',
                'герой', 'картина', 'доллар', 'спина', 'территория', 'пол', 'поле', 'изменение', 'направление',
                'рисунок',
                'течение', 'церковь', 'банк', 'сцена', 'население', 'большинство', 'музыка', 'правда', 'свобода',
                'память',
                'команда', 'союз', 'врач', 'договор', 'дерево', 'факт', 'хозяин', 'природа', 'угол', 'телефон',
                'позиция',
                'двор', 'писатель', 'самолет', 'объем', 'род', 'солнце', 'вера', 'берег', 'спектакль', 'фирма',
                'способ',
                'завод', 'цвет', 'журнал', 'руководитель', 'специалист', 'оценка', 'регион', 'песня', 'процент',
                'родитель',
                'море', 'требование', 'основание', 'половина', 'роман', 'круг', 'анализ', 'стихи', 'автомобиль',
                'экономика', 'литература', 'бумага', 'поэт', 'степень', 'господин', 'надежда', 'предмет', 'вариант',
                'министр', 'граница', 'дух', 'модель', 'операция', 'пара', 'сон', 'название', 'ум', 'повод', 'старик',
                'миллион', 'успех', 'счастье', 'ребята', 'кабинет', 'магазин', 'пространство', 'выход', 'удар', 'база',
                'знание', 'текст', 'защита', 'руководство', 'площадь', 'сознание', 'возраст', 'участник', 'участок',
                'пункт', 'линия', 'желание', 'папа', 'доктор', 'губа', 'дочь', 'среда', 'председатель', 'представление',
                'солдат', 'художник', 'волос', 'оружие', 'соответствие', 'ветер', 'парень', 'зрение', 'генерал',
                'огонь',
                'понятие', 'строительство', 'ухо', 'грудь', 'нос', 'страх', 'услуга', 'содержание', 'радость',
                'безопасность', 'продукт', 'комплекс', 'бизнес', 'сад', 'сотрудник', 'лето', 'курс', 'предложение',
                'рот',
                'технология', 'реформа', 'отсутствие', 'собака', 'камень', 'будущее', 'рассказ', 'контроль', 'река',
                'продукция', 'сумма', 'техника', 'здание', 'сфера', 'необходимость', 'фонд', 'подготовка', 'лист',
                'республика', 'хозяйство', 'воля', 'бюджет', 'снег', 'деревня', 'мужик', 'элемент', 'обстоятельство',
                'немец', 'победа', 'источник', 'звезда', 'выбор', 'масса', 'итог', 'сестра', 'практика', 'проведение',
                'карман', 'слава', 'кухня', 'определение', 'функция', 'войско', 'комиссия', 'применение', 'капитан',
                'работник', 'обеспечение', 'офицер', 'фамилия', 'предел', 'выборы', 'ученый', 'бутылка', 'бой',
                'теория',
                'зона', 'отдел', 'зуб', 'разработка', 'личность', 'гора', 'товар', 'метр', 'праздник', 'влияние',
                'читатель', 'удовольствие', 'актер', 'слеза', 'ответственность', 'учитель', 'акт', 'боль', 'множество',
                'особенность', 'показатель', 'корабль', 'звук', 'впечатление', 'частность', 'детство', 'вывод',
                'профессор',
                'доля', 'норма', 'прошлое', 'командир', 'коридор', 'поддержка', 'рамка', 'враг', 'этап', 'черт', 'дед',
                'собрание', 'прием', 'болезнь', 'клетка', 'кожа', 'заявление', 'попытка', 'сравнение', 'расчет',
                'депутат',
                'комитет', 'знак', 'дядя', 'учет', 'хлеб', 'чай', 'режим', 'целое', 'вирус', 'выражение', 'здоровье',
                'зима', 'десяток', 'глубина', 'сеть', 'студент', 'секунда', 'скорость', 'поиск', 'суть', 'налог',
                'ошибка',
                'доход', 'режиссер', 'поверхность', 'ощущение', 'карта', 'клуб', 'станция', 'революция', 'колено',
                'министерство', 'стекло', 'этаж', 'высота', 'бабушка', 'трубка', 'газ', 'мастер', 'поведение',
                'столица',
                'механизм', 'передача', 'способность', 'подход', 'энергия', 'существование', 'исполнение', 'кино',
                'сожаление', 'заместитель', 'ресурс', 'акция', 'рождение', 'администрация', 'стоимость', 'улыбка',
                'артист',
                'сосед', 'фраза', 'фигура', 'субъект', 'реакция', 'список', 'фотография', 'журналист', 'май',
                'нарушение',
                'заседание', 'толпа', 'больница', 'существо', 'свойство', 'долг', 'поколение', 'животное', 'схема',
                'усилие', 'отличие', 'остров', 'противник', 'волна', 'реализация', 'страница', 'формирование', 'житель',
                'красота', 'птица', 'растение', 'тень', 'явление', 'храм', 'запах', 'водка', 'наличие', 'ужас',
                'одежда',
                'кресло', 'больной', 'поезд', 'университет', 'традиция', 'адрес', 'декабрь', 'ладонь', 'сведение',
                'цветок',
                'лидер', 'октябрь', 'занятие', 'сентябрь', 'помещение', 'январь', 'зритель', 'редакция', 'стиль',
                'весна',
                'фактор', 'август', 'известие', 'зависимость', 'охрана', 'оборудование', 'концерт', 'отделение',
                'расход',
                'выставка', 'милиция', 'переход', 'эпоха', 'запад', 'произведение', 'родина', 'собственность', 'тайна',
                'трава', 'лагерь', 'имущество', 'кровать', 'аппарат', 'середина', 'март', 'клиент', 'дама', 'фронт',
                'отрасль', 'стул', 'беседа', 'законодательство', 'продажа', 'повышение', 'музей', 'след', 'полковник',
                'сомнение', 'понимание', 'апрель', 'князь', 'рыба', 'дума', 'кодекс', 'сутки', 'чудо', 'шея', 'судья',
                'крыша', 'настроение', 'поток', 'должность', 'преступление', 'мозг', 'честь', 'пост', 'еврей', 'июнь',
                'сотня', 'дождь', 'лестница', 'дача', 'установка', 'появление', 'получение', 'образец', 'труба',
                'главное',
                'осень', 'костюм', 'баба', 'ценность', 'обязанность', 'пьеса', 'таблица', 'вино', 'воспоминание',
                'лошадь',
                'коллега', 'организм', 'ученик', 'учреждение', 'открытие', 'том', 'черта', 'характеристика',
                'выполнение',
                'оборона', 'выступление', 'температура', 'перспектива', 'подруга', 'приказ', 'жертва', 'ресторан',
                'километр', 'спор', 'вкус', 'признак', 'промышленность', 'американец', 'лоб', 'заключение', 'восток',
                'исключение', 'ключ', 'постановление', 'слой', 'бок', 'июль', 'перевод', 'секретарь', 'кусок', 'слух',
                'польза', 'звонок', 'обстановка', 'чиновник', 'соглашение', 'деталь', 'русский', 'тишина', 'зарплата',
                'билет', 'подарок', 'тюрьма', 'ящик', 'конкурс', 'книжка', 'изучение', 'просьба', 'царь', 'публика',
                'смех',
                'сообщение', 'угроза', 'беда', 'блок', 'достижение', 'назначение', 'реклама', 'портрет', 'масло',
                'стакан',
                'урок', 'часы', 'крик', 'творчество', 'телевизор', 'инструмент', 'концепция', 'лейтенант', 'экран',
                'дно',
                'реальность', 'канал', 'мясо', 'знакомый', 'щека', 'конфликт', 'переговоры', 'запись', 'вагон',
                'площадка',
                'последствие', 'сотрудничество', 'зеркало', 'тон', 'академия', 'палата', 'потребность', 'ноябрь',
                'увеличение', 'дурак', 'поездка', 'обед', 'потеря', 'февраль', 'мероприятие', 'парк', 'принятие',
                'устройство', 'вещество', 'категория', 'сезон', 'гостиница', 'издание', 'объединение', 'темнота',
                'человечество', 'колесо', 'опасность', 'разрешение', 'воздействие', 'коллектив', 'камера', 'запас',
                'следствие', 'длина', 'крыло', 'округ', 'фон', 'кандидат', 'родственник', 'давление', 'присутствие',
                'взаимодействие', 'доска', 'партнер', 'двигатель', 'шум', 'достоинство', 'грех', 'нож', 'полет',
                'страсть',
                'испытание', 'истина', 'оплата', 'разница', 'водитель', 'пакет', 'снижение', 'формула', 'живот',
                'капитал',
                'мост', 'новость', 'эффект', 'вход', 'губернатор', 'доклад', 'смена', 'убийство', 'эксперт', 'автобус',
                'платье', 'кадр', 'тетя', 'общение', 'психология', 'лев', 'порог', 'проверка', 'процедура', 'рабочий',
                'ремонт', 'обращение', 'обучение', 'ожидание', 'памятник', 'корень', 'наблюдение', 'буква',
                'доказательство', 'признание', 'постель', 'штаб', 'владелец', 'компьютер', 'инженер', 'старуха',
                'лодка',
                'ракета', 'серия', 'шутка', 'вершина', 'выпуск', 'кулак', 'лед', 'торговля', 'нефть', 'молодежь',
                'цифра',
                'корпус', 'недостаток', 'сапог', 'сущность', 'талант', 'эффективность', 'кофе', 'полоса', 'основное',
                'рассмотрение', 'сбор', 'штат', 'следователь', 'жилье', 'мешок', 'описание', 'куст', 'отказ', 'замок',
                'редактор', 'дворец', 'забота', 'пиво', 'диван', 'столик', 'эксперимент', 'печать', 'кольцо',
                'пистолет',
                'воспитание', 'начальство', 'профессия', 'ворота', 'добро', 'дружба', 'покой', 'риск', 'окончание',
                'дым',
                'брак', 'величина', 'записка', 'инициатива', 'совесть', 'активность', 'кость', 'спорт', 'кредит',
                'господь',
                'майор', 'конференция', 'потолок', 'библиотека', 'помощник', 'конструкция', 'отдых', 'ручка', 'металл',
                'молоко', 'прокурор', 'транспорт', 'поэзия', 'соединение', 'краска', 'расстояние', 'мечта', 'село',
                'еда',
                'зло', 'подразделение', 'сюжет', 'рубеж', 'сигнал', 'атмосфера', 'крест', 'вес', 'взрыв', 'контакт',
                'сигарета', 'восторг', 'золото', 'почва', 'премия', 'король', 'подъезд', 'шанс', 'автомат', 'заказ',
                'мальчишка', 'очки', 'миг', 'штука', 'чтение', 'поселок', 'свидетель', 'ставка', 'сумка', 'удивление',
                'хвост', 'песок', 'поворот', 'возвращение', 'мгновение', 'статус', 'озеро', 'строй', 'параметр',
                'сказка',
                'тенденция', 'вина', 'дыхание', 'версия', 'масштаб', 'монастырь', 'хозяйка', 'дочка', 'танец',
                'эксплуатация', 'коммунист', 'пенсия', 'приятель', 'объяснение', 'набор', 'производитель', 'пыль',
                'философия', 'мощность', 'обязательство', 'уход', 'горло', 'кризис', 'указание', 'плата', 'яблоко',
                'препарат', 'действительность', 'москвич', 'остаток', 'изображение', 'сделка', 'сочинение',
                'покупатель', 'танк', 'затрата', 'строка', 'единица']
    return choice(word_rus)


def is_answer_valid(user_answer):
    while user_answer != 'y' and user_answer != 'n':
        print("\nНекорректное значение, введите 'y' или 'n'.\n")
        user_answer = input()
    if user_answer == 'y':
        return True
    if user_answer == 'n':
        return False


def drawing_hangman(i):
    if i == 0:
        print('''
     |----| 
     |    
     |   
     |   
    _|_
    ''')
    if i == 1:
        print('''
     |----| 
     |    O
     |   
     |   
    _|_
    ''')
    if i == 2:
        print('''
     |----| 
     |    O
     |    |
     |   
    _|_
    ''')
    if i == 3:
        print('''
     |----| 
     |    O
     |   /|
     |   
    _|_
    ''')
    if i == 4:
        print('''
     |----| 
     |    O
     |   /|\\ 
     |       
    _|_
    ''')
    if i == 5:
        print('''
     |----| 
     |    O
     |   /|\\
     |   /
    _|_''')
    if i == 6:
        print('''
     |----| 
     |    O
     |   /|\\
     |   /'\\
    _|_''')


def game(word):
    users_word = ['_'] * len(word)
    attempt = 0
    while ''.join(users_word) != word:
        if attempt > 5:
            drawing_hangman(attempt)
            print("\nYOU DIED\n")
            print("Вы не угадали слово:", word)
            break
        print('\nВведите букву.\n')
        drawing_hangman(attempt)
        print(*users_word, '\n')
        letter = input().lower()
        while not letter.isalpha() or len(letter) != 1 or ord(letter) < 1072 or ord(letter) > 1103:
            print("\nОшибка ввода, пожалуйста, введите одну букву на русском языке.\n")
            letter = input().lower()
        if letter in word:
            print("\nЕсть такая буква!\n")
            for i in range(len(word)):
                if word[i] == letter:
                    users_word[i] = letter
        else:
            print("\nНет такой буквы!\n")
            attempt += 1
    else:
        print("\nВы победили, поздравляем!\n")


def main():
    word = word_choice()
    game(word)
    print('\nСыграем еще раз (y/n)?\n')
    users_answer = input()
    if is_answer_valid(users_answer):
        main()
    else:
        print("\nСпасибо, что сыграли в 'Угадай слово'!\n")


print("Добро пожаловать в игру 'Угадай слово'!\n")
main()
