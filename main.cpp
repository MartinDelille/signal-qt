#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "ContactModel.h"
#include "ConversationModel.h"

int main(int argc, char *argv[]) {
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

	QGuiApplication app(argc, argv);

	qmlRegisterType<ContactModel>("org.signal", 1, 0, "ContactModel");
	qmlRegisterType<ConversationModel>("org.signal", 1, 0, "ConversationModel");

	QQmlApplicationEngine engine;
	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
	if (engine.rootObjects().isEmpty()) {
		return -1;
	}

	return app.exec();
}
