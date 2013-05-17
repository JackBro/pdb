#ifndef DLGSCANIMAGE_H
#define DLGSCANIMAGE_H
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
#include <QByteArray>
#include <QVector>
#include <QProcess>

//
QT_FORWARD_DECLARE_CLASS(ImageLabel)
QT_FORWARD_DECLARE_CLASS(QToolBar)
QT_FORWARD_DECLARE_CLASS(QAction)
QT_FORWARD_DECLARE_CLASS(QComboBox)
QT_FORWARD_DECLARE_CLASS(QLabel)
QT_FORWARD_DECLARE_CLASS(QScrollArea)
QT_FORWARD_DECLARE_CLASS(QPushButton)
QT_FORWARD_DECLARE_CLASS(QSpinBox)
QT_FORWARD_DECLARE_CLASS(QScrollBar)
QT_FORWARD_DECLARE_CLASS(QCheckBox)
QT_FORWARD_DECLARE_CLASS(QToolButton)
//
namespace Ui {
class DlgScanImage;
}

class DlgScanImage : public QDialog
{
    Q_OBJECT
    
public:
    explicit            DlgScanImage    (QWidget *parent = 0);
                        ~DlgScanImage   ();
    //
    const QByteArray&   getImage        () const                                          {return m_baImageAsArray;}
    const QString&      getImageName    () const                                          {return m_strImageName;}
    //
private:
    void                makeToolBar     ();
    void                setLinks        ();
    void                scaleImage      (double factor);
    void                adjustScrollBar (QScrollBar* scrollBar, double factor);
    //
    void                openImage       ();
    void                readScanSettings();
    bool                prepareRawScanCmd(QString &str_raw_command, bool &b_redefine_std_out);
    //
    void                enableInterface (bool b_enable, bool b_change_mouse_cursor);
    //
    void                eraseUndoRedoBuffer ();
    void                trimUndoRedoBuffer ();
    //
    void                addNewImage     (QPixmap* ptr_image, bool b_erase_buffer);
    void                setCurrentImage (double d_scale_factor = -1.);
    void                setUndoRedoAvailable ();
    //
private slots:

    void        onRotate    ();
    //
    void        onScan      ();
    void        onUndo      ();
    void        onRedo      ();
    //
    void        onZoomIn    ();
    void        onZoomOut   ();
    void        onZoom_1_1  ();
    //
    void        onWidthChanged(int);
    void        onHeightChanged(int);
    //
    void        onCrop      ();
    //
    void        onResize    ();
    //
    void        onSave      ();
    //
    void        onCropAllowed   (bool);
    void        onScanError     ( QProcess::ProcessError );
    void        onScanFinished  (int);

private:
    //
    QLabel*             m_ptrScanLabel;
    QComboBox*          m_ptrScanMode;
    //
    QVector<QString>    m_strNames;
    QVector<QString>    m_strScanConfigs;
    //
    QProcess*           m_ptrScanProcess;
    //
    QAction*            m_ptrScan;
    //
    QAction*            m_ptrUndo;
    QAction*            m_ptrRedo;
    //
    QAction*            m_ptrRotate;
    //
    QToolButton*        m_ptrZoom;
    QAction*            m_ptrZoomIn;
    QAction*            m_ptrZoomOut;
    QAction*            m_ptrZoom_1_1;
    //
    QAction*            m_ptrCrop;
    //
    QLabel*             m_ptrWidthLabel;
    QSpinBox*           m_ptrWidthBox;
    //
    QLabel*             m_SpaceLbl;
    QCheckBox*          m_Proportional;
    //
    QLabel*             m_ptrHeightLabel;
    QSpinBox*           m_ptrHeightBox;
    //
    bool                m_bIgnoreResize;
    //
    double              m_d_WH_Ratio;
    //
    QPushButton*        m_pResize;
    //
    QAction*            m_ptrSave;
    QAction*            m_ptrExit;
    //
    //
    QToolBar*           m_ptrToolBar;
    //
    QScrollArea*        m_ptrScrollArea;
    ImageLabel*         m_ptrImageLabel;
    //
    int                 m_iCurrentActiveImageIndex;
    QVector<QPixmap*>   m_vActionsBuffer;
    //
    QByteArray          m_baImageAsArray;
    QString             m_strImageName;
    QString             m_strScanFileName;
    //
    double              m_dscaleFactor;
    //
    Ui::DlgScanImage*   ui;
};

#endif // DLGSCANIMAGE_H
