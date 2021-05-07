
#ifndef _AUDIOMIXERWIDGET_H
#define _AUDIOMIXERWIDGET_H

#include <qwidget.h>

QT_BEGIN_NAMESPACE
namespace Ui { class AudioMixerWidget; }
QT_END_NAMESPACE

class AudioMixerWidget : public QWidget {

private:
	Ui::AudioMixerWidget *ui;

public:
	AudioMixerWidget(QWidget* parent = nullptr);
	~AudioMixerWidget();

protected:
	virtual void paintEvent(QPaintEvent* event);

};

#endif //_AUDIOMIXERWIDGET_H