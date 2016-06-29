MOD = 1000000000+7;

function main() {
	var n = +readline();
	var answer = 1;
	for (var i = 0; i < n*3; i++) {
		answer *= 3;
		answer %= MOD;
	}
	// 2..
	// 1 2 3
	b = 1;
	for (var i  =0; i < n; i++)
	{
		b *= 7
		b %= MOD;
	}
	answer = (MOD + answer - b);
	answer %= MOD;

	// 3 2 1
	//answer -= 3;

	write(answer);
}

main();