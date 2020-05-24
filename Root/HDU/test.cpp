
# include<stdio.h>

const int nMax=500000;

int in[nMax+1], que[nMax], head, tail, n, m;
long long sum[nMax+1], dp[nMax+1];

void SetDP(int i, int k){dp[i]=dp[k]+(sum[i]-sum[k])*(sum[i]-sum[k])+m;}
long long F(int i){return dp[i]+sum[i]*sum[i];}
long long G(int i){return sum[i]<<1;}
long long H(int i){return sum[i];}

int main(){
    sum[0]=dp[0]=0;
    while(~scanf("%d%d", &n, &m)){
        head=tail=0;
        que[tail++]=0;
        for(int i=1; i<=n; i++){
            scanf("%d", in+i);
            sum[i]=sum[i-1]+in[i];
            /*
                循环弹出队首直到队列里只剩一个元素或队首的两个元素间斜率不满足要求
            */
            while(tail>head+1){
                int l=que[head], r=que[head+1];
                if(F(l)-F(r) >= H(i)*(G(l)-G(r))) head++;
                else break;
            }
            //得到DP值
            SetDP(i, que[head]);
            /*
                循环删除队尾直到队列里只剩一个元素或满足队列中连续元素间斜率递增
            */
            while(tail>head+1){
                int l=que[tail-2], m=que[tail-1], r=i;
                if((G(r)-G(m))*(F(m)-F(l)) >= (F(r)-F(m))*(G(m)-G(l))) tail--;
                else break;
            }
            //加入i点
            que[tail++]=i;
        }
        printf("%lld\n", dp[n]);
    }
    return 0;
}
