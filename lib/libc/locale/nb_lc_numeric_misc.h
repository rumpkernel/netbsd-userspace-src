/* $NetBSD: nb_lc_numeric_misc.h,v 1.6 2013/08/20 19:58:30 joerg Exp $ */

/*-
 * Copyright (c)2008 Citrus Project,
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef _NB_LC_NUMERIC_MISC_H_
#define _NB_LC_NUMERIC_MISC_H_

/*
 * macro required by nb_lc_template(_decl).h
 */
#define _CATEGORY_TYPE		_NumericLocale

static __inline void
_PREFIX(build_cache)(struct _locale_cache_t * __restrict cache,
    _NumericLocale * __restrict data)
{
	struct lconv *ldata;

	_DIAGASSERT(cache != NULL);
	_DIAGASSERT(cache->ldata != NULL);
	_DIAGASSERT(data != NULL);

	ldata = cache->ldata;
	ldata->decimal_point = __UNCONST(data->decimal_point);
	ldata->thousands_sep = __UNCONST(data->thousands_sep);
	ldata->grouping      = __UNCONST(data->grouping);
}

/* ARGSUSED */
static __inline void
_PREFIX(update_global)(_NumericLocale *data)
{
}

/*
 * macro required by nb_lc_template.h
 */
#define _CATEGORY_ID		LC_NUMERIC
#define _CATEGORY_NAME		"LC_NUMERIC"

#endif /*_NB_LC_NUMERIC_MISC_H_*/