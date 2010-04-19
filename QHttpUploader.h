/**
 * QUploader �ϴ��ļ���
 * author: hetal 
 * email : hetao at hetao.name
 * date  : 2010-4-14
 */

#include <QObject>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QDebug>
#include <QFile>
#include <QNetworkReply>

class QHttpUploader:public QObject
{
	Q_OBJECT
private:
	QUrl _url;
	QString _boundary;
	QByteArray _data;
	QNetworkAccessManager _manager;
public:
	/**
	 * @param QString �ϴ���ַ
	 */
	QHttpUploader(QString);
	/**
	 * @param QUrl �ϴ���ַ
	 */
	QHttpUploader(QUrl);
	QHttpUploader();
	/**
	 * �����ϴ���ַ
	 * @param QString 
	 */
	void setUrl(QString);
	/**
	 * �����ϴ���ַ
	 * @param QUrl 
	 */
	void setUrl(QUrl);
	/**
	 * ����cookie
	 * @param QNetworkCookieJar *
	 */
	void setCookie(QNetworkCookieJar *){};
	/**
	 * ���Ӳ���
	 */
	void addItem (const QString key, const QString value );
	void addEncodedItem (const QByteArray key,const  QByteArray value );
	/*�����ļ�*/
	void addFile(QFile *);
	void addFile(QFile &);
	void addFile(QString &);
	void addFile(char*);
	/*�ϴ�*/
	void upload();

private slots:
	void	_postFinished ( QNetworkReply * reply );
signals:
	/*�ϴ���ʼ*/
	void started();
	/**
	 *�ϴ����
	 *��Ӧ��QNetworkReply::deleteLater() 
	 **/
	void finished(QNetworkReply*);
	/*�ϴ�ʧ��*/
	void error(QNetworkReply::NetworkError);

};