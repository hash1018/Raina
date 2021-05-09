
#ifndef _SOURCE_H
#define _SOURCE_H

#include <qstring.h>

class Source {

private:
    QString name;

    //temp
    static int number;

public:
    Source(const QString &name);
	~Source();


public:
    inline const QString& getName() const {return this->name;}

};

#endif //_SOURCE_H
