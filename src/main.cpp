#include <string>
#include "input_handler.h"
using namespace std;

int main(int argc, char* argv[]){
    string filename(argv[1]);
    handleInput(filename);
    return 0;
}