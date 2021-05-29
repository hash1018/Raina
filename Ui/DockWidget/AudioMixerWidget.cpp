
#include "AudioMixerWidget.h"
#include <qpainter.h>
#include <./ui_AudioMixerWidget.h>

AudioMixerWidget::AudioMixerWidget(QWidget* parent)
	:QWidget(parent), ui(new Ui::AudioMixerWidget) {

	ui->setupUi(this);
}

AudioMixerWidget::~AudioMixerWidget() {

	delete ui;
}

void AudioMixerWidget::paintEvent(QPaintEvent* event) {

	QPainter painter(this);

	painter.fillRect(this->rect(), QColor("#535353"));
}