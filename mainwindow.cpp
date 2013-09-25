#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow()
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    setWindowTitle(tr("Tessera Grid(Version 1.11)"));
    setMinimumSize(160, 160);
    resize(480, 320);


    tabdesign= new QTabWidget(widget);
    input =new  QWidget(this);

    tabdesign-> setFixedSize(690,680);
    tabdesign->addTab(input, "input");

    tabdesign->addTab(new QWidget(this),"Output");
    tabdesign->addTab(new QWidget,"Palette");
    tabdesign-> addTab(new QWidget,"Info");

    QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    infoLabel = new QLabel(tr(" --"));
    infoLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    infoLabel->setAlignment(Qt::AlignCenter);

    QWidget *bottomFiller = new QWidget;
    bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setMargin(5);
    layout->addWidget(topFiller);
    layout->addWidget(infoLabel);
    layout->addWidget(bottomFiller);
    widget->setLayout(layout);

    createActions();
    createMenus();

    QString message = tr("--");
    statusBar()->showMessage(message);


}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.addAction(cutAct);
    menu.addAction(copyAct);
    menu.addAction(pasteAct);
    menu.exec(event->globalPos());
}
void MainWindow::createTabs()
{
    infoLabel->setText(" Here a page");
}
void MainWindow::newFile()
{
    infoLabel->setText(tr(" "));
}

void MainWindow::open()
{
    infoLabel->setText(tr(" "));
}
void MainWindow::load()
{
    infoLabel->setText(tr(" "));
}
void MainWindow::save()
{
    infoLabel->setText(tr("Invoked <b>File|Save</b>"));
}
void MainWindow::savePalette()
{
  infoLabel->setText(tr("Invoked <b>File|SavePalette</b>"));
}

void MainWindow::loadPalette()
{
  infoLabel->setText(tr("Invoked <b>File|LoadPalette</b>"));
}
void MainWindow::xport()
{
    infoLabel->setText(tr("Invoked <b>File|Export</b>"));
}

void MainWindow::print()
{
    infoLabel->setText(tr("Invoked <b>File|Print</b>"));
}

void MainWindow::undo()
{
    infoLabel->setText(tr("Invoked <b>Edit|Undo</b>"));
}

void MainWindow::redo()
{
    infoLabel->setText(tr("Invoked <b>Edit|Redo</b>"));
}

void MainWindow::cut()
{
    infoLabel->setText(tr("Invoked <b>Edit|Cut</b>"));
}

void MainWindow::copy()
{
    infoLabel->setText(tr("Invoked <b>Edit|Copy</b>"));
}

void MainWindow::paste()
{
    infoLabel->setText(tr("Invoked <b>Edit|Paste</b>"));
}

void MainWindow::fullSelection()
{
  infoLabel->setText(tr("Invoked <b>Edit|FullSelection</b>"));
}

void MainWindow::blendTool()
{
    infoLabel->setText(tr("Invoked <b>Edit|BlendTool</b>"));
}

void MainWindow::copyCurrentLayer()
{
    infoLabel->setText(tr("Invoked <b>Edit|Copy Current Layer/b>"));
}

void MainWindow::resetAllParameters()
{
    infoLabel->setText(tr("Invoked <b>Edit|Reset All Parameters</b>"));
}

void MainWindow::cropInput()
{
    infoLabel->setText(tr("Invoked <b>Edit|Crop Input</b>"));
}

void MainWindow::cropOutput()
{
    infoLabel->setText(tr("Invoked <b>Edit|Crop Output</b>"));
}
void MainWindow::zoomIn()
{
    infoLabel->setText(tr("Invoked <b>View|Zooming</b>"));
}
void MainWindow::zoomOut(){
    infoLabel->setText(tr("Invoked <b>View|Zooming</b>"));
}

void MainWindow::fitWindow(){
    infoLabel->setText(tr("Invoked <b>View|Zoomout</b>"));
}

