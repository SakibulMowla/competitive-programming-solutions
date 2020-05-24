#include"iostream"
int n,i,t;
main()
{
    std::cin>>n;
    while(n--)std::cin>>i,t+=i>0?i:0;
    std::cout<<t;
}
