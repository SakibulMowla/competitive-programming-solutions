#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>
#include <deque>
#include <assert.h>

//#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

void RD(int &x){scanf("%d",&x);}
void RD(ll &x){scanf("%lld",&x);}
void RD(double &x){scanf("%lf",&x);}
void RD(int &x,int &y){scanf("%d%d",&x,&y);}
void RD(ll &x,ll &y){scanf("%lld%lld",&x,&y);}
void RD(double &x,double &y){scanf("%lf%lf",&x,&y);}
void RD(char *s){scanf("%s",s);}
void RD(char &s){scanf("%c",&s);}
void RD(string &s){cin>>s;}

void PR(int x) {printf("%d\n",x);}
void PR(int x,int y) {printf("%d %d\n",x,y);}
void PR(ll x) {printf("%lld\n",x);}
void PR(char x) {printf("%c\n",x);}
void PR(char *x) {printf("%s\n",x);}
void PR(string x) {cout<<x<<endl;}

//inline void inp( int &n ){
//    n=0;
//    int ch=getchar_unlocked();int sign=1;
//    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
//    while(  ch >= '0' && ch <= '9' )
//            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
//    n=n*sign;
//}


#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define REP2(i,a,b) for((i)=a;(i)>=(int)(b);(i)--)
#define snuke(c, itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back
#define ssort(a) stable_sort(a.begin(), a.end())

#define X first
#define Y second

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//template <class T> T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
//template <class T> T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
const ll mod = 1LL;

#define SZ  100010

