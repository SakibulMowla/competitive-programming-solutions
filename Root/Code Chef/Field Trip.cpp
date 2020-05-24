
#include <cstdio>
#include <cstring>
#include <string>
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

#define SZ 1010
Bigint nCr[SZ][SZ];

bool check(Bigint n,Bigint x)
{
    int i , l1 , l2;
    l1 = n.size();
    l2 = x.size();
    if(l1 > l2) return true;
    if(l1 < l2) return false;

    for(i=l1-1;i>=0;i--)
    {
        if(n.a[i] < x.a[i])
            return false;
        else if(n.a[i] > x.a[i])
            return true;
    }

    return true;
}

string to_string(int n)
{
    string s;
    string ch;
    while(n)
    {
        ch = (n % 10) + '0';
        s.insert(0,ch);
        n /= 10;
    }
    return s;
}

void combination()
{
    int i,j;

    for(i=0;i<SZ;i++)
    {
        for(j=0;j*2<=i;j++)
        {
//            printf("i = %d j = %d\n",i,j);
            if(i == j || j == 0) nCr[i][j] = "1";
            else if(j == 1) nCr[i][j] = to_string(i);
            else nCr[i][j] = nCr[i-1][j] + nCr[i-1][j-1];
            nCr[i][i-j] = nCr[i][j];
        }
    }
}

string vag(Bigint a , Bigint b)
{
    Bigint tmp , c , mod;
    string ans , p;

    c = a / b;

    p = c.a;

    reverse(p.begin() , p.end());

    ans = ans + p;

    mod = a % b;

    if(mod.a == "0") return ans;

    ans += '.';

    a = mod;
    if(a < b)
        a.a.insert(0,"0");
    int i;
    for(i=0;i<8;i++)
    {

        if(a < b)
        {
            a.a.insert(0,"0");
            while(a<b)
            a.a.insert(0,"0") , ans += '0';
        }
        c = a / b;
        ans = ans + c.a;
        a = a % b;
        if(a.a == "0") return ans;
    }

    return ans;

}

int main()
{
    combination();

    int i,j,s,n,m,k,t;

    Bigint a , b , c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d",&s,&n,&m,&k);
        if(k+1 > n)
        {
            printf("0.0000000\n");
        }
        else if(s == n)
        {
            printf("1.00000000\n");
        }
        else
        {
            a.a.clear();
            b.a.clear();
            c.a.clear();
            a = "0";
            for(i=m-1;i>=k;i--)
            {
//                printf("i = %d\n",i);
                c = nCr[m-1][i] * nCr[s-m][n-i-1];
//                printf("i\n");
                a = a + c;
//                printf("i\n");
            }
            b = nCr[s-1][n-1];
//            a.print() ; cout << endl;
//            b.print() ; cout << endl;
            printf("%s\n",vag(a,b).c_str());
        }
    }

    return 0;
}
