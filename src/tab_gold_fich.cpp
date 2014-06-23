#include <QFileDialog>
#include <QDebug>

#include "tab_gold_fich.h"
#include "ui_tab_gold_fich.h"

tab_gold_fich::tab_gold_fich(QWidget *parent) : QScrollArea(parent), ui(new Ui::tab_gold_fich)
{
    ui->setupUi(this);

    // allocation/setup of custom widgets
    currentDeck = new Deck(this);
    Bourse = new BloodBank(this);
    testHud = new Hud(this);
    LibraryWidget = new Library(this);
    CryptWidget = new Crypt(this);
    LibraryWidget->setSource(currentDeck);
    CryptWidget->setSource(currentDeck);

    // insertion into layouts
    ui->TopBoard->layout()->addWidget(testHud);
    ui->SideBoard->layout()->addWidget(Bourse);
    ui->SideBoard->layout()->addWidget(LibraryWidget);
    ui->SideBoard->layout()->addWidget(CryptWidget);

    // setup the scene
    Scenedejeu = new PGraphicsScene(this);
    ui->TabledeJeu->setScene(Scenedejeu);

    connect( testHud, SIGNAL( request_deck_load() ), this, SLOT( load_deck() ) );
    connect( testHud, SIGNAL( request_drawing() ), this, SLOT( restart_game() ) );
    connect( testHud, SIGNAL( request_game_restart() ), this, SLOT( test_draw() ) );
}

void tab_gold_fich::initialisation(DeckTranslator *DT)
{
    if ( ! path_list.initPaths() )
        qDebug() << "ca a chier !";

    PathCartes = path_list.getCardPath();
    PathDeck = path_list.getDeckPath();
    translator = DT;
}

tab_gold_fich::~tab_gold_fich()
{
    delete ui;
}

void tab_gold_fich::load_deck()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Deck"), PathDeck, tr("Deck Files (*.edb)"));
    if ( fileName.isEmpty() )
        return;

    translator->EdbToDeck(fileName, currentDeck);
}

void tab_gold_fich::test_draw()
{
    Carte* carte_pioched = currentDeck->drawLib();
    if ( !carte_pioched )
        {
        qDebug() << "la biblio est vide !";
        return;
        }

    PGraphicsPixmapItem* CardItem  = new PGraphicsPixmapItem(carte_pioched);
    CardItem->setPos(400, 600);
    Scenedejeu->addItem(CardItem);
}

void tab_gold_fich::restart_game()
{

}

