#include "jtoken.h"


JToken::JToken(){
}

ostream& operator <<(ostream& outs, const JToken& token){
    token.Print(outs);
    return outs;
}

void JToken::Print(ostream &outs) const{
     outs<<"TOKEN: DON't ^%#$# call me again!"<<endl;
    //Blank
}
