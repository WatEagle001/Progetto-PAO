#include "view.h"

void view::closeEvent(QCloseEvent *event)
{
    event->accept();
    emit viewClosed();
}

view::view(const QSize &s, view *parent) : QWidget(parent, Qt::Window)
{
    // Da rivedere le dimensioni
    if(!s.isNull() && !s.isEmpty()){
        setSize(s);
    }
    else{
        setSize(QSize(500,500));
    }


}

view::~view()
{
    setParent(nullptr);
};




void view::setSize(const QSize &s)
{
    resize(s);
}

void view::setTitle(const QString &title)
{
    setWindowTitle(title);
}

bool view::dialogPopUp_Question(unsigned int param, const QString &title, const QString &desc)
{
    QMessageBox::StandardButton resBtn = QMessageBox::Yes;
        switch (param)
        {
            case 2:
                resBtn = QMessageBox::question( this,title,desc,QMessageBox::No | QMessageBox::Yes | QMessageBox::Yes);
                break;

            default:
                resBtn = QMessageBox::question( this,title,desc,QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes | QMessageBox::Yes);
                break;
        }

        return (resBtn == QMessageBox::Yes);
}

void view::dialogPopUp_Warning(const QString &title, const QString &desc)
{
    QMessageBox::warning(this, title, desc, QMessageBox::Ok);
}

void view::dialogPopUp_Information(const QString &title, const QString &desc)
{
    QMessageBox::information(this, title, desc, QMessageBox::Ok);
}

void view::dialogPopUp_FatalError(const QString &title, const QString &desc)
{
    QMessageBox::critical(this, title, desc, QMessageBox::Ok);
}
