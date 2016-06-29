
function isPrime(n) {
	if (n == 1)
		return false;
	if (n <= 3) 
		return true;
	if (n % 2 == 0) 
		return false;
	for (var i = 3; i*i <= n; i += 2) 
		if (n % i == 0) return false;
	return true;
}

function main() {
	var n = +readline();
	// 3 <= n <= 10**9
	var a = [];
	if (n <= 7) {
		if (n == 3) a = [3];
		if (n == 4) a = [2,2];
		if (n == 5) a = [2,3];
		if (n == 6) a = [3,3];
		if (n == 7) a = [2,5];
	} else {
		n -= 3;
		a = [3];
		for (var i = 2; i < n; i++)
			if (isPrime(i) && isPrime(n-i))
			{
				a.push(i);
				a.push(n-i);
				break;
			}
	}
	write(a.length + "\n");
	for (var i = 0; i < a.length; i++)
		write(a[i] + " ");
}

main();