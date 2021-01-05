#ifndef HTTPSCLIENT_H
#define HTTPSCLIENT_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QEventLoop>
#include <QTimer>
class HttpsClient : public QNetworkAccessManager
{
    Q_OBJECT
public:
    explicit HttpsClient(QObject *parent = nullptr);
    QByteArray execute(QString myurl,QByteArray mydata);
    ~HttpsClient();
signals:
private:
    QNetworkReply* myreply;
private slots:
    void replyFinished(QNetworkReply *reply);

};

#endif // HTTPSCLIENT_H
