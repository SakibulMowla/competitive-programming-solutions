declare var process: any;

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
        const nx: number[] = lineToNumArray(lines.shift());
        const n: number = nx[0], x: number = nx[1];

        const arr: number[] = lineToNumArray(lines.shift());

        const distFromBegin: number = arr.findIndex(element => element % x !== 0);
        const distFromEnd: number = arr.reverse().findIndex(element => element % x !== 0);
        if (distFromBegin === -1) {
            console.log(-1);
        } else {
            const sum: number = arr.reduce((a, b) => a + b, 0);
            console.log(
                sum % x !== 0 ? 
                n :
                n - Math.min(distFromBegin, distFromEnd) - 1
            );
        }
    }
});

// input helper

function lineToNumArray(line: string): number[] {
    return line.split(' ').map(element => parseInt(element, 10));
}
