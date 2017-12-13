#include "tokenizer.h"

Tokenizer::Tokenizer(){
}

void Tokenizer::getEquation(){
    char ans;
    string equation;
    cout<<"Enter funct:";

    std::getline(cin,equation);

    Process(equation);
}

void Tokenizer::Process(string &chunks){

    JQueue<string> holder;
    int spacePos =chunks.find(" ");
    int pos = 0;

    while(pos!= chunks.length()){
        cout<<"i";
        holder.Push(chunks.substr(pos, spacePos - pos));
        pos=spacePos+1;
        spacePos=chunks.find(" ",pos);
    }

    while(!holder.isEmpty()){
        setType(holder.Pop());
    }
}

void Tokenizer::setType(string chunk){
    cout<<"|"<<chunk<<"|";

    if(!chunk.compare("+")){
        preFix.Push(new Op(chunk));
    }
    else if(!chunk.compare("-")){
        preFix.Push(new Op(chunk));
    }
    else if(!chunk.compare("/")){
        preFix.Push(new Op(chunk));
    }
    else if(!chunk.compare("*")){

        preFix.Push(new Op(chunk));
    }
    else if(!chunk.compare("^")){

        preFix.Push(new Op(chunk));
    }
    else if(!chunk.compare(")")){

        preFix.Push(new Op(chunk));
    }
    else if(!chunk.compare("(")){

        preFix.Push(new Op(chunk));
    }
    else if(!chunk.compare("sin")){
        preFix.Push(new Funct(chunk));
    }
    else if(!chunk.compare("cos")){
        preFix.Push(new Funct(chunk));
    }
    else if(!chunk.compare("tan")){
        preFix.Push(new Funct(chunk));
    }
    else if(!chunk.compare("log")){
        preFix.Push(new Funct(chunk));
    }
    else if(!chunk.compare("~")){
        preFix.Push(new Funct(chunk));
    }
    else if(!chunk.compare("sqrt")){
        preFix.Push(new Funct(chunk));
    }
    else if(!chunk.compare("ln")){
        preFix.Push(new Funct(chunk));
    }
    else{
        preFix.Push(new Double(chunk));
    }

}

