// Run by Node.js
const readline = require('readline');

let N = -1;
let M = -1;
let cur = -1;
let k = [];
let drain = [];

(async () => {
	let rl = readline.createInterface({ input: process.stdin });
	
	for await (const line of rl) {
		if (N === -1 && M === -1) {
			const [n, m] = line.split(" ").map(Number);
			N = n;
			M = m;
			for(let i=0;i<N;i++) {
				drain.push(false);
			}
		}
		else if (cur === -1) {
			k = line.split(" ").map(Number);
			cur++;
		}
		else if (cur < M) {
			const [s, e] = line.split(" ").map(Number);
			for(let i=s-1;i<e;i++) { //매 장마마다 s부터 e까지의 집 높이가 1 증가한다
				k[i]++;
				drain[i] = true;
			}
			if ((cur+1) % 3 === 0) {
				for(let i = 0;i<N;i++) {
					if (drain[i]) k[i]--;
					drain[i] = false;
				}
			}
			cur++;
		}
		else rl.close();
	}
	console.log(k.join(" "));
	process.exit();
})();
