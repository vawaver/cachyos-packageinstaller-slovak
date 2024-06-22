#ifndef ABOUT_HPP
#define ABOUT_HPP

#include <QString>

namespace about {

void display_doc(const QString& url) noexcept;
void display_about_msgbox(const QString& title, const QString& message, const QString& licence_url) noexcept;

}  // namespace about

#endif  // ABOUT_HPP
