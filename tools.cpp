#include "tools.h"
#include <QVariant>

bool Tools::isMovie(QFileInfo *f){
    if(f){
        return f->suffix() == QString("avi")
                || f->suffix() == QString("mkv");
    }
}
QString & Tools::convertCharStoQString(char * destTmp){
    QString * dest = new QString(QVariant(destTmp).toString());
    return (*dest);
}
