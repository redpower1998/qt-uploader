
```
/**
 * Qt Uploader 上传文件类
 * 可以上传多个文件
 */


#include "QHttpUploader.h"
#include <QCoreApplication>
int main(int argc,char *argv[]){
        QCoreApplication a(argc,argv);

        /*初始化上传地址*/
        QHttpUploader er("http://127.0.0.1/upload.php");
        /*也可以这里设置*/
        //er.setUrl("http://127.0.0.1/upload.php");

        /*增加参数*/
        er.addItem("NAME","VALUE");

        /*增加文件1*/
        QFile *f = new QFile("test.txt");
        er.addFile(f);

        /*增加文件2*/
        QFile f2("test.png");
        er.addFile(f2);
        /*增加文件3*/
        er.addFile("test2.png");

        /*上传*/
        er.upload();
        /**
         * 这个类有3个信号,started,finished,error
         */
        return a.exec();
}
```