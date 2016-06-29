n = readline();
a = readline().split(" ").map(Number);

answer = -1;
hacked = 0;

while (hacked < n) {
	answer += 1;
	if (answer % 2 == 0) {
		// right
		for (var i = 0; i < a.length; i++) {
			if (a[i] <= hacked && a[i] != -1) {
				a[i] = -1;
				hacked += 1;
			}
		}
	} else {
		for (var i = a.length-1; i >= 0; --i) {
			if (a[i] <= hacked && a[i] != -1) {
				a[i] = -1;
				hacked += 1;
			}	
		}
	}

}

write(answer);