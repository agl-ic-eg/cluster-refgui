/*
 * Copyright 2020,2021 Panasonic Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef REFGUI_IC_DATAPOOL_H
#define REFGUI_IC_DATAPOOL_H

#include <QObject>
#include <QVariant>

class IC_DataPool : public QObject
{
    Q_OBJECT
public:
    explicit IC_DataPool(QObject *parent = 0);
    void init();
    // Telltale
    void WriteTurnR(bool on_off);
    void WriteTurnL(bool on_off);
    void WriteBrake(bool on_off);
    void WriteSeatbelt(bool on_off);
    void WriteHighbeam(bool on_off);
    void WriteDoor(bool on_off);
    void WriteEps(bool on_off);
    void WriteSrsAirbag(bool on_off);
    void WriteAbs(bool on_off);
    void WriteLowBattery(bool on_off);
    void WriteImmobi(bool on_off);
    void WriteEspAct(bool on_off);
    void WriteEspOff(bool on_off);
    void WriteHillDescent(bool on_off);
    void WriteGeneralWarn(bool on_off);
    // Shift Position
    void WriteGearAtVal(int pos);
    // Speed
    void WriteSpAnalogVal(uint speed);
    // Tacho
    void WriteTaAnalogVal(uint rpm);
    // Trip
    void WriteOTempVal(int temp);
    void WriteCruRangeVal(uint range);

signals:
    // Telltale
    void signalTurnR(QVariant on_off);
    void signalTurnL(QVariant on_off);
    void signalBrake(QVariant on_off);
    void signalSeatbelt(QVariant on_off);
    void signalHighbeam(QVariant on_off);
    void signalDoor(QVariant on_off);
    void signalEps(QVariant on_off);
    void signalSrsAirbag(QVariant on_off);
    void signalAbs(QVariant on_off);
    void signalLowBattery(QVariant on_off);
    void signalImmobi(QVariant on_off);
    void signalEspAct(QVariant on_off);
    void signalEspOff(QVariant on_off);
    void signalHillDescent(QVariant on_off);
    void signalGeneralWarn(QVariant on_off);
    // Shift Position
    void signalGearAtVal(QVariant pos);
    // Speed
    void signalSpAnalogVal(QVariant speed);
    // Tacho
    void signalTaAnalogVal(QVariant rpm);
    // Trip
    void signalOTempVal(QVariant temp);
    void signalCruRangeVal(QVariant range);

private:
    bool TurnR;
    bool TurnL;
    bool Brake;
    bool Seatbelt;
    bool Highbeam;
    bool Door;
    bool Eps;
    bool SrsAirbag;
    bool Abs;
    bool LowBattery;
    bool Immobi;
    bool EspAct;
    bool EspOff;
    bool HillDescent;
    bool GeneralWarn;
    int GearAtVal;
    unsigned long SpAnalogVal;
    unsigned long TaAnalogVal;
    signed short OTempVal;
    unsigned short CruRangeVal;
};

#endif /* REFGUI_IC_DATAPOOL_H */

