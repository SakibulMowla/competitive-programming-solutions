declare const process: any;

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let input: string = '';
process.stdin.on('data', (line) => {
    input += line;
});

process.stdin.on('end', () => {
    const lines: string[] = input.split('\n');

    let tests: number = parseInt(lines.shift(), 10);
    while(tests--) {
        lines.shift();
        const s: string = lines.shift();
        let zeroCount: number = 0;
        let ans: string = [...s]
            .reverse()
            .reduce((acc, char) => {
                if (char === '0') {
                    zeroCount++;
                } else if (zeroCount) {
                    zeroCount = 1;
                } else {
                    acc += char;
                }
                return acc;
            }, '');
        ans += '0'.repeat(zeroCount);
        console.log([...ans].reverse().join(''));
    }
});

// input helper

function lineToNumArray(line: string): number[] {
    return line.split(' ').map(element => parseInt(element, 10));
}
