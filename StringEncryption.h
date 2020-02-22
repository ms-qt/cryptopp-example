//
// Created by 毛华伟 on 2020/2/22.
//

#ifndef CRYPTOPP_EXAMPLE_STRINGENCRYPTION_H
#define CRYPTOPP_EXAMPLE_STRINGENCRYPTION_H


#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cryptopp/pch.h>
#include <cryptopp/aes.h>
#include <cryptopp/filters.h>
#include <cryptopp/modes.h>
#include <cryptopp/config.h>

class StringEncryption
{
public:
    StringEncryption();
    std::string encrypt(std::string str);
    std::string decrypt(std::string str);

private:
    unsigned char key[CryptoPP::AES::DEFAULT_KEYLENGTH], iv[CryptoPP::AES::BLOCKSIZE];
    void initKv();
};


#endif //CRYPTOPP_EXAMPLE_STRINGENCRYPTION_H
