// CERC 2012
// Problem I: The Dragon and the knights
// Model solution, O(nm)
// Author: Jakub Pachocki

import java.io.*;
import java.util.*;

class Solver {
	
	void solve() {
		Scanner in = new Scanner(System.in);
		int nCases = in.nextInt();
		for (int testCase = 0; testCase < nCases; ++testCase) {
			int n = in.nextInt();
			int m = in.nextInt();
			int[] a = new int[n];
			int[] b = new int[n];
			int[] c = new int[n];
			long[] x = new long[m];
			long[] y = new long[m];
			for (int i = 0; i < n; ++i) {
				a[i] = in.nextInt();
				b[i] = in.nextInt();
				c[i] = in.nextInt();
			}
			for (int i = 0; i < m; ++i) {
				x[i] = in.nextLong();
				y[i] = in.nextLong();
			}
			int result = 1;
			for (int i = 0; i < n; ++i) {
				++result;
				for (int j = 0; j < i; ++j) {
					if (a[i] * b[j] != a[j] * b[i]) {
						++result;
					}
				}
			}
			Set<Long> s = new HashSet<Long>();
			for (int i = 0; i < m; ++i) {
				long h = 0;
				for (int j = 0; j < n; ++j) {
					if (a[j] * x[i] + b[j] * y[i] + c[j] > 0) {
						h = 3 * h + 1;
					} else {
						h = 3 * h;
					}
				}
				s.add(h);
			}
			System.out.println(s.size() == result ? "PROTECTED" : "VULNERABLE");
		}
		in.close();
	}
}

public class I {

	public static void main(String[] args) {
		(new Solver()).solve();
	}

}
