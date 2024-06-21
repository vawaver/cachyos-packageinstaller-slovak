// Copyright (C) 2022-2024 Vladislav Nepogodin
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

#ifndef ALPM_HELPER_HPP
#define ALPM_HELPER_HPP

#include <cstdint>

#include <alpm.h>

#include <optional>
#include <string>
#include <string_view>
#include <vector>

namespace alpm {

struct PackageView {
    std::string_view pkgver{};
    std::string_view desc{};
};

/// @brief Configures ALPM library.
/// @param handle Handle of ALPM library.
void setup_alpm(alpm_handle_t* handle) noexcept;

/// @brief Uninitializes ALPM and cleans up allocated resources.
/// @param handle Handle of ALPM library.
void destroy_alpm(alpm_handle_t* handle) noexcept;

/// @brief Reinitializes ALPM library.
/// @param handle Handle of ALPM library.
/// @param err Output parameter for the ALPM error code.
void refresh_alpm(alpm_handle_t** handle, alpm_errno_t& err) noexcept;

/// @brief Runs preparation for transactions.
/// @param handle Handle of ALPM library.
/// @param targets The vector of targets to be added to remove transaction.
/// @param flags Transaction flags for ALPM library.
/// @param conflict_msg Reference to a string to store the message on conflict.
/// @return Status code 0 on success, 1 overwise.
auto sync_trans(alpm_handle_t* handle, const std::vector<std::string>& targets, std::int32_t flags, std::string& conflict_msg) noexcept -> std::int32_t;

/// @brief Returns string containing targets which will be affected.
/// @param handle Handle of ALPM library.
/// @param verbosepkglists Flag indicating whether the output should be verbose.
/// @param conflict_msg Reference to a string to store the status message.
/// @return The affected targets.
auto display_targets(alpm_handle_t* handle, bool verbosepkglists, std::string& status_text) noexcept -> std::string;

/// @brief Adds targets to install transaction.
/// @param handle Handle of ALPM library.
/// @param targets The vector of targets to be added to install transaction.
void add_targets_to_install(alpm_handle_t* handle, const std::vector<std::string>& targets) noexcept;

/// @brief Adds targets to remove transaction.
/// @param handle Handle of ALPM library.
/// @param targets The vector of targets to be added to remove transaction.
void add_targets_to_remove(alpm_handle_t* handle, const std::vector<std::string>& targets) noexcept;

/// @brief Retrieves the view of package from syncdbs.
/// @param pkgname The pkgname of the package to retrieve.
/// @return An optional PackageView object if the package is available, std::nullopt otherwise.
auto get_package_view(alpm_handle_t* handle, std::string_view pkgname) noexcept -> std::optional<PackageView>;

}  // namespace alpm

#endif  // ALPM_HELPER_HPP
