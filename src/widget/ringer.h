#ifndef RINGER_H
#define RINGER_H

#include <QObject>
#include <QTimer>

class Ringer : public QObject
{
    Q_OBJECT
public:
    explicit Ringer(QByteArray *sndData,QObject *parent = 0);
    ~Ringer();

signals:
    void stopped();

public slots:
    void start();
    void stop();

private:
    QByteArray *sndData;
};

#endif // RINGER_H
