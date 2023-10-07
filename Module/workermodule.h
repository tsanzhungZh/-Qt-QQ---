
#ifndef WORKERMODULE_H
#define WORKERMODULE_H

#include "basemodule.h"

#include <QObject>


class WorkerModule : public BaseModule
{
    Q_OBJECT
public:
    explicit WorkerModule(QObject *parent = nullptr);
};

#endif // WORKERMODULE_H
