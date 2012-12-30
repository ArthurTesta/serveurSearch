#ifndef MEDIALIST_H
#define MEDIALIST_H

#include <QList>
#include "media.h"
/*
  ARTHUR 27/11 : Création sur base du travail de Paul
 */
class QSqlDatabase;


class MediaList {
private:
    QList<Media> * mediaList;
    QSqlDatabase * db;

    bool createConnection();

    void closeConnection();

    void buildList();

public:

    MediaList();

    QList<Media> getMediaList() const;

    void refreshList();
    QList <Media> * getMediaAlike(QString mediaName);
    void AddMovie(QString title, QString synopsis, QString date);
    bool isMovieInDB(QString title);
    void qDebugAll();
};

#endif // MEDIALIST_H
