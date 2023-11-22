#ifndef CLUSTERSERVICE_HXX
#define CLUSTERSERVICE_HXX

#include <QThread>

class QClusterService : public QThread
{
    Q_OBJECT

protected :
    virtual void run();

public:
    // class I/F for QML
    Q_INVOKABLE int getSpAnalogVal();
    Q_INVOKABLE int getTrcomTripAVal();
    Q_INVOKABLE bool getTurnR();
    Q_INVOKABLE bool getTurnL();
    Q_INVOKABLE bool getFrontRightSeatbelt();
    Q_INVOKABLE bool getFrontLeftSeatbelt();


    // class I/F for C++
    QClusterService();
    virtual ~QClusterService();
};

#endif // CLUSTERSERVICE_HXX
