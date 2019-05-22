#include "chatpanel.h"
#include "ui_chatpanel.h"

ChatPanel::ChatPanel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChatPanel)
{
    ui->setupUi(this);
    socket = new QUdpSocket (this);
}

ChatPanel::~ChatPanel()
{
    delete ui;
}


void ChatPanel::on_chatField_returnPressed()
{
    bool x = ui->chatField->text().isEmpty();
    if(!x) {
        QString MessageString = this->ui->userName->text() + " : " + ui->chatField->text();
        destinationPort = this->ui->destPort->text().toUShort();
        destinationIP =this->ui->destIP->text();
        const QByteArray message = MessageString.toUtf8();
        socket->writeDatagram(message,QHostAddress(destinationIP),destinationPort);
        this->ui->chatField->clear();
        this->ui->chat->append(MessageString+"\n");
    }

}

void ChatPanel::on_connectButton_clicked()
{
    srcPort =this-> ui->sourcePort->text().toUShort();
    srcIP = this->ui->sourceIP->text();
    socket->bind(QHostAddress(srcIP),srcPort);
    connect(socket, SIGNAL(readyRead()),this, SLOT(readPendingDatagram()));
}

void ChatPanel::on_disconnectButton_clicked()
{

}

void ChatPanel::readPendingDatagram(){
    while (socket->hasPendingDatagrams()) {
            QByteArray datagram;
            datagram.resize(socket->pendingDatagramSize());
            QHostAddress ipAd;
            quint16 Port ;
            socket->readDatagram(datagram.data(), datagram.size(), &ipAd, &Port);
            QString ss = datagram.data();
            this->ui->chat->append(ss + "\n");
    }
}

void ChatPanel::on_sendButton_clicked()
{
        QString MessageString = this->ui->userName->text() + " : " + ui->chatField->text();
        destinationPort = this->ui->destPort->text().toUShort();
        destinationIP = this->ui->destIP->text();
        const QByteArray message = MessageString.toUtf8();
        socket->writeDatagram(message,QHostAddress(destinationIP),destinationPort);
        this->ui->chatField->clear();
        this->ui->chat->append(MessageString+"\n");

}
