#include "createframe.h"
#include "random.h"
#include "player.h"
#include <QScreen>
#include <QApplication>
#include <QRect>
#include <QDebug>
#include <QVBoxLayout>
#include <QMargins>
#include <QMouseEvent>
#include <QPushButton>
#include <QRandomGenerator>
#include <QTime>
#include<QLabel>
using namespace std;

player player;



CreateFrame::CreateFrame(QWidget *parent) : parentWidget(parent),QWidget(parent)
{

    // Constructor implementation, if needed
}
random random;


// Create a QStringList with values from 00 to 39
QStringList createTableau()
{
    QStringList tableau;

    // Fill the QStringList with values
    for (int i = 0; i <= 39; ++i)
    {
        // Convert integer to a two-digit string, e.g., "01"
        QString number = QString::number(i, 10).rightJustified(2, '0');
        tableau.append(number);
    }
    return tableau;
}

// Function to handle choice level in the game
void CreateFrame::choice_level()
{
    int x = 0;
    int y = 0;

    // Assuming parentWidget is a valid pointer to the parent widget
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect desktopRect = screen->geometry();

    // Find the child widget with the name "choice" in the parent widget
    QWidget *choiceframe = parentWidget->findChild<QWidget *>("choice");
    choiceframe->setStyleSheet("background-color:green ;");

    // Center the choiceframe on the desktop
    x = desktopRect.width() / 2 - choiceframe->width() / 2;
    y = desktopRect.height() / 2 - choiceframe->height() / 2;

    choiceframe->setGeometry(x, y, choiceframe->width(), choiceframe->height());

    // Create a QVBoxLayout for the choiceframe
    QVBoxLayout *layout = new QVBoxLayout(choiceframe);

    // Create a base widget
    QWidget *widgetBase = new QWidget(choiceframe);
    widgetBase->setFixedSize(150, 70);
    widgetBase->setObjectName("Base");
    widgetBase->setStyleSheet("background-color:#223127;");

    // Create a button for the base widget
    QPushButton *buttonBase = new QPushButton("Base", widgetBase);
    buttonBase->setObjectName("buttonBase");
    buttonBase->setStyleSheet("background-color: transparent;");

    // Connect the base button click signal to hide the choiceframe
    connect(buttonBase, &QPushButton::clicked, [=]() {
        choiceframe->hide();
    });

    // Create a star widget
    QWidget *widgetStar = new QWidget(choiceframe);
    widgetStar->setFixedSize(150, 70);
    widgetStar->setObjectName("Star");
    widgetStar->setStyleSheet("background-color:#223127;");

    // Create a button for the star widget
    QPushButton *buttonStar = new QPushButton("Star", widgetStar);
    buttonStar->setObjectName("buttonStar");
    buttonStar->setStyleSheet("background-color: transparent;");

    // Connect the star button click signal to hide the choiceframe and call play_Set_Card_star
    connect(buttonStar, &QPushButton::clicked, [=]() {
        choiceframe->hide();
        player.play_Set_Card_star();
    });

    // Set the geometries for the buttons
    buttonBase->setGeometry(0, 0, 150, 70);
    buttonStar->setGeometry(0, 0, 150, 70);

    // Add widgets to the layout with some spacing
    layout->addWidget(widgetBase, 0, Qt::AlignHCenter);
    layout->addSpacing(5); // Add spacing between widgets
    layout->addWidget(widgetStar, 0, Qt::AlignHCenter);

    // Set the layout for the choiceframe
    choiceframe->setLayout(layout);
}


