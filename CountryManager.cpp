#include "CountryManager.h"
#include "JsonFileManager.h"
#include <QDebug>
#include <QTimer>

CountryManager *CountryManager::m_countryManager = nullptr;

CountryManager::CountryManager(QObject *parent) : QObject{parent} {
  // countryInitializer();
  if(!m_fileReder)
      m_fileReder = new JsonFileManager;

  // m_fileReder->writeData("CountryData.json", this);
  m_fileReder->readData("CountryData.json",this);
}

QMap<int, Country *> CountryManager::getCountryList() const {
  return m_countryList;
}

// const QMap<QString, QString> &CountryManager::getCountryCityListMap() const {
//   return M_countryCityList;
// }

// void CountryManager::addToSearchList() {

//   for (const Country *country : m_countryList) {
//     M_countryCityList[country->getCountry()] = country->getPngPath();
//     for (City *city : country->getCityList()) {
//       M_countryCityList[city->getCityName()] = country->getPngPath();
//     }
//   }
// }

// void CountryManager::displayList() {
//   for (const auto &i : M_countryCityList.keys()) {

//     qDebug() << "Name is : " << i;
//   }
// }

void CountryManager::addCountry(QString newCountryName, int newcountryIp,
                                QString newImgPage) {
  m_Country = new Country(newCountryName, newcountryIp, newImgPage);
  m_countryList.insert(newcountryIp, m_Country);
  emit countryAdded(newCountryName);
}

// void CountryManager::setCountryCityList()
// {
//     // for (Country *country: m_countryList)
//     // {
//     //     QVariantMap countryItem;
//     //     countryItem["name"] = country->getCountry();
//     //     countryItem["image"] = country->getPngPath();
//     //     countryItem["randomNumber"] = country->getRandomNumber();
//     //     m_searchList.append(countryItem);

//     // }
// }

// QVariantList CountryManager::getCountryCityList()
// {
//     return QVariantList();
// }


CountryManager *CountryManager::init() {
  if (m_countryManager == nullptr) {
    m_countryManager = new CountryManager;
    return m_countryManager;
  } else {
    return m_countryManager;
  }
}

Country *CountryManager::getCountry(int index) {
  return m_countryList.values().at(index);
}

void CountryManager::countryInitializer()
{
    addCountry("India", 91, "qrc:/Png/india.png");
    addCountry("United States", 1, "qrc:/Png/united-states.png");
    addCountry("United Kingdom", 44, "qrc:/Png/united-kingdom.png");
    addCountry("Canada", 11, "qrc:/Png/canada.png");
    addCountry("Australia", 61, "qrc:/Png/australia.png");
    addCountry("Germany", 49, "qrc:/Png/germany.png");
    addCountry("France", 33, "qrc:/Png/france.png");
    addCountry("Japan", 81, "qrc:/Png/japan.png");
    addCountry("China", 86, "qrc:/Png/china.png");
    addCountry("Brazil", 55, "qrc:/Png/brazil.png");
    addCountry("Russia", 7, "qrc:/Png/russia.png");
    addCountry("Italy", 39, "qrc:/Png/italy.png");
    addCountry("Spain", 34, "qrc:/Png/spain.png");
    addCountry("South Korea", 82, "qrc:/Png/south-korea.png");
    addCountry("Mexico", 52, "qrc:/Png/mexico.png");
    addCountry("Singapore", 65, "qrc:/Png/singapore.png");
    addCountry("Netherlands", 31, "qrc:/Png/netherlands.png");
    addCountry("Sweden", 46, "qrc:/Png/sweden.png");
    addCountry("Norway", 47, "qrc:/Png/norway.png");
    addCountry("South Africa", 27, "qrc:/Png/south-africa.png");

    Country *country;

    // United Kingdom
    country = m_countryList.value(44);
    country->addCity("London", 441);
    country->addCity("Manchester", 442);
    country->addCity("Birmingham", 443);

    // Canada
    country = m_countryList.value(11);
    country->addCity("Toronto", 111);
    country->addCity("Vancouver", 112);
    country->addCity("Montreal", 113);


    // Germany
    country = m_countryList.value(49);
    country->addCity("Berlin", 491);
    country->addCity("Munich", 492);
    country->addCity("Hamburg", 493);

    // France
    country = m_countryList.value(33);
    country->addCity("Paris", 331);
    country->addCity("Lyon", 332);
    country->addCity("Marseille", 333);

    // Japan
    country = m_countryList.value(81);
    country->addCity("Tokyo", 811);
    country->addCity("Osaka", 812);
    country->addCity("Kyoto", 813);

    // China
    country = m_countryList.value(86);
    country->addCity("Beijing", 861);
    country->addCity("Shanghai", 862);
    country->addCity("Shenzhen", 863);

    // Brazil
    country = m_countryList.value(55);
    country->addCity("Sao Paulo", 551);
    country->addCity("Rio de Janeiro", 552);
    country->addCity("Brasilia", 553);

    // Russia
    country = m_countryList.value(7);
    country->addCity("Moscow", 71);
    country->addCity("Saint Petersburg", 72);
    country->addCity("Kazan", 73);

    // Italy
    country = m_countryList.value(39);
    country->addCity("Rome", 391);
    country->addCity("Milan", 392);
    country->addCity("Venice", 393);

    // Spain
    country = m_countryList.value(34);
    country->addCity("Madrid", 341);
    country->addCity("Barcelona", 342);
    country->addCity("Valencia", 343);

    // South Korea
    country = m_countryList.value(82);
    country->addCity("Seoul", 821);
    country->addCity("Busan", 822);
    country->addCity("Incheon", 823);

    // Mexico
    country = m_countryList.value(52);
    country->addCity("Mexico City", 521);
    country->addCity("Guadalajara", 522);
    country->addCity("Monterrey", 523);

    // Singapore
    country = m_countryList.value(65);
    country->addCity("Central", 651);
    country->addCity("Jurong", 652);
    country->addCity("Woodlands", 653);

    // Netherlands
    country = m_countryList.value(31);
    country->addCity("Amsterdam", 311);
    country->addCity("Rotterdam", 312);
    country->addCity("The Hague", 313);

    // Sweden
    country = m_countryList.value(46);
    country->addCity("Stockholm", 461);
    country->addCity("Gothenburg", 462);
    country->addCity("Malmo", 463);

    // Norway
    country = m_countryList.value(47);
    country->addCity("Oslo", 471);
    country->addCity("Bergen", 472);
    country->addCity("Trondheim", 473);

    // South Africa
    country = m_countryList.value(27);
    country->addCity("Johannesburg", 271);
    country->addCity("Cape Town", 272);
    country->addCity("Durban", 273);

      int seqNum = 100;
      for (Country *c : m_countryList.values()) {
        c->setPingNumber(seqNum);
        QList<City *> cities = c->getCityList();
        for (int i = 0; i < cities.size(); ++i) {
          if (i == 0) {
            cities[i]->setPingNumber(seqNum);
          } else {
            cities[i]->setPingNumber(++seqNum);
          }
        }
        seqNum++;
      }
}

// QString CountryManager::getCountryCityList(int index) const {
//   return M_countryCityList.values().at(index);
// }

CountryManager::~CountryManager() {
  for (auto countryList : m_countryList) {
    delete countryList;
  }
  m_countryList.clear();
  delete m_Country;
}
