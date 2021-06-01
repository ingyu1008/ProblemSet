import random
import sys

if __name__ == "__main__":
    random.seed(sys.argv[1])
    V = 100000
    E = 99997 + 99996 + 99997 + 1

    print(V, E)

    print(*("1 " + str(i) + " " + str(2*i - 1)
          for i in range(2, 99999)), sep="\n")
    print(*(str(i) + " " + str(i+1) + " 1"
          for i in range(2, 99998)), sep="\n")
    print(*(str(i) + " 99999 " + str(1000000 - 2*i)
          for i in range(2, 99999)), sep="\n")
    print("99999 100000 " + str(random.randint(1, 100000)))

    print([100000, random.randint(1, 100000)][int(sys.argv[2])])
