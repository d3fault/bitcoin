#include <QCoreApplication>

#include <QTextStream>

#include "base58checktranscoder.h"

#define STDIN_READ_BUFFERSIZE 4096

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    bool encode = true;
    QStringList argz = a.arguments();
    if(argz.contains("-d") || argz.contains("--decode"))
        encode = false;

    QTextStream stdIn(stdin);
    QTextStream stdOut(stdout);
    QByteArray input;
    while(!stdIn.atEnd())
        input.append(stdIn.read(STDIN_READ_BUFFERSIZE));

    if(encode)
    {
        //encode
        QByteArray output = Base58CheckTranscoder::encodeBase58Check(input);
        stdOut << output << endl;
    }
    else
    {
        //decode
        QByteArray decoded;
        if(Base58CheckTranscoder::decodeBase58Check(input, decoded))
            stdOut << decoded << endl;
        else
        {
            QTextStream stdErr(stderr);
            stdErr << "ERROR: decode check failed" << endl;
            return 1;
        }
    }

    return 0;
}
