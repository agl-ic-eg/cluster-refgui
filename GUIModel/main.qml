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
import QtQuick.Window 2.14
import QtQuick.Scene3D 2.14

import "./FPSItem"
import "./ACC"
import "./CruisingRange"
import "./Header"
import "./Menu"
import "./Meter"
import "./ShiftPosition"
import "./Telltale"
import "./TurnByTurn"


Window {
    id: winl
    visible: true
    width: 1920
    height: 720
    color: "black"
    flags: Qt.FramelessWindowHint
    maximumWidth: width
    maximumHeight: height
    Item{
        id: rootItem
        width: 1920
        height: 720
        focus: true
        clip: true
        property int mode: 0 /* 0:normal 1:adas 2:map */
        property string car_state : "normal_default"
        property string arrow_state : "arrow_normal_default"
        property string set_state : "set_default"
        signal transNormalToAdas()

        signal keyPressed_Up()
        signal keyPressed_Down()
        signal keyPressed_Left()
        signal keyPressed_Right()
        signal keyPressed_Enter()
        signal keyPressed_Menu()


        Item{
            id:viewdata
            property int tbtArrow: 0
            property int tbtValue: 200

            onTbtArrowChanged: {
                turnByTurn.receivedArrowId = tbtArrow
                stage.received_id = tbtArrow
            }

            onTbtValueChanged: {
                turnByTurn.receivedTbtValue = tbtValue
            }
        }

        Item{
            id:acc3d_parts
            width:1920
            height:1080
            Item{
                id:acc3d
                Item{
                    id:ddditem
                    x:548
                    y:-23
                    width: 1920
                    height: 1080
                    scale:0.6
                    Scene3D {
                        anchors.fill: parent
                        aspects: ["input", "logic"]
                        multisample: false
                        cameraAspectRatioMode:Scene3D.UserAspectRatio
                        Stage {
                            id:stage
                            ACC_Animation{
                                property int direction_acc_line : 0
                                property int direction_acc_car : 0
                                id:accc_view
                                acc_line_pos: 1
                                acc_car_pos: 1
                            }
                        }
                    }

                }
            }

            Image{
                id: acc3d_mask
                width:1920
                height:720
                source: "qrc:/Images/ADASView/ACC/3D_parts_mask.ktx"
                visible:true

            }
            Image{ source:"qrc:/Images/ADASView/MAP/acc_cover.ktx"; width:1412; height:98; x:508; y:622 }

        }

        TurnByTurn{
            id:turnByTurn
        }
        Menu{
            id: menu
        }
        Meter{
            id: meter
        }
        ShiftPosition{
            id:shiftPosition
            shiftId:0
        }
        CruisingRange {
            id: cruisingRange
            cruisingRangeValue : 750.0
        }

        Header{
            id:header
        }
        Telltale{
            id:telltale
        }

        Keys.onPressed: {

            switch(event.key){
            case(Qt.Key_1):
                if(shiftPosition.shiftId < 5) {
                    shiftPosition.shiftId++
                }else{
                    shiftPosition.shiftId = 0
                }
                break

            case(Qt.Key_2):
                if(accc_view.direction_acc_line === 0){
                    if(accc_view.acc_line_pos == 1) {
                        accc_view.acc_line_pos++
                        if(mode == 0){
                            rootItem.arrow_state = "arrow_normal_middle"
                        }else{
                            rootItem.arrow_state = "arrow_adas_middle"}
                        rootItem.set_state = "set_middle"
                    }else if(accc_view.acc_line_pos == 2){
                        accc_view.acc_line_pos++
                        if(mode == 0){
                            rootItem.arrow_state = "arrow_normal_near"
                        }else{
                            rootItem.arrow_state = "arrow_adas_near"}
                        rootItem.set_state = "set_near"
                    }else if(accc_view.acc_line_pos == 3){
                        accc_view.acc_line_pos--
                        if(mode == 0){
                            rootItem.arrow_state = "arrow_normal_middle"
                        }else{
                            rootItem.arrow_state = "arrow_adas_middle"}
                        rootItem.set_state = "set_middle"
                        accc_view.direction_acc_line = 1
                    }
                }else{
                    if(accc_view.acc_line_pos == 3) {
                        accc_view.acc_line_pos--
                        if(mode == 0){
                            rootItem.arrow_state = "arrow_normal_middle"
                        }else{
                            rootItem.arrow_state = "arrow_adas_middle"}
                        rootItem.set_state = "set_middle"
                    }else if(accc_view.acc_line_pos == 2){
                        accc_view.acc_line_pos--
                        if(mode == 0){
                            rootItem.arrow_state = "arrow_normal_default"
                        }else{
                            rootItem.arrow_state = "arrow_adas_default"}
                        rootItem.set_state = "set_default"
                    }else if(accc_view.acc_line_pos == 1){
                        accc_view.acc_line_pos++
                        if(mode == 0){
                            rootItem.arrow_state = "arrow_normal_middle"
                        }else{
                            rootItem.arrow_state = "arrow_adas_middle"}
                        rootItem.set_state = "set_middle"
                        accc_view.direction_acc_line = 0
                    }
                }
                break

            case(Qt.Key_3):
                if(accc_view.direction_acc_car == 0){
                    if(accc_view.acc_car_pos == 1) {
                        accc_view.acc_car_pos++
                        if(mode == 0){
                            rootItem.car_state = "nornal_middle"
                        }else{
                            rootItem.car_state = "adas_middle"}
                    }else if(accc_view.acc_car_pos == 2) {
                        accc_view.acc_car_pos++
                        if(mode == 0){
                            rootItem.car_state = "normal_near"
                        }else{
                            rootItem.car_state = "adas_near"}
                    }else if(accc_view.acc_car_pos == 3) {
                        accc_view.acc_car_pos--
                        accc_view.direction_acc_car = 1
                        if(mode == 0){
                            rootItem.car_state = "normal_middle"
                        }else{
                            rootItem.car_state = "adas_middle"}
                    }
                }else{
                    if(accc_view.acc_car_pos == 3) {
                        accc_view.acc_car_pos--
                        if(mode == 0){
                            rootItem.car_state = "normal_middle"
                        }else{
                            rootItem.car_state = "adas_middle"}
                    }else if(accc_view.acc_car_pos == 2) {
                        accc_view.acc_car_pos--
                        if(mode == 0){
                            rootItem.car_state = "normal_default"
                        }else{
                            rootItem.car_state = "adas_default"}
                    }else if(accc_view.acc_car_pos == 1){
                        accc_view.acc_car_pos++
                        accc_view.direction_acc_car = 0
                        if(mode == 0){
                            rootItem.car_state = "normal_middle"
                        }else{
                            rootItem.car_state = "adas_middle"}
                    }
                }
                break

            case(Qt.Key_Up):
                keyPressed_Up()
                break

            case(Qt.Key_Down):
                keyPressed_Down()
                break

            case(Qt.Key_Left):
                keyPressed_Left()
                break

            case(Qt.Key_Right):
                keyPressed_Right()
                break

            case(Qt.Key_Space):
                keyPressed_Enter()
                break

            case(Qt.Key_M):
                keyPressed_Menu()
                break

            default:
                break
            }
       }

        Timer {
            property int num  : 0
            interval: 10
            repeat: true
            running: true
            onTriggered: {
                doUpdateClusterData()
            }
        }

        Timer { //test
            property int num  : 0
            interval: 5000
            repeat: true
            running: true
            onTriggered: {
                num++;
                if(num == 5){num = 1}
                viewdata.tbtArrow = num;
            }
        }

        Timer { //test
            property int v  : 200
            interval: 5000
            repeat: true
            running: true
            onTriggered: {
                if(v - 20 >= 0){
                  v = v - 20
                }else{
                    v = 200
                }
                viewdata.tbtValue = v;
            }
        }
    }

    //FpsItem{}

    function doUpdateClusterData(){
        // speed
        var speed_val_capi = cluster_service.getSpAnalogVal();
        meter.speedValue = speed_val_capi / 100.0;

        // tacho
        var tacho_val_capi = cluster_service.getTaAnalogVal();
        meter.tachoValue = tacho_val_capi;

        // temp
        var temp_val_capi = cluster_service.getOTempVal();
        header.setTemp(temp_val_capi);

        // Gear
        var gear_val_capi = cluster_service.getGearAtVal();
        if (gear_val_capi === "D") {
            shiftPosition.shiftId = 1;
        } else if (gear_val_capi === "B") {
            shiftPosition.shiftId = 2;
        } else if (gear_val_capi === "N") {
            shiftPosition.shiftId = 3;
        } else if (gear_val_capi === "R") {
            shiftPosition.shiftId = 4;
        } else if (gear_val_capi === "P") {
            shiftPosition.shiftId = 5;
        } else {
            shiftPosition.shiftId = 0;
        }

        // Trip
        //var tripa_val_capi = cluster_service.getTrcomTripAVal();
        //cruisingRange.cruisingRangeValue = tripa_val_capi / 10;

        // Turn R
        var turnr_val_capi = cluster_service.getTurnR();
        if (turnr_val_capi === true) {
            header.setTurnROn();
        } else {
            header.setTurnROff();
        }

        // Turn L
        var turnl_val_capi = cluster_service.getTurnL();
        if (turnl_val_capi === true) {
            header.setTurnLOn();
        } else {
            header.setTurnLOff();
        }

        // Seetbelt
        var sbeltr_val_capi = cluster_service.getFrontRightSeatbelt();
        if (sbeltr_val_capi === true) {
            telltale.telltaleSeatbelt = true;
        } else {
            telltale.telltaleSeatbelt = false;
        }
        var sbeltl_val_capi = cluster_service.getFrontLeftSeatbelt();
        if (sbeltl_val_capi === true) {
            telltale.telltaleSeatbelt2 = true;
        } else {
            telltale.telltaleSeatbelt2 = false;
        }

        var genwarn_val_capi = cluster_service.getGeneralWarn();
        if (genwarn_val_capi === true) {
            telltale.telltaleGeneralWarn = true;
        } else {
            telltale.telltaleGeneralWarn = false;
        }

        var eng_val_capi = cluster_service.getEngine();
        if (eng_val_capi === true) {
            telltale.telltaleMotorWarn = true;
        } else {
            telltale.telltaleMotorWarn = false;
        }

        var lbatt_val_capi = cluster_service.getLowBattery();
        if (lbatt_val_capi === true) {
            telltale.telltaleLowBatt = true;
        } else {
            telltale.telltaleLowBatt = false;
        }

        var ldwoff_val_capi = cluster_service.getLdwOff();
        if (ldwoff_val_capi === true) {
            telltale.telltaleLdw = true;
        } else {
            telltale.telltaleLdw = false;
        }

        var srsair_val_capi = cluster_service.getSrsAirbag();
        if (srsair_val_capi === true) {
            telltale.telltaleSrsAirbag = true;
        } else {
            telltale.telltaleSrsAirbag = false;
        }

        var espoff_val_capi = cluster_service.getEspOff();
        if (espoff_val_capi === true) {
            telltale.telltaleEpsOff = true;
        } else {
            telltale.telltaleEpsOff = false;
        }

        var brake_val_capi = cluster_service.getBrake();
        if (brake_val_capi === true) {
            telltale.telltaleBrake = true;
        } else {
            telltale.telltaleBrake = false;
        }

        var abs_val_capi = cluster_service.getAbs();
        if (abs_val_capi === true) {
            telltale.telltaleAbsWarn = true;
        } else {
            telltale.telltaleAbsWarn = false;
        }

        var espact_val_capi = cluster_service.getEspAct();
        if (espact_val_capi === true) {
            telltale.telltaleEspAct = true;
        } else {
            telltale.telltaleEspAct = false;
        }

        var hill_val_capi = cluster_service.getHillDescent();
        if (hill_val_capi === true) {
            telltale.telltaleHillDescent = true;
        } else {
            telltale.telltaleHillDescent = false;
        }

        var immobi_val_capi = cluster_service.getImmobi();
        if (immobi_val_capi === true) {
            telltale.telltaleImmobi = true;
        } else {
            telltale.telltaleImmobi = false;
        }

        var door_val_capi = cluster_service.getDoor();
        if (door_val_capi === true) {
            telltale.telltaleDoor = true;
        } else {
            telltale.telltaleDoor = false;
        }

        var eps_val_capi = cluster_service.getEps();
        if (eps_val_capi === true) {
            telltale.telltaleEps = true;
        } else {
            telltale.telltaleEps = false;
        }

        var hibeamgreen_val_capi = cluster_service.getAutoHiBeamGreen();
        var hibeam_val_capi = cluster_service.getHighbeam();
        if (hibeamgreen_val_capi === true) {
            telltale.telltaleHighbeamAssist = true;

            if (hibeam_val_capi === true) {
                telltale.telltaleHighbeam = true;
                telltale.telltaleLowbeam = false;
            } else {
                telltale.telltaleHighbeam = false;
                telltale.telltaleLowbeam = true;
            }
        } else {
            telltale.telltaleHighbeamAssist = false;
            telltale.telltaleHighbeam = false;
            telltale.telltaleLowbeam = false;
        }
    }
}


