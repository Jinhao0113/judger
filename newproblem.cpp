#include<bits/stdc++.h>
using namespace std;
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
}tsum;
int sum;
double tm[100];
int fen[100],zfen;
char ID[1000];
int stest;
void check1(char FL[])
{
    FILE*ch=fopen(FL,"w");
    fprintf(ch,"clear\n");;
    fprintf(ch,"printf \"waiting...\\n\"");
    fprintf(ch,"Sleep 1\n");
    fprintf(ch,"clear\n");
    fprintf(ch,"printf \"Compiling...\\n\"\n");
    fprintf(ch,"g++ %s/check.cpp -o %s/check\n",ID,ID);
    fprintf(ch,"g++ %s/submit.cpp -o %s/submit -O2 -lm -std=c++17 -DONLINE_JUDGE 2>%s/CE.txt\n",ID,ID,ID);
    fprintf(ch,"Sleep 0.5\n");
    fprintf(ch,"clear\n");
    fprintf(ch,"if diff %s/CE.txt %s/K.txt ; then\n",ID,ID);
    for(int i=1;i<=stest;i++)
    {
        fprintf(ch,"    clear\n");
        fprintf(ch,"    printf \"run on test %2d\\n\"\n",i);
        fprintf(ch,"    gtimeout %.1lf ./%s/submit < %s/in/t%d.in > %s/out/t%d.out\n",tm[i],ID,ID,i,ID,i);
        fprintf(ch,"    Sleep 0.5\n");       
    }
    fprintf(ch,"    clear\n");
    fprintf(ch,"    printf \"Judge!\\n\"\n");
    fprintf(ch,"    Sleep 1\n");
    fprintf(ch,"    clear\n");
    fprintf(ch,"    ./%s/check\n",ID);
    fprintf(ch,"else\n");
    fprintf(ch,"    printf \"CE \\n\"\n");
    fprintf(ch,"fi\n");
    fclose(ch);
}
void check(char FL[])
{
    int x;
    FILE*ch=fopen(FL,"w");
    fprintf(ch,"#include<bits/stdc++.h>\n");
    fprintf(ch,"using namespace std;\n");
    fprintf(ch,"string nd[10001],bz[10001];\n");
    fprintf(ch,"int fen[10001],n,zfen;\n");
    fprintf(ch,"int lnd,lbz,ans;\n");
    fprintf(ch,"string RE[100];");
    fprintf(ch,"int test[100],len;\n");
    fprintf(ch,"int check2(string a)\n");
    fprintf(ch,"{\n");
    fprintf(ch,"    int x=0,asd=0,len=a.length();\n");
    fprintf(ch,"    int tr;\n");
    fprintf(ch,"    for(int i=0;i<=len;i++)\n");
    fprintf(ch,"    {\n");
    fprintf(ch,"        if(a[i]>='0'&&a[i]<='9')\n");
    fprintf(ch,"        {\n");
    fprintf(ch,"            if(asd==1)x=x*10+a[i]-'0';\n");
    fprintf(ch,"            else x=a[i]-'0',asd=1;\n");
    fprintf(ch,"        }\n");
    fprintf(ch,"        else\n");
    fprintf(ch,"        {\n");
    fprintf(ch,"            if(asd==1)\n");
    fprintf(ch,"            {\n");
    fprintf(ch,"                tr=x;\n");
    fprintf(ch,"                asd=0,x=0;\n");
    fprintf(ch,"            }\n");
    fprintf(ch,"        }\n");
    fprintf(ch,"    }\n");
    fprintf(ch,"    return tr;\n");
    fprintf(ch,"}\n");
    fprintf(ch,"void check(int x)\n");
    fprintf(ch,"{\n");
    fprintf(ch,"    for(int i=1;i<=lbz;i++)\n");
    fprintf(ch,"    {\n");
    fprintf(ch,"        int lena=bz[i].length(),lenb=nd[i].length();\n");
    fprintf(ch,"        if(bz[i][lena-1]==' ')lena--;\n");
    fprintf(ch,"        if(nd[i][lenb-1]==' ')lenb--;\n");
    fprintf(ch,"        if(lena!=lenb){printf(\"\\033[91m?????????%%2d : WA ???%%3d ???\\033[0m\\n\",x,0);return ;}\n");
    fprintf(ch,"        for(int j=0;j<lena;j++)\n");
    fprintf(ch,"            if(bz[i][j]!=nd[i][j]){printf(\"\\033[91m?????????%%2d : WA ???%%3d ???\\033[0m\\n\",x,0);return ;}\n");
    fprintf(ch,"    }\n");
    fprintf(ch,"    zfen+=fen[x];\n");
    fprintf(ch,"    printf(\"\\033[92m?????????%%2d : AC ???%%3d ???\\033[0m\\n\",x,fen[x]);return ;\n");
    fprintf(ch,"}\n");
    fprintf(ch,"int main()\n");
    fprintf(ch,"{\n");
    fprintf(ch,"    ifstream CE(\"%s/CE2.txt\");\n",ID);
    fprintf(ch,"    while(len++,getline(CE,RE[len]));\n");
    fprintf(ch,"    for(int i=1;i<=len;i++)\n");
    fprintf(ch,"    {\n");
    fprintf(ch,"        test[check2(RE[i])]=1;\n");
    fprintf(ch,"    }\n");
    fprintf(ch,"    ifstream fn(\"%s/fen.txt\");\n",ID);
    fprintf(ch,"    fn>>n;\n");
    fprintf(ch,"    for(int i=1;i<=n;i++)\n");
    fprintf(ch,"        fn>>fen[i],ans+=fen[i];\n");
    fprintf(ch,"        fn.close();\n");
    for(int i=1;i<=stest;i++)
    {
        fprintf(ch,"    lbz=lnd=0;\n");
        fprintf(ch,"    if(test[1]==1)printf(\"\\033[91m????????? %2d : RE ???%%3d ???\\033[91m\\n\",0);\n",i);
        fprintf(ch,"    else\n");
        fprintf(ch,"    {\n");
        fprintf(ch,"        ifstream bzsc%d(\"%s/ans/t%d.out\");\n",i,ID,i);
        fprintf(ch,"        ifstream ndsc%d(\"%s/out/t%d.out\");\n",i,ID,i);
        fprintf(ch,"        while(lnd++,getline(ndsc%d,nd[lnd]));\n",i);
        fprintf(ch,"        while(lbz++,getline(bzsc%d,bz[lbz]));\n",i);
        fprintf(ch,"        bzsc%d.close();\n",i);
        fprintf(ch,"        ndsc%d.close();\n",i);
        fprintf(ch,"        if(bz[lbz]==\"\\n\")\n");
        fprintf(ch,"            lbz--;\n");
        fprintf(ch,"        if(nd[lnd]==\"\\n\")\n");
        fprintf(ch,"            lnd--;\n");
        fprintf(ch,"        if(lnd-lbz)\n");
        fprintf(ch,"            printf(\"\\033[91m?????????%2d : WA ???%%3d ???\\033[91m\\n\",0);\n",i);
        fprintf(ch,"        else check(%d);\n",i);  
        fprintf(ch,"    }\n");
    }
    fprintf(ch,"    printf(\"?????????:%%d\\n\",zfen);\n");
    fprintf(ch,"    if(zfen==ans){puts(\"??????????????????!\");}\n");
    fprintf(ch,"    return 0;\n");
    fprintf(ch,"}\n");
}
int main()
{
    printf("???????????????...\n");
    ifstream mn(".Problem/sum.txt");mn>>sum;mn.close();
    sum++;
    ofstream MN(".Problem/sum.txt");MN<<sum;MN.close();
    strcpy(tsum.a,"1");
    for(int i=1;i<sum;i++)tsum.pw();
    system("clear");
    printf("???????????????(???????????????)!");
    getchar();
    system("clear");
    puts("????????????");
    getchar();
    printf("??????P%d\n",sum);
    strcpy(ID,".Problem/P");strcat(ID,tsum.a);
    char dir[1000];
    strcpy(dir,"mkdir ");strcat(dir,ID);system(dir);
    strcpy(dir,"mkdir ");strcat(dir,ID);strcat(dir,"/out");system(dir);
    strcpy(dir,"touch ");strcat(dir,ID);strcat(dir,"/hzm.txt");system(dir);
    strcpy(dir,"touch ");strcat(dir,ID);strcat(dir,"/submit.cpp");system(dir);
    strcpy(dir,"touch ");strcat(dir,ID);strcat(dir,"/CE.txt");system(dir);
    strcpy(dir,"touch ");strcat(dir,ID);strcat(dir,"/K.txt");system(dir);
    int asd=0;
    while(1)
    {
        system("clear");
        puts("????????????");
        printf("??????P%d\n",sum);
        printf("?????? \n1??????or 2??????");scanf("%d",&asd);
        if(asd==2||asd==1)break;
    }
    if(asd==1)
    {
        char hzm[1000];
        system("clear");
        puts("????????????");
        printf("??????P%d\n",sum);
        puts("????????????");
        while(1)
        {
            printf("???????????????:");scanf("%s",hzm);
            if(hzm[0]=='.')break;
        }
        strcpy(dir,ID);strcat(dir,"/hzm.txt");
        ofstream hz(dir);hz<<hzm<<endl;
        printf("?????????????????????????????????????????????timain%s",hzm);
        strcpy(dir,"open ");strcat(dir,ID);system(dir);   
    }
    else
    {
        char hzm[1000];
        system("clear");
        puts("????????????");
        printf("??????P%d\n",sum);
        puts("????????????");
        while(1)
        {
            printf("???????????????(????????????PDF):");scanf("%s",hzm);
            if(!strcmp(hzm,".pdf"))continue;
            if(hzm[0]=='.')break;
        }
        strcpy(dir,ID);strcat(dir,"/hzm.txt");
        ofstream hz(dir);hz<<hzm<<endl;
        strcpy(dir,"touch ");strcat(dir,ID);strcat(dir,"/timian");strcat(dir,hzm);system(dir);
        strcpy(dir,"open ");strcat(dir,ID);strcat(dir,"/timian");strcat(dir,hzm);system(dir);  
        printf("??????????????????timain%s",hzm);
    }
    getchar();
    while(1)
    {
        system("clear");
        puts("????????????");
        printf("??????P%d\n",sum);
        puts("????????????");
        printf("????????????(?????????50???)");scanf("%d",&stest);
        if(stest>50||stest<=0)continue;
        else break;
    }
    getchar();
    while(1)
    {
        system("clear");
        puts("????????????");
        printf("??????P%d\n",sum);
        puts("????????????");
        printf("??????%d?????????",stest);
        puts("????????????:");
        printf("?????????????????????????????????,????????????????????????t_.in,?????????????????????");
        strcpy(dir,"mkdir ");strcat(dir,ID);strcat(dir,"/in");system(dir);
        strcpy(dir,"open ");strcat(dir,ID);strcat(dir,"/in");system(dir);
        break;
    }
    getchar();
    while(1)
    {
        system("clear");
        puts("????????????");
        printf("??????P%d\n",sum);
        puts("????????????");
        printf("??????%d?????????",stest);
        puts("????????????(Special judge??????):");
        printf("?????????????????????????????????,????????????????????????t_.out,?????????????????????");
        strcpy(dir,"mkdir ");strcat(dir,ID);strcat(dir,"/ans");system(dir);
        strcpy(dir,"open ");strcat(dir,ID);strcat(dir,"/ans");system(dir);
        break;
    }
    getchar();
    char judge[1000];
    while(1)
    {
        system("clear");
        puts("????????????");
        printf("??????P%d\n",sum);
        puts("????????????");
        printf("??????%d?????????\n",stest);
        printf("????????????(????????????OI)");scanf("%s",judge);
        if(!strcmp(judge,"OI"))break;
    }
    getchar();
    strcpy(dir,"touch ");strcat(dir,".Problem/P");strcat(dir,tsum.a);strcat(dir,"/judge.txt");system(dir);
    if(!strcmp(judge,"OI"))
    {
        system("clear");
        puts("????????????");
        printf("??????P%d\n",sum);
        puts("????????????");
        puts("???????????????");
        for(int i=1;i<=stest;i++)
        {
            printf("test%5d :",i);scanf("%lf",&tm[i]);
        }
        printf("?????????????????????:1 ??? 0??????");scanf("%d",&asd);
        if(asd==1)
        {
            puts("???????????????:");
            for(int i=1;i<=stest;i++)
            {
                printf("test%5d :",i);scanf("%d",&fen[i]),zfen+=fen[i];
            }
        }
        else
        {
            printf("??????100???\n");
            for(int i=1;i<stest;i++)
                fen[i]=100/stest;
            fen[stest]=100-(100/stest*(stest-1));
        }
        getchar();
        // system("clear");
        // puts("????????????");
        // printf("??????P%d\n",sum);
        // puts("????????????");
        // system("clear");
        // puts("????????????");
        // printf("??????P%d\n",sum);
        // puts("????????????");
        // puts("??????Special judge 1??? 0??????(????????????Special judge??????)");scanf("%d",&asd);
        // if(asd==1)
        // {
        //     printf("????????????????????????????????????,????????????check.cpp!(?????????check.cpp????????????!!!!)\n");
        //     strcpy(dir,"open ");strcat(dir,ID);system(dir);            
        // }
        // else
        strcpy(dir,"touch ");strcat(dir,ID);strcat(dir,"/check.cpp");system(dir);
    }
    // else if(!strcmp(judge,"ACM"))
    // {
    //     puts("???????????????");
    //     for(int i=1;i<=stest;i++)
    //     {
    //         printf("test%5d :",i);scanf("%d",&tm[i]);
    //     }
    //     puts("??????Special judge 1??? 0??????");scanf("%d",&asd);
    //     if(asd==1)
    //     {
    //         printf("????????????????????????????????????,????????????check.cpp!(????????????????????????AC,????????????WA,?????????check.cpp????????????!!!!)\n");
    //         strcpy(dir,"open ");strcat(dir,ID);system(dir);         
    //     }
    //     else
    //     {
    //         strcpy(dir,"touch ");strcat(dir,ID);strcat(dir,"/check.cpp");system(dir);
    //         strcpy(dir,ID);strcat(dir,"/check.cpp");system(dir);
    //     }
    // }
    // while(1)
    // {
    //     system("clear");
    //     puts("????????????");
    //     printf("??????P%d\n",sum);
    //     printf("??????std(??????std.cpp?????????????????????)");
    //     strcpy(dir,"open ");strcat(dir,ID);system(dir);
    //     getchar();
    //     getchar();
    //     break;
    // }
    puts("????????????(???????????????)!");
    getchar();
    system("clear");
    printf("??????????????????...\n");
    strcpy(dir,ID);strcat(dir,"/judge.txt");
    ofstream Ju(dir);Ju<<judge<<(asd==1?" +SPJ":" +0")<<endl;Ju.close();
    if(asd==0)
    {
        strcpy(dir,ID);strcat(dir,"/check.cpp");
        check(dir);
    }
    strcpy(dir,"touch ");strcat(dir,ID);strcat(dir,"/check.sh");
    strcpy(dir,ID);strcat(dir,"/check.sh");
    check1(dir);
    strcpy(dir,ID);strcat(dir,"/fen.txt");ofstream fn(dir);fn<<stest<<endl;for(int i=1;i<=stest;i++)fn<<fen[i]<<" ";
    strcpy(dir,ID);strcat(dir,"/tm.txt");ofstream TM(dir);TM<<stest<<endl;for(int i=1;i<=stest;i++)TM<<tm[i]<<" ";
    system("clear");
    return 0;
}