// CERC 2012
// Problem F: Farm and factory
// Alternative solution, O(n + m log n)
// Author: Adam Polak

import java.util.*;

public class F {

  static class Edge {
    final int v;
    final long c;
    Edge(int v, long c) {
      this.v = v;
      this.c = c;
    }
  }

  static class QueueElement implements Comparable<QueueElement> {
    final int v;
    final long d;
    QueueElement(int v, long d) {
      this.v = v;
      this.d = d;
    }
    public int compareTo(QueueElement that) {
      if (this.d != that.d) return this.d < that.d ? -1 : 1;
      if (this.v != that.v) return this.v < that.v ? -1 : 1;
      return 0;
    }
  }

  static long[] shortestPaths(int n, Vector<List<Edge>> edges, int source) {
   long[] d = new long[n];
    TreeSet<QueueElement> q = new TreeSet<QueueElement>();
    for (int i = 0; i < n; ++i)
      d[i] = 1000000000000L;  // INF
    d[source] = 0;
    q.add(new QueueElement(source, 0));

    while (!q.isEmpty()) {
      int u = q.first().v;
      long cur_d = q.first().d;
      q.remove(q.first());
      if (d[u] < cur_d) continue;
      for (Edge edge : edges.elementAt(u))
        if (d[edge.v] > cur_d + edge.c) {
          d[edge.v] = cur_d + edge.c;
          q.add(new QueueElement(edge.v, d[edge.v]));
        }
    }

    return d;
  }

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int Z = in.nextInt();
    while (Z-- > 0) {
      int n, m;
      n = in.nextInt();
      m = in.nextInt();
      Vector<List<Edge>> edges = new Vector<List<Edge>>();
      for (int i = 0; i < n; ++i) edges.add(new LinkedList<Edge>());
      for (int i = 0; i < m; ++i) {
        int u = in.nextInt() - 1;
        int v = in.nextInt() - 1;
        long c = in.nextLong();
        edges.elementAt(u).add(new Edge(v, c));
        edges.elementAt(v).add(new Edge(u, c));
      }

      long dFarm[] = shortestPaths(n, edges, 0);
      long dFactory[] = shortestPaths(n, edges, 1);

      long[] x = new long[n];
      long[] y = new long[n];
      for (int i=0; i<n; ++i) {
        x[i] = dFarm[i] + dFactory[i];
        y[i] = dFarm[i] - dFactory[i];
      }

      Arrays.sort(x);
      Arrays.sort(y);

      long result = 0;
      for (int i = 0; i < n; ++i)
        result += Math.abs(x[i] - x[n/2]);
      for (int i = 0; i < n; ++i)
        result += Math.abs(y[i] - y[n/2]);

      System.out.printf(Locale.US, "%.8f\n", result / (double)(2 * n));
    }
  }
}

