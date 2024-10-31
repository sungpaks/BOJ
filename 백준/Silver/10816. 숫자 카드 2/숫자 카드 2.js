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
    return right;
}

const input = require("fs")
    .readFileSync("/dev/stdin")
    .toString()
    .trim()
    .split("\n");
const n = Number(input[0]);
const cards = input[1].split(" ").map((item) => Number(item));
cards.sort((a, b) => a - b);
const m = Number(input[2]);
let result = "";
const questions = input[3].split(" ").map((item) => Number(item));
for (const q of questions) {
    const lower = lowerBound(cards, q);
    const upper = upperBound(cards, q);
    result += upper - lower;
    result += " ";
}
console.log(result);
