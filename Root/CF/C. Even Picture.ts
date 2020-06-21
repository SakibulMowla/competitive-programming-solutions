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
    
    const ans: [number, number][] = [[0, 0]];
    for (let i = 0; i <= n; i++) {
        ans.push([i, i + 1]);
        ans.push([i + 1, i]);
        ans.push([i + 1, i + 1]);
    }

    console.log(ans.length);
    ans.forEach(element => console.log(...element));
});

// input helper

function lineToNumArray(line: string): number[] {
    return line.split(' ').map(element => parseInt(element, 10));
}
