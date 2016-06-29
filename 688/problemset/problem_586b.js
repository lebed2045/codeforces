n = +readline();
a = [];
a[0] = readline().split(" ").map(Number);
a[1] = readline().split(" ").map(Number);
b = readline().split(" ").map(Number);

sum1 = [];
sum1[0] = 0;
for (var i = 1; i < n; i++) {
	sum1[i] = sum1[i-1] + a[0][i-1];
}

sum2 = [];
sum2[n-1] = 0;
for (var i = n-1; i >= 1; --i) {
	sum2[i-1] = sum2[i] + a[1][i-1];
}


path = [];
for (var i = 0; i < n; i++) {
	// leave only i bridge
	path[i] = b[i] + sum1[i] + sum2[i];
}
path.sort( function(a,b) {return a-b;});
write(path[0] + path[1]);