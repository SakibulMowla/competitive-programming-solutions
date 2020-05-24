import java.math.*;
import java.util.*;
import java.io.*;

//class SuperLuckyNumbers{
class Main{
	
	static BigInteger dp[][] = new BigInteger[110][2];
	static int col[][] = new int[110][2];
	static int N, b;
	
	static BigInteger solve(int indx, int pre) {
		if(indx == N)
			return new BigInteger("1");
		if(col[indx][pre] == 1)
			return dp[indx][pre];
		
		col[indx][pre] = 1;
		BigInteger ret = new BigInteger("0");
		
		int i, strt, npre;
		if(indx == 0) strt = 1;
		else strt = 0;
		
		for(i=strt; i<b; i++){
			if(i==3 && pre==1) continue;
			if(i == 1) npre = 1;
			else npre = 0;
			
			ret = ret.add(solve(indx+1, npre));
		}
		
		return dp[indx][pre] = ret;
	}
	
	public static void main(String args[]) {
		Scanner scanner = new Scanner(new BufferedInputStream (System.in));
		
		int i;
		
		while(true){
		
			b = scanner.nextInt();
			N = scanner.nextInt();
			if(b == 0 && N == 0) break;
			
			for(i=0; i<=N; i++) col[i][0] = col[i][1] = 0; 
			
			System.out.println(solve(0, 0));
		}
	}
}

//SuperLuckyNumbers