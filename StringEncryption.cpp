//
// Created by 毛华伟 on 2020/2/22.
//

#include "StringEncryption.h"



StringEncryption::StringEncryption()
{
    initKv();
}

void StringEncryption::initKv()
{
    memset(key, 0x00, CryptoPP::AES::DEFAULT_KEYLENGTH);
    memset(iv, 0x00, CryptoPP::AES::BLOCKSIZE);

    // 或者也可以

    //char tmpK[] = "1234567890123456";
    //char tmpIV[] = "1234567890123456";
    //for (int j = 0; j < CryptoPP::AES::DEFAULT_KEYLENGTH; ++j)
    //{
    //	key[j] = tmpK[j];
    //}
    //for (int i = 0; i < CryptoPP::AES::BLOCKSIZE; ++i)
    //{
    //	iv[i] = tmpIV[i];
    //}
}

std::string StringEncryption::encrypt(std::string plainText)
{
    std::string cipherText;

    CryptoPP::AES::Encryption aesEncryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption(aesEncryption, iv);
    CryptoPP::StreamTransformationFilter stfEncryptor(cbcEncryption, new CryptoPP::StringSink(cipherText));
    stfEncryptor.Put(reinterpret_cast<const unsigned char*>(plainText.c_str()), plainText.length() + 1);
    stfEncryptor.MessageEnd();

    std::string cipherTextHex;
    for (int i = 0; i < cipherText.size(); i++)
    {
        char ch[3] = { 0 };
        sprintf(ch, "%02x", static_cast<unsigned char>(cipherText[i]));
        cipherTextHex += ch;
    }
    return cipherTextHex;
}

std::string StringEncryption::decrypt(std::string cipherTextHex)
{
    std::string cipherText;
    std::string decryptedText;
    int i = 0;

    while (true)
    {
        char c;
        int x;
        std::stringstream ss;
        ss << std::hex << cipherTextHex.substr(i, 2).c_str();
        ss >> x;
        c = (char)x;
        cipherText += c;
        if (i >= cipherTextHex.length() - 2)break;
        i += 2;
    }
    CryptoPP::AES::Decryption aesDecryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Decryption cbcDecryption(aesDecryption, iv);
    CryptoPP::StreamTransformationFilter stfDecryptor(cbcDecryption, new CryptoPP::StringSink(decryptedText));
    stfDecryptor.Put(reinterpret_cast<const unsigned char*>(cipherText.c_str()), cipherText.size());

    stfDecryptor.MessageEnd();

    return decryptedText;
}