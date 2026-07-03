#include "City.h"
#include <QRandomGenerator>

City::City(QString cityName, int cityIp) {
  m_cityName = cityName;
  m_pinCode = cityIp;
  m_randomNumber = QRandomGenerator::global()->bounded(100, 199);
}

int City::getPinCode() const { return m_pinCode; }

QString City::getCityName() const { return m_cityName; }

void City::setPinCode(int newPinCode) { m_pinCode = newPinCode; }

void City::setCityName(const QString &newCityName) { m_cityName = newCityName; }

int City::getRandomNumber() const { return m_randomNumber; }

void City::setRandomNumber(int newRandomNumber) {
  m_randomNumber = newRandomNumber;
}
