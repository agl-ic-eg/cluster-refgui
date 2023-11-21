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

    // class I/F for C++
    QClusterService();
    virtual ~QClusterService();
};

#endif // CLUSTERSERVICE_HXX