// Function to create a custom frame with specified properties
// Parameters:
//   name: Object name of the frame
//   position: Position of the frame ("center", "bottom", "top", "leftTop", "rightTop", "rightButtom", "final")
//   width: Width of the frame
//   h: Height of the frame
//   imagePath: Path to the background image for the frame
void CreateFrame::createFrame(QString name, QString position, int width, int h, QString imagePath)
{
    // Define the basic style for the frame
    QString style = "border: 2px solid black;""border-radius: 10px;";

    // Create a new QWidget with the specified parentWidget
    QWidget *frame = new QWidget(parentWidget);
    frame->setObjectName(name);
    frame->setStyleSheet(style);

    // Set the fixed size for the frame
    frame->setFixedSize(width, h);

    // Set background image for the frame
    QPixmap backgroundImage(imagePath);
    QPalette palette;
    palette.setBrush(QPalette::Window, backgroundImage);
    frame->setPalette(palette);
    frame->setAutoFillBackground(true);

    // Find the existing widget with the specified object name
    QWidget *foundWidget = parentWidget->findChild<QWidget *>(name);

    if (foundWidget) {
        QScreen *screen = QGuiApplication::primaryScreen();
        QRect desktopRect = screen->geometry();

        int x = 0;
        int y = 0;

        // Set position and background image based on the specified position
        if (position == "center") {
            x = desktopRect.width() / 2 - foundWidget->width() / 2;
            y = desktopRect.height() / 2 - foundWidget->height() / 2;
            frame->setStyleSheet(style + "background-image: url(:/new/image/picturs/BGCenter.jpg);");

        } else if (position == "bottom") {
            x = desktopRect.width() / 2 - foundWidget->width() / 2;
            y = desktopRect.height() - h - 30;
            frame->setStyleSheet(style + "background-image: url(:/new/image/picturs/BGTopButtom.jpg);");

        } else if (position == "top") {
            x = desktopRect.width() / 2 - foundWidget->width() / 2;
            y = 30;
            frame->setStyleSheet(style + "background-image: url(:/new/image/picturs/BGTopButtom.jpg);");

        } else if (position == "leftTop") {
            x = 30;
            y = 30;

        } else if (position == "rightTop") {
            frame->setStyleSheet(style + "background-image: url(:/new/image/picturs/back.gif);");
            x = 1150;
            y = 30;
        } else if (position == "rightButtom") {
            frame->setStyleSheet(style + "background-image: url(:/new/image/picturs/back.gif);");
            x = 1150;
            y = 530;
        } else if (position == "final") {
            x = desktopRect.width() / 2 - foundWidget->width() / 2;
            y = desktopRect.height() - h - 30;

        }

        // Move the foundWidget to the specified position
        foundWidget->move(x, y);
    } else {
        qDebug() << "Widget with object name '" << name << "' not found";
    }
}
// ...
void CreateFrame::create_1_Widget(QWidget *parent, QString name)
{QWidget *childWidget = new QWidget(parent);

    childWidget->setObjectName(name);
    childWidget->setFixedSize(90, 130);
    childWidget->setStyleSheet("background-image: url(:/new/image/picturs/"+name+".gif);"
                                                                                     "background-repeat: no-repeat;"
                                                                                     "background-position: center;"
                                                                                     "background-size: cover;"
                                                                                     "border: none;"
                                                                                     "border-radius: 0px;");
}


QStringList tableau = createTableau();

QStringList CreateFrame::Function_Set_Card(QWidget* parent,QString showOrHidecard){
    QStringList tableaCardTopOrButtom;

    int size=tableau.length();
    qDebug()<<size;
    for(int i=0;i<4;i++){
        //do random from tableau
        QString name=random.getRandomString(tableau);
        // remove the item random
        tableau.removeOne(name);
        tableaCardTopOrButtom.append(name);
        createChildWidget(parent, name,showOrHidecard);

    }
    qDebug()<<size;
    return tableaCardTopOrButtom;
}


QStringList CreateFrame::Function_Set_4_Card_1_time(QWidget* parent){
    QStringList tableaCardCenter;
    int size=tableau.length();
    qDebug()<<size;
    for(int i=0;i<4;i++){
        //do random from tableau
        QString name=random.getRandomString(tableau);
        // remove the item random
        tableau.removeOne(name);
        tableaCardCenter.append(name);
        createChildWidgetCenter(parent, name);

    }
    qDebug()<<size;
    return tableaCardCenter;

}

