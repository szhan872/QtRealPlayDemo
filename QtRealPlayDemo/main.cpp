#include "qtrealplaydemo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtRealPlayDemo w;
	w.show();
	return a.exec();
}
