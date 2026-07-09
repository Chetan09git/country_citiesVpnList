#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QtCore/qobject.h>

class CountryManager;

class FileManager {
public:
  virtual ~FileManager() {};
  virtual bool writeDta(const QString &fileName, CountryManager *manager) = 0;
  virtual bool readData(const QString &fileName, CountryManager *manager) = 0;
};

#endif // FILEMANAGER_H
