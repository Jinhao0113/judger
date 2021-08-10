#include<bits/stdc++.h>
using namespace std;
char lg[10000]=".problem/",lug[10000],hd[10000]="/submit.cpp";
char n[1000],sum[1000];
int main()
{
    int asdasd;
    system("clear");
    FILE * in=fopen(".problem/sum.txt","r");
    fscanf(in,"%s",sum);
    fclose(in);
    while(1)
    {
        system("clear");
        printf("请输入题号(退出提交-1):");
        scanf("%s",n);
        int asd=0;
        if(!strcmp(n,"-1")){return 0;}
        if(n[0]!='P'){continue;}
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
    char lang[1000];
    while(1)
    {
        system("clear");
        printf("请选择语言(c++17)");
        scanf("%s",lang);
        if(!strcmp(lang,"c++17"))break;
    }
    strcpy(lug,lg);
    system("clear");
    int asd;
    char op[1000];
    strcpy(op,".problem/"),
    strcat(op,n);
    if(strcmp(lang,"c++")==0||strcmp(lang,"c++11")==0||strcmp(lang,"c++17")==0)
    {
        strcat(op,"/submit.cpp");
    }
    printf("<%s>\n",lang);
    ofstream out(op);
    char rmdir[1000]="rm -rf .problem/";strcat(rmdir,n);strcat(rmdir,"/out");system(rmdir);
    char mkdir[1000]="mkdir .problem/";strcat(mkdir,n);strcat(mkdir,"/out");system(mkdir);
    out.clear();
    string s;
    getchar();
    while(1)
    {
        getline(cin,s);
        if(s=="//END")break;
        out<<s<<endl;
    }
    out.close();
    if(!strcmp(lang,"c++")||!strcmp(lang,"c++11")||!strcmp(lang,"c++17"))
    {
        char ans1[10000]="./";
        char ans2[10000]="chmod 777 .Problem/";strcat(ans2,n);strcat(ans2,"/check.sh"); 
        system(ans2);
        strcat(ans1,lg),strcat(ans1,n),strcat(ans1,"/check.sh 2>.Problem/");strcat(ans1,n);strcat(ans1,"/CE2.txt");
        system(ans1);//-O2 -lm -std=c++11 -DONLINE_JUDGE
    }
    // if(!strcmp(lang,"c"))
    // {
    //     char ans[10000]="gcc ";
    //     strcat(ans,lug),strcat(ans,n),strcat(ans,"/submit.c"),
    //     strcat(ans," -o problem/t"),
    //     strcat(ans,n),strcat(ans,"/yx ");
    //     strcat(ans,"-O2 -lm -DONLINE_JUDGE");
    //     strcat(ans," 2>"),strcat(ans,lg),
    //     strcat(ans,n),
    //     strcat(ans,"/result.txt");
    //     system(ans);
    //     char ans1[10000]="./";
    //     char ans2[10000]="chmod 777 problem/t";strcat(ans2,n);strcat(ans2,"/checkc.sh"); 
    //     system(ans2);
    //     strcat(ans1,lg),strcat(ans1,n),strcat(ans1,"/checkc.sh");
    //     system(ans1);
    // }
    // else if(!strcmp(lang,"java"))
    // {
    //     char ans1[10000]="./";
    //     char ans2[10000]="chmod 777 problem/t";strcat(ans2,n);strcat(ans2,"/checkjava.sh"); 
    //     system(ans2);
    //     strcat(ans1,lg),strcat(ans1,n),strcat(ans1,"/checkjava.sh");
    //     system(ans1);
    // }
    // else if(!strcmp(lang,"python2"))
    // {
    //     char ans1[10000]="./";
    //     char ans2[10000]="chmod 777 problem/t";strcat(ans2,n);strcat(ans2,"/checkpy2.sh"); 
    //     system(ans2);
    //     strcat(ans1,lg),strcat(ans1,n),strcat(ans1,"/checkpy2.sh");
    //     system(ans1);
    // }
    // else if(!strcmp(lang,"python3"))
    // {
    //     char ans1[10000]="./";
    //     char ans2[10000]="chmod 777 problem/t";strcat(ans2,n);strcat(ans2,"/checkpy3.sh"); 
    //     system(ans2);
    //     strcat(ans1,lg),strcat(ans1,n),strcat(ans1,"/checkpy3.sh");
    //     system(ans1);
    // }
    puts("END(请按下回车)");
    getchar();
    system("clear");
    return 0;
}