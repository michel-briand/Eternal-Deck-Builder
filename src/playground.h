#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <QDir>
#include <QMenu>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsWidget>
#include <QGraphicsPixmapItem>
#include <QGraphicsLayoutItem>
#include <QGraphicsLinearLayout>
#include <QGraphicsSceneDragDropEvent>
#include <QGraphicsSceneContextMenuEvent>

#include "game_element.h"

// /////////////////////////////////////////////////////////////////////////////////////////
// Custom graphic view that show the playground
class PGraphicsView : public QGraphicsView
{
   Q_OBJECT

public:
    explicit PGraphicsView(QWidget* parent=0);

protected:
    void wheelEvent(QWheelEvent *event);
    void scaleView(qreal scaleFactor);
    void contextMenuEvent(QContextMenuEvent *event);
    void dragEnterEvent(QDragEnterEvent * event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dragLeaveEvent(QDragLeaveEvent * event);
    void dropEvent(QDropEvent * event);

private slots:
    void ContextMenuSlot(QAction *ActionChoisie);
};


// ///////////////////////////////////////////////////////////////////////////////////////////
// Custom graphic scene who host the game
class PGraphicsScene : public QGraphicsScene
{
   Q_OBJECT

public:
    explicit PGraphicsScene(QWidget* parent=0);

protected:
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
    void dragMoveEvent(QGraphicsSceneDragDropEvent *event);
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *event);
    void dropEvent(QGraphicsSceneDragDropEvent *event);
};

// /////////////////////////////////////////////////////////////////////////////////////////
// Custom graphic view that show the hand
class HandGraphicsView : public QGraphicsView
{
   Q_OBJECT

public:
    explicit HandGraphicsView(QWidget* parent=0);

protected:
    void wheelEvent(QWheelEvent *event);
    void resizeEvent(QResizeEvent * event);
    void scaleView(qreal scaleFactor);
    void contextMenuEvent(QContextMenuEvent *event);
    void dragEnterEvent(QDragEnterEvent * event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dragLeaveEvent(QDragLeaveEvent * event);
    void dropEvent(QDropEvent * event);

private slots:
    void ContextMenuSlot(QAction *ActionChoisie);
};

// ///////////////////////////////////////////////////////////////////////////////////////////
// Custom graphic scene who host the Hand
class HandGraphicsScene : public QGraphicsScene
{
   Q_OBJECT

public:
    explicit HandGraphicsScene(QWidget* parent=0);
    void setSource(Deck *d);

public slots:
    void AddCardtoHand(Carte *C);

protected:
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
    void dragMoveEvent(QGraphicsSceneDragDropEvent *event);
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *event);
    void dropEvent(QGraphicsSceneDragDropEvent *event);

private:
    Deck *currentDeck;
    QGraphicsWidget *graphicsContainer;
};

// /////////////////////////////////////////////////////////////////////////////////////////
// A card in the graphic scene
class PGraphicsPixmapItem : public QObject, public QGraphicsPixmapItem, public QGraphicsLayoutItem
{
   Q_OBJECT

public:
    explicit PGraphicsPixmapItem(Carte *C, QGraphicsItem* parent=0);
    void setTaped(bool T = true);
    void setTurned(bool T = true);
    bool isTaped();
    bool isTurned();
    CardType getCardType();
    void setGeometry(const QRectF &rect);
    void updateGeometry();

protected:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
    void dragMoveEvent(QGraphicsSceneDragDropEvent *event);
    void dragLeaveEvent(QGraphicsSceneDragDropEvent * event);
    void dropEvent(QGraphicsSceneDragDropEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
    void hoverMoveEvent(QGraphicsSceneHoverEvent * event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);
    QSizeF sizeHint(Qt::SizeHint which, const QSizeF &constraint) const;

private:
    bool Taped;
    bool Turned;
    QString FacePixmapPath;
    QString TailPixmapPath;
    Carte *card;
    PathProvider path_list;
    QPointF origin;
    int radius;
    double mySpreadingAngle;
    qint8 i;

private slots:
    void ContextMenuSlot(QAction *ActionChoisie);
};

// /////////////////////////////////////////////////////////////////////////////////////////
// A blood item in the graphic scene
class PGraphicsBlood : public QObject, public QGraphicsPixmapItem
{
   Q_OBJECT

public:
    PGraphicsBlood();

private:

};

#endif // PLAYGROUND_H
