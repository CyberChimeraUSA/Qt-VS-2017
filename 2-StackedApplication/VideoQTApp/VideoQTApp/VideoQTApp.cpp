#include "VideoQTApp.h"

VideoQTApp::VideoQTApp(QWidget *parent)
	: QMainWindow(parent)
{
	stack = new QStackedWidget();
	stack->addWidget(new Homewidget(stack));
	setCentralWidget(stack);
}


Homewidget::Homewidget(QStackedWidget* stackedWidget, QWidget *parent)
	: QBaseWidget(parent)
{
	setFixedSize(400, 300);
	widget_base_recon = new QPushButton("Home", this);
	widget_base_recon->setFixedSize(75, 75);


	BaseStackwidget = stackedWidget;

	QObject::connect(widget_base_recon, SIGNAL(clicked()), this, SLOT(CreateReconBasewidget()));

	//layout = new QVBoxLayout();
	layout = new QGridLayout();
	layout->addWidget(widget_base_recon, 0, 0);
	layout->setSpacing(0);
	layout->setAlignment(Qt::AlignLeft);
	setLayout(layout);
}


//Create the first widget
void Homewidget::CreateReconBasewidget()
{
	ReconBasewidget *first = new ReconBasewidget(BaseStackwidget);
	BaseStackwidget->addWidget(first);
	BaseStackwidget->setCurrentWidget(first);
	delete widget_base_recon;
}


ReconBasewidget::ReconBasewidget(QStackedWidget* stackedWidget, QWidget *parent)
	:QBaseWidget(parent)
{
	BaseStackwidget = stackedWidget;

	home_button = new QPushButton("Return Home");
	QObject::connect(home_button, SIGNAL(clicked()), this, SLOT(homeWidget()));
	home_button->setFixedSize(40, 40);
	home_button->move(200, 200);

	layout = new QGridLayout();
	layout->addWidget(home_button);
	layout->setSpacing(0);
	layout->setAlignment(Qt::AlignLeft);
	setLayout(layout);
}


void ReconBasewidget::homeWidget()
{
	Homewidget *home = new Homewidget(BaseStackwidget);
	BaseStackwidget->addWidget(home);
	BaseStackwidget->setCurrentWidget(home);

}