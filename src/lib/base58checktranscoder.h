#ifndef BASE58CHECKTRANSCODER_H
#define BASE58CHECKTRANSCODER_H

#include <QByteArray>

class Base58CheckTranscoder
{
public:
    Base58CheckTranscoder();
    static QByteArray encodeBase58Check(const QByteArray &input);
    static bool decodeBase58Check(const QByteArray &encodedInput, QByteArray &decodedOutput);
};

#endif // BASE58CHECKTRANSCODER_H
