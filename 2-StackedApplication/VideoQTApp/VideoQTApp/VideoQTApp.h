#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_VideoQTApp.h"
#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QStackedWidget>
#include <QStackedLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QtGui>
#include <qpushbutton.h>
#include <qboxlayout.h>
#include <qlabel.h>
#include <QRadioButton>

class QBaseWidget;

class VideoQTApp : public QMainWindow
{
	Q_OBJECT

  public:
	VideoQTApp(QWidget *parent = Q_NULLPTR);

  private:
	Ui::VideoQTAppClass ui;
	QStackedWidget *stack;
};

class QBaseWidget : public QWidget
{
	Q_OBJECT

public:
	QBaseWidget(QWidget *parent = 0)
	{

	}

protected:
	QStackedWidget*     BaseStackwidget;
};


class Homewidget : public QBaseWidget
{
	Q_OBJECT
public:
	Homewidget(QStackedWidget* stackedWidget, QWidget *parent = 0);

public slots:
	void CreateReconBasewidget();

private:
	QPushButton *widget_base_recon;
	QGridLayout *layout;

};

class ReconBasewidget : public QBaseWidget
{
	Q_OBJECT

public:
	ReconBasewidget(QStackedWidget* stackedWidget, QWidget *parent = 0);

public slots:
	void homeWidget();
private:
	QPushButton *home_button;
	QGridLayout *layout;
};


