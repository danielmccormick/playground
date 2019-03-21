bool areAnagrams(char *a, char *b) { // Will compare two c strs for equality
	int aChars[128] = {0};
	// you might have to do something like memset(aChars,0,128*sizeof(int)); ??
	int bChars[128] = {0};
	while (*a != 0) {
		aChars[*a++]++;
	}
	while (*b != 0) {
		bChars[*b++]++;
	}
	for (int i = 0; i < 128; i++) {
		if (aChars[i] != bChars[i]) return false;
	}
	return true;
}