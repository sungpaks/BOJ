// Run by Node.js

const readline = require("readline");
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout
});
let X = [];
let Y = [];
let N = [];
let T = -1;

rl.on("line", function(line) {
	if (T === -1) T = parseInt(line);
	else if (T === 0) rl.close();
	else {
		let [x,y,n] = line.split(" ").map(Number);
		X.push(x);
		Y.push(y);
		N.push(n);
		T--;
	}
}).on("close", function() {
	for(let i=0;i<X.length;i++) {
		console.log(check(X[i],Y[i],N[i]) ? "YES" : "NO")
	}
	process.exit();
});

function check(x, y, n) {
	//N초 뒤에 도착 가능?
	const d = Math.abs(x) + Math.abs(y);
	if (d > n || (n-d)%2 !== 0) return false;
	else return true;
}
