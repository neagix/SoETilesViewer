#include "finddialog.h"
#include "ui_finddialog.h"
#include <QPushButton>

FindDialog::FindDialog(QWidget *parent, const QString& text, QTextDocument::FindFlags flags, bool regex) :
    QDialog(parent, Qt::WindowSystemMenuHint | Qt::WindowTitleHint),
    ui(new Ui::FindDialog)
{
    ui->setupUi(this);
    setFixedSize(width(), height()); // hide maximize button on linux
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Find");
    ui->lineEdit->setText(text);
    ui->lineEdit->setSelection(0, ui->lineEdit->text().length());
    ui->chkRegex->setChecked(regex);
    _flags = flags;
    ui->chkCaseSensitive->setChecked(flags & QTextDocument::FindCaseSensitively);

    ui->lineEdit->setFocus();
}

FindDialog::~FindDialog()
{
    delete ui;
}

QString FindDialog::text() const
{
    return ui->lineEdit->text();
}

QTextDocument::FindFlags FindDialog::flags() const
{
    if (ui->chkCaseSensitive->isChecked())
        return _flags|QTextDocument::FindCaseSensitively;
    else
        return _flags&(~QTextDocument::FindCaseSensitively);
}

bool FindDialog::regex() const
{
    return ui->chkRegex->isChecked();
}
