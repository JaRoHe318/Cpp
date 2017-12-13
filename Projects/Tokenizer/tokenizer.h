#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "consts.h"
#include "jtoken.h"
#include "double.h"
#include "integer.h"
#include "funct.h"
#include "op.h"

class Tokenizer{
public:
    Tokenizer();
    void getEquation();
private:
    JQueue<JToken*> preFix;
    char _chunks[100];
    void Process(string &chunks);
    void setType(string chunk);
};

#endif // TOKENIZER_H
