#include <iostream>

using namespace std;
#include "jtoken.h"
#include "double.h"
#include "integer.h"
#include "funct.h"
#include "op.h"
#include "tokenizer.h"

int main(){
    cout << "Tokenizer!" << endl;
    Tokenizer getToken;
    getToken.getEquation();
    return 0;
}
