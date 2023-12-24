#ifndef CREATEFRAME_H
#define CREATEFRAME_H

#include <QWidget>
#include <QString>

class CreateFrame : public QWidget
{
    Q_OBJECT

public:
    CreateFrame(QWidget *parent = nullptr);
    void createFrame(QString name, QString position, int width, int h, QString imagePath = "");
    void createChildWidget(QWidget *parent, QString name, QString showOrHidecard);
    void createChildWidgetCenter(QWidget *parent, QString name);
    QStringList createButtonInFrameCard(QWidget* parent, QWidget *parent2) ;
    QStringList Function_Set_Card(QWidget* parent,QString showOrHidecard);
    QStringList createTableau();
    QStringList Function_Set_4_Card_1_time(QWidget* parent);
    void addCenteredWidget(QWidget *parent, QWidget *widgetToAdd);
    void Function_Set_1_Card(QWidget* parent ,QString name);
    void create_1_Widget(QWidget *parent, QString name);
    QStringList tableaCardCenter();
    void affiche();
    void choice_level();








signals:
    void frameCardClicked();

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    QWidget *parentWidget;
    // You can keep other private members or methods here
};



#endif // CREATEFRAME_H
