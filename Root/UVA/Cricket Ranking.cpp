#include <cstdio>
#include <cstring>
#include <iostream>
#include <assert.h>

using namespace std;
typedef long long ll;
const int MAXN = 1005;

struct bign {
    int len;
    ll num[MAXN];

    bign () {
	len = 0;
	memset(num, 0, sizeof(num));
    }
    bign (ll number) {*this = number;}
    bign (const char* number) {*this = number;}

    void DelZero ();
    void Put ();

    void operator = (ll number);
    void operator = (char* number);

    bool operator <  (const bign& b) const;
    bool operator >  (const bign& b) const { return b < *this; }
    bool operator <= (const bign& b) const { return !(b < *this); }
    bool operator >= (const bign& b) const { return !(*this < b); }
    bool operator != (const bign& b) const { return b < *this || *this < b;}
    bool operator == (const bign& b) const { return !(b != *this); }

    void operator ++ ();
    void operator -- ();
    bign operator + (const int& b);
    bign operator + (const bign& b);
    bign operator - (const int& b);
    bign operator - (const bign& b);
    bign operator * (const ll& b);
    bign operator * (const bign& b);
    bign operator / (const ll& b);
    //bign operator / (const bign& b);
    int operator % (const int& b);
};


bign nCr(ll n, ll r)
{
    bign ans = 1LL;
    int i;
    if(r > n-r)
        r = n-r;
    for(i=0; i<r; i++)
    {
        ans = ans * (ll)(n-i);
        ans = ans / (ll)(i+1);
    }
    return ans;
}

ll low[10], high[10];

int main()
{
    ll n, k, i, lim, mask, cnt, tot;
    bign ans1, ans2;

    while(scanf("%lld %lld",&k,&n) == 2)
    {
        for(i=0; i<k; i++)
            scanf("%lld %lld",&low[i],&high[i]);

        ans1 = 0LL;
        ans2 = 0LL;
        lim = 1<<k;

        for(mask=0; mask<lim; mask++)
        {
            cnt = 0;
            tot = n;

            for(i=0; i<k; i++)
            {
                if(mask & (1<<i))
                    cnt++, tot -= (high[i]+1);
                else
                    tot -= low[i];
            }

            if(tot < 0) continue;

            if(cnt & 1) ans2 = ans2 + nCr(tot+k-1, k-1);
            else ans1 = ans1 + nCr(tot+k-1, k-1);
        }

        ans1 = ans1 - ans2;

        ans1.Put();
        puts("");
    }

    return 0;
}


/*********************************************/

void bign::DelZero () {
    while (len && num[len-1] == 0)
	len--;

    if (len == 0) {
	num[len++] = 0;
    }
}

void bign::Put () {
    for (int i = len-1; i >= 0; i--)
	printf("%lld", num[i]);
}

void bign::operator = (char* number) {
    len = strlen (number);
    for (int i = 0; i < len; i++)
	num[i] = number[len-i-1] - '0';

    DelZero ();
}

void bign::operator = (ll number) {

    len = 0;
    while (number) {
	num[len++] = number%10;
	number /= 10;
    }

    DelZero ();
}

bool bign::operator < (const bign& b) const {
    if (len != b.len)
	return len < b.len;
    for (int i = len-1; i >= 0; i--)
	if (num[i] != b.num[i])
	    return num[i] < b.num[i];
    return false;
}

void bign::operator ++ () {
    int s = 1;

    for (int i = 0; i < len; i++) {
	s = s + num[i];
	num[i] = s % 10;
	s /= 10;
	if (!s) break;
    }

    while (s) {
	num[len++] = s%10;
	s /= 10;
    }
}

void bign::operator -- () {
    if (num[0] == 0 && len == 1) return;

    int s = -1;
    for (int i = 0; i < len; i++) {
	s = s + num[i];
	num[i] = (s + 10) % 10;
	if (s >= 0) break;
    }
    DelZero ();
}

bign bign::operator + (const int& b) {
    bign a = b;
    return *this + a;
}

bign bign::operator + (const bign& b) {
    int bignSum = 0;
    bign ans;

    for (int i = 0; i < len || i < b.len; i++) {
	if (i < len) bignSum += num[i];
	if (i < b.len) bignSum += b.num[i];

	ans.num[ans.len++] = bignSum % 10;
	bignSum /= 10;
    }

    while (bignSum) {
	ans.num[ans.len++] = bignSum % 10;
	bignSum /= 10;
    }

    return ans;
}

bign bign::operator - (const int& b) {
    bign a = b;
    return *this - a;
}


bign bign::operator - (const bign& b) {
    ll bignSub = 0;
    bign ans;
    for (int i = 0; i < len || i < b.len; i++) {
	bignSub += num[i];
	if (i < b.len)
	    bignSub -= b.num[i];
	ans.num[ans.len++] = (bignSub + 10) % 10;
	if (bignSub < 0) bignSub = -1;
	else bignSub = 0;
    }
    ans.DelZero();
    return ans;
}

bign bign::operator * (const ll& b) {
    ll bignSum = 0;
    bign ans;

    ans.len = len;
    for (int i = 0; i < len; i++) {
	bignSum += num[i] * b;
	ans.num[i] = bignSum % 10;
	bignSum /= 10;
    }

    while (bignSum) {
	ans.num[ans.len++] = bignSum % 10;
	bignSum /= 10;
    }

    return ans;
}

bign bign::operator * (const bign& b) {
    bign ans;
    ans.len = 0;

    for (int i = 0; i < len; i++){
	int bignSum = 0;

	for (int j = 0; j < b.len; j++){
	    bignSum += num[i] * b.num[j] + ans.num[i+j];
	    ans.num[i+j] = bignSum % 10;
	    bignSum /= 10;
	}
	ans.len = i + b.len;

	while (bignSum){
	    ans.num[ans.len++] = bignSum % 10;
	    bignSum /= 10;
	}
    }
    return ans;
}

bign bign::operator / (const ll& b) {

    bign ans;

    ll s = 0;
    for (int i = len-1; i >= 0; i--) {
	s = s * 10 + num[i];
	ans.num[i] = s/b;
	s %= b;
    }

    ans.len = len;
    ans.DelZero();
    return ans;
}

int bign::operator % (const int& b) {

    bign ans;

    int s = 0;
    for (int i = len-1; i >= 0; i--) {
	s = s * 10 + num[i];
	ans.num[i] = s/b;
	s %= b;
    }

    return s;
}
