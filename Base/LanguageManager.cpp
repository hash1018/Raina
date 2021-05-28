
#include "LanguageManager.h"
#include <qfile.h>
#include <qsettings.h>
#include <qdir.h>
#include <qdebug.h>

LanguageManager::LanguageManager()
	:settings(nullptr), language(Language::Korean), type(Type::Ui) {

}

LanguageManager::~LanguageManager() {

	if (this->settings != nullptr)
		delete this->settings;
}


bool LanguageManager::setLanguage(Language language) {

#ifdef Q_OS_WIN
    QString filePath = QDir::currentPath() + "/lan/" + LanguageManager::convertDirectoryName(language);
#endif 

#ifdef Q_OS_MAC
    QString filePath=QDir::currentPath() + "/lan/" + LanguageManager::convertDirectoryName(language);
    qDebug() << filePath;
#endif
	if (!QFile(filePath).exists()) {

		Q_ASSERT_X(false, "LanguageManager::setLanguage", "following language donsn't support.");
		return false;
	}

	this->language = language;

	if (this->settings != nullptr) {

		delete this->settings;
		this->settings = nullptr;
	}

	return true;
}


QString LanguageManager::getValue(const Type& type, const QString& key) {

	if (this->type != type) {
		if (this->settings != nullptr) {
			delete this->settings;
			this->settings = nullptr;
		}

		this->type = type;
	}


	if (this->settings == nullptr) {

#ifdef Q_OS_WIN
        QString filePath = QDir::currentPath() + "/lan/" + this->convertDirectoryName(this->language) +
			"/" + this->convertFileName(type);
#endif 

#ifdef Q_OS_MAC
        QString filePath = QDir::currentPath() + "/lan/" + this->convertDirectoryName(this->language) +
            "/" + this->convertFileName(type);

        qDebug() << filePath;
#endif
		if (!QFile(filePath).exists())
            Q_ASSERT_X(false, "LanguageManager::LanguageManager", "invalid filePath");

		this->settings = new QSettings(filePath, QSettings::IniFormat);
		this->settings->setIniCodec("UTF-8");

	}
	return this->settings->value(key).toString();
}


QString LanguageManager::convertDirectoryName(Language language) {

	if (language == Language::English)
		return QString("English");
	else if (language == Language::Korean)
		return QString("Korean");

	return QString("Korean");
}

QString LanguageManager::convertFileName(Type type) {

	if (type == Type::Ui)
		return QString("ui.ini");
	else if (type == Type::Message)
		return QString("message.ini");

	return QString("ui.ini");
}
