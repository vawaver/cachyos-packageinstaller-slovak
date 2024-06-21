#ifndef ABOUT_HPP
#define ABOUT_HPP

#include <QString>

namespace about {

void displayDoc(const QString& url);
void displayAboutMsgBox(const QString& title, const QString& message, const QString& licence_url);

}  // namespace about

#endif  // ABOUT_HPP
