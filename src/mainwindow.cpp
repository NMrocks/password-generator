#include <QFormLayout>
#include <QFont>
#include <QHBoxLayout>
#include <QSizePolicy>
#include <qnamespace.h>
#include <qpushbutton.h>

#include "mainwindow.h"
#include "customLbl.h"
#include "generate.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *base             = new QWidget;
    QFormLayout *layout       = new QFormLayout;
    CustomLbl *lengthLbl      = new CustomLbl;
    QHBoxLayout *lengthLayout = new QHBoxLayout;

    passwordLbl = new QLabel;
    lengthSldr  = new QSlider;
    charSetBox  = new QComboBox;
    regenBtn    = new QPushButton;
    QFont passwordFont("monospace", 16);
    
    passwordLbl->setFont(passwordFont);
    passwordLbl->setTextInteractionFlags(Qt::TextSelectableByMouse);
    passwordLbl->setCursor(Qt::IBeamCursor);
    passwordLbl->setWordWrap(true);
    passwordLbl->setAlignment(Qt::AlignCenter);
    lengthSldr ->setRange(8, 128);
    lengthSldr ->setTracking(true);
    lengthSldr ->setOrientation(Qt::Horizontal);
    lengthSldr ->setPageStep(10);
    lengthSldr ->setSliderPosition(32);
    lengthLbl  ->setInt(32);
    charSetBox ->addItems({"Alphabets", "Alphabets + Numbers", "Alphabets + Numbers + Symbols"});
    charSetBox ->setCurrentIndex(2);
    regenBtn   ->setText("Regenerate");
    
    connect(lengthSldr, &QAbstractSlider::valueChanged,   lengthLbl, &CustomLbl::setInt);
    connect(lengthSldr, &QAbstractSlider::sliderReleased, this,      &MainWindow::regenPasswd);
    connect(charSetBox, &QComboBox::currentIndexChanged,  this,      &MainWindow::regenPasswd);
    connect(regenBtn,   &QPushButton::clicked,            this,      &MainWindow::regenPasswd);

    lengthLayout->addWidget(lengthSldr);
    lengthLayout->addWidget(lengthLbl);
    layout->addRow(passwordLbl);
    layout->addRow("Length:", lengthLayout);
    layout->addRow("Characters:", charSetBox);
    layout->addRow(regenBtn);

    base->setLayout(layout);
    setCentralWidget(base);
    regenPasswd();
    setWindowTitle("Password Generator");
}

MainWindow::~MainWindow()
{
}

void MainWindow::regenPasswd()
{
    passwordLbl->setText(generatePassword(charSetBox->currentText(), lengthSldr->value()));
}
