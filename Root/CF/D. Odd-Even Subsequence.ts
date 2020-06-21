declare const process: any;

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let input: string = '';
process.stdin.on('data', (line) => {
    input += line;
});

process.stdin.on('end', () => {
    const lines: string[] = input.split('\n');

    const [n, k]: number[] = lineToNumArray(lines.shift());
    const arr: number[] = lineToNumArray(lines.shift());

    console.log(Math.min(
        binarySearch(n, k, arr, 0), binarySearch(n, k, arr, 1)
    ));
});

function binarySearch(n: number, k: number, arr: number[], parity: number) {
    let lo: number = 1, hi: number = Math.max(...arr);
    let ans: number;
    while (lo <= hi) {
        const mid: number = Math.floor((lo + hi) / 2);
        let count: number = 0;
        for (let i: number = 0; i < n && count < k; i++) {
            if (count % 2 === parity) {
                count += Number(arr[i] <= mid);
            } else {
                count++;
            }
        }
        if (count === k) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

// input helper

function lineToNumArray(line: string): number[] {
    return line.split(' ').map(element => parseInt(element, 10));
}
