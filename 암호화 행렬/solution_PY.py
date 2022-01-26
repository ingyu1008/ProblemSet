import random
import sys
input = sys.stdin.readline

def matmul(x, y):
    return [[sum(a * b for a, b in zip(X_row, Y_col)) for Y_col in zip(*y)] for X_row in x]

def mateq(x, y):
    for i in range(len(x)):
        for j in range(len(x[0])):
            if x[i][j] != y[i][j]:
                return False
    return True

def main():
    N = int(input())

    A = [list(map(int, input().split())) for _ in range(N)]
    B = [list(map(int, input().split())) for _ in range(N)]
    C = [list(map(int, input().split())) for _ in range(N)]

    cnt = [0, 0, 0, 0, 0, 0]
    num_iter = 5

    for _ in range(num_iter):
        X = [[random.randint(-100, 100)] for _ in range(N)]
        AX = matmul(A, X)
        BX = matmul(B, X)
        CX = matmul(C, X)

        if mateq(matmul(A, BX), CX):
            cnt[0] += 1
        if mateq(matmul(A, CX), BX):
            cnt[1] += 1
        if mateq(matmul(B, AX), CX):
            cnt[2] += 1
        if mateq(matmul(B, CX), AX):
            cnt[3] += 1
        if mateq(matmul(C, AX), BX):
            cnt[4] += 1
        if mateq(matmul(C, BX), AX):
            cnt[5] += 1

    A_value, B_value, C_value = 0, 0, 0

    if cnt[0] == num_iter:
        A_value |= 1
        B_value |= 2
        C_value |= 4
    if cnt[1] == num_iter:
        A_value |= 1
        B_value |= 4
        C_value |= 2
    if cnt[2] == num_iter:
        A_value |= 2
        B_value |= 1
        C_value |= 4
    if cnt[3] == num_iter:
        A_value |= 4
        B_value |= 1
        C_value |= 2
    if cnt[4] == num_iter:
        A_value |= 2
        B_value |= 4
        C_value |= 1
    if cnt[5] == num_iter:
        A_value |= 4
        B_value |= 2
        C_value |= 1

    print(A_value, B_value, C_value, sep='\n')

if __name__ == "__main__":
    main()
    