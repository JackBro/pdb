#ifndef DATABASECLEANER_H
#define DATABASECLEANER_H
//
/*
 This file is part of project pdb.

    pdb is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License.

    pdb is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with pdb.  If not, see <http://www.gnu.org/licenses/>.
*/
//
#include <QObject>
#include "advthreadjob.h"
//#include <QRunnable>
class DatabaseCleaner : public QObject, public AdvThreadJob//QRunnable
{
    Q_OBJECT
public:
    explicit DatabaseCleaner(QObject *parent = 0);
    
signals:
    
public slots:

public:
    bool exec();

private:
    bool clearAttachments();
    bool clearNodes();
    bool clearTrees();
    
};

#endif // DATABASECLEANER_H