void MainWindow::fullscreen(){
    infoLabel->setText(tr("Invoked <b>View|Full Screen</b>"));
}
/*
void MainWindow::toggleSections(){
    infoLabel->setText(tr("Invoked <b>View|Toggle Selection</b>"));
}
void MainWindow::showLayerManager(){
    infoLabel->setText(tr("Invoked <b>View|Show Manager</b>"));
}
void MainWindow::input(){
    infoLabel->setText(tr("Invoked <b>View|Input</b>"));
}
void MainWindow::output(){
    infoLabel->setText(tr("Invoked <b>View|Output</b>"));
}
void MainWindow:: palette(){
    infoLabel->setText(tr("Invoked <b>View|Palette</b>"));
}
void MainWindow::info(){
    infoLabel->setText(tr("Invoked <b>View|Info</b>"));
}*/
/*

void MainWindow::bold()
{
    infoLabel->setText(tr("Invoked <b>Edit|Format|Bold</b>"));
}

void MainWindow::italic()
{
    infoLabel->setText(tr("Invoked <b>Edit|Format|Italic</b>"));
}

void MainWindow::leftAlign()
{
    infoLabel->setText(tr("Invoked <b>Edit|Format|Left Align</b>"));
}

void MainWindow::rightAlign()
{
    infoLabel->setText(tr("Invoked <b>Edit|Format|Right Align</b>"));
}

void MainWindow::justify()
{
    infoLabel->setText(tr("Invoked <b>Edit|Format|Justify</b>"));
}

void MainWindow::center()
{
    infoLabel->setText(tr("Invoked <b>Edit|Format|Center</b>"));
}

void MainWindow::setLineSpacing()
{
    infoLabel->setText(tr("Invoked <b>Edit|Format|Set Line Spacing</b>"));
}

void MainWindow::setParagraphSpacing()
{
    infoLabel->setText(tr("Invoked <b>Edit|Format|Set Paragraph Spacing</b>"));
}

void MainWindow::about()
{
    infoLabel->setText(tr("Invoked <b>Help|About</b>"));
    QMessageBox::about(this, tr("About Menu"),
            tr("The <b>Menu</b> example shows how to create "
               "menu-bar menus and context menus."));
}

void MainWindow::aboutQt()
{
    infoLabel->setText(tr("Invoked <b>Help|About Qt</b>"));
}
*/

