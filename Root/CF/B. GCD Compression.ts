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
        const arr: number[] = lineToNumArray(lines.shift());

        const indices: number[][] = [[], []];
        arr.forEach((element, index) => indices[element % 2].push(index));

        if (indices[0].length % 2) {
            indices[0].shift();
            indices[1].shift();
        } else {
            const parity: number = Number(!indices[0].length);
            indices[parity].shift();
            indices[parity].shift();
        }

        indices.forEach(parity => {
            while (parity.length) {
                console.log(1 + parity.pop(), 1 + parity.pop());
            }
        });
    }
});

// input helper

function lineToNumArray(line: string): number[] {
    return line.split(' ').map(element => parseInt(element, 10));
}
