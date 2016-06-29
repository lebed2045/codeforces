input = readline().split(" ").map(Number);
a = input[0];
b = input[1];
m = Math.min(a,b)
write(m + " " + Math.floor((a+b-m*2)/2) );