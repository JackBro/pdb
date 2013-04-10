#ifndef DLGMANAGEICONS_H
#define DLGMANAGEICONS_H
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
//
QT_FORWARD_DECLARE_CLASS(QGridLayout)
QT_FORWARD_DECLARE_CLASS(QListWidgetItem)

namespace Ui {
class DlgManageIcons;
}

class DlgManageIcons : public QDialog
{
    Q_OBJECT
    
public:
    explicit DlgManageIcons(QWidget *parent = 0);
    ~DlgManageIcons();
    //
    int  getSelectedIconID  () const                                    {return m_iSelectedIconID;}
    //
private slots:
    void onDelete           ();
    void onSave             ();
    void onLoad             ();
    void onSelect           ();
    void onSetNothing       ();
    void onListItemChanged  ( QListWidgetItem*,QListWidgetItem* );
    void onSearchTextChanged(QString);


private:
    void makeLayout         ();
    void fillList           ();

private:
    Ui::DlgManageIcons* ui;
    //
    QGridLayout*        m_ptrLayout;
    QString             m_strExtList;
    int                 m_iSelectedIconID;
};

#endif // DLGMANAGEICONS_H
