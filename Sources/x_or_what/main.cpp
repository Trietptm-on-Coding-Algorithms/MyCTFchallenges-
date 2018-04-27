#include <QCoreApplication>
#include "QTextStream"
#include "QDebug"
#include "QChar"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream s(stdin);

    QTextStream(stdout) << "Input The Flag : ";
    QString value = s.readLine();
    QString mykey = "44";
    //FLAG{where_is_my_mind}
    QChar* input = value.data() ;
    int inputLength = value.length();
    QChar* key = mykey.data();

    char output[inputLength];
    int serial;
    QString final = "";
    for (int i = 0; i < inputLength + 1; ++i)
    {
        output[i] = input[i].toAscii() ^ key[0].toAscii();
    }
    for(int i = 0; i < inputLength + 1; ++i)
    {
        serial = output[i];
        final += QString::number(serial) + " ";
    }
    qDebug() << final;
    if(final == "114 120 117 115 79 67 92 81 70 81 107 93 71 107 89 77 107 89 93 90 80 73 52 "){
        qDebug() << "Correct !!";
    }else{
        qDebug() << "Try Harder !";
    }

    return 0;
}
