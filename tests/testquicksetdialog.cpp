#include "quicksetdialog.h"

#include <QtTest/QtTest>

/*

buttonBox->Close cannot be disabled
joystickDialogLabel->text() cannot be empty
getJoystick() cannot be null pointer
if joystickDialogLabel->text() == ui->joystickDialogLabel->text().arg(joystick->getSDLName()).arg(joystick->getName())

QListIterator<JoyControlStick*> sticksList = currentset->getSticks().values();
if sticksList.hasNext() then device has sticks (amount = currentset->getSticks().values().count())

QListIterator<JoyAxis*> axesList = currentset->getAxes()->values();;
if axesList.hasNext() then device has axes (amount = currentset->getAxes()->values().count())

QListIterator<JoyDPad*> dpadsList = currentset->getHats().values();
if dpadsList.hasNext() then device has dpads (amount = currentset->getHats().values().count())

QListIterator<VDPad*> vdpadsList = currentset->getVdpads().values();
if vdpadsList.hasNext() then device has vdpads (amount = currentset->getVdpads().values().count())

QListIterator<JoyButton*> btnsList = currentset->getButtons().values();
if btnsList.hasNext() then device has buttons (amount = currentset->getButtons().values().count())

emit pressed stick
qobject_cast<JoyControlStick*>(getLastPressedButton()) != nullptr
add thread to list

emit pressed axis
possibleAxisAction && qobject_cast<JoyAxis*>(getLastPressedButton()) != nullptr
add thread to list

emit pressed dpad
qobject_cast<JoyDPad*>(getLastPressedButton()) != nullptr
add thread to list

emit pressed vdpad
qobject_cast<VDPad*>(getLastPressedButton()) != nullptr
add thread to list

emit pressed button
qobject_cast<JoyButton*>(getLastPressedButton()) != nullptr
add thread to list

emit pressed any button
getHelper() cannot be nullptr
add thread to list

all threads should be different


run restoreJoystickState (below connections don't exist anymore):

for each stickbutton
connect(stickbutton, &JoyControlStickButton::clicked, this, [this, stickbutton]() {
                        showStickButtonDialog(stickbutton);
                    });

for each naxisbutton
connect(naxisbutton, &JoyAxisButton::clicked, this, [this, naxisbutton]() {
                showAxisButtonDialog(naxisbutton);
            });

for each paxisbutton
connect(paxisbutton, &JoyAxisButton::clicked, this, [this, paxisbutton]() {
                showAxisButtonDialog(paxisbutton);
            });

for each dpadbutton
connect(dpadbutton, &JoyDPadButton::clicked, this, [this, dpadbutton] {
                        showDPadButtonDialog(dpadbutton);
                    });

for each vdpadbutton
connect(dpadbutton, &JoyDPadButton::clicked, this, [this, dpadbutton] {
                            showDPadButtonDialog(dpadbutton);
                        });

for each button
connect(button, &JoyButton::clicked, this, [this, button] {
                showButtonDialog(button);
            });

*/

class TestQuickSetDialog: public QObject
{
    Q_OBJECT

public:
    TestQuickSetDialog(QObject* parent = 0);

private slots:

private:
    QuickSetDialog quicksetdialog;
};

TestQuickSetDialog::TestQuickSetDialog(QObject* parent) :
    QObject(parent),
    QuickSetDialog()
{
    QTestEventLoop::instance().enterLoop(1);
}

// QTEST_MAIN(TestQuickSetDialog)
#include "testquicksetdialog.moc"

