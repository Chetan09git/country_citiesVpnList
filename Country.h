#ifndef COUNTRY_H
#define COUNTRY_H

#include <QObject>
#include <QList>
#include "City.h"

class Country
{
public:
    explicit Country(QString newCountryName, int newCountryIp);
    explicit Country(QString newCountryName, int newCountryIp, QString path);
    ~Country();


    void setCountry(const QString &newCountry);
    QString getCountry()const;

    int getCountryIp() const;
    void setCountryIp(int newCountryIp);
    void addCity(QString cityName, int cityIp);


    QList<City *> getCityList() const;

    QString getPngPath() const;
    void setPngPath(const QString &newPngPath);

    int getPingNumber() const;
    void setPingNumber(int newRandomNumber);

private:
    QString m_country;
    int m_countryIp;
    QString m_pngPath;
    int m_randomNumber;

    City *m_city;
    QList< City*> m_cityList ;
};

#endif // COUNTRY_H
