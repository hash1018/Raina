
#include "AudioMixerWidget.h"
#include <qpainter.h>

AudioMixerWidget::AudioMixerWidget(QWidget* parent)
	:QWidget(parent) {

}

AudioMixerWidget::~AudioMixerWidget() {

}

void AudioMixerWidget::paintEvent(QPaintEvent* event) {

	QPainter painter(this);
	painter.fillRect(this->rect(), QColor(22, 255, 255));
}