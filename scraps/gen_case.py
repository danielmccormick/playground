from random import randint



if __name__ == '__main__':
	fo = open("testcase.txt", "w")
	fo.write("1\n")
	size = randint(1,20)
	size_str = str(size) + "\n"
	fo.write(size_str)
	for x in range(size):
		s = ""
		for y in range(size) :
			if randint(0,1) == 0:
				s += 'T'
			else:
				s += 'L'
		fo.write(str(s) + "\n")

