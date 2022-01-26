#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int T = inf.readInt(1,10000,"T");
    inf.readEoln();
    while(T--){
        inf.readInt(1,10,"x");
        inf.readSpace();
        inf.readInt(1,10,"y");
        inf.readSpace();
        inf.readInt(1,10000,"h");
        inf.readSpace();
        inf.readInt(1,100000,"d");
        inf.readEoln();
    }
    inf.readEof();
}
