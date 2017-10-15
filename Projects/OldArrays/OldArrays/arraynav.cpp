#include "arraynav.h"

ArrayNav::ArrayNav(){
}

ArrayNav::ArrayNav(const int a[],int &size):arr(a, size){
    //    PartialArray(a,size); THIS DOES NOT INITIALIZE YOUR ARRAY
    cPos = 0;
}

int ArrayNav::Left(){
    cPos--;
}


int ArrayNav::Right(){
    cPos++;
}

int ArrayNav::Insert(int InsertMe){
    arr.InsertB(InsertMe,cPos);
    return cPos;
}

int ArrayNav::Append(int AppendMe){
    arr.Append(AppendMe);
    return cPos;
}

int ArrayNav::Delete(){
    arr.Delete(cPos);
    return cPos;
}

int ArrayNav::Search(int key){
}

ostream& operator <<(ostream& out,const ArrayNav& an){
    for(int i=0;i<an.arr.NumUsing();i++){
        if(i==an.cPos){
            out<<"["<<an.arr.At(i)<<"] ";
        }
        else{
            out<<an.arr.At(i)<<" ";
        }
    }//for
    return out;
}

