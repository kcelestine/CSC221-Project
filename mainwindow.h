
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QtWidgets>
#include <QWidget>

//class QAction;
//class QActionGroup;
//class QLabel;
//class QMenu;
//class QToolBar;
//class QTableWidget;
//class QWidget;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

protected:
    void contextMenuEvent(QContextMenuEvent *event);
private:
   void createTabs();

private slots:
    void newFile();
    void open();
    void load();
    void save();

    void savePalette();
    void loadPalette();
    void xport();

    void print();
    void undo();
    void redo();
    void cut();
    void copy();
    void paste();
    void fullSelection();
    void blendTool();
    void copyCurrentLayer();
    void resetAllParameters();
    void cropInput();
    void cropOutput();

    void zoomIn();
    void zoomOut();


    void fitWindow();

    void fullscreen();
     /*
    void toggleSections();
    void showLayerManager();
    void input();
    void output();
    void palette();
    void info();*/
/*
    void bold();
    void italic();
    void leftAlign();
    void rightAlign();
    void justify();
    void center();
    void setLineSpacing();
    void setParagraphSpacing();
    void about();
    void aboutQt();*/

private:
    void createActions();
    void createMenus();

    QTabWidget *tabdesign;
    QWidget * input;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *formatMenu;
    QMenu *viewMenu;
    QActionGroup *alignmentGroup;
    QAction *newAct;
    QAction *openAct;
    QAction *loadAct;
    QAction *saveAct;
    QAction *saveAsAct;
    QAction *loadPaletteAct;
    QAction *savePaletteAct;
    QAction *xportAct;
    QAction *printAct;
    QAction *quitAct;

    QAction *undoAct;
    QAction *redoAct;
    QAction *cutAct;
    QAction *copyAct;
    QAction *pasteAct;

    QAction * fullSelectionAct;
    QAction *blendToolAct;
    QAction *copyCurrentLayerAct;
    QAction *resetAllParametersAct;
    QAction *cropInputAct;
    QAction *cropOutputAct;

    QAction *zoomInAct;
    QAction *zoomOutAct;

    QAction * fitWindowAct;

    QAction *fullscreenAct;
     /*
    QAction *toggleSectionsAct;
    QAction *showLayerManagerAct;
    QAction *inputAct;
    QAction *outputAct;
    QAction *paletteAct;*/
/*
    QAction *boldAct;
    QAction *italicAct;
    QAction *leftAlignAct;
    QAction *rightAlignAct;
    QAction *justifyAct;
    QAction *centerAct;
    QAction *setLineSpacingAct;
    QAction *setParagraphSpacingAct;
    QAction *aboutAct;
    QAction *aboutQtAct;*/

    QLabel *infoLabel;
};

#endif
