process.stdin.resume();
process.stdin.setEncoding('utf-8');

let input = '';
process.stdin.on('data', (line) => {
    input += line;
});

const reducer = (accumulator, value, index) => {
    accumulator[index % 2] += (value % 2 !== index % 2);
    return accumulator;
}

process.stdin.on('end', () => {
    const lines = input.split('\n');
    let tests = parseInt(lines.shift(), 10);
    while(tests--) {
        const n = parseInt(lines.shift(), 10);
        const arr = lines.shift().split(' ');
        const [ evenMismatch, oddMismatch ] = arr.reduce(reducer, [ 0, 0 ]);
        console.log(evenMismatch === oddMismatch ? evenMismatch : -1);
    }
});