void MainWindow::createActions()
{
    newAct = new QAction(tr("&New Project"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));

    openAct = new QAction(tr("&Open Examples"), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    loadAct = new QAction(tr("&Load Project"), this);
    loadAct->setShortcuts(QKeySequence::Save);
    loadAct->setStatusTip(tr("Load "));
    connect(loadAct, SIGNAL(triggered()), this, SLOT(load()));

    saveAct = new QAction(tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the document to disk"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

    saveAsAct = new QAction(tr("&SaveAs"), this);
    saveAsAct ->setShortcuts(QKeySequence::Save);
    saveAsAct ->setStatusTip(tr("Save the document to disk"));
    connect(saveAsAct , SIGNAL(triggered()), this, SLOT(save()));

    savePaletteAct = new QAction(tr("&SavePalette"), this);
    savePaletteAct ->setShortcuts(QKeySequence::Save);
    savePaletteAct ->setStatusTip(tr("Save the document to Palette"));
    connect( savePaletteAct , SIGNAL(triggered()), this, SLOT(savePalette()));

    loadPaletteAct = new QAction(tr("&LoadPalette"), this);
    loadPaletteAct->setShortcuts(QKeySequence::Save);
    loadPaletteAct ->setStatusTip(tr("Load the Document"));
    connect(loadPaletteAct , SIGNAL(triggered()), this, SLOT(loadPalette()));

    xportAct = new QAction(tr("E&xport"), this);
    xportAct->setShortcuts(QKeySequence::Print);
    xportAct->setStatusTip(tr("Export the document"));
    connect(xportAct  , SIGNAL(triggered()), this, SLOT(xport()));

    printAct = new QAction(tr("&Print..."), this);
    printAct->setShortcuts(QKeySequence::Print);
    printAct->setStatusTip(tr("Print the document"));
    connect(printAct, SIGNAL(triggered()), this, SLOT(print()));

    quitAct = new QAction(tr("&Quit"), this);
    quitAct ->setShortcuts(QKeySequence::Quit);
    quitAct ->setStatusTip(tr("Exit the application"));
    connect(quitAct, SIGNAL(triggered()), this, SLOT(close()));

    undoAct = new QAction(tr("&Undo"), this);
    undoAct->setShortcuts(QKeySequence::Undo);
    undoAct->setStatusTip(tr("Undo the last operation"));
    connect(undoAct, SIGNAL(triggered()), this, SLOT(undo()));

    redoAct = new QAction(tr("&Redo"), this);
    redoAct->setShortcuts(QKeySequence::Redo);
    redoAct->setStatusTip(tr("Redo the last operation"));
    connect(redoAct, SIGNAL(triggered()), this, SLOT(redo()));

    cutAct = new QAction(tr("Cu&t"), this);
    cutAct->setShortcuts(QKeySequence::Cut);
    cutAct->setStatusTip(tr("Cut the current selection's contents to the "
                            "clipboard"));
    connect(cutAct, SIGNAL(triggered()), this, SLOT(cut()));

    copyAct = new QAction(tr("&Copy"), this);
    copyAct->setShortcuts(QKeySequence::Copy);
    copyAct->setStatusTip(tr("Copy the current selection's contents to the "
                             "clipboard"));
    connect(copyAct, SIGNAL(triggered()), this, SLOT(copy()));

    pasteAct = new QAction(tr("&Paste"), this);
    pasteAct->setShortcuts(QKeySequence::Paste);
    pasteAct->setStatusTip(tr("Paste the clipboard's contents into the current "
                              "selection"));
    connect(pasteAct, SIGNAL(triggered()), this, SLOT(paste()));


    fullSelectionAct = new QAction(tr("&Fill Selection"), this);
    fullSelectionAct->setShortcut(tr("CTRL+I"));
    fullSelectionAct->setStatusTip(tr("Fill selection"));
    connect(fullSelectionAct, SIGNAL(triggered()), this, SLOT(fullSelection()));


    blendToolAct = new QAction(tr("&Blend Tool"), this);
    blendToolAct->setShortcut(tr("CTRL+D"));
    blendToolAct->setStatusTip(tr("Blend Tool"));
    connect(blendToolAct, SIGNAL(triggered()), this, SLOT(blendTool()));

    copyCurrentLayerAct = new QAction(tr("&Copy Current Layer"), this);
    copyCurrentLayerAct->setShortcuts(QKeySequence::Paste);
    copyCurrentLayerAct->setStatusTip(tr("Copy Current Laye"));
    connect(copyCurrentLayerAct, SIGNAL(triggered()), this, SLOT(copyCurrentLayer()));

    resetAllParametersAct= new QAction(tr("&Reset All Parameters"), this);
    resetAllParametersAct->setShortcuts(QKeySequence::Paste);
    resetAllParametersAct->setStatusTip(tr("reset All Parameters"));
    connect(resetAllParametersAct, SIGNAL(triggered()), this, SLOT(resetAllParameters()));

    cropInputAct = new QAction(tr("&Crop Input"), this);
    cropInputAct->setShortcuts(QKeySequence::Paste);
    cropInputAct->setStatusTip(tr("Crop Input"));
    connect(cropInputAct, SIGNAL(triggered()), this, SLOT(cropInput()));

    cropOutputAct = new QAction(tr("&Crop Output"), this);
    cropOutputAct ->setShortcuts(QKeySequence::Paste);
    cropOutputAct ->setStatusTip(tr("Crop Output"));
    connect(cropOutputAct , SIGNAL(triggered()), this, SLOT(cropOutput ()));


    zoomInAct = new QAction(tr("&zoom In"), this);
    zoomInAct ->setShortcuts(QKeySequence::Paste);
    zoomInAct ->setStatusTip(tr("zoom In"));
    connect(zoomInAct , SIGNAL(triggered()), this, SLOT(zoomIn()));

    zoomOutAct = new QAction(tr("&zoom Out"), this);
    zoomOutAct ->setShortcuts(QKeySequence::Paste);
    zoomOutAct ->setStatusTip(tr("zoom Out"));
    connect(zoomOutAct , SIGNAL(triggered()), this, SLOT(zoomOut() ));


    fitWindowAct = new QAction(tr("&fit Window"), this);
    fitWindowAct ->setShortcuts(QKeySequence::Paste);
    fitWindowAct ->setStatusTip(tr("fit Window"));
    connect(fitWindowAct , SIGNAL(triggered()), this, SLOT(fitWindow()));

    fullscreenAct= new QAction(tr("&full Screen"), this);
    fullscreenAct ->setShortcuts(QKeySequence::Paste);
    fullscreenAct ->setStatusTip(tr("full Screen"));
    connect(fullscreenAct , SIGNAL(triggered()), this, SLOT(fullscreen()));
/*
    toggleSectionsAct = new QAction(tr("&Toggle Sections "), this);
    toggleSectionsAct ->setShortcuts(QKeySequence::Paste);
    toggleSectionsAct ->setStatusTip(tr("Crop Output"));
    connect(toggleSectionsAct , SIGNAL(triggered()), this, SLOT(toggleSections ()));
*/
/*
    boldAct = new QAction(tr("&Bold"), this);
    boldAct->setCheckable(true);
    boldAct->setShortcut(QKeySequence::Bold);
    boldAct->setStatusTip(tr("Make the text bold"));
    connect(boldAct, SIGNAL(triggered()), this, SLOT(bold()));

    QFont boldFont = boldAct->font();
    boldFont.setBold(true);
    boldAct->setFont(boldFont);

    italicAct = new QAction(tr("&Italic"), this);
    italicAct->setCheckable(true);
    italicAct->setShortcut(QKeySequence::Italic);
    italicAct->setStatusTip(tr("Make the text italic"));
    connect(italicAct, SIGNAL(triggered()), this, SLOT(italic()));

    QFont italicFont = italicAct->font();
    italicFont.setItalic(true);
    italicAct->setFont(italicFont);

    setLineSpacingAct = new QAction(tr("Set &Line Spacing..."), this);
    setLineSpacingAct->setStatusTip(tr("Change the gap between the lines of a "
                                       "paragraph"));
    connect(setLineSpacingAct, SIGNAL(triggered()), this, SLOT(setLineSpacing()));

    setParagraphSpacingAct = new QAction(tr("Set &Paragraph Spacing..."), this);
    setParagraphSpacingAct->setStatusTip(tr("Change the gap between paragraphs"));
    connect(setParagraphSpacingAct, SIGNAL(triggered()),
            this, SLOT(setParagraphSpacing()));

    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAct = new QAction(tr("About &Qt"), this);
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    connect(aboutQtAct, SIGNAL(triggered()), this, SLOT(aboutQt()));

    leftAlignAct = new QAction(tr("&Left Align"), this);
    leftAlignAct->setCheckable(true);
    leftAlignAct->setShortcut(tr("Ctrl+L"));
    leftAlignAct->setStatusTip(tr("Left align the selected text"));
    connect(leftAlignAct, SIGNAL(triggered()), this, SLOT(leftAlign()));

    rightAlignAct = new QAction(tr("&Right Align"), this);
    rightAlignAct->setCheckable(true);
    rightAlignAct->setShortcut(tr("Ctrl+R"));
    rightAlignAct->setStatusTip(tr("Right align the selected text"));
    connect(rightAlignAct, SIGNAL(triggered()), this, SLOT(rightAlign()));

    justifyAct = new QAction(tr("&Justify"), this);
    justifyAct->setCheckable(true);
    justifyAct->setShortcut(tr("Ctrl+J"));
    justifyAct->setStatusTip(tr("Justify the selected text"));
    connect(justifyAct, SIGNAL(triggered()), this, SLOT(justify()));

    centerAct = new QAction(tr("&Center"), this);
    centerAct->setCheckable(true);
    centerAct->setShortcut(tr("Ctrl+E"));
    centerAct->setStatusTip(tr("Center the selected text"));
    connect(centerAct, SIGNAL(triggered()), this, SLOT(center()));

    alignmentGroup = new QActionGroup(this);
    alignmentGroup->addAction(leftAlignAct);
    alignmentGroup->addAction(rightAlignAct);
    alignmentGroup->addAction(justifyAct);
    alignmentGroup->addAction(centerAct);
    leftAlignAct->setChecked(true);*/
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(loadAct);
    fileMenu->addSeparator();
    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveAsAct);
    fileMenu->addSeparator();
    fileMenu->addAction(savePaletteAct);
    fileMenu->addAction(loadPaletteAct);
    fileMenu->addSeparator();
    fileMenu->addAction(xportAct);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAct);


    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(undoAct);
    editMenu->addAction(redoAct);
    editMenu->addSeparator();
    editMenu->addAction(cutAct);
    editMenu->addAction(copyAct);
    editMenu->addAction(pasteAct);
    editMenu->addAction(fullSelectionAct);
    editMenu->addAction(blendToolAct);
    editMenu->addAction(copyCurrentLayerAct);
    editMenu->addSeparator();
    editMenu->addAction(resetAllParametersAct);
    editMenu->addAction(cropInputAct);
    editMenu->addAction(cropOutputAct);

    viewMenu = menuBar()->addMenu(tr("&View"));
    viewMenu->addAction(zoomInAct);
    viewMenu->addAction(zoomOutAct);

    viewMenu->addAction(fitWindowAct);
    viewMenu->addAction(fullscreenAct);
   // editMenu->addSeparator();
   // viewMenu->addAction(toggleSectionsAct);
   // viewMenu->addAction(showLayerManagerAct);
   // viewMenu->addAction(inputAct);
/*
    viewMenu->addAction(aboutAct);
    viewMenu->addAction(aboutQtAct);

    formatMenu = editMenu->addMenu(tr("&Format"));
    formatMenu->addAction(boldAct);
    formatMenu->addAction(italicAct);
    formatMenu->addSeparator()->setText(tr("Alignment"));
    formatMenu->addAction(leftAlignAct);
    formatMenu->addAction(rightAlignAct);
    formatMenu->addAction(justifyAct);
    formatMenu->addAction(centerAct);
    formatMenu->addSeparator();
    formatMenu->addAction(setLineSpacingAct);
    formatMenu->addAction(setParagraphSpacingAct);*/
}
