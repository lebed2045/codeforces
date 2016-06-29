function bfs(a, n, d, startx, starty) {
	d[startx + starty*n] = 0;
	for (var y = 0; y < 3; y++) {
			for (var x = 0; x < n; x++) {	
				d[x + y*n] = -1;
			}
		}

	q = [];
	q.push([startx,starty,0]);
	while (q.length > 0) {
		var curr = q.pop();
		var x = curr[0];
		var y = curr[1];
		var t = curr[2];
		var dd = d[x + y*n];
		x += 1;
		if (x == n) continue;
		t += 1;
		// up
		if (y > 0) {
			var yy = y-1;
			if (a[t][x+yy*n] == "." && d[x+yy*n] == -1) {
				d[x + yy*n] = dd+1;
				q.push([x,y,t]);
			}
		}
		// forvard
		if (a[t][x + y*n] == "."  && d[x+y*n] == -1) {
			d[x + y*n] = dd+1;
			q.push( [x,y,t] );
		}
		//down
		if (y < 2) {
			var yy = y+1;
			if (a[t][x+yy*n] == "."  && d[x+yy*n] == -1) {
				d[x + yy*n] = dd+1;
				q.push([x,y,t]);
			}
		}
	}
}

function solution() {
	var input = readline().split(" ").map(Number);
	var n = input[0];
	var k = input[1];
	var a = [];
	var strmap = "";
	for (var i = 0; i < 3; i++) {
		a[0] = [];
		var str = readline();
		strmap += str;
		//a[0].concat(str);
	}
	a[0] = strmap.split('');
	/*write(n + "\n\n");
	
		for (var y = 0; y < 3; y++) {
			for (var x = 0; x < n; x++) {	
				write(strmap[x + y*n]);
			}
			write("\n");
		}
		write("\n");
	*/
	// make a map
	for (var time = 1; time <= n; time++) {
		a[time] = a[time-1].slice();
		var b = a[time];

		for (var x = 0; x < n; x++) 
			for (var y = 0; y < 3; y++) {
				var i = x + y*n;
				if (b[i] != "." && b[i] != "s") {
					// train!!!
					if (x >= 2) {
						// move
						b[(x-2) + y*n] = b[i];
					}
					b[i] = ".";
				}
			}
/*
		for (var y = 0; y < 3; y++) {
			for (var x = 0; x < n; x++) {	
				write(b[x + y*n]);
			}
			write("\n");
		}
		write("\n");
*/

	}

	d = [];
	for (var y = 0; y < 3; y++) 
		if (a[0][y*n] == "s") {
			// start
			bfs(a, n, d, x,y);
		}

	for (var y = 0; y < 3; y++) {
		for (var x = 0; x < n; x++) {	
			write(d[x + y*n]);
		}
		write("\n");
	}

	if (d[n-1] != -1 || d[2*n-1] != -1 || d[3*n-1] != -1) {
		write("YES\n");
	} else 
	{
		write("NO\n");
	}

}











t = +readline();
for (var i = 0; i < t; i++) solution();