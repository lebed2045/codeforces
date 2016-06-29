input = readline().split(" ").map(Number);
var n = input[0];
var t = input[1];
var s1 = readline(); 
var s2 = readline();

var diff1 = 0;
var a = new Array(n);
var answer = "";
var d = [];
var j = 0;
for (var i = 0; i < n; i++)
{
	if (s1[i] != s2[i]) {
		diff1 += 1;
		d[j++] = i;
	}
}

if (diff1 <= (t+t)) {
	for (var i = 0; i < n; i++)
		a[i] = s1.charCodeAt(i);
	
	var samePreffix = diff1 - t;

	if (samePreffix > 0) {
		var restPreffix = samePreffix;
		for (var i = 0; i < diff1; i++) {
			// part 1
			if (i < samePreffix) {
				a[d[i]] = s2.charCodeAt(d[i]);
			}
			// part 2
			if (samePreffix <= i && i < diff1-samePreffix) {
				a[d[i]] = s1.charCodeAt(d[i]) + 1;
				if (a[d[i]] > "z".charCodeAt(0))
					a[d[i]] -= 26;

				if (a[d[i]] == s2.charCodeAt(d[i]))
					a[d[i]] += 1;			
			}
			// part 3
		}
	} else {
		for (var i = 0; i < n; i++) {
			if (s1[i] == s2[i]) {
				if (samePreffix < 0) {
					a[i] += 1;
					samePreffix += 1;
				}
			} else {
				a[i] += 1;
				if (a[i] > "z".charCodeAt(0))
					a[i] -= 26;
				if (a[i] == s2.charCodeAt(i))
					a[i] += 1;
			}
		}
	}


	for (var i = 0; i < n; i++) {
		if (a[i] > "z".charCodeAt(0))
			a[i] -= 26;	
		answer += String.fromCharCode(a[i]);
	}
} else {
	answer = "-1";
}

write(answer);