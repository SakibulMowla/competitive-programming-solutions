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
        const n: number = parseInt(lines.shift(), 10);
        console.log(n % 4 ? 'NO' : 'YES');
    }
});

// input helper

function lineToNumArray(line: string): number[] {
    return line.split(' ').map(element => parseInt(element, 10));
}
