//Object.prototype.clone =  
 function clone(obj) {
	if(typeof obj === "object") {
		var copy = {};
		for (var key in obj) {
			copy[key] = clone(obj[key]);
		}
		return copy;
	}
	return obj;
}

var MapClass = function(n) {
	this.a = [];
	this.n = n;
}

MapClass.prototype.write = function() {
	for (var x = 0; x < 3; x++) {
		for (var y = 0; y < this.n; y++) {
			write(this.a[x][y]);
		}
		write("\n");
	}
}

function bfs(m, x, y) {
	d = [];
	/*
	d[{x,y}] = 0;
	q = {};
	while (q.length > 0) {
		var curr = q.pop();
		var x = curr.x;
		var y = curr.y;
		var t = x+1;
		// forvard
		for (var dy = -1; dy <= 1; dy++) {
			var xx = x + 1;
			var yy = y + dy;
			// if can go
			if (xx < n && 0 <= yy && y < 3 && m[t].a[xx][yy] == ".") {
				if ( typeof d[{xx,yy}] === "undefined" ) {
					d[{xx,yy}] = d[{x,y}]+1;
					q.push({xx,yy});
				}
			}
		}
		
	}
	*/
}

function solution() {
	var input = readline().split(" ").map(Number);
	var n = input[0];
	var k = input[1];
	var m =  [new MapClass(n)];
	for(var x = 0; x < 3; x++) {
		m[0].a[x] = readline().split("");
	}

	for (var t = 1; t < n; t++) {
		m[t] = clone(m[t-1]);
		var a = m[t].a;

		for (var x = 0; x < 3; x++) 
			for (var y = 0; y < n; y++) 
				if (a[x][y] != "." && a[x][y] != "s") {
					// train
					if (y > 1) a[x][y-2] = a[x][y];
					a[x][y] = ".";
				}

		//m[t].write();
	}

	write("write(m.keys()); ".trim());

	for (var x = 0; x < 3; x++) 
		if (m[0].a[x][y] == "s") {
			if (bfs(m, x,y)) {
				write("YES\n");
			} else {
				write("No\n");
			}
			break;
		}
}

t = +readline();
for (var i = 0; i < t; i++) solution();