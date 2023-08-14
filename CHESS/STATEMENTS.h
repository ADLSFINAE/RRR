#ifndef STATEMENTS_H
#define STATEMENTS_H
#include <QPixmap>
#include <QRectF>
#include <QSize>
#include <QVector>
#include "BOARD/block.h"

namespace GlobVal{
const static int pixelX = 80;
const static int pixelY = 80;

const static int realX = 8;
const static int realY = 8;

const static int FigureCenterX = -pixelX / 2;
const static int FigureCenterY = -pixelY / 2;

const static int PixelSceneLongX = pixelX * realX;
const static int PixelSceneLongY = pixelY * realY;

const static int ViewLongX = PixelSceneLongX + realX;
const static int ViewLongY = PixelSceneLongY + realY;

const static QRectF blockSizeRect(0, 0, pixelX, pixelY);
const static QSize viewSizeSquare(ViewLongX, ViewLongY);
const static QRectF sceneSizeRect(0, 0, PixelSceneLongX, PixelSceneLongY);
const static QRectF boardSizeRect(0, 0, PixelSceneLongX, PixelSceneLongX);

//black figures .png defs and way
const QString pngBlackKing = ":/chesscom/blackFigures/bK.png";
const QString pngBlackQueen = ":/chesscom/blackFigures/bQ.png";
const QString pngBlackRook = ":/chesscom/blackFigures/bR.png";
const QString pngBlackHorse = ":/chesscom/blackFigures/bN.png";
const QString pngBlackElephant = ":/chesscom/blackFigures/bB.png";
const QString pngBlackPawn = ":/chesscom/blackFigures/bP.png";

//white figures .png defs and way
const QString pngWhiteKing = ":/chesscom/whiteFigures/wK.png";
const QString pngWhiteQueen = ":/chesscom/whiteFigures/wQ.png";
const QString pngWhiteRook = ":/chesscom/whiteFigures/wR.png";
const QString pngWhiteHorse = ":/chesscom/whiteFigures/wN.png";
const QString pngWhiteElephant = ":/chesscom/whiteFigures/wB.png";
const QString pngWhitePawn = ":/chesscom/whiteFigures/wP.png";

const QVector<QString> pngBlackFiguresVecForChangePawnWidget = {
    pngBlackQueen,
    pngBlackRook,
    pngBlackHorse,
    pngBlackElephant,
};


const QVector<QString> pngWhiteFiguresVecForChangePawnWidget = {
    pngWhiteQueen,
    pngWhiteRook,
    pngWhiteHorse,
    pngWhiteElephant,
};

};
#endif // STATEMENTS_H
