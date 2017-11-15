#include <QApplication>
#include <QMainWindow>
#include <QDebug>
#include <qxtglobalshortcut.h>

class MyGlobalShortcutHandler : public QObject {
Q_OBJECT
public:
    explicit MyGlobalShortcutHandler(QObject *parent = 0)
            : QObject(parent) {
        m_globalShortcut.setShortcut(QKeySequence("Ctrl+Shift+X"));
        m_globalShortcut.setEnabled(true);

        connect(&m_globalShortcut, SIGNAL(activated()), SLOT(handleGlobalShortcut()));
    }

public slots:

    void handleGlobalShortcut() {
        qDebug() << "Global shortcut handled";
    }

private:
    QxtGlobalShortcut m_globalShortcut;
};