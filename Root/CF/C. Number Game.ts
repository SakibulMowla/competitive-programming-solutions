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
        const ans = ((n: number) => {
            if (n == 1) {
                return 1;
            }
            if (n === 2) {
                return 0;
            }
            if (n % 2 === 1) {
                return 0;
            }
            if ((n & (n - 1)) === 0) {
                return 1;
            }
            let twoCount: number = 0;
            while (n % 2 === 0) {
                n /= 2;
                twoCount++;
            }
            if (twoCount > 1) {
                return 0;
            }
            return isPrime(n) ? 1 : 0;
        })(n);

        console.log(['Ashishgup', 'FastestFinger'][ans]);
    }
});

function isPrime(n: number) {
    for (let i = 3; i * i <= n; i += 2) {
        if (n % i === 0) {
            return false;
        }
    }
    return true;
}

// input helper

function lineToNumArray(line: string): number[] {
    return line.split(' ').map(element => parseInt(element, 10));
}
