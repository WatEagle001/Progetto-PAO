// Classe base astratta rappresentate una vista generica
#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QSize>
#include <QMessageBox>
#include <QCloseEvent>

class view : public QWidget
{
    Q_OBJECT
private:
    virtual void connectViewSignals() const = 0;

protected:
    void closeEvent(QCloseEvent *event) override;

public:
    explicit view(const QSize& s = QSize(), view* parent = nullptr);
    virtual ~view();
    void setSize(const QSize& s);
    virtual void setTitle(const QString& title);

    //bool dialogPopUp_Question(unsigned int param, const QString& title, const QString& desc);
    void dialogPopUp_Warning(const QString& title, const QString& desc);
    void dialogPopUp_Information(const QString& title, const QString& desc);
    void dialogPopUp_FatalError(const QString& title, const QString& desc);

signals:
    void viewClosed();
};

#endif // VIEW_H