static int conteur_number_card_checked_user=0;
static int conteur_number_card_checked_Roboot=0;
void CreateFrame::createChildWidget(QWidget *parent, QString name, QString showOrHidecard)
{
    // Attempt to cast the parent widget's layout to QHBoxLayout
    QHBoxLayout *parentLayout = dynamic_cast<QHBoxLayout*>(parent->layout());

    if (!parentLayout) {
        // If the parent widget does not have a QHBoxLayout, create one
        parentLayout = new QHBoxLayout(parent);
        parentLayout->setObjectName("centerHBOX");
        parentLayout->setAlignment(Qt::AlignHCenter); // Align to the top and left
        parent->setLayout(parentLayout);
        qDebug() << "QHBoxLayout created.";
    }

    // Create a child widget with fixed size and set its properties based on showOrHidecard
    QWidget *childWidget = new QWidget(parent);
    childWidget->setFixedSize(90, 130);
    childWidget->setObjectName(name);

    if (showOrHidecard == "hide") {
        childWidget->setStyleSheet("background-image: url(:/new/image/picturs/back.gif);"
                                   "background-repeat: no-repeat;"
                                   "background-position: center;"
                                   "background-size: cover;"
                                   "border: none;"
                                   "border-radius: 0px;");
    } else {
        childWidget->setStyleSheet("background-image: url(:/new/image/picturs/" + name + ".gif);"
                                                                                         "background-repeat: no-repeat;"
                                                                                         "background-position: center;"
                                                                                         "background-size: cover;"
                                                                                         "border: none;"
                                                                                         "border-radius: 0px;");
    }

    // Create a QPushButton as a child of the childWidget
    QPushButton *button = new QPushButton(childWidget);
    button->setObjectName(name);
    button->setStyleSheet("background-repeat: no-repeat;"
                          "background-position: center;"
                          "background-size: cover;"
                          "border-radius: 0px;");

    // Connect the button's clicked signal to a lambda function
    QWidget *frameCenterWidget = parentWidget->findChild<QWidget*>("frameCenter");

    connect(button, &QPushButton::clicked, [=]() {
        // Handle button click event

        int number_card_checked_R = 0;
        int number_card_checked = player.play_Set_Card(frameCenterWidget, button, name);
        QWidget *frameTopWidget = parentWidget->findChild<QWidget*>("frameTop");
        QWidget *framecardUser1 = parentWidget->findChild<QWidget*>("cardUser1");
        QWidget *framecardUser2 = parentWidget->findChild<QWidget*>("cardUser2");

        if (number_card_checked != 0) {
            framecardUser1->show();
        }

        // Iterate through the cards in frameTopWidget and print their names
        QList<QPushButton*> listCard = frameTopWidget->findChildren<QPushButton*>();
        for (QPushButton *card : listCard) {
            qDebug() << "CARD NAME : " << card->objectName();
        }

        // Iterate through the cards and play a card if it's not the "delete" card
        for (QPushButton *card : listCard) {
            if (card->objectName().compare("delete") != 0) {
                number_card_checked_R = player.play_Set_Card(frameCenterWidget, card, card->objectName());
                break;
            }
        }

        if (number_card_checked_R != 0) {
            framecardUser2->show();
        }

        // Update counters and determine the winner
        conteur_number_card_checked_Roboot += number_card_checked_R;
        conteur_number_card_checked_user += number_card_checked;
        QString winner;

        if (tableau.length() == 4 && listCard.length() == 1) {
            qDebug() << "conteur_number_card_checked_user: " << conteur_number_card_checked_user;
            qDebug() << "conteur_number_card_checked_Roboot: " << conteur_number_card_checked_Roboot;

            if (conteur_number_card_checked_user > conteur_number_card_checked_Roboot) {
                winner = "Congratulations, you are the winner!";
                qDebug() << winner;
            } else if (conteur_number_card_checked_user < conteur_number_card_checked_Roboot) {
                winner = "unfortunately you lost ,Roboot is the winner!";
                qDebug() << winner;
            } else {
                winner = "It's a draw!";
                qDebug() << winner;
            }

            // Show the winner frame with a message and a close button
            QWidget *winerframe = parentWidget->findChild<QWidget*>("winer");

            winerframe->setStyleSheet("background-image: url(:/new/image/picturs/backWorL.jpg);"
                                      "border: 2px solid black;"
                                      "border-radius: 10px;");

            QLabel *label = new QLabel(winner);
            label->setStyleSheet("QLabel { color: red; font-size: 18px;""font-size: 24px;" "font-weight: bold;" "qproperty-alignment: AlignCenter;}");

            // Create a layout to arrange the label
            QVBoxLayout *layout = new QVBoxLayout(winerframe);
            layout->setAlignment(Qt::AlignCenter);  // Center the widget in the layout
            layout->addWidget(label);

            winerframe->setLayout(layout);
            QWidget *widgetclose = new QWidget(winerframe);
            widgetclose->setFixedSize(150, 70);
            widgetclose->setObjectName("Base");
            widgetclose->setStyleSheet("background-color: red;"
                                       "border-raduis:none;");

            // Create a button for the base widget
            QPushButton *CLOSEButton = new QPushButton("CLOSE", widgetclose);
            CLOSEButton->setObjectName("buttonBase");
            CLOSEButton->setStyleSheet("background-color: red;"
                                       "border-raduis:none;"
                                       "color:red;");
            QFont buttonFont("Arial", 12);
            CLOSEButton->setGeometry(0, 0, 150, 70);

            layout->addWidget(widgetclose, 0, Qt::AlignHCenter);

            winerframe->show();

            connect(CLOSEButton, &QPushButton::clicked, [=]() {
                // Close the entire application when the button is clicked
                QCoreApplication::quit();
                // or QApplication::quit();
            });
        }
    });

    // Set the button's geometry or size policy as needed
    button->setGeometry(0, 0, 90, 130);

    // Add the created widget to the QHBoxLayout
    parentLayout->addWidget(childWidget);
}


