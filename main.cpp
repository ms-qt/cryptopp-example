#include <iostream>
#include <string>
#include "StringEncryption.h"

int main()
{
    StringEncryption se;
    std::string encode = se.encrypt("hahha");
    std::string decode = se.decrypt(encode);
    std::cout << "encode : "<<encode << std::endl;
    std::cout << "decode : "<<decode << std::endl;
    return 0;
}
