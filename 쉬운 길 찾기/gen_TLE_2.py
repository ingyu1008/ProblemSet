import random
import sys

if __name__ == "__main__":
    random.seed(sys.argv[1])
    V = 100000
    E = 99997*2 + 99999

    print(V, E)

    print(*("1 " + str(i) + " " + str(1000000 - i)
          for i in range(2, 99999)), sep="\n")
    print(*(str(i) + " 99999 " + str(2*i)
          for i in range(2, 99999)), sep="\n")
    print(*("99999 " + str(i) + " " + str(random.randint(1, 100000))
          for i in range(1, 99999)), sep="\n")
    print("99999 100000 " + str(random.randint(1, 100000)))

    print([1, random.randint(1, 100000)][int(sys.argv[2])])
