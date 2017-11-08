#include "base58checktranscoder.h"

#include "base58.h"

QByteArray Base58CheckTranscoder::encodeBase58Check(const QByteArray &input)
{
    std::vector<unsigned char> vec;
    vec.reserve(input.size());
    for(int i = 0; i < input.size(); ++i)
        vec.push_back(static_cast<unsigned char>(input.at(i)));
    std::string retStdString = EncodeBase58Check(vec);
    QByteArray ret(retStdString.c_str(), retStdString.length());
    return ret;
}
bool Base58CheckTranscoder::decodeBase58Check(const QByteArray &encodedInput, QByteArray &decodedOutput)
{
    std::vector<unsigned char> temp;
    bool ret = DecodeBase58Check(encodedInput.constData(), temp);
    decodedOutput.reserve(temp.size());
    for(size_t i = 0; i < temp.size(); ++i)
        decodedOutput.append(temp.at(i));
    return ret;
}
