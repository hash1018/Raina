

#include "Source.h"

int Source::number = 0;

Source::Source(const QString& name)
    :name(name + QString::number(Source::number++)) {

}

Source::~Source() {


}
