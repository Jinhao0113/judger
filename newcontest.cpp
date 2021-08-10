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
int prosum;
char testin[100][1000],testout[100][1000],testname[100][1000],testdir[100][1000],hzm[100][1000];
void check1(char FL[],int x)
{
    FILE*ch=fopen(FL,"w");
    fprintf(ch,"g++ %s/check.cpp -o %s/check\n",ID,ID);
    fprintf(ch,"g++ %s/submit.cpp -o %s/submit -O2 -lm -std=c++17 -DONLINE_JUDGE 2>%s/CE.txt\n",ID,ID,ID);
    fprintf(ch,"if diff %s/CE.txt %s/K.txt ; then\n",ID,ID);
    for(int i=1;i<=stest;i++)
        fprintf(ch,"    gtimeout %lf ./%s/submit < %s/in/t%d.in > %s/out/t%d.out\n",tm[i],ID,ID,i,ID,i);
    fprintf(ch,"    clear\n");
    fprintf(ch,"    clear\n");
    fprintf(ch,"    ./%s/check\n",ID);
    fprintf(ch,"else\n");
    fprintf(ch,"    clear\n");
    fprintf(ch,"fi\n");
    fclose(ch);
}
void check(char FL[],int x)
{
    FILE*ch=fopen(FL,"w");
    fprintf(ch,"#include<bits/stdc++.h>\n");
    fprintf(ch,"using namespace std;\n");
    fprintf(ch,"string nd[1000001],bz[1000001];\n");
    fprintf(ch,"int fen[1000001],n,zfen;\n");
    fprintf(ch,"int lnd,lbz,ans,asd=0;\n");
    fprintf(ch,"int test[100],len;\n");
    fprintf(ch,"void check(int x)\n");
    fprintf(ch,"{\n");
    fprintf(ch,"    for(int i=1;i<=lbz;i++)\n");
    fprintf(ch,"        if(nd[i]!=bz[i])return ;\n");
    fprintf(ch,"    zfen+=fen[x];\n");
    fprintf(ch,"    return ;\n");
    fprintf(ch,"}\n");
    fprintf(ch,"int main()\n");
    fprintf(ch,"{\n");
    fprintf(ch,"    ifstream fn(\"%s/fen.txt\");\n",ID);
    fprintf(ch,"    fn>>n;\n");
    fprintf(ch,"    for(int i=1;i<=n;i++)\n");
    fprintf(ch,"        fn>>fen[i],ans+=fen[i];\n");
    fprintf(ch,"    fn.close();\n");
    for(int i=1;i<=stest;i++)
    {
        fprintf(ch,"    lnd=lnd=1;\n");
        fprintf(ch,"    ifstream bzsc%d(\"%s/ans/t%d.out\");\n",i,ID,i);
        fprintf(ch,"    ifstream ndsc%d(\"%s/out/t%d.out\");\n",i,ID,i);
        fprintf(ch,"    while(ndsc%d>>nd[lnd])lnd++;\n",i);
        fprintf(ch,"    while(bzsc%d>>bz[lbz])lbz++;\n",i);
        fprintf(ch,"    lnd--,lnd--,asd=0;\n");
        fprintf(ch,"    if(lnd==lbz)\n");
        fprintf(ch,"        for(int i=1;i<asd;i++)\n");
        fprintf(ch,"            if(bz[i]!=nd[i]){asd=1;break;}\n");
        fprintf(ch,"    if(!asd){zfen+=fen[%d];}\n",i);
    }
    fprintf(ch,"    printf(\"%%d\\n\",zfen);\n");
    fprintf(ch,"    return 0;\n");
    fprintf(ch,"}\n");
}
int main()
{
    printf("正在初始化...\n");
    ifstream mn(".contest/sum.txt");mn>>sum;mn.close();
    sum++;
    ofstream MN(".contest/sum.txt");MN<<sum;MN.close();
    strcpy(tsum.a,"1");
    for(int i=1;i<sum;i++)tsum.pw();
    system("clear");
    printf("初始化成功(回车以继续)!");
    getchar();
    system("clear");
    puts("新建比赛");
    getchar();
    printf("比赛号c%d\n",sum);
    strcpy(ID,".contest/c");strcat(ID,tsum.a);
    char dir[1000];
    strcpy(dir,"mkdir ");strcat(dir,ID);system(dir); 
    strcpy(dir,"mkdir ");strcat(dir,ID);strcat(dir,"/code");system(dir);
    while(1)
    {
        system("clear");
        puts("新建比赛");
        printf("比赛号c%d\n",sum);
        printf("请输入题数(1<sum≤10)");scanf("%d",&prosum);
        if(prosum>1&&prosum<=50)break;
    }
    char make[1000];
    strcpy(make,ID);strcat(make,"/sum.txt");
    strcpy(dir,"touch ");strcat(dir,ID);system(dir);
    ofstream problsum(make);problsum<<prosum<<endl;problsum.close();
    node probsum;
    strcpy(probsum.a,"0");
    for(int i=1;i<=prosum;i++)
    {
        probsum.pw();
        strcpy(ID,".contest/c");strcat(ID,tsum.a);strcat(ID,"/P");strcat(ID,probsum.a);
        strcpy(dir,"mkdir ");strcat(dir,ID);system(dir);
        strcpy(dir,"mkdir ");strcat(dir,ID);strcat(dir,"/out");system(dir);
        strcpy(dir,"touch ");strcat(dir,ID);strcat(dir,"/hzm.txt");system(dir);
        // strcpy(dir,"touch ");strcat(dir,ID);strcat(dir,"/submit.cpp");system(dir);
        strcpy(dir,"touch ");strcat(dir,ID);strcat(dir,"/CE.txt");system(dir);
        strcpy(dir,"touch ");strcat(dir,ID);strcat(dir,"/K.txt");system(dir);
        int asd=0;
        while(1)
        {
            system("clear");
            puts("新建比赛题目");
            printf("题号C%dP%d\n",sum,i);
            printf("题面 \n1上传or 2写入");scanf("%d",&asd);
            if(asd==2||asd==1)break;
        }
        if(asd==1)
        {
            system("clear");
            puts("新建比赛题目");
            printf("题号C%dP%d\n",sum,i);
            puts("题面上传");
            while(1)
            {
                printf("题面后缀名:");scanf("%s",hzm[i]);
                if(hzm[i][0]=='.')break;
            }
            strcpy(dir,ID);strcat(dir,"/hzm.txt");
            ofstream hz(dir);hz<<hzm[i]<<endl;
            printf("请将题面拖至以下文件夹并命名为timain%s",hzm[i]);
            strcpy(dir,"open ");strcat(dir,ID);system(dir);   
        }
        else
        {
            system("clear");
            puts("新建比赛题目");
            printf("题号C%dP%d\n",sum,i);
            puts("题面写入");
            while(1)
            {
                printf("题面后缀名(不能使用PDF):");scanf("%s",hzm[i]);
                if(!strcmp(hzm[i],".pdf"))continue;
                if(hzm[i][0]=='.')break;
            }
            strcpy(dir,ID);strcat(dir,"/hzm.txt");
            ofstream hz(dir);hz<<hzm[i]<<endl;
            strcpy(dir,"touch ");strcat(dir,ID);strcat(dir,"/timian");strcat(dir,hzm[i]);system(dir);
            strcpy(dir,"open ");strcat(dir,ID);strcat(dir,"/timian");strcat(dir,hzm[i]);system(dir);  
            printf("请将题面写入timain%s",hzm[i]);
        }
        getchar();
        while(1)
        {
            system("clear");
            puts("新建比赛题目");
            printf("题号C%dP%d\n",sum,i);
            puts("数据上传");
            printf("数据个数(不超过40个)");scanf("%d",&stest);
            if(stest>50||stest<=0)continue;
            else break;
        }
        getchar();
        while(1)
        {
            system("clear");
            puts("新建比赛题目");
            printf("题号C%dP%d\n",sum,i);
            puts("数据上传");
            printf("共有%d个数据",stest);
            puts("输入数据:");
            printf("请将数据拖至以下文件夹,每个测试点命名为t_.in,为测试数据编号");
            strcpy(dir,"mkdir ");strcat(dir,ID);strcat(dir,"/in");system(dir);
            strcpy(dir,"open ");strcat(dir,ID);strcat(dir,"/in");system(dir);
            break;
        }
        getchar();
        while(1)
        {
            system("clear");
            puts("新建比赛题目");
            printf("题号C%dP%d\n",sum,i);
            puts("数据上传");
            printf("共有%d个数据",stest);
            puts("输出数据:");
            printf("请将数据拖至以下文件夹,每个测试点命名为t_.out,为测试数据编号");
            strcpy(dir,"mkdir ");strcat(dir,ID);strcat(dir,"/ans");system(dir);
            strcpy(dir,"open ");strcat(dir,ID);strcat(dir,"/ans");system(dir);
            break;
        }
        getchar();
        system("clear");
        puts("新建比赛题目");
        printf("题号C%dP%d\n",sum,i);
        puts("数据上传");
        puts("测试点时限");
        for(int j=1;j<=stest;j++)
        {
            printf("test%5d :",j);scanf("%lf",&tm[j]);
        }
        printf("是否自定义分数:1 是 0不是");scanf("%d",&asd);
        if(asd==1)
        {
            puts("自定义分数:");
            for(int j=1;j<=stest;j++)
            {
                printf("test%5d :",j);scanf("%d",&fen[j]),zfen+=fen[j];
            }
        }
        else
        {
            printf("    总分100分\n");
            for(int j=1;j<stest;j++)
                fen[j]=100/stest;
            fen[stest]=100-(100/stest*(stest-1));
        }
        getchar();
        // system("clear");
        // puts("新建比赛题目");
        // printf("题号C%dP%d\n",sum,i);
        // puts("数据上传");
        // puts("是否Special judge 1是 0不是(目前没有Special judge机制)");scanf("%d",&asd);
        // if(asd==1)
        // {
        //     printf("请将数据测试器拖入文件夹,并命名为check.cpp!(请确保check.cpp的正确性!!!!)\n");
        //     strcpy(dir,"open ");strcat(dir,ID);system(dir);            
        // }
        // else
        // strcpy(dir,"touch ");strcat(dir,ID);strcat(dir,"/check.cpp");system(dir);
        // while(1)
        // {
        //     system("clear");
        //     puts("新建比赛题目");
        //     printf("题号C%dP%d\n",sum,i);
        //     printf("上传std(请将std.cpp移到以下文件夹)");
        //     strcpy(dir,"open ");strcat(dir,ID);system(dir);
        //     getchar();
        //     getchar();
        //     break;
        // }
        while(1)
        {
            system("clear");
            puts("新建比赛题目");
            printf("题号C%dP%d\n",sum,i);
            printf("此题子文件夹名:(___,如果不对会出现全WA的错误)");scanf(" %s",testdir[i]);
            printf("此题文件名:(___.cpp,如果不对会出现全WA的错误)");scanf(" %s",testname[i]);
            printf("此题输入文件名:(___.in,如果不对会出现全WA的错误)");scanf(" %s",testin[i]);
            printf("此题输出文件名:(___.out,如果不对会出现全WA的错误)");scanf(" %s",testout[i]);
            break;
        }
        puts("上传成功(回车以继续)!");
        getchar();
        system("clear");
        printf("正在保存设置...\n");
        strcpy(dir,ID);strcat(dir,"/judge.txt");
        if(asd==0)
        {
            strcpy(dir,ID);strcat(dir,"/check.cpp");
            check(dir,i);
        }
        strcpy(dir,"touch ");strcat(dir,ID);strcat(dir,"/check.sh");system(dir);
        strcpy(dir,"touch ");strcat(dir,ID);strcat(dir,"/in.txt");system(dir);
        strcpy(dir,"touch ");strcat(dir,ID);strcat(dir,"/out.txt");system(dir);
        strcpy(dir,"touch ");strcat(dir,ID);strcat(dir,"/name.txt");system(dir);
        strcpy(dir,"touch ");strcat(dir,ID);strcat(dir,"/dir.txt");system(dir);
        // strcpy(dir,ID);strcat(dir,"/check.sh");system(dir);
        // check1(dir,i);
        strcpy(dir,ID);strcat(dir,"/fen.txt");ofstream fn(dir);fn<<stest<<endl;for(int i=1;i<=stest;i++)fn<<fen[i]<<" ";
        strcpy(dir,ID);strcat(dir,"/tm.txt");ofstream TM(dir);TM<<stest<<endl;for(int i=1;i<=stest;i++)TM<<tm[i]<<" ";
        strcpy(dir,ID);strcat(dir,"/in.txt");ofstream Testin(dir);Testin<<testin[i]<<endl;
        strcpy(dir,ID);strcat(dir,"/out.txt");ofstream Testout(dir);Testout<<testout[i]<<endl;
        strcpy(dir,ID);strcat(dir,"/name.txt");ofstream Testname(dir);Testname<<testname[i]<<endl;
        strcpy(dir,ID);strcat(dir,"/dir.txt");ofstream Testdir(dir);Testdir<<testdir[i]<<endl;
        strcpy(dir,ID);strcat(dir,"/sum.txt");ofstream Testsum(dir);Testdir<<stest<<endl;
    }
    string IP;
    printf("请输入当前网络IP:");cin>>IP;
    strcpy(dir,"mkdir .contest/c");strcat(dir,tsum.a);strcat(dir,"/Web");system(dir);
    strcpy(dir,"touch .contest/c");strcat(dir,tsum.a);strcat(dir,"/Web/con.html");system(dir);
    strcpy(dir,".contest/c");strcat(dir,tsum.a);strcat(dir,"/Web/con.html");system(dir);
    FILE*con=fopen(dir,"w");
    fprintf(con,"<meta charset=\"UTF-8\">\n");
    fprintf(con,"<h3></h3>\n");
    fprintf(con,"<h3>关于题面</h3>\n");
    node x;
    strcpy(x.a,"0");
    for(int i=1;i<=prosum;i++)
    {
        x.pw();
        fprintf(con,"<a href=\"http://%s/contest/c%d/timian%d%s\">打开%s的题面</a>\n<h3></h3>\n",IP.c_str(),sum,i,hzm[i],testdir[i]);
        strcpy(dir,"sudo cp .contest/c");strcat(dir,tsum.a);strcat(dir,"/p");strcat(dir,x.a);
        strcat(dir,"/timian");strcat(dir,hzm[i]);strcat(dir," /Library/WebServer/Documents/contest/c");strcat(dir,tsum.a);
        strcat(dir,"/timian");strcat(dir,x.a);strcat(dir,hzm[i]);
        system(dir);
    }
    fprintf(con,"<h3>关于大样例</h3>\n");
    fprintf(con,"<a href=\"http://%s/contest/c%d/shuju/shuju.html\">下载</a>\n",IP.c_str(),sum);
    strcpy(dir,"mkdir .contest/c");strcat(dir,tsum.a);strcat(dir,"/Web/shuju");system(dir);
    strcpy(dir,"touch .contest/c");strcat(dir,tsum.a);strcat(dir,"/Web/shuju/shuju.html");system(dir);
    strcpy(x.a,"0");
    for(int i=1;i<=prosum;i++)
    {
        x.pw();
        // strcpy(x.a,"0");
        strcpy(dir,"mkdir .contest/c");strcat(dir,tsum.a);strcat(dir,"/Web/shuju/");strcat(dir,testdir[i]);system(dir);
        strcpy(dir,"cp .contest/c");strcat(dir,tsum.a);strcat(dir,"/p");strcat(dir,x.a);strcat(dir,"/in/t1.in ");
        strcat(dir,".contest/c");strcat(dir,tsum.a);strcat(dir,"/Web/shuju/");strcat(dir,testdir[i]);strcat(dir,"/");
        strcat(dir,testin[i]);system(dir);
        strcpy(dir,"cp .contest/c");strcat(dir,tsum.a);strcat(dir,"/p");strcat(dir,x.a);strcat(dir,"/ans/t1.out ");
        strcat(dir,".contest/c");strcat(dir,tsum.a);strcat(dir,"/Web/shuju/");strcat(dir,testdir[i]);strcat(dir,"/");
        strcat(dir,testout[i]);system(dir);
    }
    fclose(con);
    strcpy(dir,".contest/c");strcat(dir,tsum.a);strcat(dir,"/Web/shuju/shuju.html");
    FILE*shuju=fopen(dir,"w");
    for(int i=1;i<=prosum;i++)
    {
        fprintf(shuju,"<a href=\"http://%s/contest/c%d/shuju/%s/%s\" download=\"%s\">%s</a>\n",IP.c_str(),sum,testdir[i],testin[i],testin[i],testin[i]);
        fprintf(shuju,"<h5></h5>\n");
        fprintf(shuju,"<a href=\"http://%s/contest/c%d/shuju/%s/%s\" download=\"%s\">%s</a>\n",IP.c_str(),sum,testdir[i],testout[i],testout[i],testout[i]);
        fprintf(shuju,"<h5></h5>\n");        
    }
    fclose(shuju);
    strcpy(dir,"sudo cp -R .contest/c");strcat(dir,tsum.a);strcat(dir,"/Web /Library/WebServer/Documents/contest/c");strcat(dir,tsum.a);system(dir);
    strcpy(dir,"sudo open http://");strcat(dir,IP.c_str());strcat(dir,"/contest/c");strcat(dir,tsum.a);strcat(dir,"/con.html");system(dir);
    return 0;
}
// /Library/WebServer/Documents/contest