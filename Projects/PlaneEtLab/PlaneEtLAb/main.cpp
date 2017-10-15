#include <iostream>
using namespace std;


/*------------------------------------------
*Program Name: Delete Repeats
*Author: J. Hernandez
*Purpose: The pirpose of this project was to become familiar with pointers and to 
*input seating in a lab or plane setting.  To demonstrate the versatility of making base functions that
*are not reliant on specifics.
*/



typedef int T;//makes it easy to change variable types

void TestPlane();//used to test plane function
void TestLab();//used to test lab function
int sizeArray(int* size);//gives back the size of the size array
void allocate2D(T** &a,int* sizes);//creates a 2d array
void init2D(T** &a, int* sizes, T init_item);//initializes a 2d array
void print2D(T **&print2D, int* sizes);//prints a 2d array
T read2D(T** a, int row, int col);// is able to read a 2D array
void write2D(T **a, int row, int col, const T &item);//is able to write a 2D array
void printD(int a[]);//prints a single array

int main(){
    cout<<"\n\n ============================================================================= \n\n";

    //    TestPlane();
    TestLab();

    cout<<"\n\n ============================================================================= \n\n";
    return 0;
}

void TestPlane(){
    T row=0;
    T seat=0;
    T size[20]={4,4,4,4,-1};
    cout<<"\n\n The available seats: \n\n";
    cout<<" Which seat would you like?";
    cout<<" Row: ";
    cin>>row;
    cout<<" Seat: ";
    cin>>seat;


}
void TestLab(){
    char ans;
    T** labs;
    T inside = 1;
    int lab_sizes[20]={4,3,2,-1};
    int ID=0;
    int row=0;
    int col=0;

    allocate2D(labs,lab_sizes);//allocate the number of labs
    init2D(labs,lab_sizes,inside);//initialize by making them all 1's to indicate true
    //as in open for use, 0 will be written in
    print2D(labs,lab_sizes);//prints the labs and their avail

    cout<<"\n\n log[i]n log[o]ut e[x]it \n :";//menu for user
    cin>>ans;
    while(toupper(ans)!='X'){
        switch(toupper(ans)){
            case 'I':
                cout<<"----------LOG IN---------- \n";
                cout<<" labs: ";
                printD(lab_sizes);//prints the available labs
                cout<<endl;
                cout<<"\n\n Enter ID:";
                cin>>ID;
                cout<<"\n Choose a lab position!\n";
                cout<<"row: ";
                cin>>row;
                cout<<"col: ";
                cin>>col;
                write2D(labs,row,col,ID);
                print2D(labs,lab_sizes);


        }


        cout<<" log[i]n log[o]ut e[x]it \n :";
        cin>>ans;

    }
}
int sizeArray(int* size){
    int s=0;
    int* w;
    w=size+s;
    while(*w!=-1){
        w++;
        s++;
    }
    return s;
}

void allocate2D(T **&a, int *sizes){
    int size=sizeArray(sizes);
    a=new T*[size];
    T** w;
    T* w2;
    for (int i=0; i<size; i++){
        w=a+i;
        w2=sizes+i;
        *w= new T[*w2];
    }//for
    //    init2D(a,sizes,1);
    //    print2D(a,sizes);
    //    write2D(a,2,2,66);
    //    cout<<read2D(a,2,2)<<endl<<endl;
    //    print2D(a,sizes);

}//allocate void

void print2D(T **&print2D, int *sizes){
    int size=sizeArray(sizes);
    T** w;
    T* w2;
    T* s;
    for (int i=0; i<size; i++){
        w=print2D+i;
        s=sizes+i;
        for(int j=0;j<*s;j++){
            w2=*w+j;
            cout<<"["<<*w2<<"] ";
        }//for2
        cout<<endl;
    }//for
}

void init2D(T **&a, int* sizes, T init_item){
    int size=sizeArray(sizes);
    T** w;
    T* w2;
    T* s;
    for (int i=0; i<size; i++){
        w=a+i;
        s=sizes+i;
        for(int j=0;j<*s;j++){
            w2=*w+j;
            *w2=init_item;
        }//for2
    }//for
}

T read2D(T **a, int row, int col){
    T** w;
    T* w2;
    w=a+row;
    w2=*w+col;
    return *w2;
}
void write2D(T **a, int row, int col,const T& item){
    T** w;
    T* w2;
    w=a+row;
    w2=*w+col;
    *w2=item;
}
void printD(int a[]){
    int* w;
    int i=1;
    w=a;
    while(*w!=-1){
        cout<<" "<<*w;
        w=a+i;
        i++;
    }
}

