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
    //FLAG{wher3_1s_m7_m1nd}
    QChar* input = value.data() ;
    int inputLength = value.length();
    QChar* key = mykey.data();
    int keyLength   = mykey.length();

    char output[inputLength];
    int serial;
    QString final = "";
    for (int i = 0; i < inputLength + 1; ++i)
    {
        output[i] = input[i].toAscii() ^ key[i % keyLength + 1].toAscii();
    }
    for(int i = 0; i < inputLength + 1; ++i)
    {
        serial = output[i];
        final += QString::number(serial);
    }

    if(final == "114761177179119921017051107497195895510710951108012552"){
        qDebug() << "Correct !!";
    }else{
        qDebug() << "Try Harder !";
    }

    return 0;
}
