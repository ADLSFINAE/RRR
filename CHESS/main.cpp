#include <QApplication>
#include "CORE/customscene.h"
#include "CORE/customview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CustomScene* scene = new CustomScene();
    CustomView* view = new CustomView(scene);
    view->show();
    return a.exec();
}
