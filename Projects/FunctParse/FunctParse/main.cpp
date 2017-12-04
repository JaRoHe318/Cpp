
// declarations
#include <cstdlib>
#include <cstdio>

#include "parser.h"

using namespace std;
#include <iostream>

int main(int argc, char *argv[]){
    char expr[255];

    // create a parser object
    Parser prs;

//    puts("Enter an expression an press Enter to calculate the result.");
    cout<<"\nEnter an expression an press Enter to calculate the result.";
//    puts("Enter an empty expression to quit.");
    cout<<"\nEnter an empty expression to quit.";
    puts("");

    do{
        // request an expression

        cout<<"> ";
//        gets(expr);
        cin>>expr;

        if (strcmp(expr, "") != 0){
            try{
                // evaluate the expression
                char* result;
                result = prs.parse(expr);
                printf("\t%s\n", result);
            }
            catch (...){
                printf("\tError: Unknown error occured in parser\n");
            }
        }
    } while (strcmp(expr, "") != 0);

    return EXIT_SUCCESS;
}
