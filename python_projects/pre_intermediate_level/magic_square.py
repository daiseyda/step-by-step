def magic_square():
    n = int(input())
    mas = [list(map(int, input().split())) for _ in range(n)]
    mas_for_uniq_check = []
    for i in range(1, n ** 2 + 1):
        mas_for_uniq_check.append(i)
    check_sum = sum(mas[0])
    diag_sum_1, diag_sum_2 = 0, 0
    for i in range(n):
        if sum(mas[i]) != check_sum:
            return "NO"
        col_sum = 0
        for j in range(n):
            if mas[i][j] not in mas_for_uniq_check:
                return "NO"
            else:
                mas_for_uniq_check.remove(mas[i][j])
                col_sum += mas[j][i]
        if col_sum != check_sum:
            return "NO"
        diag_sum_1 += mas[i][i]
        diag_sum_2 += mas[n - i - 1][n - i - 1]
    if diag_sum_1 != check_sum or diag_sum_2 != check_sum:
        return "NO"
    return "YES"


print(magic_square())
