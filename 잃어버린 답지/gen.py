import random
import sys

if __name__ == "__main__":
    random.seed(sys.argv[1])
    Q = 100000
    print(Q)
    for q in range(Q):
        li = [0, 1, 2, 3, 4, 5]
        random.shuffle(li)
        N = random.randint(1, 5)
        M = random.randint(1, 6-N)
        mx = max(li[:N+M])
        print(N, M)
        print(*(str([[-1, 1][random.randint(0, 1)], random.randint(1, 100) * [-1, 1][random.randint(0, 1)]][x != mx]) + " " + str(x) for x in li[:N]))
        print(*(str([[-1, 1][random.randint(0, 1)], random.randint(1, 100) * [-1, 1][random.randint(0, 1)]][x != mx]) + " " + str(x) for x in li[N:N+M]))
