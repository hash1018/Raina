
#ifndef _SOURCEWIDGET_H
#define _SOURCEWIDGET_H

#include <qwidget.h>

QT_BEGIN_NAMESPACE
namespace Ui { class SourceWidget; }
QT_END_NAMESPACE

class SourceWidget : public QWidget {

private:
	Ui::SourceWidget* ui;

public:
	SourceWidget(QWidget* parent = nullptr);
	~SourceWidget();

protected:
	virtual void paintEvent(QPaintEvent* event);

private slots:
	void addButtonClicked();
	void removeButtonClicked();
	void moveUpButtonClicked();
	void moveDownButtonClicked();
};

#endif //_SOURCEWIDGET_H