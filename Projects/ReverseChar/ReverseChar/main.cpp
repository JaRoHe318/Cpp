 #include <iostream>
using namespace std;

/* Name: Jason Hernandez
 * Project: Reverse(Char *s)
 * Comments: The biggest problem I had with this problem is that I
 * thought everything had to be pointers.  I went crazy with pointers and it really confused
 * me for a couple hours.  The reason this took so long was because I kept printing
 * before the function reverse was called so it looked as if nothing happened...
 * This took way longer for me to realize than it should have.
*/

typedef char* CharPtr;//To make declaring pointers easier

void SwapPtr(char &a, char &b);//a function that moves two different values
int StrLen(char *l);//Gives the length of a Char array
void Reverse(CharPtr r);//reverses a char array without using a different array

int main(){
    cout<<endl<<endl<<endl<<"============================================="<<endl<<endl;

    char s[100]="123456789";

    cout<<endl<<"before: "<<s<<endl;

    Reverse(s);

    cout<<endl<<"after: "<<s<<endl;


    cout<<endl<<endl<<endl<<"============================================="<<endl<<endl;
    return 0;
}

void SwapPtr(char &a, char &b){
    char temp;
    temp = a;
    a=b;
    b=temp;
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
void Reverse(CharPtr r){
    int lead=0;
    int lag=StrLen(r)-1;
    CharPtr a;
    CharPtr b;
    if(lag%2!=0){//for even len
        while(lag>lead){
            a = r+lead;
            b = r+lag;
            SwapPtr(*a,*b);
            lead++;
            lag--;
        }

    }else if(lag%2==0){//for odd len
        while(lag!=lead){
            a = r+lead;
            b = r+lag;
            SwapPtr(*a,*b);
            lead++;
            lag--;

        }
    }

}//void
