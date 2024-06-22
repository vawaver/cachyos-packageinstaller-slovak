#include "about.hpp"

#include <QDesktopServices>
#include <QIcon>
#include <QMessageBox>
#include <QPushButton>
#include <QUrl>

namespace about {

// display doc as normal user when run as root
void display_doc(const QString& url) noexcept {
    QDesktopServices::openUrl(QUrl(url));
}

void display_about_msgbox(const QString& title, const QString& message, const QString& licence_url) noexcept {
    QMessageBox msg_box(QMessageBox::NoIcon, title, message);
    auto* license_btn = msg_box.addButton(QObject::tr("License"), QMessageBox::HelpRole);
    auto* cancel_btn  = msg_box.addButton(QObject::tr("Cancel"), QMessageBox::NoRole);
    cancel_btn->setIcon(QIcon::fromTheme("window-close"));

    msg_box.exec();

    if (msg_box.clickedButton() == license_btn) {
        display_doc(licence_url);
    }
}

}  // namespace about
