#include "Country.h"
#include "City.h"
#include <QRandomGenerator>

Country::Country(QString newCountryName,int newCountryIp, QObject *parent)
    : QObject{parent}
{

    m_country = newCountryName;
    m_countryIp = newCountryIp;
    m_randomNumber = QRandomGenerator::global()->bounded(100, 199);
}

Country::Country(QString newCountryName, int newCountryIp, QString path, QObject *parent) : QObject{parent}

{
    m_country = newCountryName;
    m_countryIp = newCountryIp;
    m_pngPath = path;
    m_randomNumber = QRandomGenerator::global()->bounded(100, 199);
}

Country::~Country()
{
    for (City *city : m_cityList) {
        delete city;
    }
    m_cityList.clear();
    delete m_city;
}


QString Country::getCountry() const
{
    return m_country;
}

int Country::getCountryIp() const
{
    return m_countryIp;
}


void Country::addCity(QString cityName, int cityIp)
{
    m_city = new City(cityName,cityIp);
    m_cityList.push_back(m_city);
}


QList<City *> Country::getCityList() const
{
    return m_cityList;
}

QString Country::getPngPath() const
{
    return m_pngPath;
}

void Country::setPngPath(const QString &newPngPath)
{
    m_pngPath = newPngPath;
}


void Country::setCountryIp(int newCountryIp)
{
    m_countryIp = newCountryIp;
}

void Country::setCountry(const QString &newCountry)
{
    m_country = newCountry;
}

int Country::getRandomNumber() const
{
    return m_randomNumber;
}

void Country::setRandomNumber(int newRandomNumber)
{
    m_randomNumber = newRandomNumber;
}
