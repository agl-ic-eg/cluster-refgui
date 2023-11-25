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
import QtQuick.Shapes 1.14

Item {
    id: speedGuage
    x:666
    y:97
    width:588
    height:588
    property real speedValue

    readonly property real speedGuageMax: 100
    readonly property real speedGuageMin: 0

    onSpeedValueChanged: {
        limitSpeedValue();
        effectPwr.angle = (2.25 * speedValue*Math.PI/180)+effectPwr.angleBase
    }

    Connections{
        target: rootItem
        onTransNormalToAdas:{
            normalToAdasAnimation.start()
        }
    }

    function limitSpeedValue(){
        if(speedGuageMax < speedValue){
            speedValue = speedGuageMax
        }else if(speedValue < speedGuageMin){
            speedValue = speedGuageMin
        }
    }

    /* Guage - visible in Normal mode */
    Item {
        id:pwrGuageGroup
        width:588
        height:588
        
        Image{
            id:pwrGuage
            source: "qrc:/Images/NormalView/METER/pwr_guage.png"
            width:588
            height:588

            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            opacity: 1
            visible: false
        }
        ShaderEffect{
            id: effectPwr
            anchors.fill: parent
            visible: true
            blending: true
            supportsAtlasTextures: true
            property real angleBase: -pi*1/2
            property real angle:-pi*1/2
            property var src: ShaderEffectSource{
                sourceItem: pwrGuage
                live: false
            }

            readonly property real pi: 3.1415926535

            vertexShader: "qrc:/Shaders/vert/guageMask.vert"
            fragmentShader:"qrc:/Shaders/frag/guageMask.frag"
        }
    }
    
    
    Image{
        id:ringLine
        source: "qrc:/Images/NormalView/METER/ring_line.ktx"
        width:588
        height:588
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }
    
    Image{
        id:speedTxt
        source: "qrc:/Images/NormalView/SPEED/speed_txt.png"
        width:588
        height:588
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }
    
    Image{
        id:ring5
        source: "qrc:/Images/NormalView/METER/ring5.png"
        width: 34
        height:24
        anchors.left: parent.left
        anchors.leftMargin: -11
        anchors.verticalCenter: parent.verticalCenter
    }
}