ll ans[] = {0LL, 0LL, 0LL, 2LL, 11LL, 30LL, 68LL, 124LL, 213LL, 330LL, 498LL, 698LL, 967LL, 1286LL, 1686LL, 2152LL, 2699LL, 3340LL, 4100LL, 4918LL, 5911LL, 6974LL, 8220LL, 9546LL, 11051LL, 12722LL, 14548LL, 16550LL, 18731LL, 21072LL, 23688LL, 26414LL, 29443LL, 32664LL, 36146LL, 39802LL, 43793LL, 47976LL, 52544LL, 57272LL, 62349LL, 67682LL, 73412LL, 79386LL, 85723LL, 92404LL, 99418LL, 106802LL, 114547LL, 122596LL, 131252LL, 140078LL, 149525LL, 159108LL, 169344LL, 179914LL, 191011LL, 202568LL, 214552LL, 226926LL, 239975LL, 253322LL, 267436LL, 281942LL, 296839LL, 312452LL, 328606LL, 345230LL, 362553LL, 380332LL, 398966LL, 417648LL, 437375LL, 457786LL, 478808LL, 500240LL, 522537LL, 545332LL, 569084LL, 593082LL, 618271LL, 643942LL, 670310LL, 697428LL, 725267LL, 754016LL, 783422LL, 813710LL, 844611LL, 876216LL, 909138LL, 942226LL, 976825LL, 1011858LL, 1047744LL, 1084658LL, 1122187LL, 1160828LL, 1200430LL, 1240816LL, 1282359LL, 1324238LL, 1367894LL, 1411792LL, 1457075LL, 1503044LL, 1550478LL, 1598410LL, 1647753LL, 1697626LL, 1749160LL, 1801192LL, 1854589LL, 1909012LL, 1964594LL, 2021162LL, 2078895LL, 2137780LL, 2197698LL, 2258586LL, 2320819LL, 2384300LL, 2449036LL, 2514968LL, 2581973LL, 2649926LL, 2719522LL, 2790000LL, 2862029LL, 2935256LL, 3010052LL, 3085168LL, 3162755LL, 3240750LL, 3320618LL, 3401552LL, 3483841LL, 3567500LL, 3652808LL, 3738934LL, 3827297LL, 3916204LL, 4006964LL, 4099166LL, 4192283LL, 4287438LL, 4384436LL, 4482120LL, 4581725LL, 4682234LL, 4784922LL, 4888738LL, 4994277LL, 5101528LL, 5210042LL, 5320148LL, 5431919LL, 5545698LL, 5660662LL, 5776826LL, 5895415LL, 6014812LL, 6137324LL, 6259616LL, 6385263LL, 6511822LL, 6640020LL, 6769934LL, 6901749LL, 7035038LL, 7170924LL, 7307720LL, 7446913LL, 7587352LL, 7730096LL, 7873958LL, 8019963LL, 8168492LL, 8318244LL, 8469406LL, 8623411LL, 8778102LL, 8936452LL, 9095856LL, 9256659LL, 9420004LL, 9585262LL, 9752484LL, 9921241LL, 10092186LL, 10266028LL, 10440754LL, 10617877LL, 10797376LL, 10978628LL, 11161994LL, 11347909LL, 11534510LL, 11724710LL, 11915970LL, 12110819LL, 12306162LL, 12504730LL, 12705006LL, 12908081LL, 13112580LL, 13319686LL, 13528720LL, 13740181LL, 13953626LL, 14170332LL, 14387640LL, 14609331LL, 14832276LL, 15057142LL, 15284314LL, 15514281LL, 15746158LL, 15981558LL, 16218248LL, 16457999LL, 16699020LL, 16943538LL, 17190562LL, 17438841LL, 17691272LL, 17944642LL, 18201414LL, 18460255LL, 18721304LL, 18986676LL, 19252224LL, 19521579LL, 19792476LL, 20068090LL, 20344200LL, 20623803LL, 20906158LL, 21191134LL, 21477198LL, 21766717LL, 22060086LL, 22356142LL, 22654072LL, 22954709LL, 23258276LL, 23564332LL, 23872914LL, 24185069LL, 24499148LL, 24817558LL, 25135592LL, 25459667LL, 25784746LL, 26113692LL, 26445136LL, 26779569LL, 27116514LL, 27456782LL, 27798992LL, 28145971LL, 28493934LL, 28845580LL, 29200176LL, 29557211LL, 29918712LL, 30282348LL, 30649572LL, 31019371LL, 31390296LL, 31767252LL, 32145278LL, 32528397LL, 32912894LL, 33300906LL, 33692204LL, 34086601LL, 34483954LL, 34884852LL, 35288296LL, 35695011LL, 36105178LL, 36519644LL, 36935686LL, 37356003LL, 37778914LL, 38205210LL, 38634230LL, 39067775LL, 39502892LL, 39944692LL, 40386938LL, 40832815LL, 41282652LL, 41736190LL, 42191456LL, 42651527LL, 43115510LL, 43581908LL, 44050718LL, 44525297LL, 45001840LL, 45483546LL, 45966900LL, 46454557LL, 46945166LL, 47439416LL, 47937606LL, 48439785LL, 48944378LL, 49454686LL, 49965658LL, 50481593LL, 51001858LL, 51525206LL, 52051602LL, 52583527LL, 53117046LL, 53655842LL, 54197260LL, 54741921LL, 55291862LL, 55844554LL, 56401298LL, 56961853LL, 57526152LL, 58094964LL, 58667166LL, 59242843LL, 59821464LL, 60405890LL, 60991778LL, 61584575LL, 62180270LL, 62778896LL, 63381888LL, 63987921LL, 64599400LL, 65214736LL, 65833062LL, 66457297LL, 67081930LL, 67715838LL, 68348230LL, 68988899LL, 69631316LL, 70279148LL, 70930252LL, 71586065LL, 72243962LL, 72908808LL, 73576430LL, 74248519LL, 74924616LL, 75605834LL, 76290664LL, 76979311LL, 77672078LL, 78369822LL, 79069828LL, 79776409LL, 80486302LL, 81201346LL, 81920542LL, 82644159LL, 83370414LL, 84103088LL, 84839294LL, 85579369LL, 86324532LL, 87074746LL, 87827998LL, 88586629LL, 89348526LL, 90116528LL, 90888734LL, 91663777LL, 92445336LL, 93230678LL, 94018836LL, 94815509LL, 95612922LL, 96417738LL, 97225308LL, 98037047LL, 98856154LL, 99677908LL, 100504478LL, 101336099LL, 102171254LL, 103013614LL, 103855762LL, 104708317LL, 105564182LL, 106423834LL, 107287506LL, 108157059LL, 109029790LL, 109910626LL, 110792688LL, 111682025LL, 112574662LL, 113474590LL, 114377398LL, 115285221LL, 116197444LL, 117115782LL, 118037818LL, 118965745LL, 119897754LL, 120838070LL, 121779080LL, 122728061LL, 123679566LL, 124638144LL, 125600704LL, 126569139LL, 127541868LL, 128518974LL, 129500712LL, 130491517LL, 131485030LL, 132482328LL, 133488342LL, 134495755LL, 135511478LL, 136530262LL, 137553534LL, 138583981LL, 139619446LL, 140661378LL, 141703560LL, 142755221LL, 143811462LL, 144874050LL, 145941022LL, 147012905LL, 148092262LL, 149174954LL, 150260024LL, 151356743LL, 152454192LL, 153561000LL, 154669990LL, 155786575LL, 156906686LL, 158033342LL, 159166818LL, 160303427LL, 161443468LL, 162594826LL, 163748370LL, 164910073LL, 166074520LL, 167246994LL, 168423438LL, 169602639LL, 170792444LL, 171986538LL, 173186252LL, 174391333LL, 175598680LL, 176818056LL, 178040050LL, 179268125LL, 180501724LL, 181742554LL, 182985148LL, 184238501LL, 185493018LL, 186759822LL, 188025982LL, 189301055LL, 190581174LL, 191867190LL, 193158790LL, 194458907LL, 195762956LL, 197071164LL, 198387120LL, 199708069LL, 201039060LL, 202371664LL, 203712444LL, 205059143LL, 206409224LL, 207768856LL, 209132002LL, 210504929LL, 211880510LL, 213263636LL, 214649838LL, 216046177LL, 217446756LL, 218855082LL, 220268258LL, 221687321LL, 223113338LL, 224548656LL, 225985454LL, 227431379LL, 228880116LL, 230338668LL, 231802086LL, 233269849LL, 234747036LL, 236231318LL, 237722018LL, 239215949LL, 240717184LL, 242228516LL, 243738840LL, 245262667LL, 246790782LL, 248323846LL, 249864732LL, 251412165LL, 252965580LL, 254526468LL, 256092104LL, 257666815LL, 259244500LL, 260835254LL, 262424874LL, 264027619LL, 265632278LL, 267246228LL, 268864828LL, 270489895LL, 272123992LL, 273764986LL, 275412086LL, 277067061LL, 278724662LL, 280391028LL, 282067524LL, 283746365LL, 285433312LL, 287129310LL, 288827186LL, 290536339LL, 292250020LL, 293973670LL, 295702354LL, 297436473LL, 299178726LL, 300930074LL, 302684776LL, 304449891LL, 306219104LL, 307996748LL, 309779974LL, 311571477LL, 313369166LL, 315176850LL, 316988172LL, 318810537LL, 320636236LL, 322468884LL, 324307916LL, 326157353LL, 328014764LL, 329875024LL, 331746328LL, 333624051LL, 335508710LL, 337397338LL, 339298984LL, 341205001LL, 343116202LL, 345039408LL, 346963438LL, 348901569LL, 350845460LL, 352794182LL, 354749736LL, 356714083LL, 358687200LL, 360668536LL, 362653870LL, 364651389LL, 366649324LL, 368664446LL, 370679744LL, 372701611LL, 374733520LL, 376775436LL, 378820702LL, 380876509LL, 382936512LL, 385010922LL, 387084834LL, 389172037LL, 391263076LL, 393367846LL, 395471312LL, 397588769LL, 399712404LL, 401842982LL, 403982200LL, 406126987LL, 408281508LL, 410448292LL, 412617570LL, 414793571LL, 416981348LL, 419175272LL, 421373912LL, 423584839LL, 425800040LL, 428029644LL, 430256894LL, 432501035LL, 434750296LL, 437006732LL, 439272450LL, 441544327LL, 443824670LL, 446113662LL, 448411034LL, 450718425LL, 453029596LL, 455350822LL, 457679864LL, 460014849LL, 462362480LL, 464717466LL, 467080272LL, 469448201LL, 471824596LL, 474212986LL, 476604132LL, 479011299LL, 481423624LL, 483840940LL, 486268358LL, 488704367LL, 491148790LL, 493600924LL, 496060322LL, 498531761LL, 501008778LL, 503494412LL, 505988716LL, 508492357LL, 511003812LL, 513524648LL, 516047398LL, 518587813LL, 521128854LL, 523689946LL, 526246472LL, 528821727LL, 531398682LL, 533987170LL, 536583478LL, 539186353LL, 541802316LL, 544423008LL, 547052634LL, 549692627LL, 552340926LL, 554997748LL, 557664118LL, 560337467LL, 563020802LL, 565715378LL, 568412820LL, 571126661LL, 573839802LL, 576569548LL, 579301890LL, 582045719LL, 584801206LL, 587563708LL, 590337216LL, 593114767LL, 595902836LL, 598705514LL, 601508978LL, 604327027LL, 607148012LL, 609982490LL, 612824638LL, 615679551LL, 618536958LL, 621410036LL, 624289374LL, 627174911LL, 630072808LL, 632980260LL, 635892378LL, 638818645LL, 641755490LL, 644694706LL, 647646972LL, 650607287LL, 653581758LL, 656558228LL, 659548220LL, 662548787LL, 665548964LL, 668570678LL, 671594526LL, 674631533LL, 677675112LL, 680732244LL, 683796734LL, 686868031LL, 689947500LL, 693042844LL, 696140504LL, 699254331LL, 702369880LL, 705501472LL, 708640580LL, 711790839LL, 714949134LL, 718118330LL, 721291474LL, 724476453LL, 727673410LL, 730883520LL, 734097620LL, 737324373LL, 740556698LL, 743800598LL, 747055330LL, 750318689LL, 753592610LL, 756876630LL, 760169716LL, 763473289LL, 766784718LL, 770106276LL, 773437386LL, 776779707LL, 780131024LL, 783495480LL, 786861964LL, 790250199LL, 793637936LL, 797039958LL, 800448884LL, 803868849LL, 807303256LL, 810742864LL, 814194918LL, 817655053LL, 821121610LL, 824611232LL, 828096252LL, 831597915LL, 835110088LL, 838631342LL, 842160022LL, 845704267LL, 849252254LL, 852816544LL, 856388464LL, 859969323LL, 863562352LL, 867168932LL, 870778702LL, 874401559LL, 878035846LL, 881676318LL, 885334326LL, 888992017LL, 892666750LL, 896357264LL, 900049422LL, 903757939LL, 907471682LL, 911199010LL, 914936260LL, 918682817LL, 922439478LL, 926210384LL, 929983218LL, 933776039LL, 937570996LL, 941383018LL, 945205334LL, 949036697LL, 952878746LL, 956730292LL, 960592888LL, 964469325LL, 968351264LL, 972250286LL, 976145852LL, 980064791LL, 983996386LL, 987932584LL, 991882152LL, 995838883LL, 999806592LL, 1003790136LL, 1007778282LL, 1011782813LL, 1015796136LL, 1019819884LL, 1023854844LL, 1027902277LL, 1031953412LL, 1036027392LL, 1040102732LL, 1044189675LL, 1048288450LL, 1052402564LL, 1056520174LL, 1060658841LL, 1064801636LL, 1068956950LL, 1073119980LL, 1077298371LL, 1081487756LL, 1085687996LL, 1089893636LL, 1094120277LL, 1098352082LL, 1102597034LL, 1106849860LL, 1111115023LL, 1115391518LL, 1119682030LL, 1123978892LL, 1128292289LL, 1132612714LL, 1136949728LL, 1141292718LL, 1145649599LL, 1150016402LL, 1154396576LL, 1158783982LL, 1163187149LL, 1167602734LL, 1172020234LL, 1176456968LL, 1180899797LL, 1185360856LL, 1189833246LL, 1194319274LL, 1198810907LL, 1203313700LL, 1207831740LL, 1212353614LL, 1216895057LL, 1221444284LL, 1226014214LL, 1230578102LL, 1235167289LL, 1239763496LL, 1244373010LL, 1248993656LL, 1253623569LL, 1258269710LL, 1262927266LL, 1267588704LL, 1272270609LL, 1276958248LL, 1281666744LL, 1286377248LL, 1291097745LL, 1295842104LL, 1300589184LL, 1305354312LL, 1310126795LL, 1314907974LL, 1319708374LL, 1324516372LL, 1329339497LL, 1334171022LL, 1339014078LL, 1343872374LL, 1348741681LL, 1353621780LL, 1358512436LL, 1363423074LL, 1368338449LL, 1373257390LL, 1378207372LL, 1383155126LL, 1388127455LL, 1393099286LL, 1398093280LL, 1403092934LL, 1408109365LL, 1413130942LL, 1418174714LL, 1423222478LL, 1428286515LL, 1433359394LL, 1438446994LL, 1443546930LL, 1448660839LL, 1453784036LL, 1458917338LL, 1464065556LL, 1469229427LL, 1474397428LL, 1479594284LL, 1484789650LL, 1489997613LL, 1495224446LL, 1500461612LL, 1505704910LL, 1510967135LL, 1516239952LL, 1521528614LL, 1526821424LL, 1532132499LL, 1537460138LL, 1542796822LL, 1548141222LL, 1553506025LL, 1558878236LL, 1564268904LL, 1569660156LL, 1575078443LL, 1580502582LL, 1585936358LL, 1591389054LL, 1596851039LL, 1602326250LL, 1607812792LL, 1613319396LL, 1618834379LL, 1624355678LL, 1629897204LL, 1635450492LL, 1641017161LL, 1646591046LL, 1652187168LL, 1657788330LL, 1663400577LL, 1669034962LL, 1674677622LL, 1680334198LL, 1686008379LL, 1691683576LL, 1697377740LL, 1703087876LL, 1708808603LL, 1714543602LL, 1720288930LL, 1726049318LL, 1731826991LL, 1737608408LL, 1743415158LL, 1749225376LL, 1755048583LL, 1760886392LL, 1766742024LL, 1772607610LL, 1778487249LL, 1784383054LL, 1790286670LL, 1796201350LL, 1802133113LL, 1808077322LL, 1814042028LL, 1820013252LL, 1825999833LL, 1831996446LL, 1838012158LL, 1844035588LL, 1850074357LL, 1856130064LL, 1862198538LL, 1868269978LL, 1874366383LL, 1880473160LL, 1886596954LL, 1892727994LL, 1898876493LL, 1905034940LL, 1911214000LL, 1917397746LL, 1923603787LL, 1929817982LL, 1936046480LL, 1942290124LL, 1948545619LL, 1954817070LL, 1961104286LL, 1967395982LL, 1973712645LL, 1980026286LL, 1986375114LL, 1992722426LL, 1999092851LL, 2005481704LL, 2011870736LL, 2018277368LL, 2024699573LL, 2031133808LL, 2037590422LL, 2044048790LL, 2050527229LL, 2057017486LL, 2063529198LL, 2070043604LL, 2076583171LL, 2083130478LL, 2089688356LL, 2096264324LL, 2102852661LL, 2109455504LL, 2116083104LL, 2122710044LL, 2129356929LL, 2136018078LL, 2142694792LL, 2149384854LL, 2156084869LL, 2162806546LL, 2169538172LL, 2176280250LL, 2183042587LL, 2189814282LL, 2196605140LL, 2203411088LL, 2210226163LL, 2217055862LL, 2223904854LL, 2230766750LL, 2237641939LL, 2244531312LL, 2251441318LL, 2258352708LL, 2265287467LL, 2272234380LL, 2279192438LL, 2286173164LL, 2293162229LL, 2300170538LL, 2307188698LL, 2314219424LL, 2321272981LL, 2328334160LL, 2335421796LL, 2342504148LL, 2349616301LL, 2356738252LL, 2363876262LL, 2371026402LL, 2378198699LL, 2385371026LL, 2392571952LL, 2399778344LL, 2407010531LL, 2414247088LL, 2421501128LL, 2428774424LL, 2436053759LL, 2443357608LL, 2450671678LL, 2458002960LL, 2465350571LL, 2472704628LL, 2480082930LL, 2487464266LL, 2494875811LL, 2502291156LL, 2509728110LL, 2517178886LL, 2524644481LL, 2532115854LL, 2539622234LL, 2547123884LL, 2554648493LL, 2562189102LL, 2569746008LL, 2577318444LL, 2584902065LL, 2592504332LL, 2600118002LL, 2607739420LL, 2615389337LL, 2623050010LL, 2630737830LL, 2638423496LL, 2646131407LL, 2653856144LL, 2661595812LL, 2669343860LL, 2677114075LL, 2684898404LL, 2692696100LL, 2700507324LL, 2708346097LL, 2716188140LL, 2724048602LL, 2731924626LL, 2739824367LL, 2747727094LL, 2755653304LL, 2763581664LL, 2771544989LL, 2779511986LL, 2787497436LL, 2795499146LL, 2803509087LL, 2811547272LL, 2819593068LL, 2827667396LL, 2835741215LL, 2843832460LL, 2851946376LL, 2860071672LL, 2868212001LL, 2876371834LL, 2884550162LL, 2892738262LL, 2900943289LL, 2909159498LL, 2917402436LL, 2925649046LL, 2933916555LL, 2942200394LL, 2950508912LL, 2958826128LL, 2967157705LL, 2975504826LL, 2983871422LL, 2992248076LL, 3000647317LL, 3009060108LL, 3017492078LL, 3025931462LL, 3034391409LL, 3042869564LL, 3051368278LL, 3059869744LL, 3068395075LL, 3076940398LL, 3085494774LL, 3094070474LL, 3102663193LL, 3111265392LL, 3119887434LL, 3128531510LL, 3137186311LL, 3145854658LL, 3154543194LL, 3163245048LL, 3171969921LL, 3180702228LL, 3189458186LL, 3198221820LL, 3207007835LL, 3215814866LL, 3224635958LL, 3233466032LL, 3242320911LL, 3251186286LL, 3260074784LL, 3268970542LL, 3277888485LL, 3286822254LL, 3295778194LL, 3304741224LL, 3313725247LL, 3322728056LL, 3331747736LL, 3340774756LL, 3349831943LL, 3358891346LL, 3367981834LL, 3377072366LL, 3386200661LL, 3395330854LL, 3404481132LL, 3413647434LL, 3422825597LL, 3432035886LL, 3441251794LL, 3450486860LL, 3459744617LL, 3469005996LL, 3478294182LL, 3487597762LL, 3496913429LL, 3506255126LL, 3515603688LL, 3524971112LL, 3534364383LL, 3543753068LL, 3553187882LL, 3562625586LL, 3572078889LL, 3581552838LL, 3591043530LL, 3600553214LL, 3610077505LL, 3619612176LL, 3629171058LL, 3638742880LL, 3648329983LL, 3657942756LL, 3667574058LL, 3677221490LL, 3686886575LL, 3696554262LL, 3706254602LL, 3715967352LL, 3725696121LL, 3735442280LL, 3745213208LL, 3754990936LL, 3764797299LL, 3774607422LL, 3784444000LL, 3794295452LL, 3804162935LL, 3814051642LL, 3823958468LL, 3833870402LL, 3843819521LL, 3853774946LL, 3863752794LL, 3873736580LL, 3883749599LL, 3893774886LL, 3903828796LL, 3913888122LL, 3923962065LL, 3934062880LL, 3944180908LL, 3954306946LL, 3964460997LL, 3974636338LL, 3984814952LL, 3995026492LL, 4005244173LL, 4015484746LL, 4025739016LL, 4036013920LL, 4046309745LL, 4056611540LL, 4066951402LL, 4077294908LL, 4087660523LL, 4098044754LL, 4108444296LL, 4118861316LL, 4129291725LL, 4139749672LL, 4150226260LL, 4160712312LL, 4171228123LL, 4181752636LL, 4192301648LL, 4202848788LL, 4213440203LL, 4224040930LL, 4234655616LL, 4245280674LL, 4255941459LL, 4266604244LL, 4277303624LL, 4288017828LL, 4298739445LL, 4309482642LL, 4320249284LL, 4331024952LL, 4341825263LL, 4352638676LL, 4363486228LL, 4374330008LL, 4385202637LL, 4396094768LL, 4407007128LL, 4417931138LL, 4428880517LL, 4439844890LL, 4450827200LL, 4461826768LL, 4472853827LL, 4483885734LL, 4494948096LL, 4506023292LL, 4517116817LL, 4528234382LL, 4539356806LL, 4550515056LL, 4561679877LL, 4572857356LL, 4584071888LL, 4595292890LL, 4606542993LL, 4617802410LL, 4629085510LL, 4640386594LL, 4651700381LL, 4663033888LL, 4674397298LL, 4685766306LL, 4697166731LL, 4708567286LL, 4720008006LL, 4731456334LL, 4742925135LL, 4754417472LL, 4765923050LL, 4777442572LL, 4788991157LL, 4800552188LL, 4812140932LL, 4823737882LL, 4835359215LL, 4846996330LL, 4858659238LL, 4870332442LL, 4882036813LL, 4893755386LL, 4905484792LL, 4917236172LL, 4929001053LL, 4940804200LL, 4952620652LL, 4964450976LL, 4976298095LL, 4988169502LL, 5000057552LL, 5011968356LL, 5023894541LL, 5035835648LL, 5047809216LL, 5059784460LL, 5071795863LL, 5083816234LL, 5095864934LL, 5107927060LL, 5120007965LL, 5132105290LL, 5144237132LL, 5156372832LL, 5168537731LL, 5180716510LL, 5192902448LL, 5205131122LL, 5217359843LL, 5229627736LL, 5241907206LL, 5254201766LL, 5266518501LL, 5278841946LL, 5291218752LL, 5303572548LL, 5315983379LL, 5328394754LL, 5340830426LL, 5353285678LL, 5365764123LL, 5378255520LL, 5390763990LL, 5403296500LL, 5415855413LL, 5428421548LL, 5441022362LL, 5453628856LL, 5466260927LL, 5478916122LL, 5491593708LL, 5504280034LL, 5516995733LL, 5529726564LL, 5542484984LL, 5555252230LL, 5568048879LL, 5580859282LL, 5593691916LL, 5606546944LL, 5619411103LL, 5632308312LL, 5645224318LL, 5658148320LL, 5671109461LL, 5684082056LL, 5697078664LL, 5710093978LL, 5723124395LL, 5736171788LL, 5749250110LL, 5762342560LL, 5775466619LL, 5788599392LL, 5801759552LL, 5814923566LL, 5828123773LL, 5841341812LL, 5854584392LL, 5867833968LL, 5881112787LL, 5894413690LL, 5907737418LL, 5921064822LL, 5934435543LL, 5947810364LL, 5961209364LL, 5974627188LL, 5988079583LL, 6001535090LL, 6015019086LL, 6028522420LL, 6042046305LL, 6055593062LL, 6069155484LL, 6082744716LL, 6096353467LL, 6109981702LL, 6123625354LL, 6137303534LL, 6150980725LL, 6164694554LL, 6178427180LL, 6192182712LL, 6205959849LL, 6219740820LL, 6233563810LL, 6247394634LL, 6261249869LL, 6275132292LL, 6289027520LL, 6302948346LL, 6316884703LL, 6330838464LL, 6344831974LL, 6358833876LL, 6372863285LL, 6386902792LL, 6400976138LL, 6415058044LL, 6429161209LL, 6443295864LL, 6457447262LL, 6471612314LL, 6485795827LL, 6500015886LL, 6514256296LL, 6528514510LL, 6542796133LL, 6557091444LL, 6571411556LL, 6585752098LL, 6600116623LL, 6614498638LL, 6628912074LL, 6643320358LL, 6657779863LL, 6672240586LL, 6686742416LL, 6701249562LL, 6715783261LL, 6730332980LL, 6744915450LL, 6759501228LL, 6774141795LL, 6788765402LL, 6803437928LL, 6818117324LL, 6832817799LL, 6847546144LL, 6862306472LL, 6877076088LL, 6891861455LL, 6906672550LL, 6921508406LL, 6936360110LL, 6951238091LL, 6966152740LL, 6981067016LL, 6996006722LL, 7010974505LL, 7025962836LL, 7040976768LL, 7056000262LL, 7071057471LL, 7086122786LL, 7101225682LL, 7116336376LL, 7131484837LL, 7146641742LL, 7161824410LL, 7177031456LL, 7192258125LL, 7207510684LL, 7222788556LL, 7238077116LL, 7253396549LL, 7268724944LL, 7284089646LL, 7299466810LL, 7314872037LL, 7330299190LL, 7345747968LL, 7361210018LL, 7376714765LL, 7392226006LL, 7407761534LL, 7423320360LL, 7438901823LL, 7454497872LL, 7470135622LL, 7485783456LL, 7501453705LL, 7517137984LL, 7532861902LL, 7548588772LL, 7564348613LL, 7580136504LL, 7595938332LL, 7611769638LL, 7627615027LL, 7643491018LL, 7659383706LL, 7675287472LL, 7691235231LL, 7707200636LL, 7723182276LL, 7739191588LL, 7755218183LL, 7771271536LL, 7787351162LL, 7803446452LL, 7819552329LL, 7835699892LL, 7851874882LL, 7868043894LL, 7884270609LL, 7900500194LL, 7916755054LL, 7933033936LL, 7949328199LL, 7965654984LL, 7981996938LL, 7998373306LL, 8014764355LL, 8031170000LL, 8047620492LL, 8064088702LL, 8080567459LL, 8097070614LL, 8113600314LL, 8130151704LL, 8146734195LL, 8163313906LL, 8179957184LL, 8196591222LL, 8213260903LL, 8229945606LL, 8246662854LL, 8263400030LL, 8280166991LL, 8296947394LL, 8313753072LL, 8330576036LL, 8347428617LL, 8364303778LL, 8381198684LL, 8398129274LL, 8415075903LL, 8432036870LL, 8449027290LL, 8466044390LL, 8483091213LL, 8500147402LL, 8517238056LL, 8534338100LL, 8551478059LL, 8568632332LL, 8585806624LL, 8603003904LL, 8620236761LL, 8637484664LL, 8654756228LL, 8672049078LL, 8689371021LL, 8706707828LL, 8724084558LL, 8741464716LL, 8758869845LL, 8776315872LL, 8793786478LL, 8811261542LL, 8828776297LL, 8846299826LL, 8863866972LL, 8881438166LL, 8899038141LL, 8916670780LL, 8934316064LL, 8951985032LL, 8969688235LL, 8987401792LL, 9005154004LL, 9022920212LL, 9040716837LL, 9058525756LL, 9076378884LL, 9094232466LL, 9112131607LL, 9130040664LL, 9147976436LL, 9165935286LL, 9183914635LL, 9201915412LL, 9219960668LL, 9238011710LL, 9256096289LL, 9274197982LL, 9292332054LL, 9310479906LL, 9328651563LL, 9346860410LL, 9365082730LL, 9383325102LL, 9401605173LL, 9419897462LL, 9438215878LL, 9456569852LL, 9474936963LL, 9493338050LL, 9511752600LL, 9530196170LL, 9548663989LL, 9567153882LL, 9585670192LL, 9604202160LL, 9622766037LL, 9641361308LL, 9659975268LL, 9678607498LL, 9697283647LL, 9715960670LL, 9734678656LL, 9753394090LL, 9772168013LL, 9790952606LL, 9809767222LL, 9828600080LL, 9847457497LL, 9866335658LL, 9885246928LL, 9904181660LL, 9923134041LL, 9942115358LL, 9961127538LL, 9980143916LL, 9999212883LL, 10018299334LL, 10037394762LL, 10056521814LL, 10075672885LL, 10094858354LL, 10114071712LL, 10133292404LL, 10152551249LL, 10171823716LL, 10191141344LL, 10210454996LL, 10229810327LL, 10249191438LL, 10268593014LL, 10288023408LL, 10307477751LL, 10326957710LL, 10346466062LL, 10365988134LL, 10385544293LL, 10405112618LL, 10424729834LL, 10444357406LL, 10464007713LL, 10483688728LL, 10503389540LL, 10523120972LL, 10542859943LL, 10562647566LL, 10582460418LL, 10602297632LL, 10622141839LL, 10642032142LL, 10661942614LL, 10681870766LL, 10701827929LL, 10721796916LL, 10741829828LL, 10761839592LL, 10781904345LL, 10801984338LL, 10822103090LL, 10842234270LL, 10862394213LL, 10882577588LL, 10902795876LL, 10923021046LL, 10943291315LL, 10963574444LL, 10983892294LL, 11004218694LL, 11024594431LL, 11044992220LL, 11065402084LL, 11085847880LL, 11106315841LL, 11126791342LL, 11147317096LL, 11167860636LL, 11188442783LL, 11209034778LL, 11229648802LL, 11250293976LL, 11270972865LL, 11291669372LL, 11312395298LL, 11333148526LL, 11353922653LL, 11374722580LL, 11395558206LL, 11416411576LL, 11437293557LL, 11458189896LL, 11479128746LL, 11500082586LL, 11521063591LL, 11542074872LL, 11563129804LL, 11584179460LL, 11605270381LL, 11626386488LL, 11647523330LL, 11668688458LL, 11689879179LL, 11711100370LL, 11732346128LL, 11753615846LL, 11774915977LL, 11796234228LL, 11817593764LL, 11838968516LL, 11860372937LL, 11881795858LL, 11903260776LL, 11924731368LL, 11946240101LL, 11967775622LL, 11989344036LL, 12010914006LL, 12032536895LL, 12054183772LL, 12075844670LL, 12097541070LL, 12119261983LL, 12141007596LL, 12162784930LL, 12184566690LL, 12206406107LL, 12228252614LL, 12250122580LL, 12272044010LL, 12293972345LL, 12315923116LL, 12337910366LL, 12359928610LL, 12381971157LL, 12404020572LL, 12426129422LL, 12448240350LL, 12470394811LL, 12492562516LL, 12514758184LL, 12536990520LL, 12559230039LL, 12581515318LL, 12603823728LL, 12626160400LL, 12648531997LL, 12670895832LL, 12693325334LL, 12715752434LL, 12738229191LL, 12760720940LL, 12783246232LL, 12805794472LL, 12828372863LL, 12850982004LL, 12873613496LL, 12896266106LL, 12918945325LL, 12941663296LL, 12964396994LL, 12987167764LL, 13009959455LL, 13032777670LL, 13055640356LL, 13078484158LL, 13101391487LL, 13124322864LL, 13147296126LL, 13170270528LL, 13193288217LL, 13216322512LL, 13239395578LL, 13262486492LL, 13285600859LL, 13308751950LL, 13331933228LL, 13355130312LL, 13378363525LL, 13401606654LL, 13424905814LL, 13448225050LL, 13471555571LL, 13494918234LL, 13518325980LL, 13541731566LL, 13565201927LL, 13588672056LL, 13612170438LL, 13635710296LL, 13659267843LL, 13682857958LL, 13706470216LL, 13730119430LL, 13753797521LL, 13777494144LL, 13801223470LL, 13824972750LL, 13848759985LL, 13872571514LL, 13896411188LL, 13920260568LL, 13944169249LL, 13968083300LL, 13992041940LL, 14016016638LL, 14040025735LL, 14064060506LL, 14088130430LL, 14112214174LL, 14136326211LL, 14160471100LL, 14184649166LL, 14208847684LL, 14233077947LL, 14257330580LL, 14281629678LL, 14305937202LL, 14330282399LL, 14354642572LL, 14379058808LL, 14403477800LL, 14427933293LL, 14452422320LL, 14476924334LL, 14501468336LL, 14526031525LL, 14550611826LL, 14575258960LL, 14599915764LL, 14624590353LL, 14649307726LL, 14674036560LL, 14698808100LL, 14723611153LL, 14748418166LL, 14773282134LL, 14798143938LL, 14823056561LL, 14847997872LL, 14872970836LL, 14897963804LL, 14922989853LL, 14948043436LL, 14973115476LL, 14998224332LL, 15023363785LL, 15048534572LL, 15073727448LL, 15098946162LL, 15124194037LL, 15149491292LL, 15174785390LL, 15200133970LL, 15225491451LL, 15250875116LL, 15276311618LL, 15301752072LL, 15327253689LL, 15352765076LL, 15378306070LL, 15403875638LL, 15429461667LL, 15455099622LL, 15480752478LL, 15506424248LL, 15532151343LL, 15557884500LL, 15583671346LL, 15609456626LL, 15635278941LL, 15661152350LL, 15687039060LL, 15712943794LL, 15738900857LL, 15764865016LL, 15790891834LL, 15816900186LL, 15842973423LL, 15869058628LL, 15895181784LL, 15921335458LL, 15947518869LL, 15973726224LL, 15999955134LL, 16026219464LL, 16052512879LL, 16078844830LL, 16105199162LL, 16131588250LL, 16158006287LL, 16184442692LL, 16210919090LL, 16237407364LL, 16263957085LL, 16290514354LL, 16317105364LL, 16343709892LL, 16370373971LL, 16397053922LL, 16423749906LL, 16450495500LL, 16477259903LL, 16504049234LL, 16530895922LL, 16557734408LL, 16584638761LL, 16611534976LL, 16638490382LL, 16665474124LL, 16692462689LL, 16719495984LL, 16746573778LL, 16773669214LL, 16800781595LL, 16827931674LL, 16855132496LL, 16882331206LL, 16909587021LL, 16936851538LL, 16964163616LL, 16991490290LL, 17018854213LL, 17046239568LL, 17073664784LL, 17101127704LL, 17128608743LL, 17156104042LL, 17183663168LL, 17211234562LL, 17238835951LL, 17266464770LL, 17294146488LL, 17321820196LL, 17349548331LL, 17377295416LL, 17405098964LL, 17432899814LL, 17460747943LL, 17488620662LL, 17516521618LL, 17544450448LL, 17572425447LL, 17600424912LL, 17628442122LL, 17656489986LL, 17684583923LL, 17712696444LL, 17740850230LL, 17769033680LL, 17797240639LL, 17825476118LL, 17853738104LL, 17882043836LL, 17910372801LL, 17938741918LL, 17967130214LL, 17995549806LL, 18023995317LL, 18052479814LL, 18080998176LL, 18109534864LL, 18138116441LL, 18166711096LL, 18195359370LL, 18224006588LL, 18252715047LL, 18281440374LL, 18310206524LL, 18338980964LL, 18367813869LL, 18396668104LL, 18425549136LL, 18454468966LL, 18483398125LL, 18512374114LL, 18541387558LL, 18570404150LL, 18599486567LL, 18628592906LL, 18657703644LL, 18686859232LL, 18716046853LL, 18745279774LL, 18774527482LL, 18803818674LL, 18833145303LL, 18862478966LL, 18891859618LL, 18921264244LL, 18950697327LL, 18980169810LL, 19009667936LL, 19039205800LL, 19068767351LL, 19098357214LL, 19128001662LL, 19157639736LL, 19187337709LL, 19217050890LL, 19246809278LL, 19276589068LL, 19306412337LL, 19336240588LL, 19366131864LL, 19396026832LL, 19425958873LL, 19455938600LL, 19485944316LL, 19515986918LL, 19546043477LL, 19576132726LL, 19606263326LL, 19636431128LL, 19666609365LL, 19696834394LL, 19727104970LL, 19757353614LL, 19787701785LL, 19818040942LL, 19848429620LL, 19878829056LL, 19909273441LL, 19939761128LL, 19970275822LL, 20000795696LL, 20031376997LL, 20061975182LL, 20092600638LL, 20123267014LL, 20153960463LL, 20184710080LL, 20215464924LL, 20246254032LL, 20277085067LL, 20307927424LL, 20338826526LL, 20369735954LL, 20400704429LL, 20431680344LL, 20462712824LL, 20493755800LL, 20524842691LL, 20555932006LL, 20587086902LL, 20618265034LL, 20649470177LL, 20680709572LL, 20711997328LL, 20743295138LL, 20774640263LL, 20806004856LL, 20837411096LL, 20868837110LL, 20900293333LL, 20931786142LL, 20963341648LL, 20994901062LL, 21026482153LL, 21058124702LL, 21089778936LL, 21121473748LL, 21153202421LL, 21184959842LL, 21216751208LL, 21248561574LL, 21280419055LL, 21312299434LL, 21344228444LL, 21376177872LL, 21408172329LL, 21440178784LL, 21472231412LL, 21504305276LL, 21536430445LL, 21568572538LL, 21600756848LL, 21632962082LL, 21665200653LL, 21697479592LL, 21729800518LL, 21762150104LL, 21794517499LL, 21826929924LL, 21859367972LL, 21891837396LL, 21924342881LL, 21956891346LL, 21989463742LL, 22022066148LL, 22054703515LL, 22087374828LL, 22120072666LL, 22152827802LL, 22185583989LL, 22218369222LL, 22251223676LL, 22284083800LL, 22317003671LL, 22349930050LL, 22382893566LL, 22415888758LL, 22448928827LL, 22482002710LL, 22515097314LL, 22548220344LL, 22581409651LL, 22614580132LL, 22647835194LL, 22681080768LL, 22714386301LL, 22747719762LL, 22781091458LL, 22814485296LL, 22847925521LL, 22881375740LL, 22914889334LL, 22948412082LL, 22981987341LL, 23015588956LL, 23049215580LL, 23082866676LL, 23116574277LL, 23150316704LL, 23184063670LL, 23217861044LL, 23251693689LL, 23285546546LL, 23319464186LL, 23353413406LL, 23387373951LL, 23421373318LL, 23455404876LL, 23489469900LL, 23523570055LL, 23557708714LL, 23591878154LL, 23626076336LL, 23660314657LL, 23694578900LL, 23728881648LL, 23763219812LL, 23797592885LL, 23831989974LL, 23866440090LL, 23900902530LL, 23935425443LL, 23969948060LL, 24004530098LL, 24039130364LL, 24073761697LL, 24108443134LL, 24143155988LL, 24177905376LL, 24212695275LL, 24247484040LL, 24282340990LL, 24317210598LL, 24352137889LL, 24387076928LL, 24422063206LL, 24457072792LL, 24492119935LL, 24527206344LL, 24562329910LL, 24597473268LL, 24632662189LL, 24667875578LL, 24703139552LL, 24738429770LL, 24773751911LL, 24809101090LL, 24844497316LL, 24879931178LL, 24915382113LL, 24950868552LL, 24986418640LL, 25021963892LL, 25057576457LL, 25093191060LL, 25128882680LL, 25164573576LL, 25200304261LL, 25236074556LL, 25271888990LL, 25307716812LL, 25343599443LL, 25379494642LL, 25415444250LL, 25451432394LL, 25487422517LL, 25523485744LL, 25559560472LL, 25595677296LL, 25631832535LL, 25668014074LL, 25704238576LL, 25740473940LL, 25776781233LL, 25813097992LL, 25849462522LL, 25885862050LL, 25922292871LL, 25958750250LL, 25995244404LL, 26031769900LL, 26068339841LL, 26104949822LL, 26141570498LL, 26178260834LL, 26214967497LL, 26251713234LL, 26288500116LL, 26325297518LL, 26362161505LL, 26399023274LL, 26435956496LL, 26472901262LL, 26509899053LL, 26546916512LL, 26583976300LL, 26621058530LL, 26658178401LL, 26695366964LL, 26732562478LL, 26769792688LL, 26807069131LL, 26844352060LL, 26881712512LL, 26919083490LL, 26956495377LL, 26993943104LL, 27031429818LL, 27068922558LL, 27106486265LL, 27144064390LL, 27181708024LL, 27219369872LL, 27257048349LL, 27294782010LL, 27332558482LL, 27370349612LL, 27408176237LL, 27446051340LL, 27483962544LL, 27521888684LL, 27559862781LL, 27597883870LL, 27635942300LL, 27674036422LL, 27712155453LL, 27750318000LL, 27788508500LL, 27826719644LL, 27864989115LL, 27903280246LL, 27941630410LL, 27979988616LL, 28018398369LL, 28056846838LL, 28095317506LL, 28133833890LL, 28172384151LL, 28210963240LL, 28249590004LL, 28288243646LL, 28326951403LL, 28365666962LL, 28404447892LL, 28443239914LL, 28482065093LL, 28520952318LL, 28559867844LL, 28598813120LL, 28637783477LL, 28676790442LL, 28715864554LL, 28754936440LL, 28794079573LL, 28833240452LL, 28872441752LL, 28911670514LL, 28950953491LL, 28990247594LL, 29029604862LL, 29068968486LL, 29108379923LL, 29147830628LL, 29187338384LL, 29226838420LL, 29266438961LL, 29306021590LL, 29345642418LL, 29385319430LL, 29425026497LL, 29464771352LL, 29504556500LL, 29544368818LL, 29584229615LL, 29624113694LL, 29664035752LL, 29703999968LL, 29744000851LL, 29784050836LL, 29824106944LL, 29864194866LL, 29904365393LL, 29944525240LL, 29984774644LL, 30025036222LL, 30065303909LL, 30105644886LL, 30146018242LL, 30186402768LL, 30226854249LL, 30267324378LL, 30307852176LL, 30348384192LL, 30388959193LL, 30429602642LL, 30470267284LL, 30510968386LL, 30551705975LL, 30592462588LL, 30633275182LL, 30674108380LL, 30715002867LL, 30755925012LL, 30796892560LL, 30837867184LL, 30878893491LL, 30919979362LL, 30961073922LL, 31002212626LL, 31043409001LL, 31084616424LL, 31125884168LL, 31167156566LL, 31208485157LL, 31249843792LL, 31291264530LL, 31332690232LL, 31374164615LL, 31415673140LL, 31457231434LL, 31498818978LL, 31540464387LL, 31582110194LL, 31623820450LL, 31665556220LL, 31707339699LL, 31749152170LL, 31790992178LL, 31832896552LL, 31874825979LL, 31916765322LL, 31958784276LL, 32000800204LL, 32042896931LL, 32084994136LL, 32127151474LL, 32169342044LL, 32211571521LL, 32253838444LL, 32296131360LL, 32338469650LL, 32380837031LL, 32423268800LL, 32465724690LL, 32508217744LL, 32550736097LL, 32593318632LL, 32635903024LL, 32678556708LL, 32721226259LL, 32763948030LL, 32806709878LL, 32849478660LL, 32892340257LL, 32935197744LL, 32978112642LL, 33021041010LL, 33064031575LL, 33107048486LL, 33150116138LL, 33193204452LL, 33236338661LL, 33279515518LL, 33322732668LL, 33365987512LL, 33409254183LL, 33452585598LL, 33495954966LL, 33539369830LL, 33582811939LL, 33626269714LL, 33669799540LL, 33713341902LL, 33756937901LL, 33800578504LL, 33844238068LL, 33887955796LL, 33931699859LL, 33975479128LL, 34019300774LL, 34063169634LL, 34107069375LL, 34151003346LL, 34195006626LL, 34238999882LL, 34283063915LL, 34327145264LL, 34371295780LL, 34415434136LL, 34459653165LL, 34503884880LL, 34548202428LL, 34592509102LL, 34636878789LL, 34681283850LL, 34725735624LL, 34770193946LL, 34814716337LL, 34859263280LL, 34903871430LL, 34948492262LL, 34993176971LL, 35037883380LL, 35082618080LL, 35127427896LL, 35172239553LL, 35217112242LL, 35262023698LL, 35306965738LL, 35351949141LL, 35396971286LL, 35442048274LL, 35487125012LL, 35532273341LL, 35577442954LL, 35622671628LL, 35667936540LL, 35713215171LL, 35758549622LL, 35803936994LL, 35849329914LL, 35894783061LL, 35940278442LL, 35985808660LL, 36031380044LL, 36076994073LL, 36122628006LL, 36168336746LL, 36214050002LL, 36259825493LL, 36305618022LL, 36351463320LL, 36397335366LL, 36443278941LL, 36489242850LL, 36535233644LL, 36581274504LL, 36627343961LL, 36673465620LL, 36719630852LL, 36765827488LL, 36812076035LL};

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int t, n;

    RD(t);

    while(t--){
        RD(n);
        PR(ans[n]);
    }



    return 0;
}












