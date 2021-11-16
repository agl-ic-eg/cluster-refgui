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

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSurfaceFormat>
#include <QQuickItem>
#include <QDir>
#include <QQmlContext>
#include <QDebug>
#include <QThread>
#include <QTimer>

#include "IC_Receiver.h"

int main(int argc, char *argv[])
{
    QSurfaceFormat defaultFormat;
    defaultFormat.setSwapBehavior(QSurfaceFormat::TripleBuffer);
    defaultFormat.setRenderableType(QSurfaceFormat::OpenGLES);
    defaultFormat.setProfile(QSurfaceFormat::NoProfile);
    defaultFormat.setVersion(2,0);
    defaultFormat.setSwapInterval(1);
    defaultFormat.setDepthBufferSize(8);
    defaultFormat.setAlphaBufferSize(8);
    QSurfaceFormat::setDefaultFormat(defaultFormat);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("CurDirPath", QString(QCoreApplication::applicationDirPath()));
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    //*****
    QObject *root = engine.rootObjects().constFirst();
    IC_Receiver *receiver = new IC_Receiver();
    QThread *ic_client = new QThread();
    QTimer timer;

    QObject::connect(receiver, SIGNAL(signalTurnR(QVariant)), root, SLOT(slotTurnR(QVariant)), Qt::QueuedConnection);
    QObject::connect(receiver, SIGNAL(signalTurnL(QVariant)), root, SLOT(slotTurnL(QVariant)), Qt::QueuedConnection);
    QObject::connect(receiver, SIGNAL(signalBrake(QVariant)), root, SLOT(slotBrake(QVariant)), Qt::QueuedConnection);
    QObject::connect(receiver, SIGNAL(signalSeatbelt(QVariant)), root, SLOT(slotSeatbelt(QVariant)), Qt::QueuedConnection);
    QObject::connect(receiver, SIGNAL(signalHighbeam(QVariant)), root, SLOT(slotHighbeam(QVariant)), Qt::QueuedConnection);
    QObject::connect(receiver, SIGNAL(signalDoor(QVariant)), root, SLOT(slotDoor(QVariant)), Qt::QueuedConnection);
    QObject::connect(receiver, SIGNAL(signalEps(QVariant)), root, SLOT(slotEps(QVariant)), Qt::QueuedConnection);
    QObject::connect(receiver, SIGNAL(signalSrsAirbag(QVariant)), root, SLOT(slotSrsAirbag(QVariant)), Qt::QueuedConnection);
    QObject::connect(receiver, SIGNAL(signalAbs(QVariant)), root, SLOT(slotAbs(QVariant)), Qt::QueuedConnection);
    QObject::connect(receiver, SIGNAL(signalLowBattery(QVariant)), root, SLOT(slotLowBattery(QVariant)), Qt::QueuedConnection);
    QObject::connect(receiver, SIGNAL(signalImmobi(QVariant)), root, SLOT(slotImmobi(QVariant)), Qt::QueuedConnection);
    QObject::connect(receiver, SIGNAL(signalEspAct(QVariant)), root, SLOT(slotEspAct(QVariant)), Qt::QueuedConnection);
    QObject::connect(receiver, SIGNAL(signalEspOff(QVariant)), root, SLOT(slotEspOff(QVariant)), Qt::QueuedConnection);
    QObject::connect(receiver, SIGNAL(signalHillDescent(QVariant)), root, SLOT(slotHillDescent(QVariant)), Qt::QueuedConnection);
    QObject::connect(receiver, SIGNAL(signalGeneralWarn(QVariant)), root, SLOT(slotGeneralWarn(QVariant)), Qt::QueuedConnection);
    QObject::connect(receiver, SIGNAL(signalGearAtVal(QVariant)), root, SLOT(slotGearAtVal(QVariant)), Qt::QueuedConnection);
    QObject::connect(receiver, SIGNAL(signalSpAnalogVal(QVariant)), root, SLOT(slotSpAnalogVal(QVariant)), Qt::QueuedConnection);
    QObject::connect(receiver, SIGNAL(signalTaAnalogVal(QVariant)), root, SLOT(slotTaAnalogVal(QVariant)), Qt::QueuedConnection);
    QObject::connect(receiver, SIGNAL(signalOTempVal(QVariant)), root, SLOT(slotOTempVal(QVariant)), Qt::QueuedConnection);
    QObject::connect(receiver, SIGNAL(signalCruRangeVal(QVariant)), root, SLOT(slotCruRangeVal(QVariant)), Qt::QueuedConnection);
    root->dumpObjectInfo();

    QObject::connect(&timer,SIGNAL(timeout()), receiver, SLOT(receive()));
    timer.setInterval(10);

    receiver->moveToThread(ic_client);
    ic_client->start();
    timer.start();

    app.exec();

    timer.stop();
    ic_client->terminate();
    ic_client->wait();
    delete receiver;
    delete ic_client;

    return 0;
}
