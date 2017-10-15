#include <iostream>
using namespace std;

//Do Programming Project 3 in Chapter 7. In this version of the problem,
//return a new dynamic array where all repeated letters are deleted instead of
//modifying the partially filled array. Don’t forget to free the memory allocated
//for these returned dynamic arrays when the data is no longer needed.

typedef int* IntPtr;
typedef char* CharPtr;

void DeleteRepeat(char a[]);
int StrLen(char l[]);
void StrCpy(char a[], char b[]);
int StrKey(char a[]);

int main(){
    cout<<"\n\n ============================================================================= \n\n";

    char a[20] = "abbccad";


    DeleteRepeat(a);

    cout<<"\n\n ============================================================================= \n\n";

    return 0;
}

void DeleteRepeat(char a[]){
    int len=StrLen(a);
    for(int i=0;i<len;i++){


    }//for i

//    cout<<"n: "<<n<<endl;
//    StrCpy(n,a);

}
int StrLen(char l[]){
    int len = 0;
    CharPtr w;
    w=l;
    do{
        w+=1;
        len++;
    }while(*w!=NULL);
    return len;
}
void StrCpy(char a[],char b[]){
    int len = StrLen(a);
    CharPtr w;
    CharPtr w2;

    for(int i=0;i<len;i++){
        w=a+i;
        w2=b+i;
        *w2=*w;
    }
}
int StrKey(char a[]){
    return *a;
}
