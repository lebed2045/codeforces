input = readline().split(" ").map(Number);
n = input[0];
t = input[1];
answer = "";
if (t == 10) {
	if (n == 1) {
		answer = "-1";
	} else {
		var answer = "1";
		for (var i = 1; i < n; i++) 
			answer += "0";
	}
} else {
	for (var i = 0; i < n; i++)
		answer += t;
}
write(answer);