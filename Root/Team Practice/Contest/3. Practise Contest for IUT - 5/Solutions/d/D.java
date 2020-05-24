// CERC 2012
// Problem D: Non-boring sequences
// Alternative model solution.
// Author: Jakub Pachocki
import java.io.*;
import java.util.*;

class Solver {
	
	Map<Integer, Integer> get_count(int[] s, int l, int r) {
		Map<Integer, Integer> count = new HashMap<Integer, Integer>();
		for (int i = l; i < r; ++i) {
			if (count.containsKey(s[i])) {
				count.put(s[i], count.get(s[i]) + 1);
			} else {
				count.put(s[i], 1);
			}
		}
		return count;
	}
	
	Set<Integer> get_uniques(int[] s, int l, int r, Map<Integer, Integer> count) {
		Set<Integer> uniques = new HashSet<Integer>();
		for (int i = l; i < r; ++i) {
			if (count.get(s[i]) == 1) {
				uniques.add(s[i]);
			}
		}
		return uniques;
	}
	
	void remove(int[] s, int l, int r, Map<Integer, Integer> count, Set<Integer> uniques) {
		for (int i = l; i < r; ++i) {
			if (count.get(s[i]) == 1) {
				uniques.remove(s[i]);
			} else if (count.get(s[i]) == 2) {
				uniques.add(s[i]);
			}
			count.put(s[i], count.get(s[i]) - 1);
		}
	}
	
	boolean go(int[] s, int l, int r, Map<Integer, Integer> count, Set<Integer> uniques) {
		if (count == null) {
			count = get_count(s, l, r);
			uniques = get_uniques(s, l, r, count);
		}
		if (r - l <= 1) {
			return false;
		}
		if (uniques.isEmpty()) {
			return true;
		}
		int unique = uniques.iterator().next();
		for (int c = 0; ; ++c) {
			if (s[l + c] == unique) {
				remove(s, l, l + c + 1, count, uniques);
				return go(s, l, l + c, null, null) || go(s, l + c + 1, r, count, uniques);
			} else if (s[r - c - 1] == unique) {
				remove(s, r - c - 1, r, count, uniques);
				return go(s, l, r - c - 1, count, uniques) || go(s, r - c, r, null, null);
			}
		}
	}
	
	boolean isBoring(int[] s) {
		return go(s, 0, s.length, null, null);
	}
	
	void solve() throws IOException {
		Reader.init(System.in);
		int nCases = Reader.nextInt();
		for (int i = 0; i < nCases; ++i) {
			int n = Reader.nextInt();
			int[] s = new int[n];
			for (int j = 0; j < n; ++j) {
				s[j] = Reader.nextInt();
			}
			System.out.println(isBoring(s) ? "boring" : "non-boring");
		}
	}
}

public class D {

	public static void main(String[] args) throws IOException {
		(new Solver()).solve();
	}

}

/** Class for buffered reading int and double values */
class Reader {
    static BufferedReader reader;
    static StringTokenizer tokenizer;

    /** call this method to initialize reader for InputStream */
    static void init(InputStream input) {
        reader = new BufferedReader(
                     new InputStreamReader(input) );
        tokenizer = new StringTokenizer("");
    }

    /** get next word */
    static String next() throws IOException {
        while ( ! tokenizer.hasMoreTokens() ) {
            //TODO add check for eof if necessary
            tokenizer = new StringTokenizer(
                   reader.readLine() );
        }
        return tokenizer.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt( next() );
    }
	
    static double nextDouble() throws IOException {
        return Double.parseDouble( next() );
    }
}
