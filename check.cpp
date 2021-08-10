#include<bits/stdc++.h>
using namespace std;
string nd[10001],bz[10001];
int fen[10001],n,zfen;
int lnd,lbz,ans;
string RE[100];int test[100],len;
int check2(string a)
{
    int x=0,asd=0,len=a.length();
    int tr;
    for(int i=0;i<=len;i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            if(asd==1)x=x*10+a[i]-'0';
            else x=a[i]-'0',asd=1;
        }
        else
        {
            if(asd==1)
            {
                tr=x;
                asd=0,x=0;
            }
        }
    }
    return tr;
}
void check(int x)
{
    for(int i=1;i<=lbz;i++)
    {
        int lena=bz[i].length(),lenb=nd[i].length();
        if(bz[i][lena-1]==' ')lena--;
        if(nd[i][lenb-1]==' ')lenb--;
        if(lena!=lenb){printf("\033[91m测试点%2d : WA 得%3d 分\033[0m\n",x,0);return ;}
        for(int j=0;j<lena;j++)
            if(bz[i][j]!=nd[i][j]){printf("\033[91m测试点%2d : WA 得%3d 分\033[0m\n",x,0);return ;}
    }
    zfen+=fen[x];
    printf("\033[92m测试点%2d : AC 得%3d 分\033[0m\n",x,fen[x]);return ;
}
int main()
{
    ifstream CE(".Problem/P2/check.cpp/CE2.txt");
    while(len++,getline(CE,RE[len]));
    for(int i=1;i<=len;i++)
    {
        test[check2(RE[i])]=1;
    }
    ifstream fn(".Problem/P2/check.cpp/fen.txt");
    fn>>n;
    for(int i=1;i<=n;i++)
        fn>>fen[i],ans+=fen[i];
        fn.close();
    lbz=lnd=0;
    if(test[1]==1)printf("\033[91m测试点  1 : RE 得%3d 分\033[91m\n",0);
    else
    {
        ifstream bzsc1(".Problem/P2/check.cpp/ans/t1.out");
        ifstream ndsc1(".Problem/P2/check.cpp/out/t1.out");
        while(lnd++,getline(ndsc1,nd[lnd]));
        while(lbz++,getline(bzsc1,bz[lbz]));
        bzsc1.close();
        ndsc1.close();
        if(bz[lbz]=="\n")
            lbz--;
        if(nd[lnd]=="\n")
            lnd--;
        if(lnd-lbz)
            printf("\033[91m测试点 1 : WA 得%3d 分\033[91m\n",0);
        else check(1);
    }
    lbz=lnd=0;
    if(test[1]==1)printf("\033[91m测试点  2 : RE 得%3d 分\033[91m\n",0);
    else
    {
        ifstream bzsc2(".Problem/P2/check.cpp/ans/t2.out");
        ifstream ndsc2(".Problem/P2/check.cpp/out/t2.out");
        while(lnd++,getline(ndsc2,nd[lnd]));
        while(lbz++,getline(bzsc2,bz[lbz]));
        bzsc2.close();
        ndsc2.close();
        if(bz[lbz]=="\n")
            lbz--;
        if(nd[lnd]=="\n")
            lnd--;
        if(lnd-lbz)
            printf("\033[91m测试点 2 : WA 得%3d 分\033[91m\n",0);
        else check(2);
    }
    lbz=lnd=0;
    if(test[1]==1)printf("\033[91m测试点  3 : RE 得%3d 分\033[91m\n",0);
    else
    {
        ifstream bzsc3(".Problem/P2/check.cpp/ans/t3.out");
        ifstream ndsc3(".Problem/P2/check.cpp/out/t3.out");
        while(lnd++,getline(ndsc3,nd[lnd]));
        while(lbz++,getline(bzsc3,bz[lbz]));
        bzsc3.close();
        ndsc3.close();
        if(bz[lbz]=="\n")
            lbz--;
        if(nd[lnd]=="\n")
            lnd--;
        if(lnd-lbz)
            printf("\033[91m测试点 3 : WA 得%3d 分\033[91m\n",0);
        else check(3);
    }
    lbz=lnd=0;
    if(test[1]==1)printf("\033[91m测试点  4 : RE 得%3d 分\033[91m\n",0);
    else
    {
        ifstream bzsc4(".Problem/P2/check.cpp/ans/t4.out");
        ifstream ndsc4(".Problem/P2/check.cpp/out/t4.out");
        while(lnd++,getline(ndsc4,nd[lnd]));
        while(lbz++,getline(bzsc4,bz[lbz]));
        bzsc4.close();
        ndsc4.close();
        if(bz[lbz]=="\n")
            lbz--;
        if(nd[lnd]=="\n")
            lnd--;
        if(lnd-lbz)
            printf("\033[91m测试点 4 : WA 得%3d 分\033[91m\n",0);
        else check(4);
    }
    lbz=lnd=0;
    if(test[1]==1)printf("\033[91m测试点  5 : RE 得%3d 分\033[91m\n",0);
    else
    {
        ifstream bzsc5(".Problem/P2/check.cpp/ans/t5.out");
        ifstream ndsc5(".Problem/P2/check.cpp/out/t5.out");
        while(lnd++,getline(ndsc5,nd[lnd]));
        while(lbz++,getline(bzsc5,bz[lbz]));
        bzsc5.close();
        ndsc5.close();
        if(bz[lbz]=="\n")
            lbz--;
        if(nd[lnd]=="\n")
            lnd--;
        if(lnd-lbz)
            printf("\033[91m测试点 5 : WA 得%3d 分\033[91m\n",0);
        else check(5);
    }
    printf("总得分:%d\n",zfen);
    if(zfen==ans){puts("你通过了此题!");}
    return 0;
}