void CreateFrame::createChildWidgetCenter(QWidget *parent, QString name)
{
    // Attempt to cast the parent widget's layout to QHBoxLayout
    QHBoxLayout *parentLayout = dynamic_cast<QHBoxLayout*>(parent->layout());

    if (!parentLayout) {
        // If the parent widget does not have a QHBoxLayout, create one
        parentLayout = new QHBoxLayout(parent);
        parentLayout->setObjectName("QHBoxLayoutCenter");
        parentLayout->setAlignment(Qt::AlignHCenter); // Align to the top and left
        parent->setLayout(parentLayout);
        qDebug() << "QHBoxLayout created.";
    }

    // Create a child widget with fixed size and set its properties based on the provided name
    QWidget *childWidget = new QWidget(parent);
    childWidget->setObjectName(name);
    childWidget->setFixedSize(90, 130);
    childWidget->setStyleSheet("background-image: url(:/new/image/picturs/" + name + ".gif);"
                                                                                     "background-repeat: no-repeat;"
                                                                                     "background-position: center;"
                                                                                     "background-size: cover;"
                                                                                     "border: none;"
                                                                                     "border-radius: 0px;");

    // Add the created widget to the QHBoxLayout
    parentLayout->addWidget(childWidget);
}




QStringList CreateFrame::createButtonInFrameCard(QWidget* parent,QWidget *parent2)
{


    // Find the "frameCard" widget
    QWidget *frameCard = parentWidget->findChild<QWidget*>("frameCard");


    if (frameCard)
    {
        // Create a QPushButton
        QPushButton *button = new QPushButton("", frameCard);

        // Set object name for the button (optional)
        button->setObjectName("myButton");
        button->setStyleSheet("background-image: url(:/new/image/picturs/back.gif);"
                              "background-repeat: no-repeat;"
                              "background-position: center;"
                              "background-size: cover;"
                              "border-radius: 0px;");




        connect(button, &QPushButton::clicked, [=]() {
            qDebug() << "Button Clicked";
            QWidget *frameTopWidget = parentWidget->findChild<QWidget*>("frameTop");
            QList<QPushButton*> listCard = frameTopWidget->findChildren<QPushButton*>();

            if (listCard.length() == 0) {
                qDebug() << "listCard is empty";

                QStringList tableaCardTop=Function_Set_Card(parent,"show");
                QStringList tableaCardButtom=Function_Set_Card(parent2,"hide");
                QStringList total=tableaCardTop+tableaCardButtom;

                qDebug() << "total:" << total;
                qDebug() << "done";
            } else {
                qDebug() << "listCard is not empty";
            }
        });


        // You may want to set the button's geometry or size policy as needed
        button->setGeometry(14, 11, 90, 130);

    }
    else
    {
        qDebug() << "Widget with object name 'frameCard' not found";
    }
    return QStringList(); // or some default value
}



void CreateFrame::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        emit frameCardClicked();
    }

    // Call the base class implementation to ensure normal event processing
    QWidget::mousePressEvent(event);
}


