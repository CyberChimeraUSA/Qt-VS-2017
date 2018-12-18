#include "VideoQTApp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	VideoQTApp w;
	w.show();
	return a.exec();
}
