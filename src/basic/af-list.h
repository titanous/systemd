/* SPDX-License-Identifier: LGPL-2.1+ */
#pragma once

/***
  This file is part of systemd.

  Copyright 2014 Lennart Poettering

  systemd is free software; you can redistribute it and/or modify it
  under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation; either version 2.1 of the License, or
  (at your option) any later version.

  systemd is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with systemd; If not, see <http://www.gnu.org/licenses/>.
***/

#include <sys/socket.h>

#include "string-util.h"

const char *af_to_name(int id);
int af_from_name(const char *name);

static inline const char* af_to_name_short(int id) {
        const char *f;

        if (id == AF_UNSPEC)
                return "*";

        f = af_to_name(id);
        if (!f)
                return "unknown";

        assert(startswith(f, "AF_"));
        return f + 3;
}

int af_max(void);
