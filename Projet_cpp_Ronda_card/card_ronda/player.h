#ifndef PLAYER_H
#define PLAYER_H
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
class player
{
public:
    player();
    int play_Set_Card(QWidget *frameCenterWidget, QPushButton *button , QString name );
    int play_Set_Card_star();

};

#endif // PLAYER_H
