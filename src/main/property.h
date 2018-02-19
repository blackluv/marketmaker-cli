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

#ifndef MARKETMAKER_CLI_PROPERTY_H
#define MARKETMAKER_CLI_PROPERTY_H

#include "basic.h"

#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    const char *key;
    const char *value;
} Property;

typedef struct {
    size_t   size;
    Property *properties;
} PropertyGroup;

PropertyGroup *realloc_properties(PropertyGroup *group, size_t newCapacity);

PropertyGroup *parse_properties(const char *str, err_t *err);

PropertyGroup *load_properties(const char *path, err_t *err);

bool save_properties(const PropertyGroup *group, const char *path, err_t *err);

const char *find_property(const PropertyGroup *group, const char *key);

#ifdef __cplusplus
};
#endif

#endif //MARKETMAKER_CLI_PROPERTY_H