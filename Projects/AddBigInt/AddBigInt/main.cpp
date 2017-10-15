#include <iostream>
using namespace std;

/*Name: Jason Hernandez
 * Project Add Big Int
 * Comments:  I made a lot of mistakes with pointers in the beginning.  The biggest problem was that I did not
 * fully comprehend the concept of a "walker" so in the beginning I used the initial pointer to do pointer
 * arithmetic with.  This gave the most bugs because the value would change twice
 * ex) walker+=i; If walker was say at location 4 and I did this operation it would not go simply to location
 * 5 but it would make walker 5 and add another 1 making it 6; (At least that's more or less how I saw it)
 * Once I got the hang of it, it went fairly quickly.  Unfortunately this isn't a project that can be done in a day
 * and I greatly suffered for not starting sooner.
 *
 * P.S. While I was copying and pasting the tests I realized the function wouldn
*/

typedef char* CharPtr;

/*void SwapPtr(char &a,char&b);
void StrCopy(CharPtr s, CharPtr d);
void Reverse(CharPtr r);
I thought these functions would be helpful but I made my
program in a way that didn't need them. So I commented them
out!
*/
int StrLen(char *l);//Used to give length of a char array
void AddZero(CharPtr shorter, CharPtr longer, int length);//Adds Zeros to an Array
void Add(CharPtr num1, CharPtr num2, CharPtr result, int base);

int main(){
    cout<<endl<<endl<<endl<<"============================================="<<endl<<endl;

    char a[100]="12121212";//One of two char arrays being added
    char b[100]="12121212";
    char r[100]="0";//Initialize a blank char array to store answer

    Add(a,b,r,10);

    cout<<a<<" + "<<b<<" = "<<r<<endl;

    cout<<endl<<endl<<endl<<"============================================="<<endl<<endl;
    return 0;
}
int StrLen(char *l){
    int len = 0;
    CharPtr w;
    w=l;
    do{
        w+=1;
        len++;
    }while(*w!=NULL);
    return len;
}
void AddZero(CharPtr shorter, CharPtr longer,int length){
    CharPtr w;
    CharPtr w2;
    int shortLen=StrLen(shorter);

    for(int i=0;i<length;i++){
        w=longer+i;
       *w='0';
    }
    do{
        w=longer+length;
        w2=shorter+shortLen;
        *w=*w2;
        length--;
        shortLen--;
    }while(shortLen>=0);
}//AddZero

void Add(CharPtr num1, CharPtr num2, CharPtr result, int base){
    int space;
    if(StrLen(num1)>StrLen(num2)){
        space = StrLen(num1)+2;
    }else{
        space = StrLen(num2)+2;
    }

    CharPtr a = new char[space];
    CharPtr b = new char[space];

    int lengthA=StrLen(num1);
    int lengthB=StrLen(num2);

    if(lengthA>lengthB){
        AddZero(num2,b,lengthA);
    }
    if(lengthA<lengthB){
        AddZero(num1,a,lengthB);
    }
    if(lengthA==lengthB){

        CharPtr w;
        CharPtr w2;
        CharPtr r;
        char ans;
        char remainder = '0';
        AddZero(num1,a,lengthA);
        AddZero(num2,b,lengthB);
        for(int i=lengthA;i>=0;i--){
            w=a+i-1;
            w2=b+i-1;
            r=result+i;
            ans = (*w+*w2+remainder)-(3*'0');
            if(ans>=base&&i!=0){
                *r=(ans-base)+'0';
                remainder = '1';
            }
            if(ans<base&&i!=0){
                *r=ans+'0';
                remainder = '0';
            }
            if(i==0){
                *r=remainder;
            }
        }//for

    }//if

    delete []a;
    delete []b;
}//Add

//void SwapPtr(char &a, char &b){
//    char temp;
//    temp = a;
//    a=b;
//    b=temp;
//}

//void StrCopy(CharPtr s, CharPtr d){
//    CharPtr w;
//    CharPtr w2;
//    int i=0;
//    do{
//        w=s+i;
//        w2=d+i;
//        *w2=*w;
//        i++;
//    }while (*w!=NULL);
//    *w2=NULL;


//}
//void Reverse(CharPtr r){
//    int lead=0;
//    int lag=StrLen(r)-1;
//    CharPtr a;
//    CharPtr b;
//    if(lag%2!=0){//for even len
//        while(lag>lead){
//            a = r+lead;
//            b = r+lag;
//            SwapPtr(*a,*b);
//            lead++;
//            lag--;
//        }

//    }else if(lag%2==0){//for odd len
//        while(lag!=lead){
//            a = r+lead;
//            b = r+lag;
//            SwapPtr(*a,*b);
//            lead++;
//            lag--;
//        }
//    }

//}//void
