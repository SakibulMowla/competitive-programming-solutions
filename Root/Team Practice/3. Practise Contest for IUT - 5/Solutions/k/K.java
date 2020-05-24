// CERC 2012
// Problem K: Graphic Madness
// Alternative solution, O(n)
// Author: Adam Polak

import java.util.*;

public class K {

  private static final Scanner in = new Scanner(System.in);

  private static class DfsException extends Exception {}

  private static boolean dfs(String node, String parent,
                             Map<String, List<String>> edges,
                             List<String> path) throws DfsException {
    if (node.charAt(1) == 'S') return true;
    int d = 0;
    for (String next : edges.get(node))
      if (!next.equals(parent)) {
        if (dfs(next, node, edges, path)) {
          path.add(next + "-" + node);
          d++;
        }
      }
    if (d == 1)
      return true;
    else if (d == 2)
      return false;
    else
      throw new DfsException();
  }

  private static List<String> makePath(int nodes) throws DfsException {
    Map<String, List<String>> edges = new HashMap<String, List<String>>();
    String notLeaf = null;
    for (int i = 0; i < nodes - 1; ++i) {
      String a = in.next();
      String b = in.next();
      if (!edges.containsKey(a)) edges.put(a, new LinkedList<String>());
      edges.get(a).add(b);
      if (!edges.containsKey(b)) edges.put(b, new LinkedList<String>());
      edges.get(b).add(a);
      if (notLeaf == null) {
        if (a.charAt(1) != 'S') notLeaf = a;
        if (b.charAt(1) != 'S') notLeaf = b;
      }
    }

    List<String> path = new LinkedList<String>();
    dfs(notLeaf, "NO PARENT", edges, path);
    return path;
  }

  private static List<String> verifyCycle(List<String> path) {
    Map<String, List<String>> edges = new HashMap<String, List<String>>();
    String start1 = null, start2 = null;
    for (String s : path) {
      String a = s.substring(0, s.indexOf('-'));
      String b = s.substring(s.indexOf('-') + 1);
      if (!edges.containsKey(a)) edges.put(a, new LinkedList<String>());
      edges.get(a).add(b);
      if (!edges.containsKey(b)) edges.put(b, new LinkedList<String>());
      edges.get(b).add(a);

      if (start1 == null) {
        start1 = a;
        start2 = b;
      }
    }

    List<String> cycle = new LinkedList<String>();
    String cur = start1, prev = start2;
    for (int i = 0; i < path.size(); ++i) {
      cycle.add(cur);

      String next = null;
      for (String a : edges.get(cur))
        if (!a.equals(prev))
          next = a;
      if (next == null) return null;
      prev = cur;
      cur = next;
    }

    Set<String> repetitions = new HashSet<String>();
    for (String s : cycle) repetitions.add(s);
    if (cycle.size() != repetitions.size()) return null;

    return cycle;
  }

  public static void main(String[] args) {
    int Z = in.nextInt();
    while (Z-- > 0) {
      int k = in.nextInt();
      int n = in.nextInt();
      int m = in.nextInt();

      List<String> path = new LinkedList<String>();
      boolean err = false;
      try {
        path.addAll(makePath(k + n));
      } catch (DfsException e) { err = true; }
      try {
        path.addAll(makePath(k + m));
      } catch (DfsException e) { err = true; }
      for (int i = 0; i < k; ++i)
        path.add(in.next() + "-" + in.next());

      if (err) {
        System.out.println("NO");
        continue;
      }

      List<String> cycle = verifyCycle(path);

      if (cycle == null) {
        System.out.println("NO");
      } else {
        System.out.print("YES");
        for (String s : cycle) System.out.print(" " + s);
        System.out.println();
      }
    }
  }
}
