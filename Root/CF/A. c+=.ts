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
        let a: number, b: number, n: number;
        [a, b, n] = lineToNumArray(lines.shift());

        let steps = 0;
        while (Math.max(a, b) <= n) {
            [a, b] = [a + b, Math.max(a, b)];
            steps++;
        }

        console.log(steps);
    }
});

// input helper

function lineToNumArray(line: string): number[] {
    return line.split(' ').map(element => parseInt(element, 10));
}
