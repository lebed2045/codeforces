var numberOfExperiments = 10000;

function randomInt(n) {
	return Math.floor(Math.random()*n);
}

Array.prototype.randomSuffle = function () {
	var len = this.length;
	for (var i = 0; i < len; i++) {
		var j = randomInt(len);
		var temp = this[i];
		this[i] = this[j];
		this[j] = temp;
	}
	return this;
};

function makeAnExperiment() {
	// 0 - dummy, 1 - prize
	var a = [0,0,0];
	// put a prize randomly
	a[randomInt(3)] = 1;

	// choose randomly the door
	var chose = randomInt(3);

	// the acter opens one of two rest doors
	var emptyDoor = (function(){
		// look at each door in random order 
		// and check that door is empty and not chosen
		var order = [1,2,3].randomSuffle();
		for (var i = 0, j; i < order.length; i++, j = order[i]) {
			if (j != chose && a[j] == 0) 
				return j;
		}
	})();

	// change desision
	for (var i = 0; i < a.length; i++) 
		if (i != chose && i != emptyDoor) {
			chose = i;
			break;
		}
	
	return a[chose];
}

var wins = 0;
for (var i = 0; i < numberOfExperiments; i++) {
	wins += makeAnExperiment();
}
write(wins/numberOfExperiments);