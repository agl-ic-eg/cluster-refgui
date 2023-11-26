#include "cluster-service.hxx"
#include <cluster_api.h>
#include <cluster-api-sdevent.h>

#include <systemd/sd-daemon.h>
#include <systemd/sd-event.h>

//-----------------------------------------------------------------------------------
QClusterService::QClusterService()
{

}
//-----------------------------------------------------------------------------------
QClusterService::~QClusterService()
{


}
//-----------------------------------------------------------------------------------
Q_INVOKABLE int QClusterService::getSpAnalogVal()
{
    uint32_t speed_u32 = 0;
    int retval = 0;

    speed_u32 = ::getSpAnalogVal();
    if (speed_u32 > (uint32_t)INT_MAX)
        retval = INT_MAX;
    else
        retval = (int)speed_u32;

    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE int QClusterService::getTaAnalogVal()
{
    uint32_t ta_u32 = 0;
    int retval = 0;

    ta_u32 = ::getTaAnalogVal();
    if (ta_u32 > (uint32_t)INT_MAX)
        retval = INT_MAX;
    else
        retval = (int)ta_u32;

    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE int QClusterService::getTrcomTripAVal()
{
    uint32_t tripa_u32 = 0;
    int retval = 0;

    tripa_u32 = ::getTrcomTripAVal();
    if (tripa_u32 > (uint32_t)INT_MAX)
        retval = INT_MAX;
    else
        retval = (int)tripa_u32;

    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE int QClusterService::getOTempVal()
{
    int16_t tmp_val = -40;
    int retval = -40;

    tmp_val = ::getOTempVal();
    retval = (int)tmp_val;

    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE bool QClusterService::getTurnR()
{
    IC_HMI_ON_OFF on_off_flag = IC_HMI_OFF;
    bool retval = false;

    on_off_flag = ::getTurnR();
    if (on_off_flag == IC_HMI_OFF)
        retval = false;
    else
        retval = true;

    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE bool QClusterService::getTurnL()
{
    IC_HMI_ON_OFF on_off_flag = IC_HMI_OFF;
    bool retval = false;

    on_off_flag = ::getTurnL();
    if (on_off_flag == IC_HMI_OFF)
        retval = false;
    else
        retval = true;

    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE bool QClusterService::getFrontRightSeatbelt()
{
    IC_HMI_ON_OFF on_off_flag = IC_HMI_OFF;
    bool retval = false;

    on_off_flag = ::getFrontRightSeatbelt();
    if (on_off_flag == IC_HMI_OFF)
        retval = false;
    else
        retval = true;

    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE bool QClusterService::getFrontLeftSeatbelt()
{
    IC_HMI_ON_OFF on_off_flag = IC_HMI_OFF;
    bool retval = false;

    on_off_flag = ::getFrontLeftSeatbelt();
    if (on_off_flag == IC_HMI_OFF)
        retval = false;
    else
        retval = true;

    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE bool QClusterService::getGeneralWarn()
{
    IC_HMI_ON_OFF on_off_flag = IC_HMI_OFF;
    bool retval = false;

    on_off_flag = ::getGeneralWarn();
    if (on_off_flag == IC_HMI_OFF)
        retval = false;
    else
        retval = true;

    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE bool QClusterService::getEngine()
{
    IC_HMI_ON_OFF on_off_flag = IC_HMI_OFF;
    bool retval = false;

    on_off_flag = ::getEngine();
    if (on_off_flag == IC_HMI_OFF)
        retval = false;
    else
        retval = true;

    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE bool QClusterService::getLowBattery()
{
    IC_HMI_ON_OFF on_off_flag = IC_HMI_OFF;
    bool retval = false;

    on_off_flag = ::getLowBattery();
    if (on_off_flag == IC_HMI_OFF)
        retval = false;
    else
        retval = true;

    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE bool QClusterService::getLdwOff()
{
    IC_HMI_ON_OFF on_off_flag = IC_HMI_OFF;
    bool retval = false;

    on_off_flag = ::getLdwOff();
    if (on_off_flag == IC_HMI_OFF)
        retval = false;
    else
        retval = true;

    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE bool QClusterService::getSrsAirbag()
{
    IC_HMI_ON_OFF on_off_flag = IC_HMI_OFF;
    bool retval = false;

    on_off_flag = ::getSrsAirbag();
    if (on_off_flag == IC_HMI_OFF)
        retval = false;
    else
        retval = true;

    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE bool QClusterService::getEspOff()
{
    IC_HMI_ON_OFF on_off_flag = IC_HMI_OFF;
    bool retval = false;

    on_off_flag = ::getEspOff();
    if (on_off_flag == IC_HMI_OFF)
        retval = false;
    else
        retval = true;

    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE bool QClusterService::getBrake()
{
    IC_HMI_ON_OFF on_off_flag = IC_HMI_OFF;
    bool retval = false;

    on_off_flag = ::getBrake();
    if (on_off_flag == IC_HMI_OFF)
        retval = false;
    else
        retval = true;

    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE bool QClusterService::getAbs()
{
    IC_HMI_ON_OFF on_off_flag = IC_HMI_OFF;
    bool retval = false;

    on_off_flag = ::getAbs();
    if (on_off_flag == IC_HMI_OFF)
        retval = false;
    else
        retval = true;

    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE bool QClusterService::getEspAct()
{
    IC_HMI_ON_OFF on_off_flag = IC_HMI_OFF;
    bool retval = false;

    on_off_flag = ::getEspAct();
    if (on_off_flag == IC_HMI_OFF)
        retval = false;
    else
        retval = true;

    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE bool QClusterService::getHillDescent()
{
    IC_HMI_ON_OFF on_off_flag = IC_HMI_OFF;
    bool retval = false;

    on_off_flag = ::getHillDescent();
    if (on_off_flag == IC_HMI_OFF)
        retval = false;
    else
        retval = true;

    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE bool QClusterService::getImmobi()
{
    IC_HMI_ON_OFF on_off_flag = IC_HMI_OFF;
    bool retval = false;

    on_off_flag = ::getImmobi();
    if (on_off_flag == IC_HMI_OFF)
        retval = false;
    else
        retval = true;

    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE bool QClusterService::getDoor()
{
    IC_HMI_ON_OFF on_off_flag = IC_HMI_OFF;
    bool retval = false;

    on_off_flag = ::getDoor();
    if (on_off_flag == IC_HMI_OFF)
        retval = false;
    else
        retval = true;

    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE bool QClusterService::getEps()
{
    IC_HMI_ON_OFF on_off_flag = IC_HMI_OFF;
    bool retval = false;

    on_off_flag = ::getEps();
    if (on_off_flag == IC_HMI_OFF)
        retval = false;
    else
        retval = true;

    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE bool QClusterService::getAutoHiBeamGreen()
{
    IC_HMI_ON_OFF on_off_flag = IC_HMI_OFF;
    bool retval = false;

    on_off_flag = ::getAutoHiBeamGreen();
    if (on_off_flag == IC_HMI_OFF)
        retval = false;
    else
        retval = true;

    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE bool QClusterService::getHighbeam()
{
    IC_HMI_ON_OFF on_off_flag = IC_HMI_OFF;
    bool retval = false;

    on_off_flag = ::getHighbeam();
    if (on_off_flag == IC_HMI_OFF)
        retval = false;
    else
        retval = true;

    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE QString QClusterService::getGearAtVal()
{
    IC_HMI_GEAR_AT_VAL gear_val = IC_HMI_AT_UNUSED;
    QString gear_string = QString("");

    gear_val = ::getGearAtVal();

    switch (gear_val) {
    case IC_HMI_AT_OFF :
        gear_string = QString("Off");
        break;
    case IC_HMI_AT_PARKING :
        gear_string = QString("P");
        break;
    case IC_HMI_AT_REVERSE :
        gear_string = QString("R");
        break;
    case IC_HMI_AT_NEUTRAL :
        gear_string = QString("N");
        break;
    case IC_HMI_AT_DRIVE :
        gear_string = QString("D");
        break;
    case IC_HMI_AT_SECOND :
        gear_string = QString("S");
        break;
    case IC_HMI_AT_LOW_GEAR :
        gear_string = QString("L");
        break;
    case IC_HMI_AT_FIRST :
        gear_string = QString("F");
        break;
    case IC_HMI_AT_MANUAL :
        gear_string = QString("M");
        break;
    case IC_HMI_AT_BRAKE :
        gear_string = QString("B");
        break;
    case IC_HMI_AT_ALL_ON :
    case IC_HMI_AT_ALL_OFF :
    case IC_HMI_AT_UNUSED :
        gear_string = QString("Error");
        break;
    default:
        gear_string = QString("Off");
        break;
    }

    return gear_string;
}
//-----------------------------------------------------------------------------------
/*
static void ic_notify(uint64_t signal, IC_HMI_ON_OFF val)ui
{
    fprintf(stdout, "Signal change notify %016lx , val=%1d\r", signal, val);
}
*/
void QClusterService::run()
{
    sd_event *event = NULL;
    data_pool_client_handle_sdevent handle = NULL;
    int ret = -1;

    ret = sd_event_default(&event);
    if (ret < 0)
        goto finish;

    do {
        ret = data_pool_client_setup_sdevent(event, &handle);
        if (ret == 0)
            break;
        this->msleep(10);
    } while(true);

    //(void) registerIcHmi(IC_HMI_TT_TURN_R, ic_notify);
    //(void) registerIcHmi(IC_HMI_TT_TURN_L, ic_notify);

    ret = sd_event_loop(event);
    if (ret < 0) {
        //TODO
    }
finish:
    (void) data_pool_client_cleanup_sdevent(handle);
    event = sd_event_unref(event);

    return;
}

//-----------------------------------------------------------------------------------
