#ifndef RINGER_H
#define RINGER_H

#include <QObject>
#include <QTimer>

class Ringer : public QObject
{
    Q_OBJECT
public:
    explicit Ringer(QObject *parent = 0);
    ~Ringer();

signals:
    void stopped();

public slots:
    void start();
    void stop();
private slots:
    void playRingSound();

private:
    QTimer *timer;
    bool ringing;


};

#endif // RINGER_H
