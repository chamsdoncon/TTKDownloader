#ifndef DOWNLOADTIME_H
#define DOWNLOADTIME_H

/* =================================================
 * This file is part of the TTK Downloader project
 * Copyright (c) 2016 - 2017 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include <QDataStream>
#include "downloadglobaldefine.h"
#include "downloadnumberdefine.h"

/*! @brief The class of the time object.
 * @author Greedysky <greedysky@163.com>
 */
class DOWNLOAD_CORE_EXPORT DownloadTime
{
public:
    enum Type
    {
        All_Msec,   /*!< Current time entity is msec*/
        All_Sec     /*!< Current time entity is sec*/
    };

    /*!
     * Object contsructor.
     */
    DownloadTime();
    /*!
     * Object contsructor.
     */
    DownloadTime(const DownloadTime &other);
    /*!
     * Object contsructor by value and type.
     */
    DownloadTime(qint64 value, Type type);
    /*!
     * Object contsructor by day and hour and min and sec and msec.
     */
    DownloadTime(int day, int hour, int min, int sec, int msec);

    /*!
     * Get class object name.
     */
    static QString getClassName();
    /*!
     * Set current day and hour and min and sec and msec.
     */
    void setHMSM(int day, int hour, int min, int sec, int msec = 0);
    /*!
     * Check current time is null.
     */
    bool isNull() const;
    /*!
     * Check current time is valid.
     */
    bool isValid() const;

    /*!
     * Set current time type, see Type.
     */
    inline void setType(Type type) { m_defaultType = type; }
    /*!
     * Get current time type, see Type.
     */
    inline Type getType() const { return m_defaultType; }

    /*!
     * Set current greedy mode.
     */
    inline void setGreedy(bool mode) { m_greedyMode = mode; }
    /*!
     * Get current greedy mode.
     */
    inline bool getGreedy() const { return m_greedyMode; }

    /*!
     * Set current day.
     */
    inline void setDay(int day) { m_day = day; }
    /*!
     * Set current hour.
     */
    inline void setHour(int hour) { m_hour = hour; }
    /*!
     * Set current minute.
     */
    inline void setMinute(int min) { m_min = min; }
    /*!
     * Set current second.
     */
    inline void setSecond(int sec) { m_sec = sec; }
    /*!
     * Set current millionSecond.
     */
    inline void setMillionSecond(int msec) { m_msec = msec; }
    /*!
     * Get current day.
     */
    inline int getDay() const { return m_day; }
    /*!
     * Get current hour.
     */
    inline int getHour() const { return m_hour; }
    /*!
     * Get current second.
     */
    inline int getMinute() const { return m_min; }
    /*!
     * Get current second.
     */
    inline int getSecond() const { return m_sec; }
    /*!
     * Get current millionSecond.
     */
    inline int getMillionSecond() const { return m_msec; }

    /*!
     * Transform time from string by time format.
     */
    static DownloadTime fromString(const QString &s, const QString &format);
    /*!
     * Transform time from value to string time format.
     */
    static QString toString(qint64 value, Type type, const QString &format);

    /*!
     * Transform time to string time format.
     */
    QString toString(const QString &format);
//    h	the hour without a leading zero (0 to 23 or 1 to 12 if AM/PM display)
//    hh	the hour with a leading zero (00 to 23 or 01 to 12 if AM/PM display)
//    H	the hour without a leading zero (0 to 23, even with AM/PM display)
//    HH	the hour with a leading zero (00 to 23, even with AM/PM display)
//    m	the minute without a leading zero (0 to 59)
//    mm	the minute with a leading zero (00 to 59)
//    s	the second without a leading zero (0 to 59)
//    ss	the second with a leading zero (00 to 59)
//    z	the milliseconds without leading zeroes (0 to 999)
//    zzz	the milliseconds with leading zeroes (000 to 999)
//    AP or A	use AM/PM display. A/AP will be replaced by either "AM" or "PM".
//    ap or a	use am/pm display. a/ap will be replaced by either "am" or "pm".
//    t	the timezone (for example "CEST")
    //////////////////////////////////////////////
    /*!
     * Get all time value by type.
     */
    qint64 getTimeStamp(Type type) const;
    //////////////////////////////////////////////
    /*!
     * Transform ms time from utc since epoch.
     */
    static qint64 timeStamp(bool ms = true);
    /*!
     * Init random time seed.
     */
    static void timeSRand();
    //////////////////////////////////////////////
    /*!
     * Transform msec time to string format(mm:ss).
     */
    QString msecTime2LabelJustified();
    /*!
     * Transform msec time to string format(mm:ss).
     */
    static QString msecTime2LabelJustified(qint64 time, bool greedy = true);
    /*!
     * Transform msec time to string format(/ ss / mm / hh / dd).
     */
    QString normalTime2Label() const;
    /*!
     * Transform msec time to string format(/ ss / mm / hh / dd).
     */
    static QString normalTime2Label(qint64 time);
    //////////////////////////////////////////////

    DownloadTime& operator=  (const DownloadTime &other);
    DownloadTime& operator+= (const DownloadTime &other);
    DownloadTime& operator+= (const int other);
    DownloadTime& operator-= (const DownloadTime &other);
    DownloadTime& operator-= (const int other);
    DownloadTime& operator*= (const int other);
    DownloadTime& operator/= (const int other);

    DownloadTime  operator+ (const DownloadTime &other);
    DownloadTime  operator+ (const int other);
    DownloadTime  operator- (const DownloadTime &other);
    DownloadTime  operator- (const int other);
    DownloadTime  operator* (const int other);
    DownloadTime  operator/ (const int other);

    bool operator== (const DownloadTime &other) const;
    bool operator!= (const DownloadTime &other) const;

    inline friend QDataStream& operator<<(QDataStream &stream, const DownloadTime &other)
    {
        stream << other.getDay() << other.getHour() << other.getMinute()
               << other.getSecond() << other.getMillionSecond();
        return stream;
    }

    inline friend QDataStream& operator>>(QDataStream &stream, DownloadTime &other)
    {
        int x[5];
        stream >> x[0] >> x[1] >> x[2] >> x[3] >> x[4];
        other.setHMSM(x[0], x[1], x[2], x[3], x[4]);
        return stream;
    }

protected:
    /*!
     * Init parameters;
     */
    void init();
    /*!
     * Copy other time data to this obejct;
     */
    void copyToThis(const DownloadTime &other);
    /*!
     * Transform time value by different time type;
     */
    void fromTimeStamp(qint64 value, int delta);

    bool m_greedyMode;
    Type m_defaultType;
    int m_day, m_hour;
    int m_min, m_sec, m_msec;

};

#endif // DOWNLOADTIME_H
