#include "player.h"
#include "createframe.h"
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <iostream>
#include <cstring>

// Constructor for the player class
player::player() {}

// Function to handle playing a card in the game
int player::play_Set_Card(QWidget *frameCenterWidget, QPushButton *button, QString name) {
    int number_card_checked = 0;

    // Check if the frameCenterWidget is valid
    if (frameCenterWidget) {
        // Find all child widgets of frameCenterWidget
        QList<QWidget*> childWidgets = frameCenterWidget->findChildren<QWidget*>();

        // Extract the number from the button's objectName
        QString buttonName = button->objectName();
        QString number_card_gamer = buttonName.mid(1, 1);
        QWidget *parentWidget = button->parentWidget();

        // Iterate through the list of child widgets
        bool add = true;
        for (QWidget *childWidget : childWidgets) {
            // Extract the number from the child widget's objectName
            QString widgetName = childWidget->objectName();
            QString number_card_in_tabel = widgetName.mid(1, 1);

            // Compare numbers and perform actions accordingly
            if (number_card_gamer.compare(number_card_in_tabel) == 0) {
                // Delete the existing cards with the same number
                childWidget->deleteLater();
                parentWidget->deleteLater();
                number_card_checked = 2;
                add = false;
                break;
            }
        }

        // If no card with the same number is found, add a new card
        if (add) {
            parentWidget->deleteLater();
            QWidget *childWidget = new QWidget(parentWidget);
            childWidget->setFixedSize(90, 130);
            childWidget->setObjectName(name);
            childWidget->setStyleSheet(
                "background-image: url(:/new/image/picturs/" + name + ".gif);"
                                                                      "background-repeat: no-repeat;"
                                                                      "background-position: center;"
                                                                      "background-size: cover;"
                                                                      "border: none;"
                                                                      "border-radius: 0px;");

            // Find the QHBoxLayout within frameCenter
            QHBoxLayout *centerLayout = frameCenterWidget->findChild<QHBoxLayout*>("QHBoxLayoutCenter");
            centerLayout->addWidget(childWidget);
        }

    } else {
        qDebug() << "Widget with name 'frameCenter' not found.";
    }
    return number_card_checked;
}

// Function to handle playing a card with a star (to be developed in v2)
int player::play_Set_Card_star() {
    // To be developed in v2
    return 0;
}
