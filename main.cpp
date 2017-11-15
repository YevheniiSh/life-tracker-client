#include <iostream>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <qxtglobalshortcut.h>
#include "KeyPress.h"

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    QTextStream out(stdout);
    QTextStream err(stderr);

    const QKeySequence shortcut(QKeySequence::Undo);
    const QxtGlobalShortcut globalShortcut(shortcut);

    if (!globalShortcut.isValid()) {
        err << QString("Error: Failed to set shortcut %1")
                .arg(shortcut.toString()) << endl;
        return 1;
    }

    out << QString("Press shortcut %1 (or CTRL+C to exit)").arg(shortcut.toString()) << endl;

    QObject::connect(
            &globalShortcut, &QxtGlobalShortcut::activated, &globalShortcut,
            [&] {
                out << QLatin1String("Shortcut pressed!") << endl;
                QApplication::quit();
            });

    return app.exec();
}