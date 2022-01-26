import random
import sys

if __name__ == "__main__":
	random.seed(sys.argv[1])
	n = int(sys.argv[2])
	print(n)
	print(*(random.randint(1, 1000) for i in range(4*n - 1)))