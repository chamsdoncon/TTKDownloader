#ifndef DOWNLOADNETWORKSPEEDTESTTHREAD_H
#define DOWNLOADNETWORKSPEEDTESTTHREAD_H

/* =================================================
 * This file is part of the TTK Downloader project
 * Copyright (c) 2016 - 2017 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/
#include <QThread>
#include <QStringList>
#include "downloadglobaldefine.h"

class QProcess;

/*! @brief The class of the network speed test thread.
 * @author Greedysky <greedysky@163.com>
 */
class DOWNLOAD_NETWORK_EXPORT DownloadNetworkSpeedTestThread : public QThread
{
    Q_OBJECT
public:
    /*!
     * Object contsructor.
     */
    explicit DownloadNetworkSpeedTestThread(QObject *parent = 0);

    ~DownloadNetworkSpeedTestThread();

    /*!
     * Get class object name.
     */
    static QString getClassName();

    /*!
     * Stop and quit current thread.
     */
    void stopAndQuitThread();
    /*!
     * Set available newtwork names.
     */
    void setAvailableNewtworkNames(const QStringList &names);
    /*!
     * Get available newtwork names.
     */
    QStringList getAvailableNewtworkNames() const;
    /*!
     * Get newtwork names.
     */
    QStringList getNewtworkNames() const;

Q_SIGNALS:
    /*!
     * Send current upload and download speed data.
     */
    void networkData(ulong upload, ulong download);

public Q_SLOTS:
    /*!
     * Strat thread now.
     */
    void start();
    /*!
     * Thread run now.
     */
    virtual void run() override;

private Q_SLOTS:
    /*!
     * Get output recieved data on linux network.
     */
    void outputRecieved();

protected:
    bool m_run;
    QStringList m_names;
    QProcess *m_process ;

};

#endif // DOWNLOADNETWORKSPEEDTESTTHREAD_H
