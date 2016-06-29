n = +readline();
h = readline().split(" ").map(Number);


m = [];
m[n] = h[n] = 0;

for (var i = n-1; i >= 0; --i) {
	//write(i + " = " + h[i+1] + ", " + m[i+1] + "\n");
	m[i] = Math.max(h[i+1], m[i+1]);
}


answer = "";
for (var i = 0; i < n; i++) {
	if (m[i] >= h[i]) {
		answer += (m[i]+1 - h[i]) + " ";
	} else {
		answer += "0 ";
	}
}

write(answer);