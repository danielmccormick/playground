bool areAnagrams(char *a, char *b) { // Will compare two c strs for equality
	int aChars[128] = {0};
	// you might have to do something like memset(aChars,0,128*sizeof(int)); ??
	int bChars[128] = {0};
	int cCnt = 0;
	while (*a != 0) {
		aChars[*(a++)]++;
		cCnt++;
	}
	while (*b != 0) {
		bChars[*(b++)]++;
		cCnt--;
		if (cCnt < 0) return false;
	}
	return (!memcmp(aChars,bChars,128*sizeof(int));
}
