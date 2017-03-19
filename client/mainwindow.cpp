#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("untitled - Superlime"));

    fontSize = 15;
    setupListView();
    setupTreeView();
    setupEditor();
    setupTab();

    connection = new Connection(this);
    serverAddress = defaultServerAddress;
    serverPort = defaultServerPort;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupTab()
{
    outputTab = new QTabWidget(this);
    ui->splitter_2->addWidget(outputTab);

    browserOutput = new QTextEdit(this);
    browserErrMsg = new QTextEdit(this);
    browserOutput->setReadOnly(true);
    browserErrMsg->setReadOnly(true);

    outputTab->addTab(browserOutput, "Output");
    outputTab->addTab(browserErrMsg, "Errors");
    ui->splitter_2->setStretchFactor(0,3);
    ui->splitter_2->setStretchFactor(1,1);

    QFont font;
    font.setFamily("Consolas");
    font.setFixedPitch(true);
    font.setPointSize(fontSize);
    browserOutput->setFont(font);
    browserErrMsg->setFont(font);
}

void MainWindow::setupListView()
{
    ui->splitter_3->setStretchFactor(0, 2);
    ui->splitter_3->setStretchFactor(1, 5);
}

void MainWindow::setupTreeView()
{
    model = new QDirModel(this);
    model->setReadOnly(true);
    model->setSorting(QDir::DirsFirst | QDir::IgnoreCase | QDir::Name);

    ui->treeView->setModel(model);

    QStringList filters;
    filters.append("*.java");
    model->setFilter(QDir::AllDirs | QDir::AllEntries |QDir::NoDotAndDotDot);
    model->setNameFilters(filters);

    QDir dir;
    QString pwd = dir.currentPath();
    QModelIndex index = model->index(pwd);
    ui->treeView->expand(index);
    ui->treeView->scrollTo(index);
    ui->treeView->setCurrentIndex(index);
    ui->treeView->resizeColumnToContents(0);
}

void MainWindow::setupEditor()
{
    saved = true;
    QFont font;
    font.setFamily("Consolas");
    font.setFixedPitch(true);
    font.setPointSize(fontSize);

    codeEditor = new CodeEditor(this);
    ui->splitter_2->addWidget(codeEditor);

    codeEditor->setFont(font);
    codeEditor->setTabStopWidth(4 * codeEditor->fontMetrics().width(' '));

    highlighter = new Highlighter(codeEditor->document());

    connect(codeEditor->document(),
            SIGNAL(contentsChange(int,int,int)), this, SLOT(isTextChanged()));
}

void MainWindow::setServerSetting(QString newAddress, QString newPort)
{
    serverAddress = newAddress;
    serverPort = newPort;
}

void MainWindow::isTextChanged()
{
    saved = false;
}

