#ifndef JSONFILEMANAGER_H
#define JSONFILEMANAGER_H

#include "FileManager.h"
#include <QObject>

// class CountryManager;

class JsonFileManager : public FileManager {
public:
  bool writeDta(const QString &fileName, CountryManager *manager);
  bool readData(const QString &fileName, CountryManager *manager);
};

#endif