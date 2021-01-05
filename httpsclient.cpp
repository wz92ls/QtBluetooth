#include "httpsclient.h"

HttpsClient::HttpsClient(QObject *parent) : QNetworkAccessManager(parent)
{
    qDebug() << this->supportedSchemes();
}

HttpsClient::~HttpsClient()
{
    if (myreply != NULL)
    {
        myreply->abort();
        myreply->deleteLater();
    }
}
QByteArray HttpsClient::execute(QString myurl,QByteArray mydata)
{
    QNetworkRequest request;
    request.setRawHeader("Content-Type", "application/x-www-form-urlencoded");
    request.setRawHeader("Host", "openbfapi.gongyitech.com");
    //    connect(this, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinished(QNetworkReply *)));
    QSslConfiguration config;
    QSslConfiguration conf = request.sslConfiguration();
    conf.setPeerVerifyMode(QSslSocket::VerifyNone);
    conf.setProtocol(QSsl::TlsV1_2);
    request.setSslConfiguration(conf);

    QUrl url(myurl);
    request.setUrl(url);
    myreply = this->post(request, mydata);//data数据可能是Json格式串

    QTimer timer;
    timer.setInterval(5000);
    timer.setSingleShot(true);
    timer.start();

    QEventLoop eventLoop;
    connect(myreply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
    eventLoop.exec(QEventLoop::ExcludeUserInputEvents);

    QByteArray replyData = myreply->readAll();
    myreply->deleteLater();
    myreply = nullptr;

    return replyData;

}

void HttpsClient::replyFinished(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    qDebug()<<bytes;
}
