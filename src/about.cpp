#include "about.hpp"

#include <QDesktopServices>
#include <QIcon>
#include <QMessageBox>
#include <QPushButton>
#include <QUrl>

namespace about {

// display doc as normal user when run as root
void displayDoc(const QString& url) {
    QDesktopServices::openUrl(QUrl(url));
}

void displayAboutMsgBox(const QString& title, const QString& message, const QString& licence_url) {
    QMessageBox msgBox(QMessageBox::NoIcon, title, message);
    auto* btnLicense = msgBox.addButton(QObject::tr("License"), QMessageBox::HelpRole);
    auto* btnCancel  = msgBox.addButton(QObject::tr("Cancel"), QMessageBox::NoRole);
    btnCancel->setIcon(QIcon::fromTheme("window-close"));

    msgBox.exec();

    if (msgBox.clickedButton() == btnLicense) {
        displayDoc(licence_url);
    }
}

}  // namespace about
