input = readline().split(" ").map(Number);
n = input[0];
k = input[1];
a = readline().split(" ").map(Number);

b = [];

for (var i = 0; i < n; i++) {
	b.push( {mod: a[i]%10, i: i} );
}
b.sort(function(x,y) { return x.mod - y.mod}).reverse();

for (var i = 0; i < n; i++) {
	if ( k >= (10 - b[i].mod) ) {
		var add = Math.min((10 - b[i].mod)%10, k);
		//write("add = " + add + "\n");
		a[b[i].i] += add;
		k -= add;
	}
}

a.sort();
for (var i = 0; i < n; i++) {
	if (a[i] < 100 && k > 0) {
		var add = Math.min(100 - a[i],k);
		a[i] += add;
		k -= add;
	}
}

answer = 0;
for (var i = 0; i < n; i++) {
	answer += Math.floor(a[i]/10);
}

write(answer);


//write("b[i].mod = " + b[i].mod + "\n");

