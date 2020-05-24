// CERC 2012
// Problem B: Who wants to live forever?
// O(n log n) solution
// Author: Lech Duraj

import java.util.Scanner;
import java.util.ArrayList;
public class B
{
  public static Boolean go(ArrayList<Integer> A)
  {
    int n = A.size();
    Boolean allzero = true;
    for(int i=0; i<n; i++)
      if (A.get(i)==1)
        allzero = false;
    if (allzero)
      return true;
    if (n==1)
      return true;
    if (n%2==0)
      return false;
    ArrayList<Integer> even = new ArrayList<Integer>();
    ArrayList<Integer> odd = new ArrayList<Integer>();
    for(int i=1; i<n; i+=2)
    {
      even.add(A.get(i));
      odd.add(A.get(i-1)^A.get(i+1));
    }
    return go(odd) && go(even);
  }

  public static void main(String args[])
  {
       Scanner in = new Scanner(System.in); 
       int TT = in.nextInt();
       in.nextLine();
       while(TT>0)
       {
         TT--;
         String s = in.nextLine();
         int n = s.length();
         ArrayList<Integer> A = new ArrayList<Integer>();
         for(int i=0; i<n; i++)
           A.add(s.charAt(i)-'0');
         if (go(A))
           System.out.println("DIES");
         else
           System.out.println("LIVES");
       }
   }
}
