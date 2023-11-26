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
    Q_INVOKABLE int getTaAnalogVal();
    Q_INVOKABLE int getTrcomTripAVal();
    Q_INVOKABLE bool getTurnR();
    Q_INVOKABLE bool getTurnL();
    Q_INVOKABLE bool getFrontRightSeatbelt();
    Q_INVOKABLE bool getFrontLeftSeatbelt();
    Q_INVOKABLE bool getGeneralWarn();
    Q_INVOKABLE bool getEngine();
    Q_INVOKABLE bool getLowBattery();
    Q_INVOKABLE bool getLdwOff();
    Q_INVOKABLE bool getSrsAirbag();
    Q_INVOKABLE bool getEspOff();
    Q_INVOKABLE bool getBrake();
    Q_INVOKABLE bool getAbs();
    Q_INVOKABLE bool getEspAct();
    Q_INVOKABLE bool getHillDescent();
    Q_INVOKABLE bool getImmobi();
    Q_INVOKABLE bool getDoor();
    Q_INVOKABLE bool getEps();
    Q_INVOKABLE bool getAutoHiBeamGreen();
    Q_INVOKABLE bool getHighbeam();

    Q_INVOKABLE QString getGearAtVal();


    // class I/F for C++
    QClusterService();
    virtual ~QClusterService();
};

#endif // CLUSTERSERVICE_HXX