void MainWindow::closeEvent (QCloseEvent *event)
{
    if (close_helper())
    {
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

void MainWindow::on_action_New_File_triggered()
{
    if (saved)
    {
        mFilename = "";
        codeEditor->setPlainText("");
        setWindowTitle(tr("untitled - Superlime"));
    }
    else
    {
        on_actionClose_triggered();
    }
    saved = true;

    ui->statusBar->showMessage("Open new file.", 3000);
}

void MainWindow::on_action_Copy_triggered()
{
    codeEditor->copy();

    ui->statusBar->showMessage("Contents copied.", 3000);
}

void MainWindow::on_action_Paste_triggered()
{
    codeEditor->paste();

    ui->statusBar->showMessage("Contents pasted.", 3000);
}

void MainWindow::on_action_Cut_triggered()
{
    codeEditor->cut();

    ui->statusBar->showMessage("Contents cut.", 3000);
}

void MainWindow::on_action_Undo_triggered()
{
    codeEditor->undo();

    ui->statusBar->showMessage("Undo last command.", 3000);
}

void MainWindow::on_action_Redo_triggered()
{
    codeEditor->redo();

    ui->statusBar->showMessage("Redo last command.", 3000);
}

void MainWindow::on_actionOpen_File_triggered()
{
    if (!close_helper())
    {
        return;
    }
    QString file = QFileDialog::getOpenFileName(this, "Open a file");

    if (!file.isEmpty())
    {
        QFile sFile(file);
        if (sFile.open(QFile::ReadOnly | QFile::Text))
        {
            mFilename = file;
            QTextStream in(&sFile);
            QString text = in.readAll();
            sFile.close();

            codeEditor->setPlainText(text);

            QStringList paths = file.split("/");
            QString actualName = paths.at(paths.size()-1);
            setWindowTitle(actualName + tr(" - Superlime"));
        }
    }
    saved = true;
    ui->statusBar->showMessage("Opened " + mFilename + ".", 3000);
}

void MainWindow::on_actionSave_triggered()
{
    if (mFilename.isEmpty())
    {
        on_actionSave_As_triggered();
    }
    else
    {
        QFile sFile(mFilename);
        if (sFile.open(QFile::WriteOnly | QFile::Text))
        {
            QTextStream out(&sFile);

            out << codeEditor->toPlainText();

            sFile.flush();
            sFile.close();
        }
        ui->statusBar->showMessage("Saved " + mFilename + ".", 3000);
    }
    saved = true;
}

void MainWindow::on_actionSave_As_triggered()
{
    QString file = QFileDialog::getSaveFileName(this, "Save a file");

    if (!file.isEmpty())
    {
        mFilename = file;

        QStringList paths = file.split("/");
        QString actualName = paths.at(paths.size()-1);
        setWindowTitle(actualName + tr(" - Superlime"));
        on_actionSave_triggered();
    }
    saved = true;
    ui->statusBar->showMessage("Saved " + mFilename + ".", 3000);
}

void MainWindow::on_treeView_doubleClicked(const QModelIndex &index)
{
    QString file = model->fileInfo(index).absoluteFilePath();

    if (!file.isEmpty())
    {
        QFile sFile(file);
        if (sFile.open(QFile::ReadOnly | QFile::Text))
        {
            mFilename = file;
            QTextStream in(&sFile);
            QString text = in.readAll();
            sFile.close();

            QStringList paths = file.split("/");
            QString actualName = paths.at(paths.size()-1);
            setWindowTitle(actualName + tr(" - Superlime"));
            codeEditor->setPlainText(text);
        }
    }
}

bool MainWindow::close_helper()
{
    bool doExit = true;

    if(!saved)
    {
         QMessageBox msgBox(QMessageBox::Warning, "","" );
         msgBox.setText("The document has been modified.");
         msgBox.setInformativeText("Do you want to save your changes?");
         msgBox.setStandardButtons(
                     QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
         msgBox.setDefaultButton(QMessageBox::Save);
         int ret = msgBox.exec();
         switch (ret)
         {
            case QMessageBox::Save:
                on_actionSave_triggered();
                break;
            case QMessageBox::Discard:
                break;
            case QMessageBox::Cancel:
                doExit = false;
                break;
          }
     }
    return doExit;
}

void MainWindow::on_actionClose_triggered()
{
    if (close_helper())
    {
        ui->statusBar->showMessage("Closed " + mFilename + ".", 3000);
        mFilename = "";
        codeEditor->setPlainText("");
        setWindowTitle(tr("untitled - Superlime"));
        saved = true;
    }
}

void MainWindow::on_actionExit_triggered()
{
    if (close_helper())
    {
        exit(0);
    }
}

void MainWindow::on_actionZoom_In_triggered()
{
    if (fontSize == 30)
    {
        return;
    }
    fontSize++;
    QFont font;
    font.setFamily("Consolas");
    font.setFixedPitch(true);
    font.setPointSize(fontSize);

    codeEditor->setFont(font);
    browserOutput->setFont(font);
    browserErrMsg->setFont(font);
}

void MainWindow::on_actionZoom_Out_triggered()
{
    if (fontSize == 7) {
        return;
    }
    fontSize--;
    QFont font;
    font.setFamily("Consolas");
    font.setFixedPitch(true);
    font.setPointSize(fontSize);

    codeEditor->setFont(font);
    browserOutput->setFont(font);
    browserErrMsg->setFont(font);
}

void MainWindow::on_action_Select_All_triggered()
{
    codeEditor->selectAll();
}

void MainWindow::on_actionBuild_triggered()
{
    on_actionSave_triggered();

    ui->statusBar->showMessage("Compiling " + mFilename + "...", 3000);
    if (mFilename.length() > 0)
    {
        connection->SetFileName(mFilename);
        connection->SetServerAddress(serverAddress, serverPort);

        connection->StartConnection(browserErrMsg, nullptr);
        ui->statusBar->showMessage("Finished compiling " + mFilename, 3000);
    }
}

void MainWindow::on_actionRun_triggered()
{
    on_actionSave_triggered();

    ui->statusBar->showMessage("Running " + mFilename + "...", 3000);
    if (mFilename.length() > 0)
    {
        connection->SetFileName(mFilename);
        connection->SetServerAddress(serverAddress, serverPort);

        connection->StartConnection(browserErrMsg, browserOutput);

        ui->statusBar->showMessage("Finished running " + mFilename, 3000);
    }
}

void MainWindow::on_actionServer_Settings_triggered()
{
    SsettingDialog *sDialog = new SsettingDialog(serverAddress, serverPort, this);
    connect(sDialog, SIGNAL(paramsChanged(QString, QString)), this, SLOT(setServerSetting(QString, QString)));
    sDialog->setDefault(defaultServerAddress, defaultServerPort);
    sDialog->setModal(true);
    sDialog->exec();
}
