#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QSlider>
#include <QComboBox>

class MainWindow : public QMainWindow
{
        Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
    
    private:
        QLabel *passwordLbl;
        QSlider *lengthSldr;
        QComboBox *charSetBox;
        QPushButton *regenBtn;
    
    public slots:
        void regenPasswd();
};

#endif // MAINWINDOW_H
