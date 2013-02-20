#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_StartChildProcess_clicked()
{
    char CommandLine[] = "calc.exe"; // can`t write string as function parameter??? due to it will be as literal???
        // init structure StartupInfo where info for process will be kept
        STARTUPINFOA st = {sizeof(st)};
        PROCESS_INFORMATION info; // contains info about process
        bool success = false;
        success = CreateProcessA (//BOOL CreateProcess(CreateProcess - macros, CreateProcessA - single char, CreateProcessW - unicode
    0,//LPCTSTR lpApplicationName,	//имя исполняемого файла или 0, если имя указано в командной строке
    CommandLine,//LPTSTR lpCommandLine,			//командная строка LP - for long pointer
    0,//LPSECURITY_ATTRIBUTES lpProcessAttributes, //атрибуты безопасности создаваемого процесса или 0
    0,//LPSECURITY_ATTRIBUTES lpThreadAttributes, //атрибуты безопасности потока или 0
    0,//BOOL bInheritHandles,	//наследует ли порождаемый процесс дескрипторы порождающего
    0,//DWORD dwCreationFlags,	// параметры создания процесса: задание приоритета и состояния выполнения. Если 0, приоритет создаваемого процесса по умолчанию NORMAL_PRIORITY_CLASS и первичный поток начинает выполняться
    0,//LPVOID lpEnvironment, // значения переменных окружения или 0, если наследуется окружение порождающего процесса
    0,//LPCTSTR lpCurrentDirectory // текущий каталог или 0, если используется текущий каталог порождающего
    &st,//LPSTARTUPINFO lpStartupInfo , //задаваемая информация о запускаемом процессе
    &info);//LPPROCESS_INFORMATION lpProcessInformation// сюда возвращается функцией информация о порожденном процессе
    //);
        // As we aren`t going to work with created process - close handles (they can be inherited???)
        if (success)
        {
            CloseHandle(info.hProcess);
            CloseHandle(info.hThread);
        }
        // if process creation has failed - notify user
        else
            QMessageBox::warning(this,"Process creation error","While trying to create child process, error was encountered. Check CreateProcess syntax or name of process you tried to execute!");

}
