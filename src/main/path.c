/******************************************************************************
 * Copyright © 2014-2017 The SuperNET Developers.                             *
 *                                                                            *
 * See the AUTHORS, DEVELOPER-AGREEMENT and LICENSE files at                  *
 * the top-level directory of this distribution for the individual copyright  *
 * holder information and the developer policies on copyright and licensing.  *
 *                                                                            *
 * Unless otherwise agreed in a custom licensing agreement, no part of the    *
 * SuperNET software, including this file may be copied, modified, propagated *
 * or distributed except according to the terms contained in the LICENSE file *
 *                                                                            *
 * Removal or modification of this copyright notice is prohibited.            *
 *                                                                            *
 ******************************************************************************/

#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "path.h"
#include "safe_alloc.h"

char *home_path(const char *path)
{
    const char *homedir;

    if ((homedir = getenv("HOME")) == NULL) {
        homedir = ".";
    }
    size_t dest_len = strlen(homedir) + 1 + strlen(path) + 1;
    char *dest = safe_malloc(dest_len);
    snprintf(dest, dest_len, "%s/%s", homedir, path);
    return dest;
}
