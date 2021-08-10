#include<bits/stdc++.h>
using namespace std;
struct cj
{
    string name;
    int problem[1000],zf;
}cj1[1000];
int shuju[1000];
double tm[1000];
char ID[100],sum[100],n[100];
string in[1000],out[1000],Dir[1000],nm[1000],OIer[1000];;
int tsum;
struct node
{
    char a[1000];
    void pw()
    {
        char s2[1000]="1";
        int ans[2000];
        int as1[2000],bs1[2000];
        int lena=strlen(a),lenb=1;
        for(int i=lena-1;i>=0;i--)as1[lena-i]=a[i]-'0';
        for(int i=lenb-1;i>=0;i--)bs1[lenb-i]=s2[i]-'0';
        int x=0,j=max(lena,lenb);
        for(int i=1;i<=j;i++)
            ans[i]=as1[i]+bs1[i]+x,x=ans[i]/10,ans[i]=ans[i]%10;
        if(x!=0) j++,ans[j]=x;
        while(ans[j]==0)j--;
        for(int i=j;i>=1;i--)
            a[j-i]=ans[i]+'0';
    }
};
void sc(char FL[],int SOI,int ST)
{
    char dir[1000];
    FILE*scl=fopen(FL,"w");
    for(int i=1;i<=ST;i++)
        fprintf(scl,"g++ .contest/%s/p%d/check.cpp -o .contest/%s/p%d/check\n",n,i,n,i);
    for(int i=1;i<=SOI;i++)
        for(int j=1;j<=ST;j++)
        {
            fprintf(scl,"printf \"run on %s\'s %s\\n\"\n",OIer[i].c_str(),Dir[j].c_str());
            fprintf(scl,"touch .contest/%s/code/%s/%s/k.txt\n",n,OIer[i].c_str(),Dir[j].c_str());
            fprintf(scl,"touch .contest/%s/code/%s/%s/CE.txt\n",n,OIer[i].c_str(),Dir[j].c_str());
            // fprintf(scl,"touch .contest/%s/code/%s/%s/CE.txt\n",n,OIer[i].c_str(),Dir[j].c_str());
            fprintf(scl,"g++ .contest/%s/code/%s/%s/%s -o ",n,OIer[i].c_str(),Dir[j].c_str(),nm[j].c_str());
            fprintf(scl,".contest/%s/code/%s/%s/code ",n,OIer[i].c_str(),Dir[j].c_str());
            fprintf(scl,"-O2 -lm -std=c++17 -DONLINE_JUDGE ");
            fprintf(scl,"2> .contest/%s/code/%s/%s/CE.txt\n",n,OIer[i].c_str(),Dir[j].c_str());
            fprintf(scl,"if diff .contest/%s/code/%s/%s/CE.txt .contest/%s/code/%s/%s/k.txt ; then\n",n,OIer[i].c_str(),Dir[j].c_str(),n,OIer[i].c_str(),Dir[j].c_str());
            fprintf(scl,"   rm -rf /Users/hu/Desktop/oj2.0/.contest/%s/p%d/out\n",n,j);
            fprintf(scl,"   mkdir /Users/hu/Desktop/oj2.0/.contest/%s/p%d/out\n",n,j);
            node asd;
            strcpy(asd.a,"0");
            for(int k=1;k<=j;k++)asd.pw();
            strcpy(dir,".contest/");strcat(dir,n);strcat(dir,"/P");strcat(dir,asd.a);strcat(dir,"/tm.txt");
            int sum1;
            ifstream tm1(dir);tm1>>sum1;
            for(int k=1;k<=sum1;k++)
                tm1>>tm[k];
            for(int k=1;k<=sum1;k++)
            {
                fprintf(scl,"   cd\n");
                fprintf(scl,"   cd desktop/oj2.0/.contest/%s/code/%s/%s\n",n,OIer[i].c_str(),Dir[j].c_str());
                fprintf(scl,"   cp /Users/hu/Desktop/oj2.0/.contest/%s/p%d/in/t%d.in %s\n",n,j,k,in[j].c_str());
                fprintf(scl,"   if !(gtimeout %.1lf ./code > df.txt) ; then \n",tm[k]);
                fprintf(scl,"       gtimeout %.1lf ./code > df.txt\n",tm[k]);
                fprintf(scl,"   fi\n");
                fprintf(scl,"   cp %s /Users/hu/Desktop/oj2.0/.contest/%s/P%d/out/t%d.out\n",out[j].c_str(),n,j,k);
                // fprintf(scl,"   printf \"%d\\n\"\n",k);
            }
            if(i==SOI)
            {
                // fprintf(scl,"printf \"run on %s\'s %s\\n\"\n",OIer[i].c_str(),Dir[j].c_str());
                fprintf(scl,"touch .contest/%s/code/%s/%s/k.txt\n",n,OIer[i].c_str(),Dir[j].c_str());
                fprintf(scl,"touch .contest/%s/code/%s/%s/CE.txt\n",n,OIer[i].c_str(),Dir[j].c_str());
                // fprintf(scl,"touch .contest/%s/code/%s/%s/CE.txt\n",n,OIer[i].c_str(),Dir[j].c_str());
                fprintf(scl,"g++ .contest/%s/code/%s/%s/%s -o ",n,OIer[i].c_str(),Dir[j].c_str(),nm[j].c_str());
                fprintf(scl,".contest/%s/code/%s/%s/code ",n,OIer[i].c_str(),Dir[j].c_str());
                fprintf(scl,"-O2 -lm -std=c++17 -DONLINE_JUDGE ");
                fprintf(scl,"2> .contest/%s/code/%s/%s/CE.txt\n",n,OIer[i].c_str(),Dir[j].c_str());
                fprintf(scl,"if diff .contest/%s/code/%s/%s/CE.txt .contest/%s/code/%s/%s/k.txt ; then\n",n,OIer[i].c_str(),Dir[j].c_str(),n,OIer[i].c_str(),Dir[j].c_str());
                fprintf(scl,"   rm -rf /Users/hu/Desktop/oj2.0/.contest/%s/p%d/out\n",n,j);
                fprintf(scl,"   mkdir /Users/hu/Desktop/oj2.0/.contest/%s/p%d/out\n",n,j);
                node asd;
                strcpy(asd.a,"0");
                for(int k=1;k<=j;k++)asd.pw();
                strcpy(dir,".contest/");strcat(dir,n);strcat(dir,"/P");strcat(dir,asd.a);strcat(dir,"/tm.txt");
                int sum1;
                ifstream tm1(dir);tm1>>sum1;
                for(int k=1;k<=sum1;k++)
                    tm1>>tm[k];
                for(int k=1;k<=sum1;k++)
                {
                    fprintf(scl,"   cd\n");
                    fprintf(scl,"   cd desktop/oj2.0/.contest/%s/code/%s/%s\n",n,OIer[i].c_str(),Dir[j].c_str());
                    fprintf(scl,"   cp /Users/hu/Desktop/oj2.0/.contest/%s/p%d/in/t%d.in %s\n",n,j,k,in[j].c_str());
                    fprintf(scl,"   if !(gtimeout %.1lf ./code > df.txt) ; then \n",tm[k]);
                    fprintf(scl,"       gtimeout %.1lf ./code > df.txt\n",tm[k]);
                    fprintf(scl,"   fi\n");
                    fprintf(scl,"   cp %s /Users/hu/Desktop/oj2.0/.contest/%s/P%d/out/t%d.out\n",out[j].c_str(),n,j,k);
                    // fprintf(scl,"   printf \"%d\\n\"\n",k);
                }
            }
            fprintf(scl,"   cd\n");
            fprintf(scl,"   cd desktop/oj2.0\n");
            fprintf(scl,"   ./.contest/%s/p%d/check > .contest/%s/code/%s/%s/fen.txt\n",n,j,n,OIer[i].c_str(),Dir[j].c_str());
            fprintf(scl,"else\n    printf \"CE\\n\"\nfi\n");
        }
        fprintf(scl,"cd desktop/oj2.0");
}
bool cmp(cj x,cj y)
{
    if(x.zf==y.zf)
    {
        for(int i=1;i<=tsum;i++)
            if(x.problem[i]!=y.problem[i])return x.problem[i]>y.problem[i];
        if(x.name.length()==y.name.length())return x.name<y.name;
        return x.name.length()<y.name.length();
    }
    else return x.zf>y.zf;
}
int main()
{
    FILE*In=fopen(".contest/sum.txt","r");fscanf(In,"%s",sum);fclose(In);
    while(1)
    {
        system("clear");
        printf("请输入比赛号(退出提交-1):");
        scanf("%s",n);
        int asd=0;
        if(!strcmp(n,"-1")){return 0;}
        if(n[0]!='C'){continue;}
        for(int i=1;i<strlen(n);i++)
            if(n[i]<'0'&&n[i]>'9')
            {
                system("clear"),
                puts("error!"),
                asd=1;
                break;
            }
        if(asd==1)continue;
        char check[1000];
        for(int i=1;i<strlen(n);i++)check[i-1]=n[i];
        // printf("%s|\n%s|\n",sum,check);
        if(strcmp(n+1,sum)>0)
            system("clear"),
            puts("error!");
        else break;
    }
    printf("请将选手文件夹拖入以下文件夹!");
    char rmdir[1000]="rm -rf .contest/";strcat(rmdir,n);strcat(rmdir,"/code");system(rmdir);
    char mkdir[1000]="mkdir .contest/";strcat(mkdir,n);strcat(mkdir,"/code");system(mkdir);
    char dir[1000]="open .contest/";strcat(dir,n);strcat(dir,"/code");system(dir);getchar();getchar();
    strcpy(dir,".contest/");strcat(dir,n);strcat(dir,"/sum.txt");
    ifstream sm(dir);sm>>tsum;sm.close();
    strcpy(dir,"ls .contest/");strcat(dir,n);strcat(dir,"/code >OIer.txt");
    system(dir);
    
    int Usum=0;
    ifstream OI("OIer.txt");
    while(Usum++,getline(OI,OIer[Usum]));
    strcpy(dir,"mkdir .contest/");strcat(dir,n);strcat(dir,"/code/zzzzzzzzzz");system(dir);
    strcpy(dir,"cp .contest/");strcat(dir,n);strcat(dir,"/code/");strcat(dir,OIer[Usum-1].c_str());
    strcat(dir," .contest/");strcat(dir,n);strcat(dir,"/code/zzzzzzzzzz 2> fk.txt");
    system(dir);
    OIer[Usum]="zzzzzzzzzz";
    OI.close();
    printf("共有%d个比赛者\n",Usum-1);
    node asd;
    strcpy(asd.a,"0");
    for(int i=1;i<=tsum;i++)
    {
        asd.pw();
        strcpy(dir,".contest/");strcat(dir,n);strcat(dir,"/P");strcat(dir,asd.a);strcat(dir,"/name.txt");
        ifstream name1(dir);name1>>nm[i];
        strcpy(dir,".contest/");strcat(dir,n);strcat(dir,"/P");strcat(dir,asd.a);strcat(dir,"/dir.txt");
        ifstream dir1(dir);dir1>>Dir[i];
        strcpy(dir,".contest/");strcat(dir,n);strcat(dir,"/P");strcat(dir,asd.a);strcat(dir,"/in.txt");
        ifstream in1(dir);in1>>in[i];
        strcpy(dir,".contest/");strcat(dir,n);strcat(dir,"/P");strcat(dir,asd.a);strcat(dir,"/out.txt");
        ifstream out1(dir);out1>>out[i];
        strcpy(dir,".contest/");strcat(dir,n);strcat(dir,"/P");strcat(dir,asd.a);strcat(dir,"/sum.txt");
        ifstream sum1(dir);sum1>>shuju[i];
    }
    // for(int i=1;i<=tsum;i++)
    //     cout<<nm[i];
    // for(int i=1;i<=tsum;i++)
    //     cout<<Dir[i];
    for(int i=1;i<=Usum-1;i++)
        cout<<OIer[i]<<endl;
    strcpy(dir,".contest/");strcat(dir,n);strcat(dir,"/code/check.sh");
    sc(dir,Usum,tsum);
    char qx[1000]="chmod +x ";strcat(qx,dir);
    system(qx);
    // system("clear");
    printf("正在测评\n");
    strcpy(qx,". ./");strcat(qx,dir);strcat(qx," 2> fk.txt");
    system(qx);
    // system("clear");
    printf("测评结束\n");
    char td[1000];
    for(int i=1;i<=Usum-1;i++)
        for(int j=1;j<=tsum;j++)
        {
            // strcpy(td,"open .contest/");strcpy(td,n);strcat(td,"/code/");strcat(td,OIer[i].c_str());
            // strcat(td,"/");strcat(td,Dir[j].c_str());//strcat(td,"/");strcat(td,nm[j].c_str());
            // strcat(td,"/fen.txt");
            strcpy(td,".contest/");strcat(td,n);strcat(td,"/code/");strcat(td,OIer[i].c_str());
            strcat(td,"/");strcat(td,Dir[j].c_str());//strcat(td,"/");strcat(td,nm[j].c_str());
            strcat(td,"/fen.txt");

            // printf("%s\n",td);
            cj1[i].name=OIer[i];
            ifstream read(td);read>>cj1[i].problem[j],cj1[i].zf+=cj1[i].problem[j];read.close();
            // puts("");
        }
    sort(cj1+1,cj1+Usum,cmp);
    strcpy(td,"touch .contest/");strcat(td,n);strcat(td,"/code/chengji.csv");system(td);
    strcpy(td,".contest/");strcat(td,n);strcat(td,"/code/chengji.csv");
    freopen(td,"w",stdout);
    printf("rank,Userename,Totalscore");
    for(int i=1;i<=tsum;i++)printf(",%s",Dir[i].c_str());puts("");
    for(int i=1;i<=Usum-1;i++)
    {
        printf("%d,%s,%d",i,cj1[i].name.c_str(),cj1[i].zf);
        for(int j=1;j<=tsum;j++)printf(",%d",cj1[i].problem[j]);
        puts("");
    }
    strcpy(td,"open .contest/");strcat(td,n);strcat(td,"/code/chengji.csv");system(td);
    return 0;
}
