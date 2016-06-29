n = +readline();

a0 = readline().split(" ").map(Number);
a0_ = [0];
a0min = [];
a0min[0] = a0[0];
for (var i = 0; i < a0.length; i++) {
	a0min[i+1] = Math.min(a0[i], a0min[i]);
	a0_.push( a0_[i] + a0[i] );
}

a1 = readline().split(" ").map(Number);
a1_ = []; a1_[n-1] = 0;
a1min = [];
a1min[n-1] = a1[n-2];
for (var i = n-2; i >= 0; --i) {
	a1min[i] = Math.min(a1min[i+1], a1[i]);
	a1_[i] = a1_[i+1] + a1[i];
}

b = readline().split(" ").map(Number);
d = [];
for (var i = 0; i < b.length; i++) {
	d.push( b[i] + a0_[i] + a1_[i] );
	//d.push( b[i] + a0_[i] + a1_[i] + 2*a0min[i]);
	d.push( b[i] + a0_[i] + a1_[i] + 2*a1min[i]);
}

d.sort(function(a,b) {return a-b;});
//write(d + "\n");

write(d[0]+d[1]);