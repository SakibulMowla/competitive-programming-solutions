// CERC 2012
// Problem G: Jewel heist
// Model solution, O(n log n)
// Author: Jakub Pachocki

import java.io.*;
import java.util.*;

import com.sun.org.apache.bcel.internal.generic.IREM;

class Solver {
	
	class Point implements Comparable<Point> {
		int x, y, color;
		
		@Override
		public int compareTo(Point o) {
			if (y != o.y) {
				return y < o.y ? -1 : 1;
			} else {
				return x < o.x ? -1 : x > o.x ? 1 : 0;
			}
		}
	}
	
	int[] sum;
	int z;
	
	void add(int x) {
		while (x < z) {
			++sum[x];
			x += x & -x;
		}
	}
	
	int sum_to(int x) {
		int res = 0;
		while (x > 0) {
			res += sum[x];
			 x -= x & -x;
		}
		return res;
	}
	
	void solve() throws IOException {
		Reader.init(System.in);
		int n_cases = Reader.nextInt();
		while (n_cases-- > 0) {
			long BASE = 2 * (long) 1e9;
			int n = Reader.nextInt();
			int k = Reader.nextInt();
			ArrayList<TreeSet<Integer>> colorSets = new ArrayList<TreeSet<Integer>>(k);
			ArrayList<Point> p = new ArrayList<Point>(n);
			TreeSet<Integer> xs = new TreeSet<Integer>();
			for (int i = 0; i < n; ++i) {
				p.add(new Point());
				p.get(i).x = Reader.nextInt();
				xs.add(p.get(i).x);
				p.get(i).y = Reader.nextInt();
				p.get(i).color = Reader.nextInt();
				--p.get(i).color;
			}
			xs.add((int) 1e9 + 5);
			xs.add(-5);
			HashMap<Integer, Integer> renamed = new HashMap<Integer, Integer>();
			z = 0;
			for (int x: xs) {
				renamed.put(x, ++z);
			}
			sum = new int[z + 1];
			for (int i = 0; i < k; ++i) {
				colorSets.add(new TreeSet<Integer>());
			}
			int result = 0;
			Collections.sort(p);
			int last = 0;
			for (int i = 0; i < n; ++i) {
				int l = -1;
				int r = (int) 1e9 + 1;
				int x = p.get(i).x;
				int y = p.get(i).y;
				int color = p.get(i).color;
				SortedSet<Integer> head = colorSets.get(color).headSet(x + 1);
				SortedSet<Integer> tail = colorSets.get(color).tailSet(x);
				if (!head.isEmpty()) {
					l = head.last() + 1;
				}
				if (!tail.isEmpty()) {
					r = tail.first() - 1;
				}
				if (l <= r) {
					result = Math.max(result, sum_to(renamed.get(xs.headSet(r + 1).last())) - sum_to(renamed.get(xs.headSet(l).last())));
				}
				if (i + 1 == n || p.get(i + 1).y != y) {
					for (int j = last; j <= i; ++j) {
						add(renamed.get(p.get(j).x));
						colorSets.get(p.get(j).color).add(p.get(j).x);
					}
					last = i + 1;
				}
			}
			for (int i = 0; i < k; ++i) {
				Iterator<Integer> it = colorSets.get(i).iterator();
				int l = -1;
				while (it.hasNext()) {
					int r = it.next() - 1;
					if (l <= r) {
						result = Math.max(result, sum_to(renamed.get(xs.headSet(r + 1).last())) - sum_to(renamed.get(xs.headSet(l).last())));
					}
					l = r + 2;
				}
				int r = (int) 1e9 + 1;
				if (l <= r) {
					result = Math.max(result, sum_to(renamed.get(xs.headSet(r + 1).last())) - sum_to(renamed.get(xs.headSet(l).last())));
				}
			}
			System.out.println(result);
		}
		
	}
}

public class G {

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
