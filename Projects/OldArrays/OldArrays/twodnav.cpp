#include "twodnav.h"

TwoDNav::TwoDNav(){
    rowC=0;
    colC=0;
}

TwoDNav::TwoDNav(int t[][COLSS],int row,int col):TwoD(t,row,col){
    cout<<"CONS2DN";
}

int TwoDNav::Left(){
    colC--;
//    cout<<TwoD;
    return colC;
}

int TwoDNav::Right(){
    colC++;
//    cout<<TwoD;
    return colC;
}

int TwoDNav::Up(){
    rowC--;
//    cout<<TwoD;
    return rowC;
}

int TwoDNav::Dow(){
    rowC++;
//    cout<<TwoD;
    return rowC;
}

int TwoDNav::Insert(int InsertMe){
    TwoD.Insert(InsertMe,rowC,colC);
//    cout<<TwoD;
    return colC;
}

int TwoDNav::Append(int AppendMe){
    TwoD.Append(AppendMe,rowC);
//    cout<<TwoD;
    return colC;
}

int TwoDNav::Delete(){
    TwoD.Delete(rowC,colC);
//    cout<<TwoD;
    return colC;

}
void TwoDNav::Print(){
    TwoD.Print(rowC,colC);
}
