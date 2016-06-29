Array.prototype.sub_reverse = function(x,y) {
	var a = this;
	var n = a.length;
	for (var i = 0; i+i < (y - x); i++) {
		var temp = a[x+i];
		a[x+i] = a[y-1-i];
		a[y-1-i] = temp;
	}
}

Array.prototype.next_permutation = function(){
	var a = this;
	var n = a.length;
	if (n < 2) return false;

	//Find the largest index k such that a[k] < a[k + 1]. If no such index exists, the permutation is the last permutation.
	for (var k = n-2; k >= 0 && a[k] >= a[k+1]; --k){}
	if (k == -1) return false;

	//Find the largest index l greater than k such that a[k] < a[l].
	for (var l = n-1;  k < l && a[k] >= a[l]; --l){}
	if (k == l) return false;	

	//Swap the value of a[k] with that of a[l].
	var temp = a[k];
	a[k] = a[l];
	a[l] = temp;

	//Reverse the sequence from a[k + 1] up to and including the final element a[n].
	a.sub_reverse(k+1,n);
	return true;
}

function solve(a,order) {
	var letter = ["A","B","C"];
	var A = {x:a[0][0], y:a[0][1], letter:letter[order[0]]};
	var B = {x:a[1][0], y:a[1][1], letter:letter[order[1]]};
	var C = {x:a[2][0], y:a[2][1], letter:letter[order[2]]};
	
	// AA
	// BB
	// CC
	if (A.x == B.x && B.x == C.x && A.x == (A.y + B.y + C.y) ) {
		write(A.x + "\n");
		for (var i = 0; i < A.y; i++) {
			for (var j = 0; j < A.x; j++)
				write(A.letter);
			write("\n");
		}
		for (var i = 0; i < B.y; i++) {
			for (var j = 0; j < B.x; j++)
				write(B.letter);
			write("\n");
		}
		for (var i = 0; i < C.y; i++) {
			for (var j = 0; j < C.x; j++)
				write(C.letter);
			write("\n");
		}
		return true;
	}

	// ABB
	// ACC
	if (B.x == C.x && A.y == (B.y+C.y) && A.y == (A.x + B.x)) {
		write(A.y + "\n");
		for (var i = 0; i < B.y; i++) {
			for (var j = 0; j < A.x; j++) write(A.letter);
			for (var j = 0; j < B.x; j++) write(B.letter);
			write("\n");
		}
		for (var i = 0; i < C.y; i++) {
			for (var j = 0; j < A.x; j++) write(A.letter);
			for (var j = 0; j < C.x; j++) write(C.letter);
			write("\n");	
		}
		return true;
	}
	return false;
}


function main() {
	a = readline().split(" ").map(Number);

	var order = [0,1,2];
	do {
		// 2d array
		var b = [];
		for (var i = 0; i < 3; i++) {
			b.push([ a[2*order[i]], a[2*order[i]+1] ]);
		}
		
		for (var rotation_mask = 0; rotation_mask < 8; rotation_mask++) {
			var c = [];
			// rotate
			for (var i = 0; i < 3; i++)
				if (rotation_mask & (1<<i)) {
					c[i] = b[i].slice(0).reverse();
				} else {
					c[i] = b[i].slice();
				}
			result = solve(c, order);
			if (result) break;
		}
		if (result) break;
	} while (order.next_permutation());

	if (!result) {
		write("-1\n");
	}
}

main();

