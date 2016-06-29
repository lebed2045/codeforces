n = +readline();
v = [], d = [], p = [];
line = [];
for (var i = 0; i < n; i++) {
	input = readline().split(" ").map(Number);
	v[i] = input[0];
	d[i] = input[1];
	p[i] = input[2];
	line.push({v:v[i],d:d[i],p:p[i],i:i+1});
}

answer = [];
while (line.length > 0) {
	//write(line + "\n");

	var patient = line[0];
	//write(patient.v + "\n");
	answer.push(patient.i);
	line.splice(0,1);

	//
	var cry = -1;
	for (var i = 0; i < line.length && i < patient.v; i++) {
		line[i].p -= patient.v-i;
		if (cry == -1 && line[i].p < 0) 
			cry = i;
	}

	//for (var i = 0; i < line.length; i++) write(line[i].p + " ");

	while (cry >= 0) {
		var j = cry;
		cry = -1;
		for (var i = j; i < line.length; i++) {
			line[i].p -= line[j].d;
			if (cry == -1 && i > j && line[i].p < 0) {
				cry = i;
			}
		}
	}

	for (var i = line.length-1; i >= 0; --i) {
		if (line[i].p < 0) {
			line.splice(i,1);
		}
	}
	
}
write(answer.length + "\n");
for (var i = 0; i < answer.length; i++) {
	write(answer[i] + " ");
}

