#ifndef TOOLS_H
#define TOOLS_H

#include <QFileInfo>

class Tools
{
public:
    static bool isMovie(QFileInfo * f);
    static QString & convertCharStoQString(char * source);
};

#endif // TOOLS_H
