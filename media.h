#ifndef MEDIA_H
#define MEDIA_H

class QString;

/*
  ARTHUR 27/11 : Création sur base du travail de Paul
 */


/**
 * @brief The Media class.
 */
class Media {
private:
    int id;
    QString * title;
    QString * synopsis;
    QString * date;

public:

    Media(const int id, const QString title, const QString synopsis, const QString date);

    QString getDate() const;

    QString getSynopsis() const;

    QString getTitle() const;

    int getId() const;
};

#endif // MEDIA_H
