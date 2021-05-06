
#ifndef _AUDIOMIXERWIDGET_H
#define _AUDIOMIXERWIDGET_H

#include <qwidget.h>

class AudioMixerWidget : public QWidget {

public:
	AudioMixerWidget(QWidget* parent = nullptr);
	~AudioMixerWidget();

protected:
	virtual void paintEvent(QPaintEvent* event);

};

#endif //_AUDIOMIXERWIDGET_H