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

import QtQuick 2.14
import QtGraphicalEffects 1.14

Item {
    id: meter
    property real speedValue: 0
    property real tachoValue: 0
    property real chargeValue:100

    onSpeedValueChanged: {
        speedGuage.speedValue = speedValue
        speedNeedle.speedValue = speedValue
        digitalSpeed.speedValue = speedValue
    }

    onTachoValueChanged: {
        tachometer.tachoValue = tachoValue
    }
    onChargeValueChanged: {
        chargeGuage.chargeValue = chargeValue
    }


    Item {
       id: meterParts
       property var easing: Easing.InOutQuad

       Connections{
           target: rootItem
           onTransNormalToAdas:{
               / *nop */
           }
       }

       Sideline {
           id: sideline
       }

       Ring {
           id: ring
       }

       ChargeGuage {
           id: chargeGuage
       }

       SpeedGuage {
           id: speedGuage
       }

       SpeedNeedle {
           id: speedNeedle
       }

       Tachometer {
           id: tachometer
       }

       Ready {
           id: ready
       }

       Mask {
           id: mask
       }

       DigitalSpeed {
           id: digitalSpeed
       }
    }
}


