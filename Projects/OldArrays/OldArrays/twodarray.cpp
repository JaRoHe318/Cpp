#include "twodarray.h"

TwoDArray::TwoDArray(){
}
TwoDArray::TwoDArray(int td[][COL],int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            TwoD[i][j]=td[i][j];
        }//for2
    }//for


}
int TwoDArray::Append(int AppendMe,int row){
    for(int i=0;i<5;i++){
        TwoD[row][i]=c[i];
    }
    return row;
}

int TwoDArray::Insert(int InsertMe,int row,int col){
    //    c[row].InsertB(InsertMe,col);
    return col;
}

int TwoDArray::Delete(int row,int col){
//    c[row].Delete(col);
    return col;
}

void TwoDArray::Print(int row, int col){
    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
            if((i==row)&&(j==col)){
                cout<<"["<<TwoD[i][j]<<"] ";
            }
            else{
                cout<<" "<<TwoD[i][j]<<"  ";
            }
        }//for2
        cout<<endl;
    }
}



//ostream& operator <<(ostream& out, const TwoDArray& td){
//    cout<<"OSTREAM\n :"<<td.TwoD<<endl;
//    for(int i=0;i<4;i++){
//        for(int j=0;i<td.c[i].NumUsing();){
//            out<<td.TwoD[i][j]<<" ";

//        }
//    }//for

//}
