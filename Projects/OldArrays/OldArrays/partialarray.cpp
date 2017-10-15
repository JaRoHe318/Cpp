#include "partialarray.h"

PartialArray::PartialArray(){
    numUsed=0;
}//constructor

PartialArray::PartialArray(const int a[],int &size){
    numUsed=size;
    for (int i=0; i<size; i++){
        array[i] = a[i];
    }//for

}//constructor


void PartialArray::Print()const{
    ::Print(array,numUsed);
}

int PartialArray::At(int i)const{
//    cout<<":"<<array[i]<<endl;
    return array[i];
}

int PartialArray::ShiftR(int start){
    ::ShiftR(array,numUsed,start);
    return numUsed;
}

int PartialArray::ShiftL(int start){
    ::ShiftL(array,numUsed,start);
    return numUsed;
}
int PartialArray::Append(int num){
    ::Append(array,numUsed,num);
    return numUsed;
}

int PartialArray::InsertB(int InsertMe,int Pos){
    ::InsertB(array,numUsed,InsertMe,Pos);
    return numUsed;
}

int PartialArray::InsertA(int InsertMe,int Pos){
    ::InsertA(array,numUsed,InsertMe,Pos);
    return numUsed;
}

int PartialArray::Delete(int Pos){
    ::Delete(array,numUsed,Pos);
    return numUsed;
}


int PartialArray::Search(){
}

void PartialArray::Sort(){
}

void PartialArray::Reverse(){
}

void PartialArray::DeleteRepeats(){
}

int PartialArray::NumUsing()const {
   return numUsed;
}

int& PartialArray::operator[](int i){

    int fail=-1;
    if(i<numUsed){
        return array[i];
    }

//    int fail = -1;
//    cout<<"i: "<<i<<endl;
//    cout<<"OP[]\n nu:"<<numUsed<<endl;
//    if(i >= numUsed){

//        cout<<"case 1"<<endl;
//        return fail;
//    }
//    else{
//        cout<<"case 2"<<endl;
//        return i;
//    }

}//int
