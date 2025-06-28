#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QMap>

class Keyboard : public QWidget {
    Q_OBJECT
public:
    explicit Keyboard(QWidget *parent = nullptr);

    
    void updateKeyColor(const QString &key, const QString &color);

    
    void resetKeyboard();

signals:
    void keyPressed(const QString &key);

private:
    QGridLayout *layout;
    QMap<QString, QPushButton*> buttons;  

    void setupKeys();
};

#endif // KEYBOARD_H
