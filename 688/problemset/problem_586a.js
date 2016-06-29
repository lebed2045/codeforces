n = +readline();
a = readline().split(" ").map(Number);

answer = 0;
last_i = -100;
for (var i = 0; i < n; i++) {
	if (a[i] == 1) {
		if (last_i >=0 && last_i+2 == i) {
			// a[i-1] == 0
			answer += 1;
		}
		answer += 1;
		last_i = i;
	}
}
write(answer);