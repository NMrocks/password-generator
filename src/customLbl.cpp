#include <QLabel>
#include <QString>

#include "customLbl.h"

void CustomLbl::setInt(int n)
{
    this->setText(QString().setNum(n));
}