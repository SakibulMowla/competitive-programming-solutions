import java.math.*;
import java.util.*;
import java.io.*;

class Main{
	
	static BigInteger dp[][] = new BigInteger[10010][110];
	static int col[][] = new int[10010][110];
	static String str, txt;
	static int N, M;
	
	static BigInteger solve(int indx1, int indx2)
	{
		if(indx2 == M)
			return new BigInteger("1");
		if(indx1 == N)
			return new BigInteger("0");
		if(col[indx1][indx2] == 1)
			return dp[indx1][indx2];
		
		col[indx1][indx2] = 1;
			
		BigInteger ret = new BigInteger("0");
		
		if(str.charAt(indx1) == txt.charAt(indx2))
			ret = ret.add(solve(indx1+1, indx2+1));
		ret = ret.add(solve(indx1+1, indx2));
		
		return dp[indx1][indx2] = ret;
	}
	
	public static void main(String args[])
	{
		Scanner scanner = new Scanner(new BufferedInputStream (System.in));
		//BigInteger b = new BigInteger("100");
		int t, i, j;
		
		t = scanner.nextInt();
		
		while(t > 0)
		{
			t--;
			str = scanner.next();
			txt = scanner.next();
		
			N = str.length();
			M = txt.length();
			
			for(i=0; i<=N; i++)
				for(j=0; j<=M; j++)
					col[i][j] = 0;
				
			System.out.println(solve(0, 0));
		}
	}
}

//Distinct_Subsequences