#include "tab_deck_tuning.h"
#include "ui_tab_deck_tuning.h"

tab_deck_tuning::tab_deck_tuning(QWidget *parent) :
    QScrollArea(parent),
    ui(new Ui::tab_deck_tuning)
{
    ui->setupUi(this);
}

tab_deck_tuning::~tab_deck_tuning()
{
    delete ui;
}
