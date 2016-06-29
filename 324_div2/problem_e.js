var answer = {
	price: 0,
	swap_list: []
};

function swap(i, j) {
	var temp = b[i];
	b[i] = b[j];
	b[j] = temp;
	answer.price += Math.abs(i-j);
	answer.swap_list.push([i,j]);
}

function solve(i, j) {
	if (b2i[a[i]] >= j) {
		swap(i, j);
	}
	var k = -1;
	for (var j = i + 1; j <= n; j++)
		if(a[j] == b[i]) {
			k = j;
			break;
		}
	
	while (k != i) {
		for ( var j = i; j < k; j++)
		{
			if (b2i[a[j]] >= k)
			{
				swap(k,j);

				break;
			}
		}
	}
}

function main(){
	n = +readline();
	a = readline().split(" ").map(Number);
	b = readline().split(" ").map(Number);
	for (var i = a.length; i > 0; --i) {
		a[i] = a[i-1];
		b[i] = b[i-1];
	}

	// normalization
	a2i = [];
	b2i = [];
	for (var i = 1; i < a.length; i++) {
		// item a to index
		a2i[ a[i] ] = i;
	}
	for (var i = 1; i < b.length; i++) {
		//b[i] = a2i[b[i]] + 1;
		b2i[ b[i] ] = i;
	}

	// solution
	// items shift only to right
	for (var i = 1; i < b.length; i++) {
		if (a[i] != b[i])
			solve(i, a2i[b[i]]);
	}
}

main();