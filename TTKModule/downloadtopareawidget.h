#ifndef DOWNLOADTOPAREAWIDGET_H
#define DOWNLOADTOPAREAWIDGET_H

/* =================================================
 * This file is part of the TTK Downloader project
 * Copyright (c) 2016 - 2017 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include <QWidget>
#include <QTimer>
#include "downloadglobaldefine.h"

class DownloadBackgroundSkinDialog;

namespace Ui {
    class DownloadApplication;
}

/*! @brief The class of the app top area widget.
 * @author Greedysky <greedysky@163.com>
 */
class DOWNLOAD_GUI_EXPORT DownloadTopAreaWidget : public QWidget
{
    Q_OBJECT
public:
    /*!
     * Object contsructor.
     */
    explicit DownloadTopAreaWidget(QWidget *parent = 0);

    ~DownloadTopAreaWidget();

    /*!
     * Get class object name.
     */
    static QString getClassName();
    /*!
     * Get class object instance.
     */
    static DownloadTopAreaWidget *instance();
    /*!
     * Set up app ui.
     */
    void setupUi(Ui::DownloadApplication* ui);

    /*!
     * Set background skin and alpha and list alpha parameter.
     */
    void setParameters(const QString &skin, int alpha);
    /*!
     * Get background skin name.
     */
    inline QString getBackgroundPath() const { return m_backgroundImagePath; }
    /*!
     * Get background skin alpha.
     */
    inline int getBackgroundAlpha() const { return m_backgroundAlpha; }
    /*!
     * Get background skin pixmap.
     */
    QPixmap getRendererPixmap() const;

public Q_SLOTS:
    /*!
     * Current slider state changed.
     */
    void backgroundSliderStateChanged(bool state);
    /*!
     * Show change background skin dailog.
     */
    void showSkinChangedWindow();
    /*!
     * Current background transparent changed.
     */
    void backgroundTransparentChanged();
    /*!
     * Current background transparent changed by index.
     */
    void backgroundTransparentChanged(int index);
    /*!
     * Current background transparent changed by string.
     */
    void backgroundTransparentChanged(const QString &fileName);
    /*!
     * Resize current background skin when geometry changed.
     */
    void backgroundThemeChangedByResize();
    /*!
     * Current background skin changed by new path.
     */
    void backgroundSkinChanged(const QString &fileName);

protected:
    /*!
     * Draw window background rect.
     */
    void drawWindowBackgroundRect();
    /*!
     * Draw window background rect.
     */
    void drawWindowBackgroundRect(const QImage &image);
    /*!
     * Draw window background rect by qimage.
     */
    void drawWindowBackgroundRectString();
    /*!
     * Draw window background rect by picture.
     */
    void drawWindowBackgroundRectString(const QString &path);

    Ui::DownloadApplication *m_ui;
    DownloadBackgroundSkinDialog *m_backgroundWidget;

    QImage m_backgroundImage;
    QString m_backgroundImagePath;
    int m_backgroundAlpha;

    static DownloadTopAreaWidget *m_instance;
};

#endif // DOWNLOADTOPAREAWIDGET_H
