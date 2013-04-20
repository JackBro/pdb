#ifndef DLGASKENCRYPTMETHOD_H
#define DLGASKENCRYPTMETHOD_H
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
#include <QDialog>

namespace Ui {
class DlgAskEncryptMethod;
}

class DlgAskEncryptMethod : public QDialog
{
    Q_OBJECT
    
public:
    explicit DlgAskEncryptMethod(QWidget *parent = 0);
    ~DlgAskEncryptMethod();
public:

private slots:
    void            onOK                    ();
    void            onEncryptModeChanged    (int);
    
private:

    void fillEncryptMethodList              ();

private:
    Ui::DlgAskEncryptMethod *ui;
    //
    unsigned int m_uiEncryptMode;
    unsigned int m_uiInitialEncryptMode;
};

#endif // DLGASKENCRYPTMETHOD_H
