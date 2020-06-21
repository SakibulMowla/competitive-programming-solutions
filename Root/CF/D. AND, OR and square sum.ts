declare const process: any;

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let input: string = '';
process.stdin.on('data', (line) => {
    input += line;
});

process.stdin.on('end', () => {
    const lines: string[] = input.split('\n');

    const n: number = parseInt(lines.shift(), 10);
    const arr: number[] = lineToNumArray(lines.shift());

    const bitCount: number[] = Array(20).fill(0);
    arr.forEach(element => {
        for (let i: number = 0; i < 20; i++) {
            if (element & (1 << i)) {
                bitCount[i]++;
            }
        }
    });

    let ans: bigint = 0n;
    for (let i: number = 0; i < n; i++) {
        let element: number = 0;
        for (let j: number = 0; j < 20; j++) {
            if (bitCount[j]) {
                element += (1 << j);
                bitCount[j]--;
            }
        }
        ans += BigInt(element ** 2);
    }

    console.log(ans.toString());
});

// input helper

function lineToNumArray(line: string): number[] {
    return line.split(' ').map(element => parseInt(element, 10));
}
