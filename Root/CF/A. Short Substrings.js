process.stdin.resume();
process.stdin.setEncoding('utf-8');

let input = '';
process.stdin.on('data', (line) => {
    input += line;
});

process.stdin.on('end', () => {
    const lines = input.split('\n');
    let tests = parseInt(lines.shift(), 10);
    while(tests--) {
        const b = lines.shift();
        const a = b
            .split('')
            .filter((_, index) => {
                return index === 0 ||
                    index === b.length - 1 ||
                    index % 2
                }
            ).join('');
        console.log(a);
    }
});
