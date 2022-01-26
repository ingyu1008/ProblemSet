import random
import sys

if __name__ == "__main__":
	random.seed(sys.argv[1])
	V = int(sys.argv[2])
	E = int(sys.argv[3])

	if E > (V*(V-1)) // 2:
		E = (V*(V-1)) // 2
	
	print(V, E)

	if V < 5000 :
		li = [(x, y, random.randint(1,1000000)) for x in range(1, V+1) for y in range(1, V+1)]

		random.shuffle(li)
		cnt = 0
		pos = 0
		while cnt < E:
			if li[pos][0] == li[pos][1]:
				pos += 1
				continue
			print(li[pos][0], li[pos][1], li[pos][2])
			cnt += 1
			pos += 1
	else :
		st = set()
		cnt = 0
		while cnt < E:
			u = random.randint(1, V)
			v = random.randint(1, V)
			if u == v or f"{u} {v}" in st:
				continue
			print(u, v, random.randint(1,1000000))
			st.add(f"{u} {v}")
			cnt += 1

	print(random.randint(1, V))
