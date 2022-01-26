import random
import sys

if __name__ == "__main__":
    random.seed(sys.argv[1])
    V = 100000
    E = 99999

    print(V, E)

    print(*(str(i) + " " + str(i+1) + " 100000" for i in range(1, V)), sep="\n")

    print(random.randint(1, V+1))
