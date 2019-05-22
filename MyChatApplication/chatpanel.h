#ifndef CHATPANEL_H
#define CHATPANEL_H

#include <QDialog>
#include <QUdpSocket>
#include <QtCore>


namespace Ui {
class ChatPanel;
}

class ChatPanel : public QDialog
{
    Q_OBJECT

public:
    explicit ChatPanel(QWidget *parent = 0);
    ~ChatPanel();


private slots:
    void on_chatField_returnPressed();

    void on_connectButton_clicked();

    void on_disconnectButton_clicked();

    void readPendingDatagram () ;

    void on_sendButton_clicked();

private:
    Ui::ChatPanel *ui;
    QUdpSocket *socket ;
    quint16 srcPort,destinationPort;
    QString srcIP,destinationIP ;

};

#endif // CHATPANEL_H
