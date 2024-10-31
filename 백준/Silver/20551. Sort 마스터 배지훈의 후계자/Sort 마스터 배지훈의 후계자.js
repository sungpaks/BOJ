function lowerBound(array, x) {
    let left = -1;
    let right = array.length;
    while (left + 1 < right) {
        const mid = Math.floor((left + right) / 2);
        if (array[mid] < x) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return right;
} // -1 0 2 3 9

function upperBound(array, x) {
    let left = -1;
    let right = array.length;
    let mid = Math.floor((left + right) / 2);
    while (left + 1 < right) {
        if (array[mid] <= x) {
            left = mid;
        } else {
            right = mid;
        }
        mid = Math.floor((left + right) / 2);
    }
    console.log(right);
}

const input = require("fs")
    .readFileSync("/dev/stdin")
    .toString()
    .trim()
    .split("\n");
const [n, m] = input[0].split(" ").map((value) => Number(value));
const array = [];
let i = 1;
for (i; i <= n; i++) {
    array.push(Number(input[i]));
}
array.sort((a, b) => a - b);
for (i; i <= n + m; i++) {
    const x = Number(input[i]);
    const result = lowerBound(array, x);
    console.log(array[result] === x ? result : -1);
}
