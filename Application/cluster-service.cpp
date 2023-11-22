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
