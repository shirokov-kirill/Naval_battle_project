#ifndef SIGNALHELPER_H
#define SIGNALHELPER_H
#include <QObject>

class SignalHelper : public QObject {
    Q_OBJECT
    QString  text_;
public:
    SignalHelper(const QString & text)
            : text_(text) {
    }
signals:
    void textChanged(const QString & text);
public slots:
    void onButtonPressed() {
        emit textChanged(text_);
    }
};

#endif // SIGNALHELPER_H
