declare const process: any;

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let input: string = '';
process.stdin.on('data', (line) => {
    input += line;
});

process.stdin.on('end', () => {
    const lines: string[] = input.split('\n');

    const k: bigint = BigInt(lines.shift());

    const occur: bigint[] = Array(10).fill(1n);
    let count: bigint = 1n;
    let index: number = 0;

    while (count < k) {
        count /= occur[index];
        occur[index]++;
        count *= occur[index];
        index++;
        if (index === 10) {
            index = 0;
        }
    }

    const word: string = "codeforces";
    const ans: string = occur
        .map((value, index) => word[index].repeat(Number(value)))
        .join('');

    console.log(ans);
});

// input helper

function lineToNumArray(line: string): number[] {
    return line.split(' ').map(element => parseInt(element, 10));
}
