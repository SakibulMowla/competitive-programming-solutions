
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

struct Bigint
{
    // representations and structures
    string a; // to store the digits
    int sign; // sign = -1 for negative numbers, sign = 1 otherwise

    // constructors
    Bigint() {} // default constructor
    Bigint( string b )
    {
        (*this) = b;    // constructor for string
    }

    // some helpful methods
    int size()   // returns number of digits
    {
        return a.size();
    }
    Bigint inverseSign()   // changes the sign
    {
        sign *= -1;
        return (*this);
    }
    Bigint normalize( int newSign )   // removes leading 0, fixes sign
    {
        for( int i = a.size() - 1; i > 0 && a[i] == '0'; i-- )
            a.erase(a.begin() + i);
        sign = ( a.size() == 1 && a[0] == '0' ) ? 1 : newSign;
        return (*this);
    }

    // assignment operator
    void operator = ( string b )   // assigns a string to Bigint
    {
        a = b[0] == '-' ? b.substr(1) : b;
        reverse( a.begin(), a.end() );
        this->normalize( b[0] == '-' ? -1 : 1 );
    }

    // conditional operators
    bool operator < ( const Bigint &b ) const   // less than operator
    {
        if( sign != b.sign ) return sign < b.sign;
        if( a.size() != b.a.size() )
            return sign == 1 ? a.size() < b.a.size() : a.size() > b.a.size();
        for( int i = a.size() - 1; i >= 0; i-- ) if( a[i] != b.a[i] )
                return sign == 1 ? a[i] < b.a[i] : a[i] > b.a[i];
        return false;
    }
    bool operator == ( const Bigint &b ) const   // operator for equality
    {
        return a == b.a && sign == b.sign;
    }



    // mathematical operators
    Bigint operator + ( Bigint b )   // addition operator overloading
    {
        if( sign != b.sign ) return (*this) - b.inverseSign();
        Bigint c;
        for(int i = 0, carry = 0; i<a.size() || i<b.size() || carry; i++ )
        {
            carry+=(i<a.size() ? a[i]-48 : 0)+(i<b.a.size() ? b.a[i]-48 : 0);
            c.a += (carry % 10 + 48);
            carry /= 10;
        }
        return c.normalize(sign);
    }
    Bigint operator - ( Bigint b )   // subtraction operator overloading
    {
        if( sign != b.sign ) return (*this) + b.inverseSign();
        int s = sign;
        sign = b.sign = 1;
        if( (*this) < b ) return ((b - (*this)).inverseSign()).normalize(-s);
        Bigint c;
        for( int i = 0, borrow = 0; i < a.size(); i++ )
        {
            borrow = a[i] - borrow - (i < b.size() ? b.a[i] : 48);
            c.a += borrow >= 0 ? borrow + 48 : borrow + 58;
            borrow = borrow >= 0 ? 0 : 1;
        }
        return c.normalize(s);
    }
    Bigint operator * ( Bigint b )   // multiplication operator overloading
    {
        Bigint c("0");
        for( int i = 0, k = a[i] - 48; i < a.size(); i++, k = a[i] - 48 )
        {
            while(k--) c = c + b; // ith digit is k, so, we add k times
            b.a.insert(b.a.begin(), '0'); // multiplied by 10
        }
        return c.normalize(sign * b.sign);
    }
    Bigint operator / ( Bigint b )   // division operator overloading
    {
        if( b.size() == 1 && b.a[0] == '0' ) b.a[0] /= ( b.a[0] - 48 );
        Bigint c("0"), d;
        for( int j = 0; j < a.size(); j++ ) d.a += "0";
        int dSign = sign * b.sign;
        b.sign = 1;
        for( int i = a.size() - 1; i >= 0; i-- )
        {
            c.a.insert( c.a.begin(), '0');
            c = c + a.substr( i, 1 );
            while( !( c < b ) ) c = c - b, d.a[i]++;
        }
        return d.normalize(dSign);
    }
    Bigint operator % ( Bigint b )   // modulo operator overloading
    {
        if( b.size() == 1 && b.a[0] == '0' ) b.a[0] /= ( b.a[0] - 48 );
        Bigint c("0");
        b.sign = 1;
        for( int i = a.size() - 1; i >= 0; i-- )
        {
            c.a.insert( c.a.begin(), '0');
            c = c + a.substr( i, 1 );
            while( !( c < b ) ) c = c - b;
        }
        return c.normalize(sign);
    }



    // output method
    void print()
    {
        if( sign == -1 ) putchar('-');
        for( int i = a.size() - 1; i >= 0; i-- ) putchar(a[i]);
    }
};

using namespace  std;

typedef long long ll;

//ll bigmod(ll a,ll b,ll m)
//{
//    if(b == 0) return 1%m;
//    ll x = bigmod(a,b/2,m);
//    x = (x * x) % m;
//    if(b % 2 == 1) x = (x * a) % m;
//    return x;
//}
//
//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way
//
//template <class T> T gcd(T a, T b)
//{
//    while(b == 0) return a;
//    return gcd(b,a%b);
//}
//
//template <class T> T lcm(T a, T b)
//{
//    return (a/gcd(a,b)) * b;
//}

typedef pair<ll,ll> pii;
const ll inf = 1<<28;
#define MP(a,b) make_pair(a,b)
#define SZ 1010

int mark[300];

Bigint f(ll c)
{
    Bigint b;
    if(c==0)
        b = "0";
    if(c==1)
        b = "1";
    if(c==2)
        b = "2";
    if(c==3)
        b = "3";
    if(c==4)
        b = "4";
    if(c==5)
        b = "5";
    if(c==6)
        b = "6";
    if(c==7)
        b = "7";
    if(c==8)
        b = "8";
    if(c==9)
        b = "9";
    if(c==10)
        b = "10";
    return b;
}

int main()
{
    ll n, m, i, j, k, chalu;

    Bigint ans, ten, nine;

    string s;

    while(cin >> s)
    {
        chalu = 10;
        memset(mark,0,sizeof(mark));
        k = s.size();
        ans.a = "1";
        for(i=0; i<k; i++)
        {
            if(s[i] == '?')
            {
                if(i == 0) ans = ans * f(10-1);
                else ans = ans * f(10);
            }
            else if(s[i] >= '0' && s[i] <= '9')
            {
//                ans *= 1;
                    ;
            }
            else
            {
                if(mark[ s[i] ] == 0)
                {
                    mark[ s[i] ] = 1;
//                    printf("yes\n");
                    if(i == 0) ans = ans * f(chalu-1);
                    else ans = ans * f(chalu);
//                    printf("yes1\n");
                    chalu--;
                }
            }
        }

        ans.print();
        printf("\n");
    }

    return 0;
}
