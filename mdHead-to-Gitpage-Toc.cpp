#include<fstream>
using namespace std;

int main(){
    ifstream markdown;
    //filename of your md
    markdown.open("filename1");
    ofstream toc;
    //filename of your toc
    toc.open("filename2");
    char word='\0';
    int count;
    count=0;
    int i;
    i=0;
    bool flag;
    flag=0;
    char tocstring[100]={0};
     while(markdown.get(word)){
       if(word=='#'){
         count++;
         continue;
       }
       if(count&&!flag){
         if(word==' ') flag=1;
         if(word!='#'&&word!=' ') count=0;
         continue;
       }
       if(flag){
         tocstring[i]=word;
         i++;
       }
       if(flag&&(word=='\n')){
         for(int k=0;k<2*(count-1);k++){
           toc<<' ';
         }
         if(count%2!=0) toc<<"- ";
         if(count%2==0) toc<<"* ";
         toc<<'[';
         tocstring[i-1]='\0';
         toc<<tocstring;
         toc<<"](#";
         toc<<tocstring;
         toc<<')';
         toc<<'\n';
         flag=0;
         count=0;
         for(i=0;i<100;i++){
           tocstring[i]='\0';
         }
         i=0;
     }
       if(word=='\n') count=0;
  }
  markdown.close();
  toc.close();
  return 0;
}
