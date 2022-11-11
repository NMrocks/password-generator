#ifndef CUSTOMLBL_H
#define CUSTOMLBL_H

#include <QLabel>

class CustomLbl: public QLabel
{
    Q_OBJECT

    public slots:
    void setInt(int n);
};

#endif
