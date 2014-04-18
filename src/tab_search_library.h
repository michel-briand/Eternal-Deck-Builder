#ifndef TAB_SEARCH_LIBRARY_H
#define TAB_SEARCH_LIBRARY_H

#include <QScrollArea>
#include <QCompleter>

#include "Global.h"
#include "pitemview.h"

namespace Ui {
    class tab_search_library;
}

class tab_search_library : public QScrollArea
{
    Q_OBJECT

public:
    explicit tab_search_library(QWidget *parent = 0);
    ~tab_search_library();
    PSqlTableModel *ModelReponseCarte;

protected:
    void keyPressEvent(QKeyEvent *);

private:
    Ui::tab_search_library *ui;
    QCompleter *Completer;
    QPixmap DosCarte;

private slots:
    void AdapteSousType();
    void ClearForm();
    void RechercheCarte();
    void request_affichage(QModelIndex Idx);
    void AfficheImageCarte(QString CardName);

signals:
    void new_card_selected(QString);
    void card_picture_missing(QString);
};

#endif // TAB_SEARCH_LIBRARY_H
