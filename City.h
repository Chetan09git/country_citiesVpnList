#ifndef CITY_H
#define CITY_H

#include <QObject>

class City
{
public:
    explicit City(QString cityName,int cityIp);

    int getPinCode() const;
    void setPinCode(int newPinCode);

    QString getCityName() const;

    void setCityName(const QString &newCityName);

    int getRandomNumber() const;
    void setRandomNumber(int newRandomNumber);

private:
    QString m_cityName;
    int m_pinCode;
    int m_randomNumber;
};

#endif // CITY_H
