// main.cpp

#include <QApplication>
#include "mainwindow.h"
#include "createframe.h"
#include "random.h" // Include the header file where Random is defined
#include <QRandomGenerator>
#include <QStringList>
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    CreateFrame createFrame(&w);

    // Create frames
    createFrame.createFrame("cardUser1", "rightButtom", 90, 130, "");
    createFrame.createFrame("cardUser2", "rightTop", 90, 130, "");
    createFrame.createFrame("frameTop", "top", 500, 150, ":/new/image/picturs/00.gif");
    createFrame.createFrame("frameCenter", "center", 700, 300, ":/new/image/picturs/00.gif");
    createFrame.createFrame("frameBottom", "bottom", 500, 150, ":/new/image/picturs/00.gif");
    createFrame.createFrame("frameCard", "leftTop", 120, 150, "");
    createFrame.createFrame("winer", "final", 800, 600, "");
    createFrame.createFrame("choice", "beginning", 900, 750, "");
    createFrame.choice_level();
    w.findChild<QWidget*>("winer")->hide();
    w.findChild<QWidget*>("cardUser1")->hide();
    w.findChild<QWidget*>("cardUser2")->hide();

    // Style for frame frameCard
    w.findChild<QWidget*>("frameCard")->setStyleSheet("background-image: url(:/new/image/picturs/BGTopButtom.jpg);"
                                                       "background-repeat: no-repeat;"
                                                       "background-position: center;"
                                                       "background-size: cover;"
                                                       "border-radius: 10px;");

    // Create card center
    createFrame.Function_Set_4_Card_1_time(w.findChild<QWidget*>("frameCenter"));

    // Call the createButtonInFrameCard function directly for frame top
    createFrame.createButtonInFrameCard(w.findChild<QWidget*>("frameBottom"), w.findChild<QWidget*>("frameTop"));

    w.showFullScreen();
    return a.exec();
}
