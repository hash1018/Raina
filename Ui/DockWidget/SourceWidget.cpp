
#include "SourceWidget.h"
#include <qpainter.h>
#include <./ui_SourceWidget.h>
#include "../NotifyEvent/NotifyEvent.h"
#include "../Base/Scene.h"
#include "../Base/Source.h"
#include "../Chain/Request.h"

SourceWidget::SourceWidget(QWidget* parent, Chain* chain)
    :QWidget(parent), Chain(chain), ui(new Ui::SourceWidget), scene(nullptr) {

    ui->setupUi(this);

    connect(ui->addButton, &QPushButton::clicked, this, &SourceWidget::addButtonClicked);
    connect(ui->removeButton, &QPushButton::clicked, this, &SourceWidget::removeButtonClicked);
    connect(ui->moveDownButton, &QPushButton::clicked, this, &SourceWidget::moveDownButtonClicked);
    connect(ui->moveUpButton, &QPushButton::clicked, this, &SourceWidget::moveUpButtonClicked);

}

SourceWidget::~SourceWidget() {

	delete ui;
}

void SourceWidget::updateNotifyEvent(NotifyEvent* event) {

   
	if (event->getEventType() == NotifyEvent::EventType::CurrentSceneChanged) {
        
        this->scene = dynamic_cast<CurrentSceneChangedEvent*>(event)->getScene();

		this->updateList();
	}
    else if (event->getEventType() == NotifyEvent::EventType::CurrentSourceChanged) {
    
        this->scene = dynamic_cast<CurrentSourceChangedEvent*>(event)->getScene();
        this->updateList();

        const Source* source = dynamic_cast<CurrentSourceChangedEvent*>(event)->getSource();

        if (source != nullptr) {
        
            disconnect(ui->listWidget, &QListWidget::currentRowChanged, this, &SourceWidget::listCurrentRowChanged);

            int index = this->scene->indexOf(const_cast<Source*>(source));
            ui->listWidget->setCurrentRow(index);

            connect(ui->listWidget, &QListWidget::currentRowChanged, this, &SourceWidget::listCurrentRowChanged);
        }
    }
    

}


void SourceWidget::paintEvent(QPaintEvent* event) {

	QPainter painter(this);

    painter.fillRect(this->rect(), QColor("#535353"));
}

void SourceWidget::addButtonClicked() {

    if (this->scene == nullptr)
        return;

    RequestChangeSource request(const_cast<Scene*>(this->scene), "123");
    this->request(&request);
}

void SourceWidget::removeButtonClicked() {

    if (this->scene == nullptr)
        return;

    int index = ui->listWidget->currentRow();

    if (index == -1)
        return;

    RequestChangeSource request(const_cast<Scene*>(this->scene), this->scene->at(index),
        RequestChangeSource::ChangeType::Remove);
    this->request(&request);
}

void SourceWidget::moveUpButtonClicked() {
    
    int index = ui->listWidget->currentRow();
    if (index == -1)
        return;

    if (index == 0)
        return;

    RequestChangeSource request(const_cast<Scene*>(this->scene), this->scene->at(index),
        RequestChangeSource::ChangeType::MoveUp);
    this->request(&request);
}

void SourceWidget::moveDownButtonClicked() {

    
    int index = ui->listWidget->currentRow();
    if (index == -1)
        return;

    if (index == ui->listWidget->count() - 1)
        return;

    RequestChangeSource request(const_cast<Scene*>(this->scene), this->scene->at(index),
        RequestChangeSource::ChangeType::MoveDown);
    this->request(&request);
}

void SourceWidget::listCurrentRowChanged(int row) {

    if (row == -1) {
        RequestChangeSource request(const_cast<Scene*>(this->scene), nullptr, RequestChangeSource::ChangeType::CurrentSource);
        this->request(&request);
    }
    else {
    
        RequestChangeSource request(const_cast<Scene*>(this->scene), this->scene->at(row), 
            RequestChangeSource::ChangeType::CurrentSource);
        this->request(&request);
    }

}

void SourceWidget::updateList() {

    disconnect(ui->listWidget, &QListWidget::currentRowChanged, this, &SourceWidget::listCurrentRowChanged);

	ui->listWidget->clear();

	if (this->scene == nullptr)
		return;

    for(int i=0; i<this->scene->size(); i++)
        ui->listWidget->addItem(this->scene->at(i)->getName());

    connect(ui->listWidget, &QListWidget::currentRowChanged, this, &SourceWidget::listCurrentRowChanged);
}
